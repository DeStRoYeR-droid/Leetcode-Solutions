// Last updated: 14/09/2026, 09:31:49
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