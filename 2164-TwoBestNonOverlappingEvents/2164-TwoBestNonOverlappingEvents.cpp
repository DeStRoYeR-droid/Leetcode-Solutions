// Last updated: 06/07/2026, 18:59:13
class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b){
        if(a[0]==b[0]) return a[1]<b[1];
        return a[0]<b[0];
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end(),compare);
        priority_queue<pair<int,int>,vector<pair<int,int>>, 
            greater<pair<int,int>>> q;
        int val=0;
        int result=0;
        for(auto &e:events){
            while(!q.empty() && q.top().first<e[0]){
                val=max(val,q.top().second);
                q.pop();
            }
            result=max(result,val+e[2]);
            q.push({e[1],e[2]});
        }
        return result;
    }
};