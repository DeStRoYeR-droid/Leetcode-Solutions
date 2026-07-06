// Last updated: 06/07/2026, 18:59:35
class Solution {
public:
    int findGCD(vector<int>& nums) {
        return gcd(*min_element(nums.begin(), nums.end()),
                   *max_element(nums.begin(), nums.end()));
    }

    int gcd(int a, int b){
        if (a % b == 0) return b;
        else return gcd(b, a % b);
    }
};