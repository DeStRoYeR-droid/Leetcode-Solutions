// Last updated: 06/07/2026, 18:57:58
class Solution {
public:
    int countCollisions(string directions) {
        const int n = directions.size();
        int result = 0;
        int i = n - 1;

        while (i >= 0 && directions[i] == 'R') --i;
        int endIdx = i;

        i = 0;
        while (i < n && directions[i] == 'L') ++i;
        int startIdx = i;

        for (int i = startIdx; i <= endIdx; ++i){
            if (directions[i] != 'S') ++result;
        }
        return result;
    }
};