// Last updated: 06/07/2026, 19:00:11
class Solution {
public:
    string removeOccurrences(string& s, const string& part) {
        while (s.find(part) != string::npos){
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};