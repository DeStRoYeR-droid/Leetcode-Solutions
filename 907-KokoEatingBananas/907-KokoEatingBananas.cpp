// Last updated: 06/07/2026, 19:07:31
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *(max_element(piles.begin(), piles.end()));

        while (left < right){
            int mid = left + (right - left) / 2;
            if (canEatInTime(piles, mid, h)) right = mid;
            else left = mid + 1;
        }
        return left;
    }

    bool canEatInTime(const vector<int>& piles, int k, int h){
        long long hours = 0;
        for (int pile : piles) {
            hours += (pile + k - 1) / k;  
        }
        return hours <= h;
    }
};