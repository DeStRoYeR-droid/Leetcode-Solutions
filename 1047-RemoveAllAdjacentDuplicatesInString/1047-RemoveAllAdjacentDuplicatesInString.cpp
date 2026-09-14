// Last updated: 14/09/2026, 09:29:18
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for (const char& ch : s){
            if (st.size() == 0) st.push(ch);
            else{
                if (st.top() == ch) st.pop();
                else st.push(ch);
            }
        }
        string result = "";
        result.reserve(st.size());
        while (st.size()){result += st.top(); st.pop();}
        reverse(result.begin(), result.end());
        return result;
    }
};