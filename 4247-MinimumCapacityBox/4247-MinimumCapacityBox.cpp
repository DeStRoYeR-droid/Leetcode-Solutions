// Last updated: 06/07/2026, 18:47:11
typedef pair<int, int> pii;
class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        vector<pii> v;
        for (int i = 0; i < capacity.size(); ++i){
            v.push_back({capacity[i], i});
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < capacity.size(); ++i){
            if (itemSize <= v[i].first){
                return v[i].second;
            }
        }
        return -1;
    }
};