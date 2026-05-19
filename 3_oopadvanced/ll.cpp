#include <iostream>
using namespace std;

class LinkedList{
    private:
        struct Node{
            Node* m_next;
            int m_data;
        };
        Node* m_head;
        int m_size;
    public:
        /**
         * it needs a big 3 because Node* m_head is a pointer to heap memory, eveyr node was individually new'd
         *          */
        LinkedList(){
            m_head = nullptr;
            m_size=0;
        }
        ~LinkedList(){
            //1. traverse through linked list
            Node* curr = m_head;
            while(curr!=nullptr){
                //2. save the next node befor eyou delete
                Node* temp = curr->m_next;
                //3. dleete
                delete curr;
                //4. set destroyed current node to temp
                curr = temp;
            }
            //5. set m_head to nullptr
            m_head = nullptr;
        }
        LinkedList(const LinkedList& other){
            // object is brand new, so m_head holds garbage, it's nto a real pointer yet
            //not the time to call delete or read from m_head, because there is nothing to read or celan up

            m_size = other.m_size;
            m_head = nullptr;

            //walk the other's list, read only
            Node* o = other.m_head;
            while(o != nullptr){
                // create a new independent node for our list
                Node* newNode = new Node();
                newNode->m_data = o->m_data;
                newNode->m_next = nullptr; // nullptr bc thee new node has no next yet
                //check if empty
                if(m_head==nullptr){
                    //the list is still empty, so this is the first nost
                    m_head = newNode; // head points to first new node
                }else{
                    //list already has ndoes, so traverse to find the last one
                    Node* curr = new Node();
                    while(curr->m_next != nullptr){
                        curr= curr->m_next; // walk to the end of our list at the very last node where the next thing its pointing to is a nullptr;
                    }
                    curr->m_next = newNode; // attach the node at the end
                }

                //now the list has brand new nodes with the same values in the same order, completely independnet form each other
            }

        }

        LinkedList& operator=(const LinkedList& other){
            //copy assignment operator
            //1. self assignment guard
            if(this==&other){
                return *this;
            }

            //delete everything currently
            Node* curr = m_head;
            while(curr!=nullptr){
                Node* next = curr->m_next;
                delete curr;
                curr = next;
            }

            //reset to empty
            m_head = nullptr;
            m_size = other.m_size;

            //deep copy from other
            Node* o = other.m_head;
            while(o!=nullptr){
                Node* newNode = new Node();
                newNode->m_data = o->m_data;
                newNode->m_next = nullptr;

                if(m_head == nullptr){
                    m_head = newNode;
                }else{
                    Node* curr = m_head;
                    while(curr->m_next!=nullptr){
                        curr = curr->m_next;
                    }
                    curr->m_next = newNode;
                }
                o = o->m_next;
            }

            *this;
        }
};

