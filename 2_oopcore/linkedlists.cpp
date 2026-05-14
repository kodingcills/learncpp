/**
 * linked lists
 * made up of ndes and the data the nodss point to
 * every linked list relies on 3 main:
 *  head
 *  nodes
 *  nullptr
 * 
 * The Nodes
 *  a node is a box divided into 2 rooms
 *  a node has the dat, and the pointer to the next ndoe
 * Tge gead
 *  head is the pointer to the first node in the list
 *  if yoy lose the head, you lose the first node, meaning you lose the second node, etc etc leading to a memory leak
 * 
 * nullptr
 *  the end, it is the very last node in the chain, it only has the data and since there sno next node to point to, it just points to nullptr
 */


 /**
  * traversing linked list
  * 1. look at head to see whos first
  * 2. create tmeporary pointer and point it at the first
  * 3. to read tot eh next ndoe, read the pointer to the next node of curr curr->m_next to move there
  * repeat untuil it gets to nullptr so curr!=nullptr
  * 
  */
struct Node{
    int m_data; // the value
    Node* m_next; // pointer to next node - nullptr if last
};

class List{
    private:
        struct Node{
            int m_data;
            Node* m_next;
        };
        Node* m_head;
        int m_size;
    // //traversal
    // Node* curr = m_head; // copy of head
    // while(curr != nullptr){//traverse until it goes to the end
    //     //do smth with curr ->m_data
    //     curr = curr->m_next; // to advance
    // }
    /**
     * InsertFront(int val)
     * when inserting fdront, you dont have to traverse through each node because you're just oding the front, so all you have to change
     */
    void InsertFront(int val){
        Node* curr = new Node();
        curr->m_data = val;
        curr->m_next = m_head; // you have to point ot hrthe current head to tell the new node's pointer to the next node should be pointing tot he head so now the new node holds onto the old front of the list. this way you dont have to individually traverse and copy all the values, because it's already pointing to the first node of the original, so then it points to the 2nd, then the 3rd, etc etc
        m_head=curr;
        m_size++;
    }

    /**
     * insertend takes in a val as a arameter and thats the data stored in the temp node the temp node is ognna be the one inserted at the end
     * first check if the head is pointing toa. nullptr, meaning its empty, then set the head node to be pointing to the temp node
     * if not, then traverse
     * traverze by first always making a traversal temp node called curr
     * keep traversing by going to the next node it points to with curr->m_next until it reaches nullptr
     * then set the current node to teh next node to keep going
     * once you reach the end when the loop ends, then set the next node which at this point is the eyr end node to teh temp
     * incrememnt size always
     */
    void InsertEnd(int val){
        Node* temp = new Node();
        temp->m_data = val;
        temp->m_next = m_head;

        if(m_head==nullptr){
            m_head = temp;
        }else{
            Node* curr = m_head;
            while(curr->m_next!=nullptr){
                curr = curr->m_next;
            }
            curr->m_next = temp;
        }
        m_size++;
    }

    /**
     * bool Remove(int target) removes the node with hte value that the target is
     */

    bool Remove(int target){
        Node* curr = m_head; // set up traversal node to keep going
        Node* prev = nullptr; // this is for keeping travk of what came before, this is because once we remove the node at that target we need to be able to access the previous node so it cna point ot the one that went after the rone removed

        // go until it reaches the target and as long as it isnt pointing tot eh end of the list to the nullptr
        while(curr->m_data != target && curr != nullptr){
            prev = curr; // set the previous node to the current
            curr = curr->m_next; // update the current tot eh next
        }
        //now remove the node at that target

        //now check to see if the curr went all the way to the end meaning its a nullptr as in it went thorugh the whole list and didnt find the tragfet, so its not in there
        if(curr==nullptr){
            return false;
        }

        //before deleting the current, figure out what to do with previous
        //if the previous iss till pointing to the nullptr as in its removing teh head
        if(prev == nullptr){
            m_head = curr->m_next;
        }else{
            prev->m_next = curr->m_next; // make the previosu next the current next to go pass the target node
        }

        delete curr;
        curr = nullptr;
        m_size--;
        return true;
    }

    void InsertAt(int index, int val){
        //checking if the index is out of bounds first
        if(index < 0 || index > m_size){
            return;
        }
        if (index==0){
            InsertFront(val);
            return;
        }

        Node* curr = m_head;
        Node* prev = nullptr;

        //go until it reaches the index, because we know the position index number we're not usinga whilel0op[s]
        for(int i = 0; i < index; i++){
            prev = curr;
            curr = curr->m_next;
        }

        Node* temp = new Node();
        temp->m_data = val;
        temp->m_next = curr; // new node points to what was at that index
        prev->m_next = temp; // previous ndo points to teh new node tyhat was inserted after it
        m_size++;
    }

    ~List(){
        //need to deep delete and delete everything in the node, different from delte [] array dynamically allocated because an arrya itself is a pointer but the linkedlist is made up of poitners ot the next
        Node* curr = m_head;
        while(curr!=nullptr){ // traverse until the end
            Node* next = curr->m_next; // save the next node before deleting because we're delting them in order from first to last, and if we lose the node then we also lose the pointer t the next node
            delete curr;
            curr = next; 
        }
        m_head = nullptr;
    }

    void Reverse(){
        Node* prev = nullptr; // previous points to curr
        Node* curr = m_head;
        Node* next = nullptr; // next is currently an empty pointer to be used to store the next node current points to

        //need previous curr and next for reversing 

        while(curr!=nullptr){
            next = curr->m_next; 
            curr->m_next = prev; // reverse the direction it poitns to, instead of going to the next it goes to previous
            prev = curr;
            curr = next;
            
        }

        m_head = prev; // last node visited becoems new head
    }

    
};