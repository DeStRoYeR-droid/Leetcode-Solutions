// Last updated: 06/07/2026, 18:58:33
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        int i = 0;
        sort(asteroids.begin(), asteroids.end());
        long long m = mass;
        while (i < n){
            if (m < asteroids[i]) break;
            m += asteroids[i];
            ++i;
        }
        return i == n;
    }
};