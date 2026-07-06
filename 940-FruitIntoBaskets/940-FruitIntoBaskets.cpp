// Last updated: 06/07/2026, 19:07:16
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        const int n = fruits.size();
        int left = 0, right = 0, result = 0;
        map<int, int> seen;
        while (right < n){
            if (seen.size() == 2){
                if (seen.find(fruits[right]) != seen.end()){
                    seen[fruits[right]] += 1;
                    ++right;
                }
                else {
                    while (seen.size() == 2){
                        seen[fruits[left]] -= 1;
                        if (seen[fruits[left]] == 0) seen.erase(fruits[left]);
                        ++left;
                    }
                    seen[fruits[right]] = 1;
                    ++right;
                }
            }
            else {
                seen[fruits[right]] += 1;
                ++right;
            }
            result = max(result, right - left);
        }
        return result;
    }
};