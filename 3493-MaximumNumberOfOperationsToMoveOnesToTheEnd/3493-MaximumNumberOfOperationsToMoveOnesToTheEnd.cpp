// Last updated: 06/07/2026, 18:52:35
class Solution {
public:
    int maxOperations(string s) {
        const int n = s.size();
        int result = 0, oneCounter = 0;
        for (int i = 0; i < n -1; ++i){
            if (s[i] == '1'){
                ++oneCounter;
                if (s[i + 1] == '0') result += oneCounter;
            }
        }
        return result;
    }
};