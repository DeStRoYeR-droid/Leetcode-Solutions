// Last updated: 06/07/2026, 19:03:43
class Solution {
public:
    bool isPossible(vector<int>& target) {
        long total = 0;
        const int n = target.size();
        
        int a;

        priority_queue<int> pq(target.begin(), target.end());
        for (const int& a : target)
            total += a;
        
        while (true){
            a = pq.top(); pq.pop();
            total -= a;
            if (a == 1 || total == 1) return true;
            if (a < total || total == 0 || a % total == 0) return false;
            a %= total;
            total += a;
            pq.push(a);
        }
    }
};