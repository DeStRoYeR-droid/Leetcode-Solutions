// Last updated: 06/07/2026, 19:01:18
class Solution {
public:
    int largestAltitude(const vector<int>& gain) {
        int result = 0;
        int running_height = 0;
        for (const int& num : gain){
            running_height += num;
            result = max(running_height, result);
        }
        return result;
    }
};   