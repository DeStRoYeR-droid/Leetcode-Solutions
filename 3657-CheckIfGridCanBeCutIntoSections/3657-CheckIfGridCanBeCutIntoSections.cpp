// Last updated: 06/07/2026, 18:51:34
class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        return (numberValidCuts(rectangles, 0, 0, 2) > 2 || numberValidCuts(rectangles, 1, 1, 3) > 2);
    }

    int numberValidCuts(vector<vector<int>>& rectangles, int sortIndex, int startIndex, int endIndex){
        sort(rectangles.begin(), rectangles.end(), [&](const vector<int>& a, const vector<int>& b){
            return a[sortIndex] < b[sortIndex];
        });

        int curStart = rectangles[0][startIndex];
        int curEnd = rectangles[0][endIndex];
        int intervals = 1;

        for (const auto& rect : rectangles){
            if (rect[startIndex] < curEnd){
                curEnd = max(rect[endIndex], curEnd);
            }
            else{
                intervals++;
                curStart = rect[startIndex];
                curEnd = rect[endIndex];
            }
        }

        return intervals;
    }
};