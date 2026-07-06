// Last updated: 06/07/2026, 19:07:48
class Solution {
public:
    int solve(string s1, string s2) {
        int ans = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == s2[i])
                ans++;
        }
        return ans;
    }

    void findSecretWord(vector<string>& words, Master& master) {
        unordered_set<string> st(words.begin(), words.end());

        while (!st.empty()) {
            string first = *st.begin();
            int guessed = master.guess(first);

            for (auto it = st.begin(); it!= st.end();) {
                if(solve(*it,first) != guessed) it = st.erase(it);
                else it++;
            }
            st.erase(first);
        }
    }
};