class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0); // Initialize with 0s
        stack<int> st; // Stores INDICES, not values

        for (int i = 0; i < n; i++) {
            // While stack is not empty AND current temp is warmer than the top
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevIndex = st.top();
                st.pop();
                
                // Calculate the wait time
                answer[prevIndex] = i - prevIndex;
            }
            // Push current index to wait for its own warmer day
            st.push(i);
        }

        return answer;
    }
};