// Last updated: 13/07/2026, 22:19:19
class LFUCache {
public:
    unordered_map<int, pair<int, int>> a;
    unordered_map<int, list<int>> b;
    unordered_map<int, list<int>::iterator> c;
    int minFreq=0;
    int cap;
    LFUCache(int capacity) { cap = capacity; }

    int get(int key) {
        if (!a.count(key))
            return -1;
        int val = a[key].first;
        int freq = a[key].second;
        b[freq].erase(c[key]);
        a[key].second++;
        int newFreq = freq + 1;
        b[newFreq].push_front(key);
        c[key] = b[newFreq].begin();
        if (b[freq].empty() && freq == minFreq)
            minFreq++;
        return val;
    }

    void put(int key, int value) {
    if (cap == 0) return; 
    if (a.count(key)) {
        a[key].first = value;
        get(key);
        return;
    } 
    if (a.size() == cap) {
        int evictKey = b[minFreq].back();
        b[minFreq].pop_back();
        a.erase(evictKey);
        c.erase(evictKey);
    } 
    a[key] = {value, 1};
    b[1].push_front(key);
    c[key] = b[1].begin();
    minFreq = 1;
}

};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */