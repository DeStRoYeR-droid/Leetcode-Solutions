// Last updated: 13/07/2026, 22:22:23
#include <algorithm>

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> slidingWindow;
        int index = 0;


        for (int i = 0; i < nums.size(); i++){
            if (!slidingWindow.empty() && slidingWindow.front() == (i - k)) 
                slidingWindow.pop_front();

            while (!slidingWindow.empty() && nums[slidingWindow.back()] < nums[i]) 
                slidingWindow.pop_back();
            
            slidingWindow.push_back(i);
            if (i >= (k - 1))
                result.push_back(nums[slidingWindow.front()]);
        }
        return result;
    }
};