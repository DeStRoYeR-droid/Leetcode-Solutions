// Last updated: 13/07/2026, 22:21:50
class Solution {
public:
    int hIndex(vector<int>& citations) {
        const int papers = citations.size();
        vector<int> buckets(papers + 1, 0);

        for (int citation : citations)
            buckets[min(citation, papers)]++;

        int cumulative = 0;
        for (int hIndex = papers; hIndex >= 0; --hIndex){
            cumulative += buckets[hIndex];
            if (cumulative >= hIndex)
                return hIndex;
        }
        return 0;
    }
};