// Last updated: 06/07/2026, 18:58:43
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        const int n = fruits.size();
        if (n == 0) return 0;

        vector<int> positions(n);
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i){
            positions[i] = fruits[i][0];
            prefix[i + 1] = prefix[i] + fruits[i][1];
        }

        int maxFruits = 0, left = 0;
        for (int right = 0; right < n; ++right){
            int posL = positions[left];
            int posR = positions[right];

            int cost = (posR - posL) + min(abs(startPos - posL), abs(startPos - posR));

            while (left <= right && cost > k){
                ++left;
                if (left > right) break;
                posL = positions[left];
                cost = (posR - posL) + min(abs(startPos - posL), abs(startPos - posR));
            }

            if (left <= right){
                int cur = prefix[right + 1] - prefix[left];
                maxFruits = max(maxFruits, cur);
            }
        }
        return maxFruits;
    }
};