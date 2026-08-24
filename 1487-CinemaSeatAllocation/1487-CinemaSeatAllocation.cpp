// Last updated: 24/08/2026, 22:44:40
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;
        for (const auto& v: reservedSeats){
            int r = v[0], c = v[1];
            if (c >= 2 && c <= 9){
                int m = mp[r];
                m |= (1 << (c - 2));
                mp[r] = m;
            }
        }

        int result = 2 * n;
        for (const auto [r, m]: mp){
            bool left = (m & 15) == 0,
                 right = (m & 240) == 0,
                 mid = (m & 60) == 0;
            result -= 2;
            if (left && right){
                result += 2;
            }
            else if (left || right || mid){
                result += 1;
            }
        }
        return result;
    }
};