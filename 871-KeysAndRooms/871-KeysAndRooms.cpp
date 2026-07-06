// Last updated: 06/07/2026, 19:07:50
class Solution {
public:
    void dfs(int roomno, vector<vector<int>>& rooms, vector<bool>& visited){
        if (visited[roomno]) return;
        visited[roomno] = true;
        for (auto& key : rooms[roomno]){
            dfs(key, rooms, visited);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        const int n = rooms.size();
        vector<bool> visited(n, 0);
        dfs(0, rooms, visited);
        for (int i = 0; i < n; ++i){
            if (!visited[i]) return false;
        }
        return true;
    }
};