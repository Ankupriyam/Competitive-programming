
#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 1000000007;

ll f(ll x)
{
    x %= MOD;
    ll y = (x + 1) % MOD;

    if (x % 2 == 0)
        x /= 2;
    else
        y = (y * 500000004LL) % MOD;

    return (x * y) % MOD;
}

void solve()
{
    ll n;
    cin >> n;

    ll ans = 0;
    ll j = 1, last = 0;

    while (j <= n)
    {
        ll curr = n / j;
        ll low = j, high = n/curr;

        while (low <= high)
        {
            ll mid = low + (high - low) / 2;

            if (n / mid == curr)
                low = mid + 1;
            else
                high = mid - 1;
        }

        ll times = (f(high) - f(last) + MOD) % MOD;

        ans = (ans + (curr % MOD * times) % MOD) % MOD;

        last = high;
        j = high + 1;
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}