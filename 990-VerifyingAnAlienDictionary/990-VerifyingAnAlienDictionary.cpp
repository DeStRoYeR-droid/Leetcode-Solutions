// Last updated: 06/07/2026, 19:06:49
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> idx(26, 0);
        for (int i = 0; i < 26; ++i){
            idx[order[i] - 'a'] = i;
        }

        for (int i = 0; i < words.size() - 1; ++i){
            string w1 = words[i];
            string w2 = words[i + 1];

            int j = 0;
            bool order = true;
            while (j < w1.size() && j < w2.size()){
                if (w1[j] != w2[j]){
                    if (idx[w1[j] - 'a'] > idx[w2[j] - 'a']){
                        return false;
                    }
                    break;
                }
                ++j;
            }

            if (j == w2.size() && w1.size() > w2.size()){
                return false;
            }
        }
        return true;

    }
};