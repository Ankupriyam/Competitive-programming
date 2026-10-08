#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> nums(n);
    ll odd = 0, even = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        if (nums[i] % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }
    if (even == 0)
    {
        cout << 0;
        return;
    }
    if ((x % 2 == 0 && odd == 0))
    {
        cout << -1 ;
        return;
    }
    if(x%2==1){
        cout<<(even+1)/2;
        return;
    }else{
        cout<<even;
        return;
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