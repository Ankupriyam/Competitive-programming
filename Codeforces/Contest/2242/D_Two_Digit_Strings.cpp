#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define Oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ll long long
#define int long long
#define popcount(n) __builtin_popcountll(n)
#define MSB(n) (63 - __builtin_clzll(n))
#define LSB(n) __builtin_ctzll(n)
#define pb push_back /*Display gcd ncr lcm sieve firstnprime isprime  */
const ll MOD = 1000000007;
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
void display(vector<ll> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << ' ';
    }
}

/* ================= DEBUG ================= */
#ifndef ONLINE_JUDGE
#define debug(x)         \
    cerr << #x << " = "; \
    _print(x);           \
    cerr << endl;
#else
#define debug(x)
#endif

// void _print(int x) { cerr << x; }
void _print(long long x) { cerr << x; }
void _print(string x) { cerr << x; }
void _print(char x) { cerr << x; }
void _print(double x) { cerr << x; }

template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.first);
    cerr << ",";
    _print(p.second);
    cerr << "}";
}

template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
/* ========================================= */

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
vector<int> firstNPrimes(int n)
{
    if (n <= 0)
        return {};
    int limit;
    if (n < 6)
    {
        limit = 15;
    }
    else
    {
        limit = n * (log(n) + log(log(n))) + 10;
    }
    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= limit; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= limit; j += i)
                isPrime[j] = false;
        }
    }
    vector<int> primes;
    for (int i = 2; i <= limit && primes.size() < n; i++)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
        }
    }
    return primes;
}
bool isPrime(int n)
{
    if (n < 2)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int findMEX(vector<ll> &a)
{
    unordered_set<ll> s(a.begin(), a.end());

    int mex = 0;
    while (s.count(mex))
    {
        mex++;
    }
    return mex;
}

// /*ncrmod*/const int MAXN = 1e6 + 5;ll fact[MAXN], invFact[MAXN];ll power(ll a, ll b) {ll res = 1;while (b) {if (b & 1) res = (res * a) % MOD;a = (a * a) % MOD;b >>= 1;}return res;}void precompute() {fact[0] = 1;for (int i = 1; i < MAXN; i++) {fact[i] = (fact[i - 1] * i) % MOD;}invFact[MAXN - 1] = power(fact[MAXN - 1], MOD - 2); for (int i = MAXN - 2; i >= 0; i--) {invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;}}ll ncrmod(ll n, ll r) {if (r < 0 || r > n) return 0;return (fact[n] * invFact[r] % MOD * invFact[n - r] % MOD) % MOD;}

// ll modInverse(ll x)
// {
//     return power(x, MOD - 2);
// }

bool isPalindrome(string s)
{
    int l = 0, r = s.size() - 1;
    while (l < r)
    {
        if (s[l] != s[r])
            return false;
        l++;
        r--;
    }
    return true;
}

int dp[5004][5004];
ll f(int i, int j, vector<ll> &a, vector<ll> &b)
{
    ll n = a.size(), m = b.size();
    if (i < 0 || j < 0)
    {
        return 0;
    }
    int ans = 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (a[i] == b[j])
    {
        ans = max(ans, 1 + f(i - 1, j - 1, a, b));
    }
    ans = max(ans, f(i, j - 1, a, b));
    ans = max(ans, f(i - 1, j, a, b));
    return dp[i][j] = ans;
}

void solve()
{
    ll n, m;
    // vector<ll> nums(n);
    string a, b;
    cin >> a;
    cin >> b;
    n = a.size(), m = b.size();
    ll sum1 = 0, sum2 = 0;
    vector<ll> x, y;
    for (int i = 0; i < n; i++)
    {
        sum1 += a[i] - '0';
        x.pb(a[i] - '0');
        if (i) x[i] = (x[i] + x[i - 1]) % 10;
    }
    for (int i = 0; i < m; i++)
    {
        sum2 += b[i] - '0';
        y.pb(b[i] - '0');
        if (i) y[i] = (y[i] + y[i - 1]) % 10;
    }
    if ((sum1 % 10) != (sum2 % 10))
    {
        cout << -1;
        return;
    }
    memset(dp, -1, sizeof(dp));
    cout<<f(x.size()-1,y.size()-1,x,y);
}

signed main()
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