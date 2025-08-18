#include <cstddef>
#include <unordered_map>
class LFUCache {
public:
    class Node{

        public:

        int key, value;
        int counter = 0;
        Node* prev;
        Node* next;


        Node(int key, int value){
        this->key = key;
        this->value = value;
        prev = NULL;
        next = NULL; 
        }
    };
    int capacity;
    unordered_map<int, Node*> map;
    Node* head = new Node(0,0);
    Node* tail = new Node(0,0);

    
    LFUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head; 
    }

void swapnode(Node* node) {
    // Keep swapping until prev node's count > current node's count
    while (node->prev && node->prev != head && node->prev->counter <= node->counter) {
        Node* prevNode = node->prev;
        
        // Update the nodes before and after
        prevNode->prev->next = node;
        node->next->prev = prevNode;
        
        // Swap the two middle nodes
        node->prev = prevNode->prev;
        prevNode->next = node->next;
        
        // Connect the swapped nodes to each other
        node->next = prevNode;
        prevNode->prev = node;
    }
}

    void insertAttail(Node* node){

        Node* temp = tail->prev;

        tail->prev = node;
        node->next = tail;

        node->prev = temp;
        temp->next = node;

    }


    void deletenode(Node* node){
        node->prev->next =  node->next;
        node->next->prev = node->prev;
        delete node;
    }  

    
    int get(int key) {
         if(map.find(key)== map.end()){
            return -1;
         }
         else{
            Node* currNode = map.at(key);
            currNode->counter += 1;
            swapnode(currNode);
            int val = currNode->value;
            return val;
         }
        
    }
    
    void put(int key, int value) {

        if(map.find(key) != map.end()){
            Node* curNode = map.at(key);
            curNode->counter+=1;
            curNode->value = value;
            swapnode(curNode);
            return;
        }
        

        if(map.size()== capacity){
            int keytoerase = tail->prev->key;
            deletenode(tail->prev);
            map.erase(keytoerase);
           
        }

        Node* newnode =new Node(key, value);

        map[key] = newnode;

        insertAttail(newnode);
        newnode->counter += 1;
        swapnode(newnode);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */