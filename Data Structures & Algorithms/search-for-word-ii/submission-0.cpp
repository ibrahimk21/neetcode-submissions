class Solution {
public:
    // 1. Node Definition 
    class Node {
    public:
        Node* next[26];
        string* word;
        Node() {
            word = nullptr;
            for (auto& c : next) c = nullptr;
        }
    };

    Node* head = new Node();

    // 2. Insert 
    void insert(string& word) {
        Node* curr = head;
        for (char c : word) {
            if (!curr->next[c - 'a']) {
                curr->next[c - 'a'] = new Node();
            }
             curr = curr->next[c - 'a'];
        }
        curr->word = &word;
    }

    // 3. DFS inside Solution
    void dfs(vector<vector<char>>& board, int i, int j, Node* currNode, vector<string>& result) {
        int rows = board.size();
        int cols = board[0].size();
        
        // Bounds and Visited check
        if (i < 0 || i >= rows || j < 0 || j >= cols || board[i][j] == '#') {
            return;
        }

        char c = board[i][j];

        // Pruning: If path doesn't exist in Trie, return
        if (!currNode->next[c - 'a']) {
            return;
        }

        // Move to next node
        currNode = currNode->next[c - 'a']; // Fixed: use currNode, not curr

        // Found a word?
        if (currNode->word) {
            result.push_back(*currNode->word); // Fixed: Dereference the pointer (*)
            currNode->word = nullptr;          // Avoid duplicates
        }

        // Backtracking
        board[i][j] = '#';

        dfs(board, i + 1, j, currNode, result);
        dfs(board, i, j + 1, currNode, result);
        dfs(board, i - 1, j, currNode, result);
        dfs(board, i, j - 1, currNode, result);

        board[i][j] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        if (board.empty() || words.empty()) return result;

        // Fill trie (Using the member function directly)
        for (string& word : words) {
            insert(word);
        }

        int rows = board.size();
        int cols = board[0].size();
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                dfs(board, i, j, head, result);
            }
        }
        return result;
    }
};