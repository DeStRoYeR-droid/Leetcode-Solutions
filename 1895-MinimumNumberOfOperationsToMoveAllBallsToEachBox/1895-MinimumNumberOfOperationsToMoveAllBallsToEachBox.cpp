// Last updated: 06/07/2026, 19:00:52
class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> result(boxes.size());
        vector<int> positions;
        for (int i = 0; i < boxes.size(); i++)
            if (boxes[i] == '1') positions.push_back(i);

        for (int i = 0; i < result.size(); i++){
            int cur = 0;
            for (auto& pos : positions)
                cur += abs(pos - i);
            result[i] = cur;
        }
        return result;
    }
};