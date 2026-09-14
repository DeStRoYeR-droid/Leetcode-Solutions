// Last updated: 14/09/2026, 09:24:26
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