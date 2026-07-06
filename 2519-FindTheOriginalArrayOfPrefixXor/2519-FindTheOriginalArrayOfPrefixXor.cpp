// Last updated: 06/07/2026, 18:56:33
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        const int n = pref.size();
        vector<int> arr(n);
        arr[0] = pref[0];
        for (int i = 1; i < n; i++) {
            arr[i] = pref[i] ^ pref[i-1];
        }
        return arr;
    }
};