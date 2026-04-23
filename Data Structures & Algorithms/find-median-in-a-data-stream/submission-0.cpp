    class MedianFinder {
    public:
        priority_queue<int> leftHeap;
        priority_queue<int, vector<int>, greater<int>> rightHeap;
        void moveFromLeftToRight()
        {
            rightHeap.push(leftHeap.top());
            leftHeap.pop();
        }
        void moveFromRightToLeft()
        {
            leftHeap.push(rightHeap.top());
            rightHeap.pop();
        }
        MedianFinder() {
            
        }
        
        void addNum(int num) {
            leftHeap.push(num);
            moveFromLeftToRight();
            if(rightHeap.size() > leftHeap.size())
            {
                moveFromRightToLeft();
            }
        }
        
        double findMedian() {
            if(leftHeap.size() > rightHeap.size()) return leftHeap.top();
            else return (leftHeap.top() + rightHeap.top()) / 2.0;
        }
    };

    /**
    * Your MedianFinder object will be instantiated and called as such:
    * MedianFinder* obj = new MedianFinder();
    * obj->addNum(num);
    * double param_2 = obj->findMedian();
    */