class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        
        for (const string& token : tokens) {
            // Check if token is an operator
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                
                if (token == "+") s.push(a + b);
                else if (token == "-") s.push(a - b);
                else if (token == "*") s.push(a * b);
                else s.push(a / b);
            } 
            else {
                // Token is a number
                s.push(stoi(token));
            }
        }
        
        return s.top();
    }
};