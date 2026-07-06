// Last updated: 06/07/2026, 18:55:47
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        const long long carCount = (long long) cars;
        long long left = 1;
        long long right = *max_element(ranks.begin(), ranks.end()) * carCount * carCount;


        while (left <= right){
            long long mid = left + (right - left) / 2;
            if (canFix(ranks, carCount, mid)){
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return left;
    }

    bool canFix(const vector<int>& ranks, const long long cars, long long time){
        long long count = 0;
        for (int i = 0; i < ranks.size(); ++i){
            count += sqrt((time * 1.0) / ranks[i]);
        }
        return count >= cars;
    }
};