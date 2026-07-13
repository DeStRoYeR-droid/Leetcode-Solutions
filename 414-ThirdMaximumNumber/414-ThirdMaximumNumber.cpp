// Last updated: 13/07/2026, 22:19:57
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long m1 = LLONG_MIN, m2 = LLONG_MIN, m3 = LLONG_MIN;
        for (const int& val : nums){
            if (val > m1){
                m3 = m2;
                m2 = m1;
                m1 = val;
            }
            else if (val > m2 && val != m1 && val < m1){
                m3 = m2;
                m2 = val;
            }
            else if (val > m3 && val != m2 && val < m2){
                m3 = val;
            }
        }
        if (m3 != LLONG_MIN) return m3;
        else return m1;
    }
};