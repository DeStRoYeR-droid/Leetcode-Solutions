// Last updated: 08/08/2026, 11:14:29
class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();

        vector<int> last(m);
        int j = m - 1;
        for (int i = n - 1; i >= 0; --i){
            if (j >= 0 && word1[i] == word2[j]){
                last[j] = i;
                --j;
            }
        }

        vector<int> result(m);
        bool usedSwap = false;
        j = 0;
        for (int i = 0; i < n && j < m; ++i){
            if (word1[i] == word2[j]){
                result[j] = i;
                ++j;
            }
            else if (usedSwap == false && (j == m - 1 || i + 1 <= last[j + 1])){
                result[j] = i;
                ++j;
                usedSwap = true;
            }
        }

        return (j != m) ? vector<int>() : result;
    }
};