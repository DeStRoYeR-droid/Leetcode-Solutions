// Last updated: 30/09/2026, 18:15:49
class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < (int)nums.size(); ++i){
            int sum = 0, n = nums[i];
            while(n){
                sum += n%10;
                n /= 10;
            }
            if(sum==i) return i;
        }
        return -1;
    }
    int sumDigits(int n){
        int result = 0;
        while (n){
            result += n % 10;
            n /= 10;
        }
        return result;
    }
};