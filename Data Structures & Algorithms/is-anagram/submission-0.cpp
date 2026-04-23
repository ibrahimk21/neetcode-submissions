class Solution {
public:
    bool isAnagram(string s, string t) {
    if(s.size() != t.size()) return false;
    int size = s.size();
    int s_hist[128] = {0};
    int t_hist[128] = {0};
    for (int i = 0; i < size; i++)
    {
        s_hist[s[i]]++;
        t_hist[t[i]]++;
    }
    for (int i = 0; i < 128; i++)
    {
        if (s_hist[i] != t_hist[i])
            return false;
    }
    return true;
}
};
