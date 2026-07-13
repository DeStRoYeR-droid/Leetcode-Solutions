// Last updated: 13/07/2026, 22:30:26
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common = "";
        int shortest_len = 200;
        for (string str : strs) 
            shortest_len = (str.length() < shortest_len) ? str.length() : shortest_len;

        for (int i = 0; i < shortest_len; i++){
            char cur_char = strs[0][i];
            bool isEqual = true;
            for (int j = 1; j < strs.size(); j++){
                if (strs[j][i] == cur_char) continue;
                isEqual = false;
                break;
            }
            if (isEqual) common += cur_char;
            else break;
        }

        return common;
    }
};