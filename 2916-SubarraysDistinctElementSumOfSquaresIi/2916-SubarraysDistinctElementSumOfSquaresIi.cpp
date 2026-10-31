// Last updated: 31/10/2026, 19:56:24
#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    static constexpr long long MOD = 1'000'000'007LL;

    struct Node {
        long long sum = 0;
        long long sumSq = 0;
        long long lazy = 0;
    };

    int n;
    vector<Node> tree;

    // Apply an addition of val to every element in [l, r].
    void apply(int node, int l, int r, long long val) {
        long long len = r - l + 1;

        // Update sum of squares using the OLD sum.
        tree[node].sumSq =
            (tree[node].sumSq
             + 2LL * val % MOD * tree[node].sum % MOD
             + val * val % MOD * len % MOD) % MOD;

        // Update sum.
        tree[node].sum =
            (tree[node].sum + val * len) % MOD;

        // Record pending update for children.
        tree[node].lazy =
            (tree[node].lazy + val) % MOD;
    }

    void push(int node, int l, int r) {
        if (tree[node].lazy == 0 || l == r) {
            return;
        }

        int mid = l + (r - l) / 2;
        long long val = tree[node].lazy;

        apply(node * 2, l, mid, val);
        apply(node * 2 + 1, mid + 1, r, val);

        tree[node].lazy = 0;
    }

    void pull(int node) {
        tree[node].sum =
            (tree[node * 2].sum
             + tree[node * 2 + 1].sum) % MOD;

        tree[node].sumSq =
            (tree[node * 2].sumSq
             + tree[node * 2 + 1].sumSq) % MOD;
    }

    void update(int node, int l, int r,
                int ql, int qr, long long val) {
        // No overlap.
        if (qr < l || r < ql) {
            return;
        }

        // Complete overlap.
        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }

        // Partial overlap.
        push(node, l, r);

        int mid = l + (r - l) / 2;

        update(node * 2, l, mid, ql, qr, val);
        update(node * 2 + 1, mid + 1, r, ql, qr, val);

        pull(node);
    }

public:
    explicit SegmentTree(int size) : n(size) {
        tree.resize(4 * n + 5);
    }

    // Add val to every element in [l, r].
    void rangeAdd(int l, int r, long long val) {
        if (l > r) {
            return;
        }

        update(1, 0, n - 1, l, r, val);
    }

    // Sum of squares over the entire array.
    long long getSumOfSquares() const {
        return tree[1].sumSq;
    }
};

class Solution {
private:
    static constexpr long long MOD = 1'000'000'007LL;

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        SegmentTree seg(n);

        vector<int> last(100001, -1);
        long long answer = 0;

        for (int r = 0; r < n; ++r) {
            int x = nums[r];
            int prev = last[x];

            // Update distinct counts for subarrays
            // ending at r.
            seg.rangeAdd(prev + 1, r, 1);

            // Add the contribution of all subarrays
            // ending at r.
            answer =
                (answer + seg.getSumOfSquares()) % MOD;

            last[x] = r;
        }

        return static_cast<int>(answer);
    }
};