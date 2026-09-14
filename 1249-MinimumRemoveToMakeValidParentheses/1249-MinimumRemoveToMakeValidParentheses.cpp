// Last updated: 14/09/2026, 09:26:23
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int openCount = 0, closeCount = 0;
        stack<char> st;

        for (const char& ch : s){
            if (ch == '(') openCount++;
            else if (ch == ')') closeCount++;
            
            if (closeCount > openCount) closeCount--;
            else st.push(ch);
        }

        string result = "";
        while (!st.empty()){
            char cur = st.top(); st.pop();
            if (openCount > closeCount && cur == '(') openCount--;
            else result += cur;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};