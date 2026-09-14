// Last updated: 14/09/2026, 09:27:31
class Solution {
public:
    bool threeConsecutiveOdds(const vector<int>& arr) {
        const int n = arr.size();
        if (n < 2) return false;
        for (int i = 0; i < n - 2; ++i){
            if (arr[i] % 2 && arr[i+1] % 2 && arr[i+2] % 2) return true;
        }
        return false;
    }
};