// Last updated: 06/07/2026, 19:03:55
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        const int n = mat.size();
        const int m = mat[0].size();
        vector<vector<int>> store(m + 1);
        for (int i = 0; i < n; ++i){
            int count = 0;
            for (const auto val : mat[i]){
                if (val == 0) break;
                else ++count;
            }
            store[count].push_back(i);
        }

        vector<int> result;
        result.reserve(k);
        int index = 0;
        while (index <= m && k > 0){
            int i = store[index].size(), temp = 0;
            while (temp < i && k > 0){
                result.push_back(store[index][temp]);
                ++temp;
                --k;
            }
            ++index;
        }
        return result;
    }
};