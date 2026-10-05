#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{

    ll a, b, m;
    cin >> a >> b >> m;
    if (b / m == a / m)
    {

        ll ans = ((b % m) * ((b % m) + 1)) / 2 - (((a) % m) * (((a) % m) + 1)) / 2;
        cout << ans;
    }
    else
    {

        ll ans = ((b % m) * ((b % m) + 1)) / 2 + (m * (m - 1)) / 2 - (((a ) % m) * (((a) % m) + 1)) / 2 + (((m * (m - 1)) / 2) * (b / m - a / m - 1));
        cout << ans;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << '\n';
    }
}