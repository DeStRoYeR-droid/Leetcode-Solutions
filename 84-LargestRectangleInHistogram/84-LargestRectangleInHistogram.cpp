// Last updated: 13/07/2026, 22:28:00
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        const int n = heights.size();

        vector<int> pse(n, -1), nse(n, n);
        stack<int> st;

        for (int i = 0; i < n; ++i){
            while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if (!st.empty()) pse[i] = st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; --i){
            while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if (!st.empty()) nse[i] = st.top();
            st.push(i);
        }

        int result = 0;
        for (int i = 0; i < n; ++i){
            result = max(result, heights[i] * (nse[i] - pse[i] - 1));
        }

        return result;
    }
};