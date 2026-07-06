// Last updated: 06/07/2026, 19:02:31
class Solution {
public:
    int minNumberOperations(const vector<int>& target) {
        const int n = target.size();
        int prev = 0, curr = 0;

        int result = 0;
        for (int i = 0; i < n; ++i){
            curr = target[i];
            if (curr > prev){
                result += curr - prev;
            }
            prev = curr;
        }
        return result;
    }
};