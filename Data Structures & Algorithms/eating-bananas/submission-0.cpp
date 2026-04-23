class Solution {
public:
    long long hoursToFinish(vector<int>& piles, int k)
    {
        long long h = 0;
        for(int i = 0; i < piles.size(); i++)
        {
            h += (piles[i] + k - 1) / k;
        }
        return h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        if(h == 0) return 0;


        int left = 1, right = 0;

        for(int p : piles) right = max(right, p);

        int result  = right;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            long long hours = hoursToFinish(piles, mid);
            if(hours <= h)
            {
                result = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return result;
    }
};