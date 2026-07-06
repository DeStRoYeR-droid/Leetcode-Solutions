// Last updated: 06/07/2026, 18:48:58
class Solution {
public:
    int distinctPoints(string s, int k) {
        const int n = s.size();
        vector<int> xCoor(n + 1, 0), yCoor(n + 1, 0);
        for (int i = 0; i < n; ++i){
            xCoor[i + 1] = xCoor[i];
            yCoor[i + 1] = yCoor[i];
            char ch = s[i];
            if (ch == 'R') xCoor[i + 1]++;
            else if (ch == 'L') xCoor[i + 1]--;
            else if (ch == 'U') yCoor[i + 1]++;
            else yCoor[i + 1]--;
        }

        int finalX = xCoor[n], finalY = yCoor[n];
        set<pair<int, int>> seen;

        for (int i = 0; i + k <= n; ++i){
            int Nx = finalX - (xCoor[i + k] - xCoor[i]);
            int Ny = finalY - (yCoor[i + k] - yCoor[i]);

            seen.emplace(Nx, Ny);
        }
        
        return seen.size();
    }
};