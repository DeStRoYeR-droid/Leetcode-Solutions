// Last updated: 13/07/2026, 22:25:26
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        const int n = (int)nums.size();
        if (n < 2) return 0;

        int minVal = INT_MAX, maxVal = INT_MIN;
        for (int num : nums) {
            if (num < minVal) minVal = num;
            if (num > maxVal) maxVal = num;
        }
        if (minVal == maxVal) return 0;

        int bucketSize = max(1, (maxVal - minVal) / (n - 1));
        int bucketCount = (maxVal - minVal) / bucketSize + 1;

        struct Bucket {
            int minVal = INT_MAX;
            int maxVal = INT_MIN;
        };
        vector<Bucket> buckets(bucketCount);

        const int rangeStart = minVal;
        for (int num : nums) {
            int idx = (num - rangeStart) / bucketSize;
            Bucket& b = buckets[idx];
            if (num < b.minVal) b.minVal = num;
            if (num > b.maxVal) b.maxVal = num;
        }

        int maxGap = 0;
        int prevMax = minVal;

        for (int i = 0; i < bucketCount; ++i) {
            const Bucket& b = buckets[i];
            if (b.minVal == INT_MAX) continue;

            int gap = b.minVal - prevMax;
            if (gap > maxGap) maxGap = gap;
            prevMax = b.maxVal;
        }

        return maxGap;
    }
};