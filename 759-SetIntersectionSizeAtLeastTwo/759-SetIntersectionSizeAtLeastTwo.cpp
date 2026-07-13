// Last updated: 13/07/2026, 22:16:37
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), 
            [](const vector<int>& a, const vector<int>& b){
            if (a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });

        vector<int> result;
        for (const auto& interval : intervals) {
            int start = interval[0], end = interval[1], count = 0;
            for (int num : result) {
                if (num >= start && num <= end) {
                    count++;
                }
            }
            if (count < 2) {
                int required = 2 - count;
                int lastAdded = end + 1;

                while (required > 0) {
                    --lastAdded;
                    if (find(result.begin(), result.end(), lastAdded) 
                        == result.end()) {
                        result.push_back(lastAdded);
                        required--;
                    }
                }
            }
        }
        return result.size();
    }
};