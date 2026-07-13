// Last updated: 13/07/2026, 22:16:51
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        const int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> st;
        for (int i = 0; i < temperatures.size(); ++i){
            while (!st.empty() && temperatures[i] > temperatures[st.top()]){
                int idx = st.top(); st.pop();
                result[idx] = i - idx;
            }
            st.push(i);
        }
        return result;
    }
};