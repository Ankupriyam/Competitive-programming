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

void solve()
{
    ll n;
    cin >> n;
    // vector<ll> nums(n);
    string nums;
    cin >> nums;
    vector<ll> prefx(n, 0), prefy(n, 0);
    if (nums[0] == 'L')
        prefx[0] = -1;
    if (nums[0] == 'R')
        prefx[0] = 1;
    if (nums[0] == 'U')
        prefy[0] = 1;
    if (nums[0] == 'D')
        prefy[0] = -1;
    for (ll i = 1; i < n; i++)
    {
        prefx[i] = prefx[i - 1];
        prefy[i] = prefy[i - 1];
        if (nums[i] == 'L')
            prefx[i] += -1;
        if (nums[i] == 'R')
            prefx[i] += 1;
        if (nums[i] == 'U')
            prefy[i] += 1;
        if (nums[i] == 'D')
            prefy[i] += -1;
    }
    vector<ll> xinc(n, 1), yinc(n, 1), xdec(n, 1), ydec(n, 1);
    map<pair<ll, ll>, ll> mp;
    for (ll i = n - 1; i >= 0; i--)
    {
        if (mp.find({prefx[i] + 1, prefy[i]}) != mp.end())
        {
            xinc[i] = max(xinc[i], 1 + xinc[mp[{prefx[i] + 1, prefy[i]}]]);
        }
        if (mp.find({prefx[i] - 1, prefy[i]}) != mp.end())
        {
            xdec[i] = max(xdec[i], 1 + xdec[mp[{prefx[i] - 1, prefy[i]}]]);
        }
        if (mp.find({prefx[i], prefy[i] + 1}) != mp.end())
        {
            yinc[i] = max(yinc[i], 1 + yinc[mp[{prefx[i], prefy[i] + 1}]]);
        }
        if (mp.find({prefx[i], prefy[i] - 1}) != mp.end())
        {
            ydec[i] = max(ydec[i], 1 + ydec[mp[{prefx[i], prefy[i] - 1}]]);
        }

        mp[{prefx[i], prefy[i]}] = i;
    }
    ll q;
    cin >> q;
    while (q--)
    {
        ll x, y;
        cin >> x >> y;
        ll finalx = x + prefx.back(), finaly = y + prefy.back();
        auto it = mp.find({-x, -y});
        if (it == mp.end())
        {
            cout << finalx << ' ' << finaly << endl;
            continue;
        }
        char c = nums[it->second];
        if (c == 'L')
        {
            cout << finalx + xdec[it->second] << ' ' << finaly << endl;
        }
        else if (c == 'R')
        {
            cout << finalx - xinc[it->second] << ' ' << finaly << endl;
        }
        else if (c == 'D')
        {
            cout << finalx << ' ' << finaly + ydec[it->second] << endl;
        }
        else
        {
            cout << finalx << ' ' << finaly - yinc[it->second] << endl;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // precompute(); /*when ncrmod*/
    // int t;
    // cin >> t;
    // while (t--)
    // {
    solve();
    //     cout << '\n';
    // }
    return 0;
}