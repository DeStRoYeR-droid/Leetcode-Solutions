// Last updated: 13/07/2026, 22:20:47
class SummaryRanges {
    map<int,int> intervals;
public:
    SummaryRanges() {}
    
    void addNum(int value) {
        if (intervals.empty()) {
            intervals[value] = value;
            return;
        }

        auto it = intervals.upper_bound(value);
        int start = value, end = value;

        if (it != intervals.begin()) {
            auto prev = std::prev(it);
            if (prev->second >= value) return; 
            if (prev->second + 1 == value) {
                start = prev->first;
                end = value;
                intervals.erase(prev);
            }
        }

        if (it != intervals.end() && it->first == value + 1) {
            end = it->second;
            intervals.erase(it);
        }

        intervals[start] = end;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        res.reserve(intervals.size());
        for (auto &p : intervals)
            res.push_back({p.first, p.second});
        return res;
    }
};