#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define Oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// order_of_key(k) : no. of elements < k
// *find_by_order(i) : value at index i (0-based)

using namespace std;

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i].first >> nums[i].second;

        sort(nums.begin(), nums.end()); 
        Oset st;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += i - st.order_of_key(nums[i].second);  
            st.insert(nums[i].second); 
        } 
        cout << ans << '\n';
    }

    return 0;
}

