// Last updated: 13/07/2026, 22:13:59
class Solution {
public:
    inline static int q[45];
    inline static bool init = []() {
        int n = 0;
        for (int i = 1; i < 10; i++)
            q[n++] = i;

        for (int i = 0; i < n; i++) {
            int d = q[i] % 10;
            if (d < 9) q[n++] = q[i] * 10 + d + 1;
        }

        return 0;
    }();
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        for (const int& val : q){
            if (val >= low && val <= high) result.push_back(val);
        }
        return result;
    }
};