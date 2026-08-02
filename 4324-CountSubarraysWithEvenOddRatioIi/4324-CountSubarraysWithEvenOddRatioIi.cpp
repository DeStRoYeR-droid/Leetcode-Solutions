// Last updated: 02/08/2026, 14:01:47
class Solution {
public:
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        vector<long long> v(n + 1, 0);

        long long e = 0, o = 0;
        for (int i = 0; i < n; ++i){
            if (nums[i] % 2 == 0) ++e;
            else ++o;
            v[i + 1] = e * b - o * a;
        }

        vector<long long> sorted_v = v;
        sort(sorted_v.begin(), sorted_v.end());
        sorted_v.erase(unique(sorted_v.begin(), sorted_v.end()), sorted_v.end());

        int m = sorted_v.size();
        vector<int> bit(m + 1, 0);

        long long result = 0;
        for (int i = 0; i <= n; ++i){
            int rank = lower_bound(sorted_v.begin(), sorted_v.end(), v[i]) - sorted_v.begin() + 1;
            result += i - query(rank - 1, bit);
            update(rank, 1, bit);
        }
        return result;
    }

    long long query(int i, vector<int>& bit){
        long long total = 0;
        for (; i > 0; i -= i & -i) total += bit[i];
        return total;
    }

    void update(int i, int d, vector<int>& bit){
        for (; i < bit.size(); i += i & -i){
            bit[i] += d;
        }
    }
};