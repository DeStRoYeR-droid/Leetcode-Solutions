// Last updated: 13/07/2026, 22:23:34
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);
        vector<int> result;

        for (const auto& edge : prerequisites){
            adj[edge[1]].push_back(edge[0]);
            inDegree[edge[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i){
            if (inDegree[i] == 0) q.push(i);
        }

        int count = 0;
        while (!q.empty()){
            int node = q.front(); q.pop();
            result.push_back(node);
            ++count;

            for (int num : adj[node]){
                inDegree[num]--;
                if (inDegree[num] == 0) q.push(num);
            }
        }
        if (count == numCourses) return result;
        return {};
    }
};