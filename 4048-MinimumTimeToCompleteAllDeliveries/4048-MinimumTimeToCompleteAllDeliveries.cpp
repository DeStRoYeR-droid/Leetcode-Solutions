// Last updated: 06/07/2026, 18:48:45
class Solution {
public:
    long long minimumTime(vector<int>& d, vector<int>& r) {
        auto canDeliver = [&](long long T) -> bool {
            long long blockedHours = T / lcm(r[0], r[1]);
            long long effectiveHours = T - blockedHours;
            
            long long delivery1 = T - T / r[0];
            long long delivery2 = T - T / r[1];

            if (delivery1 < d[0] || delivery2 < d[1]) return false;
            if (d[0] + d[1] > effectiveHours) return false;
            return true;
        };


        long long left = d[0] + d[1], right = 1e18, result = right;

        while (left <= right){
            long long mid = left + (right - left) / 2;
            if (canDeliver(mid)){
                result = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return result;
    }
};