class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() == 0) return true;

        int left = 0, right = s.size() - 1;
        while(left < right)
        {
            if(isalnum(s[left]) && isalnum(s[right]))
            {
                if(tolower(s[left]) != tolower(s[right]))
                    return false;
                left++;
                right--;
                continue;
            }
            if(!isalnum(s[left])) left++;
            if(!isalnum(s[right])) right--;
        }
        return true;
    }
};