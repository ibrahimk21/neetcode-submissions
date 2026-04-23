class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1));
        for(int i = 0; i <= text1.size(); i++)
        {
            for(int j = 0; j <= text2.size(); j++)
            {
                if(i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    if(text1[i-1] == text2[j-1])
                    {
                        dp[i][j] = 1 + dp[i-1][j-1];
                    }
                    else
                    {
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    }
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
};

// dp[i][j] represents the LCS length using text1 up to index i and text2 up to index j
// dp[i][j] = if text1[i] == text2[j] then 1 + dp[i-1][j-1]
//             else max(dp[i-1][j], dp[i][j-1])