// Last updated: 06/07/2026, 18:58:08
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        const int prefix_size = pref.size();
        int result = 0;
        for (const string& word : words){
            result += (word.substr(0, prefix_size) == pref);
        }
        return result;
    }
};