#include <vector>
#include <string>
#include <stack>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> st;
        
        for (const std::string& token : tokens) {
            if (token == "+") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(a + b);
            } else if (token == "-") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(a - b);
            } else if (token == "*") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(a * b);
            } else if (token == "/") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(a / b);
            } else {
                // Handle numbers (push to stack)
                st.push(std::stoi(token));
            }
        }
        
        return st.top();
    }
};