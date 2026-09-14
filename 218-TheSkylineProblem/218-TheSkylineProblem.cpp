// Last updated: 14/09/2026, 09:41:56
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> events;
        for (const auto& b : buildings) {
            events.push_back({b[0], -b[2]}); // Negative to make it appear in front
            events.push_back({b[1], b[2]});
        }

        // Sort the events
        sort(events.begin(), events.end());

        // Ordered multiset to track active heights (includes ground level 0)
        multiset<int> heights = {0};
        int prev_max = 0;
        vector<vector<int>> skyline;

        // Line sweep processing
        for (const auto& [x, h] : events) {
            if (h < 0) {
                // Start event: add height to multiset
                heights.insert(-h);
            } else {
                // End event: remove ONE instance of height from multiset
                heights.erase(heights.find(h));
            }

            // Current max height is at the end of the sorted multiset
            int current_max = *heights.rbegin();

            // Record a keypoint whenever the max height changes
            if (current_max != prev_max) {
                skyline.push_back({x, current_max});
                prev_max = current_max;
            }
        }

        return skyline;
    }
};