// Last updated: 13/07/2026, 22:25:10
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        char start = 'A';
        while (columnNumber > 0){
            columnNumber--;
            result = (char)(start + (columnNumber  % 26)) + result; 
            columnNumber /= 26;
        }
        return result;
    }
};