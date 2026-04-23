class Solution {
public:
    int reverse(int x) {
        int res = 0;
        
        while (x != 0) {
            int digit = x % 10;
            x /= 10;
            
            // Check for OVERFLOW before multiplying by 10
            // If res > 214748364, the next step (res * 10) will overflow
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > 7)) {
                return 0;
            }
            
            // Check for UNDERFLOW
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && digit < -8)) {
                return 0;
            }
            
            res = res * 10 + digit;
        }
        
        return res;
    }
};