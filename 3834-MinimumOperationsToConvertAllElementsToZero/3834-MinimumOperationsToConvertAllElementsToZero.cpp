// Last updated: 06/07/2026, 18:50:26
class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;
        int result = 0;
        for (auto& val : nums){
            while (!st.empty() && st.top() > val) st.pop();
            if (val == 0) continue;
            if (st.empty() || st.top() < val){
                ++result;
                st.push(val);
            }
        }
        return result;
    }
};