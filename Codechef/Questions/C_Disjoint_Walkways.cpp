#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{

    ll n, q;
    cin >> n >> q;
    vector<vector<ll>> nums(q, vector<ll>(2, 0));
    ll ans = 0;
    for (int i = 0; i < q; i++)
    {
        // cin >> nums[i][0] >> nums[i][1];
        ll x, y;
        cin >> x >> y;
        if (x == y)
        {
            cout << 0 << '\n';
            continue;
        }
        if ((x & y) == 0)
        {
            // ans+=x+y;
            cout << x + y << '\n';
            continue;
        }
        ll a = 1e9, b = 1e9, same = 32;
        for (int j = 0; j < 32; j++)
        {
            if (((x >> j) & 1) == 0)
            {
                a = j;
                break;
            }
        }
        for (int j = 0; j < 32; j++)
        {
            if (((y >> j) & 1) == 0)
            {
                b = j;
                break;
            }
        }
        for (int j = 0; j < 32; j++)
        {
            if (((y >> j) & 1) == 0 && ((x >> j) & 1) == 0)
            {
                same = j;
                break;
            }
        }
        if ((1 << a) > n || (1 << b) > n)
        {
            cout << -1 << '\n';
            continue;
        }
        if (a == b)
        {
            cout << x + y + 2 * (1 << a) << '\n';
            continue;
        }

        ll poss = 1e17;
        if ((1 << same) <= n)
        {
            poss = x + y + 2 * (1 << same);
        }

        poss = min(poss, x + y + 2 * ((1 << a) + (1 << b)));
        cout << poss << '\n';
    }
}

int main()
{
    // int t;
    // cin >> t;
    // while (t--)
    // {
    solve();
    //     cout << '\n';
    // }
}