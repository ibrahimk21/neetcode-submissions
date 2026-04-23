class Solution {
public:
    double myPow(double x, int n) {
        // 1. Use long long to handle the edge case of n = INT_MIN
        long long N = n;
        
        // 2. If negative power, flip x and make N positive
        // x^-n = (1/x)^n
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        
        double result = 1.0;
        
        // 3. Binary Exponentiation Loop
        while (N > 0) {
            // If N is odd, we multiply the extra 'x' into our result
            if (N % 2 == 1) {
                result *= x;
            }
            
            // Square the base (x^2, x^4, x^8...)
            x *= x;
            
            // Cut the exponent in half
            N /= 2;
        }
        
        return result;
    }
};