// Last updated: 06/07/2026, 18:59:19
class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int result = 0;
        for (int i = 0; i < seats.size(); i++) result += abs(seats[i] - students[i]);
        return result;
    }
};