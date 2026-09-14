// Last updated: 14/09/2026, 09:15:30
class Solution {
public:
    string removeOccurrences(string& s, const string& part) {
        while (s.find(part) != string::npos){
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};