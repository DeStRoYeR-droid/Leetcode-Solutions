// Last updated: 07/09/2026, 22:40:29
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        const int n = words.size();
        int cur = groups[0];
  
        vector<string> result;
        result.push_back(words[0]);

        for (int i = 1; i < n; i++){
            if (cur != groups[i]){
                result.push_back(words[i]);
                cur = groups[i];
            }
        }
        return result;
        
    }
};