// Last updated: 06/07/2026, 18:47:44
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long result = 1e15;

        if (costBoth > cost1 + cost2){
            return (long long)need1 * cost1 + (long long)need2 * cost2;
        }

        int t3Need = min(need1, need2);
        long long minC = (long long)t3Need * costBoth;
        need1 = max(0, need1 - t3Need);
        need2 = max(0, need2 - t3Need);

        result = minC;
        if (need1 > 0) result += (min((long long)need1 * cost1, (long long)need1 * costBoth));
        if (need2 > 0) result += (min((long long)need2 * cost2, (long long)need2 * costBoth));
        
        return result;
    }
};