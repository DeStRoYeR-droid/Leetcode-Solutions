// Last updated: 06/07/2026, 18:58:42
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int total_length = s.length() + spaces.size();
        int index = 0;
        int res_index = 0;
        string result(s.size() + spaces.size(), ' ');

        for (int i = 0; i < s.length(); i++){
            if (index < spaces.size() && spaces[index] == i){
                index++;
                res_index++;
            }
            result[res_index++] = s[i];
        }
        return result; 
    }
};