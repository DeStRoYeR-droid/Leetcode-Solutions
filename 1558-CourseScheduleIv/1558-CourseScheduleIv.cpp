// Last updated: 06/07/2026, 19:03:05
static auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, unordered_set<int>> requisite;
        for (auto& prereq : prerequisites) 
            requisite[prereq[1]].insert(prereq[0]);

        for (int i = 0; i < numCourses; ++i){
            for (int j = 0; j < numCourses; ++j){
                if (requisite[j].count(i)) 
                    requisite[j].insert(requisite[i].begin(), requisite[i].end());
            }
        }

        vector<bool> result(queries.size());
        for (int i = 0; i < queries.size(); ++i){
            result[i] = requisite[queries[i][1]].count(queries[i][0]) > 0;
        }
        return result;
    }
};