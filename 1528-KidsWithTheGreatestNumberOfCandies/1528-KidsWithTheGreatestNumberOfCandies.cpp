// Last updated: 06/07/2026, 19:03:19
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result (candies.size());
        int max_candy = *max_element(candies.begin(), candies.end());
        for (int i = 0; i < candies.size(); i++)
            result[i] = (candies[i] + extraCandies) >= max_candy;
        return result;
    }
};