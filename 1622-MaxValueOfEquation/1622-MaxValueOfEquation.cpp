// Last updated: 06/07/2026, 19:02:38
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<int> dq;
        int ans =INT_MIN;
        for(int i=0;i<points.size();i++){
            while(!dq.empty() && points[i][0]-points[dq.front()][0]>k )dq.pop_front();

            if(!dq.empty()){
                ans = max(ans,points[i][0] + points[i][1] + points[dq.front()][1]- points[dq.front()][0]);
            }
            while(!dq.empty() && points[i][1] - points[i][0]>=points[dq.back()][1]-points[dq.back()][0]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return ans ;
    }
};