#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int ballast = 0;
    int n;
    cin >> n;
    
    vector<long long> v(n);
    for (int i = 0; i < n; ++i) {
        long long a;
        cin >> a;
        // Using 1-based indexing for the math invariant: V_i = a_i - i
        v[i] = a - (i + 1);
    }
    
    // Sort and remove duplicates to find unique available V values
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    
    // Find the longest consecutive sequence of integers
    int max_len = 1;
    int cur_len = 1;
    for (int i = 1; i < (int)v.size(); ++i) {
        if (v[i] == v[i - 1] + 1) {
            cur_len++;
        } else {
            max_len = max(max_len, cur_len);
            cur_len = 1;
        }
    }
    max_len = max(max_len, cur_len);
    
    cout << max_len << "\n";
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}