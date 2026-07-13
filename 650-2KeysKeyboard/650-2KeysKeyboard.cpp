// Last updated: 13/07/2026, 22:17:33
class Solution {
public:
    int minSteps(int n) {
        if (n == 1) return 0;
        return 1 + findMinSteps(1, 1, n);
    }

    inline int findMinSteps(int curLen, int clipLen, const int& totalLen){
        if (curLen == totalLen) return 0;
        if (curLen > totalLen) return INT_MAX / 2;

        int copyPaste = 2 + findMinSteps(curLen * 2, curLen, totalLen);
        int pasteIt = 1 + findMinSteps(curLen + clipLen, clipLen, totalLen);

        return min(copyPaste, pasteIt);
    }
};