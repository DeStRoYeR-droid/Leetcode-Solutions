// Last updated: 06/07/2026, 18:55:37
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefix(words.size() + 1, 0);
        vector<int> result(queries.size());

        int checker = 1065233;
        int i;
        for (i = 0; i < words.size(); i++){
            prefix[i+1] = prefix[i] + (
                        ((1 << (words[i].front() - 'a')) & checker) && 
                        ((1 << (words[i].back() - 'a')) & checker)
            );
        }
        
        i = 0;
        for (auto& q : queries) result[i++] = prefix[q[1] + 1] - prefix[q[0]];
        
        return result;
    }
};