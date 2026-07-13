// Last updated: 13/07/2026, 22:25:44
class Solution {
public:
    inline int calculate(int a, int b, char op){
        if (op == '+') return a + b;
        else if (op == '-') return b - a;
        else if (op == '*') return a * b;
        return b / a;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        const int n = tokens.size();
        for (const string& token : tokens){
            if (token.size() == 1 && token[0] < 48){
                int int1 = st.top(); st.pop();
                int int2 = st.top(); st.pop();
                st.push(calculate(int1, int2, token[0]));
            }
            else{
                st.push(stoi(token));
            }
        }
        return st.top();    
    }
};