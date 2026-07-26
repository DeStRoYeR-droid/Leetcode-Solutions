// Last updated: 26/07/2026, 13:27:43
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        long long result = 0;    
        int n = nums.size();
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);

        for (const auto& q : swaps){
            adj[q[0]].push_back(q[1]);
            adj[q[1]].push_back(q[0]);
        }

        for (int i = 0; i < n; ++i){
            if (!vis[i]){
                priority_queue<int, vector<int>, greater<int>> h;
                result += dfs(i, adj, 0, h, vis, nums);
            }
        }
        return result;
    }
    long long dfs(int node, vector<vector<int>>& adj, int oddCount, 
            priority_queue<int, vector<int>, greater<int>>& heap, vector<bool>& vis, const vector<int>& nums){
        if (node % 2){
            ++oddCount;
        }
        vis[node] = true;
        long long result = 0;
        
        queue<int> q;
        q.push(node);

        while (!q.empty()){
            int n = q.front(); q.pop();
            vis[n] = true;
            heap.push(nums[n]);
            for (const int& next : adj[n]){
                if (!vis[next]){
                    q.push(next);
                    if (next % 2) ++oddCount;
                    vis[next] = true;
                }
            }
        }

        while (!heap.empty()){
            auto val = heap.top(); heap.pop();
            if (oddCount){
                result -= val;
                --oddCount;
            }
            else result += val;
        }
        cout << endl;

        return result;
    }
};