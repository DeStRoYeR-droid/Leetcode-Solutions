// Last updated: 06/07/2026, 18:47:08
class DSU {
public:
    vector<int> parent;
    vector<int> size;

    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            if (size[root_i] < size[root_j])
                swap(root_i, root_j);
            parent[root_j] = root_i;
            size[root_i] += size[root_j];
        }
    }
};

class Solution {
public:
    int maxActivated(vector<vector<int>>& points) {
        const int n = points.size();
        if (n <= 2) return n + 1;

        DSU dsu(n);
        unordered_map<int, int> x_map, y_map;

        for (int i = 0; i < n; ++i){
            int x = points[i][0];
            int y = points[i][1];

            if (x_map.count(x)){
                dsu.unite(i, x_map[x]);
            }
            else x_map[x] = i;

            if (y_map.count(y)){
                dsu.unite(i, y_map[y]);
            }
            else y_map[y] = i;
        }

        vector<int> components;
        for (int i = 0; i < n; ++i){
            if (dsu.parent[i] == i){
                components.push_back(dsu.size[i]);
            }
        }

        sort(components.rbegin(), components.rend());

        if (components.size() == 1) return components[0] + 1;
        else return components[0] + components[1] + 1;
    }
};