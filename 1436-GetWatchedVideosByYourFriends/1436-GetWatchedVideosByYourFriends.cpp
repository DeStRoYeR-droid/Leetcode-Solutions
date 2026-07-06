// Last updated: 06/07/2026, 19:04:15
class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size();
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(id);
        visited[id] = true;
        int currLevel = 0;

        while (!q.empty() && currLevel < level) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int cur = q.front();
                q.pop();
                for (int neigh : friends[cur]) {
                    if (!visited[neigh]) {
                        visited[neigh] = true;
                        q.push(neigh);
                    }
                }
            }
            currLevel++;
        }

        unordered_map<string, int> freq;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (string &video : watchedVideos[cur]) {
                freq[video]++;
            }
        }

        vector<pair<string, int>> freqVec(freq.begin(), freq.end());
        sort(freqVec.begin(), freqVec.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            if (a.second != b.second) return a.second < b.second;
            return a.first < b.first;
        });

        vector<string> result;
        for (auto &p : freqVec) {
            result.push_back(p.first);
        }
        return result;
    }
};
