// Last updated: 06/07/2026, 18:48:38
class Solution {
public:
    int longestBalanced(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); ++i){
            vector<int> state(26, 0);
            for (int len = 1; i + len <= s.size(); ++len){
                state[s[i + len - 1] - 'a']++;
                if (isBalanced(state)){
                    result = max(result, len);
                }
            }
        }
        return result;
    }

    bool isBalanced(vector<int>& state){
        int val = -1;
        for (int& value : state){
            if (value != 0){
                val = value;
                break;
            }
        }

        for (int& value : state){
            if (value == 0 || value == val) continue;
            else return false;
        }
        return true;
    }
};