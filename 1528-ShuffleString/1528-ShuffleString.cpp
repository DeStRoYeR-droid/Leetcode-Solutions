// Last updated: 14/09/2026, 09:20:31
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string result = s;
        for (int i = 0; i < s.size(); ++i){
            result[indices[i]] = s[i];
        }   
        return result;
    }
};