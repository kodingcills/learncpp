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
        // void InsertEnd(int data){
        //     Node* temp = new Node();
        //     temp->m_data = data;
        //     temp->m_next = nullptr;
        //     if(m_head==nullptr){
        //         m_head=temp;
        //     }else{
        //         Node* cur = m_head;
        //         while(cur->m_next!=nullptr){
        //             cur = cur->m_next;
        //         }
        //         cur->m_next = temp;
        //     }
        // }
        /**
         * InsertEnd appends a Node at the end that holds data passed as arugment into aprameter int data
         * Make a temporary node to store the data in the node tha will be the new end node
         * data = input data
         * Node pointer to the address of the next node is nullptr bc the end always points to ullptr
         * If the first node (m_head) == nullptr, that's checking if hte LinkedList is empty
         *  if its empty, set the head, the first node, to the temp node
         * if not
         *  iterate through the list by iterating thorugh every note,
         *  have to start at the ointer to the beginner node, make a temporary node for hte current node
         *  keep iterating through the m_next value of the temporary pointer node until it reacehs nullptr, have to do cur->m_next because we cwant to stop when the next pointer is nullptr, as in we are at hte end
         *      set cur to cur -> m_next; this makes the current node set to m_head, then reassigned the pointer to the next node to that temp node originally mad,  which holds the data and next
         *          */

        void InsertEnd(int data){
            Node* temp = new Node();
            temp->m_data = data; // assign data to new tmep int for it to be end ptr
            temp->m_next = nullptr;

            if(m_head==nullptr){
                //checking if LinkedList is empty
                m_head=temp; // if list is empty, set first node to temp node
            }else{
                Node* cur = m_head; // pointer points to head
                while(cur->m_next!=nullptr){
                    cur = cur -> m_next;
                }
                cur->m_next = temp;
            }
        }

        void InsertEnd(Node* temp){
            temp->m_next = nullptr;
            if(m_head = nullptr){
                temp->m_next = m_head;
            }else{
                Node* curr = m_head;
                while(curr->m_next != nullptr){
                    curr = curr->m_next;
                }
                curr->m_next = temp;
            }
        }

        void Print(){
            Node* cur = m_head;
            while(cur->m_next!=nullptr){
                cout << cur->m_data << endl;
                cur  = cur -> m_next;
            }
        }
};