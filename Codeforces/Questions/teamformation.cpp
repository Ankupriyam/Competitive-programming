// G - Team Formation Tactics
//
// strength(x>=y>=z) = max(6x, 4x+4y, 3x+3y+3z).
// Because it is a max, each team may "choose" a mode and the optimum is unchanged:
//   mode A: weights (6,0,0)   mode B: weights (4,4,0)   mode C: weights (3,3,3)
// With k1/k2/k3 teams in modes A/B/C (k1+k2+k3 = n) the multiset of 3n weights is fixed:
//   k1 sixes, 2*k2 fours, 3*k3 threes, rest zeros.
// By the rearrangement inequality the biggest weights go to the biggest ratings.
// With ratings sorted descending and prefix sums P:
//   F(k1,k2) = 2*P[k1] + P[k1+2*k2] + 3*P[3n-2*k1-k2]
// For fixed k1, F is concave in k2 -> binary search on the discrete difference.
// Total complexity: O(n log n) per test.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int N = 3 * n;

        vector<ll> b(N);
        for (auto &x : b) scanf("%lld", &x);
        sort(b.begin(), b.end(), greater<ll>());

        // 1-indexed sorted ratings (descending) and prefix sums
        vector<ll> a(N + 1), P(N + 1, 0);
        for (int i = 1; i <= N; i++) {
            a[i] = b[i - 1];
            P[i] = P[i - 1] + a[i];
        }

        ll best = 0;
        for (int k1 = 0; k1 <= n; k1++) {
            // smallest k2 in [0, n-k1] with k2 == n-k1 or F(k1,k2+1) - F(k1,k2) <= 0
            int lo = 0, hi = n - k1;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                ll D = a[k1 + 2 * mid + 1] + a[k1 + 2 * mid + 2] - 3 * a[N - 2 * k1 - mid];
                if (D > 0) lo = mid + 1;
                else hi = mid;
            }
            ll val = 2 * P[k1] + P[k1 + 2 * lo] + 3 * P[N - 2 * k1 - lo];
            best = max(best, val);
        }
        printf("%lld\n", best);
    }
    return 0;
}