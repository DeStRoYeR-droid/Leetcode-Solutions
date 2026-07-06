// Last updated: 06/07/2026, 18:57:16
class Solution {
public:
    bool canChange(string start, string target) {
        int i = 0;
        int j = 0;
        const int n = start.length();
        while (i < n && j < n){
            char a = start[i], b = target[j];
            if (a == '_' && b == '_'){
                i++;
                j++;
            }
            else if (a == '_') i++;
            else if (b == '_') j++;

            else if ((a == b) && (a == 'L' && i >= j || a == 'R' && i <= j)){
                    i++;
                    j++;
            }
            else return false;
        }

        while (i < n && start[i] == '_') i++;
        if (i != n) return false;
       
        while (j < n && target[j] == '_') j++;
        return j == n;
    }
};