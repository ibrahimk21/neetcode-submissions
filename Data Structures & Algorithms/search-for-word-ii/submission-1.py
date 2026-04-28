class TrieNode():
    def __init__(self):
        self.children = {}
        self.word = None

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        if not board: return []
        
        root = TrieNode()
        for word in words:
            curr = root
            for char in word:
                if char not in curr.children:
                    curr.children[char] = TrieNode()
                curr = curr.children[char]
            curr.word = word
        
        ROWS, COLS = len(board), len(board[0])
        res  = []

        def dfs(r, c, node):
            if (r < 0 or c < 0 or r >= ROWS or c >= COLS or
                board[r][c] not in node.children or board[r][c] == "#"):
                return

            temp_char = board[r][c]
            curr_node = node.children[temp_char]

            if curr_node.word:
                res.append(curr_node.word)
                curr_node.word = None

            board[r][c] = "#"

            dfs(r + 1, c, curr_node)
            dfs(r - 1, c, curr_node)
            dfs(r, c + 1, curr_node)
            dfs(r, c - 1, curr_node)

            board[r][c] = temp_char
        
        for r in range(ROWS):
            for c in range(COLS):
                dfs(r, c, root)
                
        return res

            