// Last updated: 06/07/2026, 18:52:06
class Solution {
public:
    int possibleStringCount(string word) {
        const int n = word.size();
        int result = 1;
        for (int i = 1; i < n; ++i){
            result += (word[i] == word[i - 1]);
        }
        return result;
    }
};