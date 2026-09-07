// Last updated: 07/09/2026, 22:30:34
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