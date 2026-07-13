// Last updated: 13/07/2026, 22:25:12
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while ((numbers[left] + numbers[right]) != target){
            if ((numbers[left] + numbers[right]) > target) right--;
            else ++left;
        }
        return {left + 1, right + 1};
    }
};