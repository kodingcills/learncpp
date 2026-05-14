#include <iostream>
using namespace std;

class LinkedList{
    private:
        struct Node{
            int m_data;
            Node* m_next;
        };
        Node* m_head;
        int m_size;
    public:
        LinkedList(){
            m_head = nullptr;
            m_size = 0;
        }

        ~LinkedList(){
            Node* curr = m_head;
            while(curr!=nullptr){
                Node* next = curr->m_next;
                delete curr;
                curr = next;
            }
            m_head = nullptr;
        }

        //set the new data tot eh val set hte next tot eh head set hte head to the new now and increment
        void InsertFront(int val){
            Node* curr = new Node();
            curr->m_data = val;
            curr->m_next=m_head;
            m_head = curr;
            m_size++;
        }

        // make a new node for the temp then traverse
        void InsertEnd(int val){
            Node* temp = new Node();
            temp->m_data = val;
            temp->m_next = nullptr;
            if(m_head == nullptr){
                m_head = temp;
            }else{
                Node* curr = m_head;
                while(curr->m_next != nullptr){
                    curr = curr->m_next;
                }
                curr->m_next = temp;
            }
            m_size++;
        }

        //insert at node
        void InsertAt(int index, int val){
            if(index<0 || index>=m_size){
                return;
            }
            if(index==0){
                Node* curr = new Node();
                curr->m_data = val;
                curr->m_next = m_head;
                m_head = curr;
            }

            Node* prev = nullptr;
            Node* curr = m_head;
            // dont need next because once we dont need to access the node after the target one
            for(int i = 0; i < index; i++){
                prev->m_next = curr;
                curr = curr->m_next;
            }
            Node* temp = new Node();
            temp->m_next = curr;
            temp->m_data = val;
            prev->m_next = temp;

            m_size++;
        }

        // remoecs now ith the value the target is at
        /**
         * 
         * 1. set up traversla node current
         * 2. need previous node to keep tracl of what came before
         * 3. go until it reaxhes the target and as long as it itsnt pointing to the end of the list to the nullptr
         *      - set previous node to current
         *      - update current to next
         * 4. check to ee if curr points to a nullptr as in the target is not there so return false
         * 
         * //before deleting the current pointe rto free it up you ahve to check the prev
         * //if the prev points to a nullptr that means its empty
         * //else point ot the o ne after the curr, as in the m-_next of the curr
         * 
         */
        bool Remove(int val){
            Node* prev = nullptr;
            Node* curr = m_head;

            while(curr!=nullptr && curr->m_data!=val){
                prev = curr;
                curr = curr->m_next;
            }

            if(curr == nullptr){
                return false;
            }

            if(prev == nullptr){
                m_head = curr->m_next;
            }else{
                prev->m_next = curr->m_next;
            }

            delete curr;
            curr = nullptr;
            m_size--;
            return true;
        }

        bool Contains(int val) const{
            Node* curr = m_head;

            while (curr!=nullptr && curr->m_data!=val){
                curr = curr->m_next;
            }

            if(curr==nullptr){
                return false;
            }
            return true;
        }

        void Print() const{
            Node* temp = m_head;
            if(m_head == nullptr){
                cout << "Empty" << endl;
            }
            while(temp!=nullptr){
                cout << temp->m_data << " -> ";
                temp = temp->m_next;
            }
            cout << "END " << endl;
        }

        void Reverse() {
            Node* prev = nullptr;
            Node* next = nullptr;
            Node* curr = m_head;
            while(curr!=nullptr){
                next = curr->m_next;
                curr->m_next = prev;

                prev = curr;
                curr = next;
            }

            m_head = prev;
        }

        void PrintMiddle() const{
            if(m_head == nullptr){ cout << "Empty" << endl; return; }
            Node* temp = m_head;
            for(int i = 0; i < m_size/2; i++){
                temp = temp->m_next;
            }
            cout << temp->m_data << endl;
        }
        int GetSize() const{return m_size;}
};

int main(){
    LinkedList l;
    l.InsertEnd(1);
    l.InsertEnd(2);
    l.InsertEnd(3);
    l.InsertEnd(4);
    l.InsertEnd(5);

    l.Print();

    l.InsertFront(0);
    l.Print();

    l.InsertAt(3, 99);
    l.Print();

    l.Remove(99);
    l.Print();
    l.Remove(0);
    l.Print();
    l.Remove(5);
    l.Print();

    l.Remove(999);
    l.Contains(3);

    l.PrintMiddle();
    l.Reverse();
    cout << l.GetSize() << endl;
}