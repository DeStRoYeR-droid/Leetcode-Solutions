// Last updated: 06/07/2026, 18:53:30
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total = accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.begin(), capacity.end(), greater<int>());
        int r = 0, curr = 0;
        while (curr < total){
            curr += capacity[r];
            ++r;
        }
        return r;
    }
};