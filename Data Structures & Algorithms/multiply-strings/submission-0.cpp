class Solution {
public:
    string multiply(string num1, string num2) {
        // 1. Edge Case: If either is "0", result is "0"
        if (num1 == "0" || num2 == "0") return "0";
        
        int m = num1.size();
        int n = num2.size();
        
        // 2. Result array (initialized to 0)
        // Max size is m + n
        vector<int> pos(m + n, 0);
        
        // 3. Iterate Backwards (Right to Left)
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // Multiply current digits
                int mul = (num1[i] - '0') * (num2[j] - '0'); 
                
                // Determine positions in result array
                int p1 = i + j;     // The carry position
                int p2 = i + j + 1; // The current digit position
                
                // Add multiplication result to whatever is already there (from previous steps)
                int sum = mul + pos[p2];

                // Update digits
                pos[p1] += sum / 10; // Add carry to the left neighbor
                pos[p2] = sum % 10;  // Keep the remainder here
            }
        }
        
        // 4. Convert Array to String
        string result = "";
        for (int p : pos) {
            // Skip leading zero if result is empty
            if (!(result.empty() && p == 0)) { 
                result += to_string(p);
            }
        }
        
        return result;
    }
};