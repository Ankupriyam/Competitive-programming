#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{

    ll n;
    cin >> n;
    vector<ll> nums(n);
    map<ll, ll> mp;
    ll mini = 1e17;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        mp[nums[i]]++;
        mini = min(mini, nums[i]);
    }
    ll ans = 0;
    for (auto &it : mp)
    {

        ll take = min(mp[it.first - 1], it.second);
        ans += take;
        it.second -= take;
        ll x = it.second / 2;
        ans += x;
        it.second -= 2 * x;
        // if (idx + 1 == it.first)
        // {

        // last = it.second - take;
        // idx = it.first;
        // }
    }
    cout << ans;
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