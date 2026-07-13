// Last updated: 13/07/2026, 22:26:11
class Solution {
public:
    int candy(vector<int>& ratings) {
        const int n = ratings.size();
        int candy = n, i = 1;

        while (i < n){
            if (ratings[i] == ratings[i-1]){
                i++;
                continue;
            }

            // Increasing
            int peak = 0;
            while (i < n && ratings[i] > ratings[i - 1]){
                ++peak;
                candy += peak;
                ++i;
            }

            // Decreasing
            int valley = 0;
            while (i < n && ratings[i] < ratings[i-1]){
                ++valley;
                candy += valley;
                ++i;
            }

            candy -= min(peak, valley);
        }

        return candy;
    }
};