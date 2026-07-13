// Last updated: 13/07/2026, 22:30:33
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int dist = height.size() - 1;
        int result = 0;
        while (left < right){
            result = max(result, min(height[left], height[right]) * dist);
            (height[left] < height[right]) ? left++ : right--;
            dist--;
        }
        return result;
    }
};