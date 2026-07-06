// Last updated: 06/07/2026, 18:56:32
class Solution {
public:
    char last(vector<int>& freq){
        for (int i = 0; i < 26; ++i) if (freq[i]) return 'a' + i;
        return 'a';
    }
    string robotWithString(string s) {
        stack<char> st;
        string t = "";

        vector<int> freq(26, 0);
        for (const char& ch : s) freq[ch - 'a']++;

        for (const char& ch : s){
            st.push(ch);
            freq[ch - 'a']--;

            while (!st.empty() && st.top() <= last(freq)){
                t += st.top();
                st.pop();
            }
        }

        while (!st.empty()){
            t += st.top(); st.pop();
        }
        return t;
    }
};