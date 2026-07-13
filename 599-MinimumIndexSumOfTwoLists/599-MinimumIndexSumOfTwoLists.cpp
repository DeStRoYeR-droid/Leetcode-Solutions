// Last updated: 13/07/2026, 22:17:57
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> result;
        int res_count = INT_MAX;

        unordered_map<string, int> m1;
        for (int i = 0; i < list1.size(); ++i) m1[list1[i]] = i;

        for (int i = 0; i < list2.size(); ++i){
            if (m1.find(list2[i]) != m1.end()){
                int cur = i + m1[list2[i]];
                if (res_count == cur){
                    result.push_back(list2[i]);
                }
                else if (res_count > cur){
                    res_count = cur;
                    result.clear();
                    result.push_back(list2[i]);
                }
            }
        }
        return result;
    }
};