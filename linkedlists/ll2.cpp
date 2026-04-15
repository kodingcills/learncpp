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
        void InsertFront(int data){
            Node* temp = new Node(); // make a new Node 
            temp->m_data = data; // put the data in the Node
            temp->m_next=m_head; //point the next node to the new data, start temp at head
            m_head=temp; // 
            m_size++;
        }

        void InsertEnd(int data){
            Node* temp = new Node();
            temp ->m_data = data;
            temp->m_next = nullptr;
            if(m_head==nullptr){
                m_head=temp;
            }else{
                Node* cur = m_head; // have to point to first one
                while(cur->m_next!=nullptr){
                    cur = cur->m_next;
                }
                cur->m_next = temp;
            }
            m_size++;
        }
};
int main() {
    // Your code goes here
    
    return 0;
}