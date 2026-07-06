// Last updated: 06/07/2026, 19:03:59
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](const int& a, const int& b){
            int onesA = __builtin_popcount(a);
            int onesB = __builtin_popcount(b);
            if (onesA == onesB) return a < b;
            else return onesA < onesB;
        });
        return arr;
    }
};