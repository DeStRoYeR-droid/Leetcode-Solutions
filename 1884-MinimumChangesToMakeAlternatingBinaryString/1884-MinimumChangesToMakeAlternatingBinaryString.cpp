// Last updated: 06/07/2026, 19:01:01
class Solution {
public:
    int minOperations(string s) {
        return min(startsOne(s) , startsZero(s));
    }
    int startsOne(const string& s){
        int result = 0;
        for (int i = 0; i < s.length(); i++){
            if (s[i] == ('0' + (i % 2))) result++;
        }
        return result;
    }
    int startsZero(const string& s){
        int result = 0;
        for (int i = 0; i < s.length(); i++){
            if (s[i] == ('0' + !(i % 2))) result++;
        }
        return result;
    }
};