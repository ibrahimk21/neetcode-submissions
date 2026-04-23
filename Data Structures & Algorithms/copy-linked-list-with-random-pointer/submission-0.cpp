/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        // Map: Old Address -> New Address
        unordered_map<Node*, Node*> oldToNew;
        
        // Pass 1: Create all nodes (Isolated)
        Node* curr = head;
        while (curr) {
            oldToNew[curr] = new Node(curr->val);
            curr = curr->next;
        }
        
        // Pass 2: Connect pointers
        curr = head;
        while (curr) {
            // "The clone of current" -> next = "The clone of (current's next)"
            oldToNew[curr]->next = oldToNew[curr->next];
            
            // "The clone of current" -> random = "The clone of (current's random)"
            oldToNew[curr]->random = oldToNew[curr->random];
            
            curr = curr->next;
        }
        
        return oldToNew[head];
    }
};