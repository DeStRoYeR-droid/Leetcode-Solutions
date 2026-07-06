// Last updated: 06/07/2026, 19:02:36
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int d = arr[1] - arr[0];

        for (int i = 1; i < arr.size() - 1; ++i){
            int curD = arr[i + 1] - arr[i];
            if (curD != d) return false;
        }
        return true;
    }
};