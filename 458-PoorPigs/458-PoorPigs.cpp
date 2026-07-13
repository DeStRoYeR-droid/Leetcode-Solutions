// Last updated: 13/07/2026, 22:19:22
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int rounds = minutesToTest / minutesToDie;
        int pigs = 0;
        long long states = 1;

        while (states < buckets){
            states = states * (rounds + 1);
            ++pigs;
        }
        return pigs;
    }
};