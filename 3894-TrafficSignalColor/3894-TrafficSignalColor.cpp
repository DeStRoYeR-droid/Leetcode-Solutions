// Last updated: 07/09/2026, 22:22:05
class Solution {
public:
    string trafficSignal(int timer) {
        if (timer == 0) return "Green";
        if (timer == 30) return "Orange";
        if (30 < timer && timer <= 90) return "Red";
        return "Invalid";
    }
};