// Last updated: 06/07/2026, 18:57:04
class NumberContainers {
    map<int, int> mp;
    map<int, set<int>> mpp;
public:
    NumberContainers() {}
    
    void change(int index, int number) {
        if (mp.find(index) != mp.end() && mp[index] != number){
            mpp[mp[index]].erase(index);
            if (mpp[mp[index]].empty()){
                mpp.erase(mp[index]);
            }
        }
        mp[index] = number;
        mpp[number].insert(index); 
    }
    
    int find(int number) {
        if (mpp.find(number) == mpp.end()) return -1;
        return *mpp[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */