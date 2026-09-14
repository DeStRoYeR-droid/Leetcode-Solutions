// Last updated: 14/09/2026, 09:20:02
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