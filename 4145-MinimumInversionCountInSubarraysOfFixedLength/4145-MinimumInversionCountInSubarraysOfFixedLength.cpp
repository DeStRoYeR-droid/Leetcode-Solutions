// Last updated: 06/07/2026, 18:47:47
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#pragma GCC optimize("O3", "unroll-loops")

template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    long long minInversionCount(vector<int>& arr, int k) {
        ordered_multiset<int> store;
        long long inversionCount = 0, minInversionCount = 1e10;
        for (int i = 0; i < arr.size(); i++) {
            store.insert(arr[i]);
            inversionCount += store.size() - store.order_of_key(arr[i] + 1);
            if (i >= k) {
                inversionCount -= store.order_of_key(arr[i - k]);
                store.erase(store.find_by_order(store.order_of_key(arr[i - k])));
            }
            if (i >= k - 1) {
                minInversionCount = min(minInversionCount, inversionCount);
            }
        }
        return minInversionCount;
    }
};