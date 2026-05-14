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
            delete m_head;
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

        //
        void InsertEnd(int val){

        }

};