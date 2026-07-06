// Last updated: 06/07/2026, 18:55:44
class Graph {
    vector<vector<pair<int, int>>> adj;
    int n;
public:
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        this->adj = vector<vector<pair<int, int>>>(n);
        for (const auto& e : edges){
            adj[e[0]].push_back({e[2], e[1]});
        }
    }
    
    void addEdge(vector<int> e) {
        adj[e[0]].push_back({e[2], e[1]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,
            greater<pair<int,int>>>pq;

        pq.push({0, node1});

        vector<bool> visited(n, false);

        while (!pq.empty()){
            auto [dist, node] = pq.top(); pq.pop();
            if (node == node2) return dist;
            
            visited[node] = true;

            for (const auto& [d, next] : adj[node]){
                if (visited[next]) continue;
                else pq.push({dist + d, next});
            }

        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */