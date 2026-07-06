// Last updated: 06/07/2026, 19:04:25
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        const int n = candies.size();
        int result = 0;
        vector<bool> haveKeys(n, false), visited(n, false);
        
        deque<int> q(initialBoxes.begin(), initialBoxes.end());

        while (!q.empty()){
            int cur = q.front(); q.pop_front();

            if ((status[cur] || haveKeys[cur]) && !visited[cur]){
                result += candies[cur];
                
                candies[cur] = -1;
            }

            for (const int& key : keys[cur]){
                haveKeys[key] = true;
                if (visited[key] && candies[key] != -1){
                    visited[key] = false;
                    q.push_back(key);
                }
            }
            for (const int& box : containedBoxes[cur]){
                if (!visited[box] && (haveKeys[box] || status[box])) q.push_front(box);
                else q.push_back(box);
            }
            visited[cur] = true;
            
        }
        return result;
    }
};