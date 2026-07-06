// Last updated: 06/07/2026, 18:56:50
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<long long> busy(n, 0);
        vector<int> count(n, 0);

        for (auto& meeting : meetings){
            int start = meeting[0], end = meeting[1];
            long long earliest = LLONG_MAX;
            int room = - 1;
            bool assigned = false;
            
            for (int i = 0; i < n; ++i){
                if (busy[i] < earliest){
                    earliest = busy[i];
                    room = i;
                }
                if (busy[i] <= start){
                    busy[i] = end;
                    count[i]++;
                    assigned = true;
                    break;
                }
            }

            if (!assigned){
                busy[room] += (end - start);
                count[room]++;
            }
        }

        int result = 0, maxCount = 0;
        for (int i = 0; i < n; ++i){
            if (count[i] > maxCount){
                maxCount = count[i];
                result = i;
            }
        }   
        return result;
    }
};