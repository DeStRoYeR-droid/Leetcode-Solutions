// Last updated: 06/07/2026, 19:07:19
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> values, currentOrs;

        for (int x : arr){
            unordered_set<int> nextOrs;
            nextOrs.insert(x);

            for (int y : currentOrs) nextOrs.insert(x | y);
            values.insert(nextOrs.begin(), nextOrs.end());
            currentOrs = nextOrs;
        }

        return values.size();
    }
};