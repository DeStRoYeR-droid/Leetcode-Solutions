// Last updated: 06/07/2026, 19:01:41
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {

        int oddSum = 0, evenSum = 0;
        vector<int> odd , even;
        int n = nums.size();

        for(int i = 1;i<n;i++){
            if(i%2 == 0){
                evenSum+=nums[i];
                even.push_back(nums[i]);
            }else{
                oddSum+=nums[i];
                odd.push_back(nums[i]);
            }
        }
        int ans = 0;
        if(oddSum == evenSum)ans++;

        int idx1 = 0 , idx2 = 0;
        bool isOdd = true;
        int deleted = nums[0];
        while(idx1<odd.size() || idx2<even.size()){
            if(isOdd && idx1<odd.size()){
                oddSum -= odd[idx1];
                oddSum += deleted;
                deleted = odd[idx1];
                odd[idx1++] = deleted;
            }else if(idx2<even.size()){
                evenSum -= even[idx2];
                evenSum += deleted;
                deleted = even[idx2];
                even[idx2++] = deleted;
            }else
                break;

            if(oddSum == evenSum){
                ans++;
            }
            isOdd = !isOdd;
        }

        return ans;
    }
};