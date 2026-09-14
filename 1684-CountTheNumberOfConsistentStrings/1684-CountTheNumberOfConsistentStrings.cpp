// Last updated: 14/09/2026, 09:18:45
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int state = 0;
        int result = 0;

        for (char& ch : allowed) state = state ^ (1 << (ch - 'a'));
        for (string word: words){
            bool is_valid = true;
            for (char& ch : word){
                if (!(1 << (ch - 'a') & state)){
                    is_valid = false;
                    break;
                }
            }
            result += is_valid;
        }
        return result;
    }
};