// Last updated: 06/07/2026, 19:01:45
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int count = 0;
        string temp = word;
        while (sequence.find(temp) != string::npos){
            count++;
            temp += word;
        }
        return count;
    }
};