// Last updated: 07/09/2026, 22:34:38
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