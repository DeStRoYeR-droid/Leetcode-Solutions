// Last updated: 06/07/2026, 18:58:34
class Solution {
public:
    int numberOfBeams(const vector<string>& bank) {
        int result = 0, prev = 0;
        for (const string& str : bank){
            int ones = count(str.begin(), str.end(), '1');
            if (ones > 0){
                result += prev * ones;
                prev = ones;
            }
        }
        return result;
    }
};