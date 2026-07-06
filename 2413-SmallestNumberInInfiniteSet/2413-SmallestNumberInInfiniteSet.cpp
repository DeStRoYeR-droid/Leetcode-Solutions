// Last updated: 06/07/2026, 18:57:17
class SmallestInfiniteSet {
private:
    vector<bool> v;
    int minIndex;
public:
    SmallestInfiniteSet(){
        v = vector<bool>(1001, 0);
        minIndex = 0;
    }
    
    int popSmallest() {
        while (v[minIndex++] == 1);
        v[minIndex - 1] = 1;
        return minIndex;
    }
    
    void addBack(int num) {
        v[num - 1] = 0;
        minIndex = min(minIndex, num - 1);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */