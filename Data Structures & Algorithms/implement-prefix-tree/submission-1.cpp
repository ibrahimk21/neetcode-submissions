class PrefixTree {
public:
    class Node
    {
    public:
        bool isLast;
        Node* next[26];
        Node()
        {
            isLast = false;
            for(auto &c:next) c=nullptr;
        }
    };

    Node* head;
    PrefixTree() {
        head = new Node();
    }
    
    void insert(string word) {
        Node* curr = head;
        for(char c: word)
        {
            if(!curr->next[c-'a'])
            {
                curr->next[c-'a'] = new Node();
            }
            curr = curr->next[c-'a'];
        }
        curr->isLast = true;
    }
    
    bool search(string word) {
        Node* curr = head;
        for(char c: word)
        {
            if(!curr->next[c - 'a']) return false;
            curr = curr->next[c - 'a'];
        }
        return curr->isLast;
    }
    
    bool startsWith(string prefix) {
        Node* curr = head;
        for(char c: prefix)
        {
            if(!curr->next[c - 'a']) return false;
            curr = curr->next[c - 'a'];
        }
        return true;
    }

    void clear(Node* node) {
        if (!node) return;
        
        for (Node* child : node->next) {
            if (child) {
                clear(child);
            }
        }
        
        delete node;
    }
    ~PrefixTree() {
        clear(head);
    }
};
