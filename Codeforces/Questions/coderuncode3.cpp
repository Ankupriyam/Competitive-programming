
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve()
{
    ll n, k;
    cin >> n >> k;
    if (n > k)
    {
        cout << -1;
        return;
    }
    vector<ll> nums(n, 1);
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> nums[i];
    // }
    // k-=n;
    // nums[0]+=k;
    ll curr = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            curr++;
        }
    }

    k -= curr;
    if (k < 0)
    {
        cout << -1;
        return;
    }
    nums[0] += k;

    // display(nums);
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << ' ';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // precompute(); /*when ncrmod*/
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << '\n';
    }
    return 0;
}