// Last updated: 13/07/2026, 22:17:13
class UnionFind{
    vector<int> root, rank;
    public:
        UnionFind(int n) : root(n), rank(n){
            rank.assign(n, 1);
            iota(root.begin(), root.end(), 0);
        }
        int Find(int x){
            if (x == root[x]) return x;
            else return root[x] = Find(root[x]);
        }

        bool Union(int x, int y){
            int rX = Find(x), rY = Find(y);
            if (rX == rY) return false;
            if (rank[rX] > rank[rY]) swap(rX, rY);
            root[rX] = rY;
            if (root[rX] == rank[rY]) rank[rY]++;
            return 1;
        }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        const int n = edges.size();
        UnionFind G(n+1);
        for (const auto& e : edges)
            if (!G.Union(e[0], e[1])) return e;
        return {};
    }
};