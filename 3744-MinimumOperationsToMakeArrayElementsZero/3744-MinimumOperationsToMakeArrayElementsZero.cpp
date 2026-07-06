// Last updated: 06/07/2026, 18:51:09
class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long result = 0;
        for (const auto& query : queries){
            int l = query[0], r = query[1];
            long long steps = 0;

            long long base = 1, step = 1;
            while (base <= r){
                long long left = max((long long)l, base);
                long long right = min((long long)r, base * 4 - 1);

                if (left <= right){
                    long long count = right - left + 1;
                    steps += count * step;
                }

                base *= 4;
                ++step;
            }
            result += (steps + 1) / 2;
        }
        return result;
    }
};