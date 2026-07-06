// Last updated: 06/07/2026, 19:03:13
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> visited;

        for (auto& path: paths) visited.insert(path[0]);

        for (auto& path: paths){
            string cur_dest = path[1];
            if (visited.find(cur_dest) == visited.end()) return cur_dest;
        }

        return "";
    }
};