// Last updated: 06/07/2026, 18:50:13
class Solution {
public:
    string resultingString(const string& s) {
        stack<char> st;
        for (const char& ch : s){
            if (!st.empty() && abs(st.top() - ch) % 24 == 1) st.pop();
            else st.push(ch); 
        }
        string result;
        while (!st.empty()){
            result += st.top(); st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};