// Last updated: 06/07/2026, 18:51:01
class Solution {
public:
    int maxDistance(string s, int k) {
        vector<int> dist(4, 0);
        int result = 0;
        for (int i = 0; i < s.size(); ++i){
            char ch = s[i];
            if (ch == 'S') dist[0]++;
            else if (ch == 'W') dist[1]++;
            else if (ch == 'N') dist[2]++;
            else dist[3]++;

            int distance = abs(dist[2] - dist[0]) + abs(dist[1] - dist[3]) + 2 * k;
            result = max(result, min(distance, i + 1));
        }
        return result;
    }
};