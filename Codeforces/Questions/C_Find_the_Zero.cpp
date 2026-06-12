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
    int n;
    cin >> n;
    // vector<long long> nums(2 * n);
    // for(int i=0;i<n;i++){
    //     cin>>nums[i];
    // }
    int check = 1;
    for (int i = 3; i < 2 * n; i += 2)
    {
        cout << "? " << i << " " << i + 1 << endl;
        cout.flush();
        int x;
        cin >> x;
        if (x == 1)
        {
            cout << "! " << i << endl;
            cout.flush();
            return;
        }
    }
    ll z = 4;
    while (z > 2)
    {
        cout << "? " << 1 << " " << z << endl;
        cout.flush();
        int x;
        cin >> x;
        if (x == 1)
        {
            cout << "! " << 1 << endl;
            cout.flush();
            return;
        }
        z--;
    }

    cout << "! " << 2 << endl;
    cout.flush();
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}