class Solution {
public:
    const vector<string> KEYPAD = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    void backtrack(string& digits, int start, string& current, vector<string>& result)
    {
        if(start == digits.size())
        {
            result.push_back(current);
            return;
        }
        string letters = KEYPAD[digits[start] - '0'];
        for(int j = 0; j < letters.size(); j++)
        {
            current.push_back(letters[j]);

            backtrack(digits, start + 1, current, result);

            current.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.empty()) return result;
        string current = "";
        backtrack(digits, 0, current, result);
        return result;
    }
};