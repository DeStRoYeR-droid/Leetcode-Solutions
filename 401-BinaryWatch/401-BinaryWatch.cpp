// Last updated: 13/07/2026, 22:20:12
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> times;
        for (int h = 0; h < 12; ++h){
            for (int m = 0; m < 60; ++m){
                int hOnes = __builtin_popcount(h);
                int mOnes = __builtin_popcount(m);

                if (hOnes + mOnes == turnedOn){
                    times.push_back(
                        to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m)
                    );
                }
            }
        }
        return times;
    }
};