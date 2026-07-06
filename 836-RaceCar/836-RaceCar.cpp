// Last updated: 06/07/2026, 19:08:06
class Solution {
public:
    int racecar(int target) {
        queue<pair<int, int>> q;
        q.push({0, 1});

        set<pair<int, int>> visited;
        visited.insert({0, 1});

        int result = 0;
        while (!q.empty()){
            int sz = q.size();
            while (sz--){
                auto [pos, speed] = q.front(); q.pop();

                if (pos == target){
                    return result;
                }

                // Moving forward
                int nPos = pos + speed;
                int nSpeed = speed << 1;
                if (abs(nPos) <= 2 * target && visited.find({nPos, nSpeed}) == visited.end()){
                    q.push({nPos, nSpeed});
                    visited.insert({{nPos, nSpeed}});
                }
                
                // Moving backward
                int revSpeed = (speed > 0) ? -1 : 1;
                if (!visited.count({pos, revSpeed})){
                    q.push({pos, revSpeed});
                    visited.insert({pos, revSpeed});
                }
            }
            ++result;
        }
        return result;
    }
};