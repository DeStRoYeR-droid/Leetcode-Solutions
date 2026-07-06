// Last updated: 06/07/2026, 18:50:48
using namespace std;

class SegmentTree {
    vector<int> count;
    vector<double> length;
    const vector<int>& coords;
    int n;

public:
    SegmentTree(const vector<int>& c) : coords(c) {
        n = coords.size();
        count.assign(4 * n, 0);
        length.assign(4 * n, 0.0);
    }

    void update(int v, int tl, int tr, int l, int r, int add) {
        if (l > r) return;
        if (l == tl && r == tr) {
            count[v] += add;
        } else {
            int tm = (tl + tr) / 2;
            update(2 * v, tl, tm, l, min(r, tm), add);
            update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, add);
        }
        
        if (count[v] > 0) {
            length[v] = (double)coords[tr + 1] - coords[tl];
        } else if (tl != tr) {
            length[v] = length[2 * v] + length[2 * v + 1];
        } else {
            length[v] = 0;
        }
    }

    double get_root_length() {
        return length[1];
    }
};

struct Event {
    int y, x1, x2, type;
    bool operator<(const Event& other) const {
        return y < other.y;
    }
};

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<int> x_coords;
        vector<int> y_boundaries;
        for (const auto& s : squares) {
            x_coords.push_back(s[0]);
            x_coords.push_back(s[0] + s[2]);
            y_boundaries.push_back(s[1]);
            y_boundaries.push_back(s[1] + s[2]);
        }
        
        sort(x_coords.begin(), x_coords.end());
        x_coords.erase(unique(x_coords.begin(), x_coords.end()), x_coords.end());
        
        sort(y_boundaries.begin(), y_boundaries.end());
        y_boundaries.erase(unique(y_boundaries.begin(), y_boundaries.end()), y_boundaries.end());

        vector<Event> events;
        for (const auto& s : squares) {
            int x1 = lower_bound(x_coords.begin(), x_coords.end(), s[0]) - x_coords.begin();
            int x2 = lower_bound(x_coords.begin(), x_coords.end(), s[0] + s[2]) - x_coords.begin() - 1;
            events.push_back({s[1], x1, x2, 1});
            events.push_back({s[1] + s[2], x1, x2, -1});
        }
        sort(events.begin(), events.end());

        SegmentTree st(x_coords);
        vector<pair<double, double>> slabs;
        double totalArea = 0;
        int eventIdx = 0;

        for (int i = 0; i < (int)y_boundaries.size() - 1; ++i) {
            while (eventIdx < events.size() && events[eventIdx].y <= y_boundaries[i]) {
                st.update(1, 0, (int)x_coords.size() - 2, events[eventIdx].x1, events[eventIdx].x2, events[eventIdx].type);
                eventIdx++;
            }
            double width = st.get_root_length();
            double height = (double)y_boundaries[i + 1] - y_boundaries[i];
            slabs.push_back({width, height});
            totalArea += width * height;
        }

        double targetArea = totalArea / 2.0;
        double currentArea = 0;
        double resultY = y_boundaries[0];

        for (int i = 0; i < slabs.size(); ++i) {
            double slabArea = slabs[i].first * slabs[i].second;
            if (currentArea + slabArea >= targetArea - 1e-9) {
                double needed = targetArea - currentArea;
                resultY = y_boundaries[i] + (needed / slabs[i].first);
                break;
            }
            currentArea += slabArea;
        }

        return resultY;
    }
};