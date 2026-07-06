// Last updated: 06/07/2026, 19:06:58
class RecentCounter {
    queue<int> pings;
    int size;
public:
    RecentCounter() {
        size = 0;
    }
    
    int ping(int t) {
        pings.push(t);
        size++;
        
        while (t - pings.front() > 3000){
            pings.pop();
            size--;
        }
        return size;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */