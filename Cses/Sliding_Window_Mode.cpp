#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define all(nums) nums.begin(), nums.end()
#define ll long long
#define pb push_back
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);
long long gcd(long long a, long long b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
long long nCr(ll n, ll r)
{
    if (r > n)
        return 0;
    if (r > n - r)
        r = n - r;
    ll res = 1;
    for (ll i = 0; i < r; i++)
    {
        res = res * (n - i) / (i + 1);
    }
    return res;
}
vector<bool> sieve(int n)
{
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (long long i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (long long j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}

void solve()
{
    int n, k;
    cin >> n>> k;
    vector<long long> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    map<int, set<int>> mp;
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        freq[nums[i]]++;
        mp[freq[nums[i]]].insert(nums[i]);
        if (freq[nums[i]] != 1)
        {
            mp[freq[nums[i]] - 1].erase(nums[i]);
            if (mp[freq[nums[i]] - 1].empty())
            {
                mp.erase(freq[nums[i]] - 1);
            }
        }
        if (i >= k - 1)
        {
            cout << *(mp.rbegin()->second.begin()) << ' ';
            int out = nums[i - k + 1];
            mp[freq[out]].erase(out);
            if (mp[freq[out]].size() == 0)
            {
                mp.erase(freq[out]);
            }
            freq[out]--;
            if (freq[out] == 0)
            {
                freq.erase(out);
            }
            else
            {
                mp[freq[out]].insert(out);
            }
        }
    }
}

int main()
{
    // int t;
    // cin >> t;
    // while (t--) {
    solve();
    // }
    return 0;
}