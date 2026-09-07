// Last updated: 07/09/2026, 22:34:02
class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int maxtime = events[0][1];
        int result = events[0][0];
        for(int i = 1; i < events.size(); i++){
            if(maxtime < events[i][1] - events[i-1][1]){
                maxtime = events[i][1] - events[i-1][1];
                result = events[i][0];
            }
            else if (maxtime == events[i][1] - events[i-1][1]){
                result = min(result, events[i][0]);
            }
        }
        return result;
    }
};