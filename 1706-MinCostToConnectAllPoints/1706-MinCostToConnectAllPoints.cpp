// Last updated: 06/07/2026, 19:02:03
class UnionFind {
private:
    vector<int> parent, rank;
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx != ry) {
            if (rank[rx] < rank[ry]) swap(rx, ry);
            parent[ry] = rx;
            if (rank[rx] == rank[ry]) rank[rx]++;
        }
    }
public:
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    bool connected(int x, int y) { return find(x) == find(y); }
    void merge(int x, int y) { unite(x, y); }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 1) return 0;
        
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                pq.push({dist, i, j});
            }
        }
        
        UnionFind uf(n);
        int cost = 0, edges_used = 0;
        while (!pq.empty() && edges_used < n - 1) {
            auto [dist, u, v] = pq.top(); pq.pop();
            if (!uf.connected(u, v)) {
                uf.merge(u, v);
                cost += dist;
                edges_used++;
            }
        }
        return cost;
    }
};
