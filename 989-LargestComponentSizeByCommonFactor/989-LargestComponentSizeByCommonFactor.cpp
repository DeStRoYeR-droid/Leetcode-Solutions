// Last updated: 06/07/2026, 19:06:50
class Solution {
public:
    vector<int>parent,rank;

    int find(int x){
        if(parent[x]!=x)parent[x]=find(parent[x]);
        return parent[x];
    }

    void unite(int a ,int b){
        int pa = find(a) , pb = find(b);
        if(pa==pb) return ;
        if(rank[pa]<rank[pb])swap(pa,pb);
        parent[pb]=pa;
        if(rank[pa]==rank[pb])rank[pa]++;
    }

    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        parent.resize(maxi+1);
        rank.resize(maxi+1,0);
        for(int i =0 ; i<=maxi ; i++)parent[i]=i;
        vector<int>sieve(maxi+1);
        for(int i = 2 ;i<=maxi ; i++){
            if(sieve[i]==0){
                for(int j = i ; j<=maxi ; j+=i){
                    if(sieve[j]==0) sieve[j]=i;
                }
            }
        }
         for(auto num : nums){
            int x = num ;
            while(x>1){
                int p  = sieve[x];
                unite(p,num);
                while(x%p==0)x/=p;
            }
         }
         unordered_map<int,int>mpp;
         int ans = 0;
         for(auto num : nums){
            int par = find(num);
            mpp[par]++;
            ans=max(ans,mpp[par]);
         }
         return ans;
    }
};