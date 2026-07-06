// Last updated: 06/07/2026, 19:01:30
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int c0 = 0, c1 = 0, i = 0, n = sandwiches.size();
        for (const int& val : students){
            if (val == 0) c0++;
            else c1++;
        }
        while (i < n){
            if (sandwiches[i] == 0){
                if (c0) --c0;
                else break;
            }
            else{
                if (c1) --c1;
                else break;
            }

            ++i;
        }
        return c0 + c1;
    }
};