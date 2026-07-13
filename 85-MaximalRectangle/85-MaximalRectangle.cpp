// Last updated: 13/07/2026, 22:27:59
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        const int m = matrix.size(), n = matrix[0].size();

        vector<int> heights(n, 0);
        int result = 0;

        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (matrix[i][j] == '1') heights[j] = heights[j]+ 1;
                else heights[j] = 0;
            }
            result = max(result, largestRectangleArea(heights));
        }

        return result;
    }

    int largestRectangleArea(vector<int>& heights){
        stack<int> st;
        heights.push_back(0);
        int maxArea = 0, n = heights.size();

        for (int i = 0; i < n; ++i){
            while (!st.empty() && heights[i] < heights[st.top()]){
                int height = heights[st.top()]; st.pop();
                int width = (st.empty()) ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        heights.pop_back();

        return maxArea;
    }
};