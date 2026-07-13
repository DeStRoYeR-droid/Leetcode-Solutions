// Last updated: 13/07/2026, 22:29:30
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int water = 0;
        for(int i=0; i<height.size(); ++i){
            while(!s.empty() && height[i]>height[s.top()]){
                int mid = s.top();
                s.pop();
                if(s.empty()) break;
                int left = s.top();
                int h = min(height[left],height[i]) - height[mid];
                int w = i - left - 1;
                water += h*w;
            }
            s.push(i);
        }
        return water;
    }
};