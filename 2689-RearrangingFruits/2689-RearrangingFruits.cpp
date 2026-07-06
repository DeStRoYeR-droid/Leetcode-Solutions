// Last updated: 06/07/2026, 18:55:40
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> totalCounts;

        for (int fruit : basket1) totalCounts[fruit]++;   
        for (int fruit : basket2) totalCounts[fruit]++;   

        long long val = LLONG_MAX;
        for (auto const& [fruit, count] : totalCounts){
            if (count % 2) return -1;
            val = min(val, (long long) fruit);
        }

        vector<long long> swappingFruit;
        map<int, int> count1;

        for (int fruit : basket1) count1[fruit]++;

        for (auto const& [fruit, totalCount] : totalCounts){
            int diff = count1[fruit] - totalCount / 2;
            for (int i = 0; i < abs(diff); ++i) swappingFruit.push_back(fruit);
        }

        sort(swappingFruit.begin(), swappingFruit.end());
        long long total = 0;
        int swaps = swappingFruit.size() / 2;
        for (int i = 0; i < swaps; ++i) total += min(swappingFruit[i], 2 * val);
        return total;
    }
};