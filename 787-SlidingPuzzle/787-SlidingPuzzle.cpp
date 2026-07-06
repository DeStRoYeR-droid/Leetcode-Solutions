// Last updated: 06/07/2026, 19:08:39
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        static const string resultState = "123450";
        string state = "";

        for (const vector<int>& row: board){
            for (const int& val : row){
                state += to_string(val);
            }
        }

        vector<vector<int>> adj = {
            {1, 3},
            {0, 2, 4},
            {1, 5},
            {0, 4},
            {1, 3, 5},
            {2, 4}
        };

        queue<pair<string, int>> q;
        set<string> visited;

        q.push({state, 0});

        while (!q.empty()){
            auto [state, moves] = q.front(); q.pop();
            if (state == resultState) return moves;
            visited.insert(state);
            int zeroPos = state.find('0');
            for (auto& neigh : adj[zeroPos]){
                string next = state;
                swap(next[zeroPos], next[neigh]);

                if (!visited.count(next)){
                    q.push({next, moves + 1});
                }
            }
        }
        return -1;
    }
};