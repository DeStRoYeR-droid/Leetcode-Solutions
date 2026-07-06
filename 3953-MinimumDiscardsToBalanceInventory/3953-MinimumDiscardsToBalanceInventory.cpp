// Last updated: 06/07/2026, 18:49:41
class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        const int n = arrivals.size();
        vector<bool> kept(n, false);
        unordered_map<int, int> having;

        int result = 0;
        int left = 0;
        for (int right = 0; right < arrivals.size(); ++right){
            having[arrivals[right]]++;
            kept[right] = true;
            
            if (having[arrivals[right]] > m){
                result++;
                having[arrivals[right]]--;
                kept[right] = false;
            }
            
            if ((right - left + 1) >= w){
                if (kept[left]){
                    having[arrivals[left]]--;
                }
                ++left;
            }
        }
        return result;
    }
};