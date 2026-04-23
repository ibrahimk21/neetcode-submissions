#include <unordered_map>

class LRUCache {
    
    // 1. Define the Node Structure
    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    // 2. Class Variables
    Node* head;
    Node* tail;
    int capacity;
    std::unordered_map<int, Node*> map; // Maps Key -> Node Pointer

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        
        // Initialize Dummies
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        
        // Connect them: [Head] <-> [Tail]
        head->next = tail;
        tail->prev = head;
    }
    
    // --- Helper Function: Add right after Head (Make MRU) ---
    void addNode(Node* newnode) {
        Node* temp = head->next; // The current first node
        
        newnode->next = temp;
        newnode->prev = head;
        
        head->next = newnode;
        temp->prev = newnode;
    }
    
    // --- Helper Function: Remove node from existing spot ---
    void deleteNode(Node* delnode) {
        Node* prevNode = delnode->prev;
        Node* nextNode = delnode->next;
        
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    
    // --- The Actual GET API ---
    int get(int key) {
        if (map.find(key) != map.end()) {
            Node* resNode = map[key];
            int res = resNode->val;
            
            // It was accessed, so it's now "Fresh".
            // Move it to the front.
            deleteNode(resNode); // Unplug it
            addNode(resNode);    // Plug it in at the front
            
            return res;
        }
        return -1;
    }
    
    // --- The Actual PUT API ---
    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            // Case 1: Exists. Update value and move to front.
            Node* existingNode = map[key];
            existingNode->val = value;
            deleteNode(existingNode);
            addNode(existingNode);
        } else {
            // Case 2: New node.
            
            // Check capacity first
            if (map.size() == capacity) {
                // Find the LRU node (it's right before tail)
                Node* lru = tail->prev;
                
                // CRITICAL: Remove from map first using the key stored in the node
                map.erase(lru->key);
                
                // Remove from list logic
                deleteNode(lru);
                
                // Free memory
                delete lru;
            }
            
            // Create new node and add to front
            Node* newNode = new Node(key, value);
            map[key] = newNode; // Add to map
            addNode(newNode);   // Add to list
        }
    }
};