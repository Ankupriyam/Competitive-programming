#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ll long long
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
// /*ncrmod*/const int MAXN = 1e6 + 5;ll fact[MAXN], invFact[MAXN];ll power(ll a, ll b) {ll res = 1;while (b) {if (b & 1) res = (res * a) % MOD;a = (a * a) % MOD;b >>= 1;}return res;}void precompute() {fact[0] = 1;for (int i = 1; i < MAXN; i++) {fact[i] = (fact[i - 1] * i) % MOD;}invFact[MAXN - 1] = power(fact[MAXN - 1], MOD - 2); for (int i = MAXN - 2; i >= 0; i--) {invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;}}ll ncrmod(ll n, ll r) {if (r < 0 || r > n) return 0;return (fact[n] * invFact[r] % MOD * invFact[n - r] % MOD) % MOD;}
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

void _print(int x) { cerr << x; }
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
// void f(int i,int j,vector<ll>&nums){
//     if(j-i<=1)return;
//     int idx=(i+j)/2;
//     nums[idx]=nums[i]^nums[j];
//     f(idx,j,nums);
//     f(i,idx,nums);
// }
void solve()
{
    ll n, k;
    cin >> n >> k;
    string s, z;
    cin >> s;
    cin >> z;
    ll onesA = 0;
    ll onesB = 0;
    for (char c : s)
        onesA += (c == '1');
    for (char c : z)
        onesB += (c == '1');
    ll fA = onesA * (n - onesA);
    ll fB = onesB * (n - onesB);
    ll cnt = 1LL << (k - 1);
    ll ans = cnt * fA + (cnt + 1) * fB;
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