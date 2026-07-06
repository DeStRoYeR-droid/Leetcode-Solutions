// Last updated: 06/07/2026, 18:57:55
class Solution {
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int,int>>>adj(n);
        vector<vector<pair<int,int>>>radj(n);
        for(auto&it:edges){
            int u=it[0];
            int v=it[1];
            int cost=it[2];
            adj[u].push_back({cost,v});
            radj[v].push_back({cost,u});
        }
        vector<long long>dist1(n,1e17);
        vector<long long>dist2(n,1e17);
        vector<long long>dist3(n,1e17);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        dist1[src1]=0;
        pq.push({0,src1});
        dist2[src2]=0;
        dist3[dest]=0;
        while(!pq.empty()){
            auto [a,b]=pq.top();
            pq.pop();
            if(dist1[b]<a)continue;
            for(auto &it:adj[b]){
                long long newdist=it.first+a;
                if(newdist<dist1[it.second]){
                    dist1[it.second]=newdist;
                    pq.push({newdist,it.second});
                }
            }
        }
        pq.push({0,src2});
        while(!pq.empty()){
            auto [a,b]=pq.top();
            pq.pop();
            if(dist2[b]<a)continue;
            for(auto &it:adj[b]){
                long long newdist=it.first+a;
                if(newdist<dist2[it.second]){
                    dist2[it.second]=newdist;
                    pq.push({newdist,it.second});
                }
            }
        }
        pq.push({0,dest});
        while(!pq.empty()){
            auto [a,b]=pq.top();
            pq.pop();
            if(dist3[b]<a)continue;
            for(auto &it:radj[b]){
                long long newdist=it.first+a;
                if(newdist<dist3[it.second]){
                    dist3[it.second]=newdist;
                    pq.push({newdist,it.second});
                }
            }
        }
        long long mini= LLONG_MAX;
        for(int i=0;i<n;i++){
            mini=min(mini,dist1[i]+dist2[i]+dist3[i]);
        }
        return (mini>=1e17)?-1:mini;
    }
};