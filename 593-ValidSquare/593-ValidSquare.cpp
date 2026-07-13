// Last updated: 13/07/2026, 22:18:05
class Solution {
public:
    bool validSquare(const vector<int>& p1, const vector<int>& p2, const vector<int>& p3, const vector<int>& p4) {
        vector<int> distances = {
            dist(p1, p2), dist(p1, p3), dist(p1, p4),
            dist(p2, p3), dist(p2, p4),
            dist(p3, p4)
        };
        sort(distances.begin(), distances.end());

        bool sidesEqual = true;
        for (int i = 1; i < 4; ++i){
            if (distances[i] != distances[0]){
                sidesEqual = false;
                break;
            }
        }

        if (sidesEqual && distances[4] == distances[5] && distances[5] > distances[0]) return true;
        return false;
    }
    int dist(const vector<int>& p1, const vector<int>& p2){
        return pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2);
    }
};