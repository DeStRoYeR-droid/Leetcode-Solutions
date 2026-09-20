// Last updated: 20/09/2026, 10:32:24
class Solution {
public:
    int reverseDegree(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); ++i){
            result += (i + 1) * ('z' - s[i] + 1);
        }
        return result;
    }
};