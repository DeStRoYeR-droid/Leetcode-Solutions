// Last updated: 06/07/2026, 19:08:21
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;

        const int n = s.size();

        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                if (s[i] == goal[j]){
                    int count = 0, i1 = i, j1 = j;
                    while (count < n){
                        if (s[i1] == goal[j1]) ++count;
                        else break;
                        i1 = (i1 + 1) % n;
                        j1 = (j1 + 1) % n;
                    }

                    if (count == n) return true;
                }
            }
        }
        return false;
    }
};