#include <iostream>
using namespace std;
class List{
    private:
        struct Node{
            int m_data;
            Node* m_next;
        };
        Node* m_head;
        int m_size;
    public:
        List(){
            m_head = nullptr;
            m_size = 0;
        }

        ~List(){
            Node* curr = m_head;
            while(curr != nullptr){
                Node* next = curr->m_next; // copy the next pointer
                //delete current node
                delete curr;
                curr = next;
            }
            m_head=nullptr;
            m_size=0;
        }

        void InsertFront(int val){
            Node* temp = new Node();
            temp->m_data = val;
            temp->m_next  = m_head;
            m_head = temp;
            m_size++;
        }

        void InsertEnd(int val){
            Node* temp = new Node();
            temp -> m_data = val;
            temp -> m_next = nullptr;
            // insert the end, if the list is empty, the head is the first node which is the temp that's being adde at the tend
            if(m_head == nullptr){
                m_head = temp;
            }else{
                Node* curr = m_head;
                while(curr->m_next != nullptr){ // this is to stop at the last node, not past it, since we're iterating to the end of the node then appending it
                    curr = curr->m_next;
                }
                curr -> m_next = temp;
            }
            m_size++;
        }

        bool Remove(int target){
            // removing any node requires knowing the node before it, because you need to r-link around it
            Node * curr = m_head;
            Node * prev = nullptr;
            while(curr != nullptr && curr->m_data !=target){
                prev = curr;
                curr = curr ->m_next; // manually go to next one
            }

            if(curr == nullptr){ /// if not found, do something
                return false;
            }
            if(prev == nullptr){
                //renove the head
                m_head = curr ->m_next;
            }else{
                prev->m_next = curr->m_next;
            }

            delete curr;
            curr = nullptr;
            m_size--;
            return true;
        }

        void Print() const{
            Node* curr = m_head;
            while(curr!= nullptr){
                cout << curr->m_data << " -> " ;
                curr = curr ->m_next;
            }
            cout << "null" << endl;
        }

        int GetSize() const{
            return m_size;
        }

        bool Contains(int target) const{
            Node* curr = m_head; // copy of first pointer
            while(curr != nullptr){
                if(curr->m_data == target){
                    return true;
                }
                curr = curr -> m_next; //manually set
            }
            return false; // return false if there isn't a value that matches the target
        }
};


int main(){
    List l;
    l.InsertEnd(1);
    l.InsertEnd(2);
    l.InsertEnd(3);
    l.InsertEnd(4);
    l.InsertEnd(5);
    l.Print();
    l.InsertFront(3);
    l.Print();
    l.Remove(3);
    l.Print();
    l.Remove(0);
    l.Print();
    l.Remove(5);
    l.Print();
    l.Remove(99);
    l.Print();
    l.GetSize();
}