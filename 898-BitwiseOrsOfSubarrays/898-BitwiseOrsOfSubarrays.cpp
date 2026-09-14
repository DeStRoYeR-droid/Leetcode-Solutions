// Last updated: 14/09/2026, 09:32:35
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