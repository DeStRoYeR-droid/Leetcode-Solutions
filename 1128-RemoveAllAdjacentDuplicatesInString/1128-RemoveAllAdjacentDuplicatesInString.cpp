// Last updated: 06/07/2026, 19:05:57
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