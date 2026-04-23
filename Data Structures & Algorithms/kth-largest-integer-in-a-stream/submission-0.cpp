class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> heap;
    int _k;
    KthLargest(int k, vector<int>& nums) {
        _k = k;
        for(int n: nums)
        {
            heap.push(n);
            if(heap.size() > _k)
            {
                heap.pop();
            }
        }
    }
    
    int add(int val) {
        heap.push(val);
        if(heap.size() > _k)
        {
            heap.pop();
        }
        return heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */