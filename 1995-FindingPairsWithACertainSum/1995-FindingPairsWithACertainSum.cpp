// Last updated: 06/07/2026, 19:00:23
class FindSumPairs {
private:
    vector<int> n1, n2;
    unordered_map<int, int> freq;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        n2 = nums2;
        for (const int& n : n2) freq[n]++;
    }
    
    void add(int index, int val) {
        freq[n2[index]]--;
        n2[index] += val;
        freq[n2[index]]++;
    }
    
    int count(int tot) {
        int result = 0;
        for (const int& n : n1) result += freq[tot - n];
        return result;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */