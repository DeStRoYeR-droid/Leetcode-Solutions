// Last updated: 06/07/2026, 19:02:11
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        const int n = piles.size() / 3;
        int result = 0, index = piles.size() - 2;
        for (int i = 0; i < n; ++i){
            result += piles[index];
            index -= 2;
        }
        return result;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();