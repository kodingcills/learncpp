#include <iostream>
class LinkedList{
    private:
        //Node is a container that bundles the data with a pointer to the next container
        struct Node{
            int m_data;
            Node* m_next;
        };
        Node* m_head; // pointer to memory address of first node
        Node* m_tail; // pointer to memory address of last node
        int m_size; // how many nodes exist
    public:
        LinkedList(){
            m_head = nullptr;
            m_tail = nullptr;
            m_size = 0;
        }

        ~LinkedList(){
            //destroy all pointers starting at beginning
            Node* curr = m_head;
            while(curr != nullptr){
                Node* next = curr->m_next; // copy th next pointer
                delete curr; // delete current pointer
                curr = next; // set current pointer to now the temporary copy of the next pointer
            }
            m_head = nullptr;
            m_tail = nullptr;
        }

        void AddFront(int value){
            Node* temp = new Node();
            temp->m_data = value; // setting the data stored in the Ndoe to value
            temp->m_next = m_head; // points the node to the address of the first node, so it's the first node
            m_head = temp; // updates head to makes the top nde the new node
            m_size++;
        }

        void InsertEnd(int value){
            Node* temp;
            temp->m_data = value;
            temp->m_next = nullptr;
            if(m_head==nullptr){ // cheking if its empty
                m_head = temp;
                m_tail = temp;
            }else{
                m_tail->m_next = temp;
                m_tail = temp; // putting the last node at the end
            }
            m_size ++;
        }
        //searching for a value
        bool searchIfValue(int target){
            Node* curr = m_head; // copy of first pointer
            while(curr != nullptr){
                if(curr->m_data == target){
                    return true;
                }
                curr = curr -> m_next; //manually set
            }
            return false; // return false if there isn't a value that matches the target
        }

        //position tracking
        int searchPosition(int target){
            Node * curr = m_head;
            //need an int to track the position, we are searcing for hte position that has the value
            int pos = 0;
            while(curr != nullptr){
                if(curr->m_data == target){
                    return pos;
                }
                curr = curr -> m_next;
                pos++;
            }
            return -1;
        }
};