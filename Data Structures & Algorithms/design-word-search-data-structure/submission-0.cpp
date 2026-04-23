class WordDictionary {
public:
    class Node
    {
    public:
        bool isLast;
        Node* next[26];
        Node()
        {
            isLast = false;
            for(auto& c: next) c = nullptr;
        }
    };
    Node* trie;
    WordDictionary() {
        trie = new Node();
    }
    
    void addWord(string word) {
        Node* curr = trie;
        for(char& c: word)
        {
            if(!curr->next[c - 'a']) 
            {
                curr->next[c - 'a'] = new Node();
            }
            curr = curr->next[c - 'a'];
        }
        curr->isLast = true;
    }

    bool match(string& word, int index, Node* node) {
        if (index == word.size()) {
            return node->isLast;
        }

        if (word[index] == '.') {
            for (auto& child : node->next) {
                if (child && match(word, index + 1, child)) {
                    return true;
                }
            }
            return false;
        } 
        
        else {
            int i = word[index] - 'a';
            if (!node->next[i]) return false;
            return match(word, index + 1, node->next[i]);
        }
    }
    
    bool search(string word) {
        return match(word, 0, trie);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */