// Last updated: 06/07/2026, 18:55:26
class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        const int n = word.size();
        long long val = 0;
        
        vector<int> result(n, 0);
        for (int i = 0; i < n; ++i){
            val = (val * 10 + (word[i] - '0'));
            result[i] = (val % m) == 0;
            val = val % m;
        }
        
        return result;
    }
};