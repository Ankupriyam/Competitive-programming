
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve()
{
    ll n;
    cin >> n;
    vector<ll> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    ll ans = 0;
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        // debug(ans);
        if (nums[i] == 1)
        {
            ans++;
            continue;
        }
        else
        {
            if (nums[i] > n)
            {
                continue;
            }

            if (mp.find(nums[i]) != mp.end() && mp[nums[i]] >= max(0LL, i - nums[i] + 1))
            {

                ll left = min(i + 1, nums[i]);
                ll right = min(n - i, nums[i]);
                ll prev = mp[nums[i]];
                mp[nums[i]] = i;
                if (right + left - 1 >= nums[i])
                {
                    ll ri = min(n - 1, i + nums[i] - 1);
                    ll li = max(prev+1, i - nums[i] + 1);
                    ans += max(0LL,ri - li + 2 - nums[i]);

                    // ll uska = min(n - 1, i + nums[i] - 1) - max(0LL, i - nums[i] + 1) + 2 - nums[i];
                    // ll z = max(0LL, uska - (i - prev));
                    // debug(z);

                    // ans -= z;
                }

                // continue;
            }
            else
            {
                ll left = min(i + 1, nums[i]);
                ll right = min(n - i, nums[i]);
                if (right + left - 1 >= nums[i])
                {

                    ll ri = min(n - 1, i + nums[i] - 1);
                    ll li = max(0LL, i - nums[i] + 1);
                    ans += ri - li + 2 - nums[i];
                }
            }
        }
        // debug(ans);
        mp[nums[i]]=i;
    }
    cout << ans;
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