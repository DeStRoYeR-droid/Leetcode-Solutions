// Last updated: 13/07/2026, 22:19:10
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<32;i++){
            int zeroes=0,ones=0;
            for(int j=0;j<nums.size();j++){
                ones+=(nums[j]>>(31-i)&1);
                zeroes=nums.size()-ones;
            }
            sum+=ones*zeroes;
        }
        return sum;
    }
};