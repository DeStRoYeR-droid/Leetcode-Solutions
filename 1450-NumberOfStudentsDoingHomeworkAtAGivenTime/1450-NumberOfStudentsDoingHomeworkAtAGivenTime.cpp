// Last updated: 14/09/2026, 09:22:04
class Solution {
public:
    int busyStudent(const vector<int>& startTime, const vector<int>& endTime, const int queryTime) {
        int result = 0;
        for (int i = 0; i < startTime.size(); ++i){
            if (startTime[i] <= queryTime && queryTime <= endTime[i]) ++result;
        }
        return result;
    }
};