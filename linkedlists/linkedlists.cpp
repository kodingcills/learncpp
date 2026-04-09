#include <iostream>
using namespace std;
/**
 * A regular array stores data in one contiguous block of memory
 * A linked list scatters the nodes anywhre in the memory and connects them with pointers, much like dynamic memory allocation
 * 
 * each node only knows where the next node is
 * 
Array:   [10][20][30][40]   ← all adjacent in memory

Linked:  [10|→]  ...  [20|→]  ...  [30|→]  ...  [40|null]
          anywhere      anywhere      anywhere      anywhere

* the only entry point is m_head. Lose m_head, lose the entire list
 */

 /**
  * Structure: a linked list is a dynamic data structure made up of nodes. Each node contains the data being stored and a pointer to the next node in the list
  * Every node points to either another node or nullptr. Very last node in a linked list ALWAYS points to nullptr
  * 
  * Dummy nodes: to avoid edge-case with errors with the first or last elements, linked lists use :dummy" head nad tail nodes, tehse are standard nodes that have null elements and don't count towards total size
  */

  /**
   * LINKEDLISTS VS VECTORS
   * linkedlists can change size, and inserting or deleting data can happen anywhere in the list. Vectors require a contiguous block of memory to be stored in the Stack, not heap;
   * 
   * For linkedlists, to access the data, yiou must sequentially iterate throught he list and require manual memory management as it's a dynamic memory structure. You have to iteratrethrough the entire list to get tot eh point you want because the node has the address of the next node, so you have to keep following the trail of nodes until you get to the value you need
   */
/**
 * NODES
 * stores the data being stored and a pointer to the next node in the list
 * data = actual information being stored in the node (name, test grade)
 * a pointer to the address of the next node
 */
class List{
    private:
        struct Node { 
            int m_data; // the data
            Node* m_next; // pointer to next node, not the next data, the next instace of the node class
        };
        Node* m_head;   // only data member of List — pointer to first node
        Node* m_tail;   // optional but useful — pointer to last node
        int m_size;     // optional but useful
    public:
    /**
     * WHEN O USE -> vs .
     *  Node* ptr = new Node;
        ptr->m_data = 10;     //ptr is a POINTER use ->
        ptr->m_next = nullptr;

        Node obj;
        obj.m_data = 10;      // obj is an OBJECT → use .
     */
        List(){
            m_head = nullptr; // first node;
            m_tail = nullptr; //pointer to last node, hte nodes have to be pointers
            m_size = 0; 
        }
        void InsertFront(int data){
            Node * temp = new Node ; //create a new temporary node
            temp->m_data = data; // ppopulate the data with the new data, pointer temp is now pointing to m_data and settting it to the int data, changing the actual value of m_data to data
            temp-> m_next = m_head; // new node points to current head

            //head points to new node
            m_head = temp;
            m_size ++ ;
        }
    
        void InsertEnd(int data){
            Node * temp = new Node;
            temp -> m_data = data;
            temp -> m_next = nullptr; //because we're inserting at the end, the last node always points to nll regardless

            //chekc if it's an empty list in the first place. if so, the new temporary node is the first node that is being inserted at the end
            if(m_head == nullptr){
                m_head = temp;
                m_tail = temp;
            }else{
                m_tail->m_next = temp; // current tail points to new node, which is temo
                m_tail = temp; // tail updates to new node
            }
            m_size++;
        }

        void Print(){
            Node* temp = m_head; // head is the first node, we are printing starting at first node value
            while(temp != nullptr){
                cout << temp -> m_data << " -> ";
                temp = temp -> m_next; // advance to next node
            }
            cout << "nnull" << endl;
        }

        void Remove(int target){
            // removing any node requires knowing the node before it, because you need to r-link around it
            Node * curr = m_head;
            Node * prev = nullptr;
            while(curr != nullptr && curr->m_data !=target){
                prev = curr;
                curr = curr ->m_next; // manually go to next one
            }

            if(curr == nullptr){ /// if not found, do something
                return ;
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
        }
        /**
         * why this worksL removing a node at the target requires you to traverse through the linked list one by one node by node starting at the head, curr->m_data is pointing ot the value stored in m_data
         */

         ~List(){
            Node* curr = m_head;
            while(curr != nullptr){
                Node* next = curr -> m_next; //save next BEFORE dleeting curr, curr is the node pointer to the memory address of m_head
                // -> is the arrow operator, used to access the data or functions inside an object when yoou are using a pointer to that object
                //since a pointer is a memory address, you can't just ask the pointer fo tthe data directly, -> tells the computer to dereference it, so it's dereferencing it
                delete curr; // free current node, curr pointer still holds memory address;
                curr = next; // move to saved next
            }
            m_head = nullptr;

            /**
             * what this is doing is taking the nodw here the head is and deleting the pointer of that Node at that node;
             */

         }

         void Reverse(){
            Node* prev = nullptr;
            Node* curr = m_head;
            Node* next = nullptr;
            
            while(curr != nullptr){//the very last node is always pointing to a nullptr, so it's just running until the current node reaches the end node
                next = curr->m_next; // save next
                curr->m_next = prev; // reverse the pointer
                prev = curr; // advance prev
                curr = next; // advance the curr
            }
            m_head = prev; // prev is the last node we visited, head is the last node visited so prev = new head
         }
};

int main() {
}