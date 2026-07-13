// Last updated: 13/07/2026, 22:16:53
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> res;
        for (const int& asteroid : asteroids){
            if (asteroid > 0) res.push(asteroid);
            while (!res.empty() && 0 < res.top() && res.top() < -asteroid){
                res.pop();
            }

            if (res.empty() || res.top() < 0) res.push(asteroid);
            if (!res.empty() && res.top() == -asteroid) res.pop();
        }

        vector<int> result(res.size());
        int index = res.size() - 1;
        while (index >= 0){
            result[index--] = res.top();
            res.pop();
        }
        return result;
    }
};