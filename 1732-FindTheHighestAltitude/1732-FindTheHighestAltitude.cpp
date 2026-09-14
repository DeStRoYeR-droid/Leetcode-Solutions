// Last updated: 14/09/2026, 09:17:58
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