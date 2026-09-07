// Last updated: 07/09/2026, 22:28:31
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