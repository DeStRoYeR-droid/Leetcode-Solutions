// Last updated: 06/07/2026, 19:05:33
class Solution {
public:
    void func(vector<vector<pair<int,int>>>&adjList,int n, vector<int>&ans){
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        pq.push({0,0,-1});

        vector<vector<int>>vis(n,vector<int>(3,0));
        vis[0][0]=true;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int len = top[0];
            int node = top[1];
            int colr  = top[2];

            ans[node]=min(ans[node], len);
            for(auto it:adjList[node]){
                if(!vis[it.first][it.second] && colr != it.second){
                    vis[it.first][it.second]=1;
                    pq.push({len+1,it.first,it.second});
                }
            }
        }
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>>adjList(n);
        for(auto it:redEdges){
            int u=it[0];
            int v=it[1];
            adjList[u].push_back({v,1});
        }

        for(auto it:blueEdges){
            int u=it[0];
            int v=it[1];
            adjList[u].push_back({v,2});
        }

        vector<int>ans(n,INT_MAX);
        func(adjList,n,ans);
        for(int i=0;i<n;i++) if(ans[i]==INT_MAX) ans[i]=-1;

        
        return ans;
    }
};