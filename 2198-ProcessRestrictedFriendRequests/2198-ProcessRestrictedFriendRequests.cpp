// Last updated: 06/07/2026, 18:58:57
class Solution {
public:
    vector<int>par,rank;
    int find(int a){
        if(par[a]==a) return par[a];
        else return par[a] = find(par[a]);
    }
    void unioon(int a,int b){
        int x = find(a);
        int y = find(b);
        if(rank[x]>rank[y]){
            rank[x]++;
            par[y] = x;
        }
        else{
            rank[y]++;
            par[x] = y;
        }
    }
    vector<bool> friendRequests(int n, vector<vector<int>>& res, vector<vector<int>>& req) {
        vector<bool>ans;
        par.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            par[i] = i;
        }
        for(int i=0;i<req.size();i++){
            int x = req[i][0];
            int y = req[i][1];
            vector<int>tpar = par;
            vector<int>trank = rank;
            unioon(x,y);
            bool flag = false;
            for(int j=0;j<res.size();j++){
                int a = res[j][0];
                int b = res[j][1];
                a = find(a);
                b = find(b);
                if(a==b){
                    flag = true;
                    break;
                }
            }
            if(flag==true){
                par = tpar;
                rank = trank;
                ans.push_back(false);
            }
            else ans.push_back(true);
        }
        return ans;
    }
};