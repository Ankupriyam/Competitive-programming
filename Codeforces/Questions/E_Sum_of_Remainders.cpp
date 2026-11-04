#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1000000007;
ll power(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
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

ll sumofdivisors(ll n, ll m)
{

    ll ans = 0;
    ll j = 1, x = min(n, m);

    while (j <= x)
    {
        ll curr = n / j;
        ll high = n / curr;
        high = min(high, x);
        ll times = (f(high) - f(j - 1) + MOD) % MOD;
        ans = (ans + (curr % MOD * times) % MOD) % MOD;
        j = high + 1;
    }

    return ans;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    // n *m  - n/1+2(n/2)+

    ll sum = (((m % MOD) * (n % MOD)) % MOD - sumofdivisors(n, m) + MOD) % MOD;
    cout << sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}