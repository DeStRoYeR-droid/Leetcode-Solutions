// Last updated: 13/07/2026, 22:30:52
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> hashmap;
        vector<int> solution;

        for (int i = 0; i < nums.size(); i++){
            int search = target - nums[i];
            if (hashmap.find(search) != hashmap.end()){
                solution.insert(solution.begin() , hashmap[search]);
                solution.insert(solution.begin() + 1 , i);
                break;
            }
            hashmap.insert({nums[i], i});
        }

        return solution;
    }
};