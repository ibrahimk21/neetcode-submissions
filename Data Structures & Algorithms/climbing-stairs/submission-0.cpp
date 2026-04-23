class Solution {
public:
    int climbStairs(int n) {
        vector<int> S(n + 1);
        S[0] = 1;
        S[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            S[i] = S[i-1] + S[i-2];
        }
        return S[n];
    }
};