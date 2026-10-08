#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define Oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define Mset tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
// Max heap
template <class T>
using pq = priority_queue<T>;
// Min heap
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
#define lb lower_bound
#define ub upper_bound
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ll long long
#define endlf "\n" << flush;
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define popcount(n) __builtin_popcountll(n)
#define MSB(n) (63 - __builtin_clzll(n))
#define LSB(n) __builtin_ctzll(n)
#define pb push_back /*Display gcd ncr lcm sieve firstnprime isprime  */
const ll MOD = 1000000007;
const ll M = 998244353;
#define PI 3.1415926535897932384626433832795
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

/* ================= DEBUG TEMPLATE ================= */

#ifndef ONLINE_JUDGE

#define debug(x)         \
    cerr << #x << " = "; \
    _print(x);           \
    cerr << '\n';

#define debug2(x, y)             \
    cerr << #x << " = ";         \
    _print(x);                   \
    cerr << ", " << #y << " = "; \
    _print(y);                   \
    cerr << '\n';

#define debug3(x, y, z)          \
    cerr << #x << " = ";         \
    _print(x);                   \
    cerr << ", " << #y << " = "; \
    _print(y);                   \
    cerr << ", " << #z << " = "; \
    _print(z);                   \
    cerr << '\n';

/* ---------- Basic Types ---------- */

void _print(int x) { cerr << x; }
void _print(long long x) { cerr << x; }
void _print(unsigned int x) { cerr << x; }
void _print(unsigned long long x) { cerr << x; }
void _print(float x) { cerr << x; }
void _print(double x) { cerr << x; }
void _print(long double x) { cerr << x; }
void _print(char x) { cerr << '\'' << x << '\''; }
void _print(bool x) { cerr << (x ? "true" : "false"); }
void _print(string x) { cerr << '"' << x << '"'; }
void _print(const char *x) { cerr << '"' << x << '"'; }

/* ---------- Forward Declarations for Templates ---------- */

template <class T, class V>
void _print(const pair<T, V> &p);
template <class T>
void _print(const vector<T> &v);
template <class T, size_t N>
void _print(const array<T, N> &a);
template <class T>
void _print(const set<T> &s);
template <class T>
void _print(const multiset<T> &s);
template <class T>
void _print(const unordered_set<T> &s);
template <class T>
void _print(const unordered_multiset<T> &s);
template <class T, class V>
void _print(const map<T, V> &m);
template <class T, class V>
void _print(const multimap<T, V> &m);
template <class T, class V>
void _print(const unordered_map<T, V> &m);
template <class T, class V>
void _print(const unordered_multimap<T, V> &m);
template <class T, class Container>
void _print(stack<T, Container> s);
template <class T, class Container>
void _print(queue<T, Container> q);
template <class T, class Container, class Compare>
void _print(priority_queue<T, Container, Compare> pq);
template <class T>
void _print(const deque<T> &d);
template <class T>
void _print(const list<T> &l);
template <class T>
void _print(const forward_list<T> &l);
template <size_t N>
void _print(const bitset<N> &b);
template <class... T>
void _print(const tuple<T...> &t);
template <class T>
void _print(const optional<T> &x);
template <class... T>
void _print(const variant<T...> &v);
template <class T, size_t N>
void _print(const T (&a)[N]);
template <typename T, typename... V>
void _print(T t, V... v);

/* ---------- Pair ---------- */
template <class T, class V>
void _print(const pair<T, V> &p)
{
    cerr << "{";
    _print(p.first);
    cerr << ", ";
    _print(p.second);
    cerr << "}";
}

/* ---------- Vector ---------- */
template <class T>
void _print(const vector<T> &v)
{
    cerr << "[ ";
    for (const auto &x : v)
    {
        _print(x);
        cerr << " ";
    }
    cerr << "]";
}

/* ---------- Array ---------- */
template <class T, size_t N>
void _print(const array<T, N> &a)
{
    cerr << "[ ";
    for (const auto &x : a)
    {
        _print(x);
        cerr << " ";
    }
    cerr << "]";
}

/* ---------- Set ---------- */
template <class T>
void _print(const set<T> &s)
{
    cerr << "{ ";
    for (const auto &x : s)
    {
        _print(x);
        cerr << " ";
    }
    cerr << "}";
}

/* ---------- Multiset ---------- */
template <class T>
void _print(const multiset<T> &s)
{
    cerr << "{ ";
    for (const auto &x : s)
    {
        _print(x);
        cerr << " ";
    }
    cerr << "}";
}

/* ---------- Unordered Set ---------- */
template <class T>
void _print(const unordered_set<T> &s)
{
    cerr << "{ ";
    for (const auto &x : s)
    {
        _print(x);
        cerr << " ";
    }
    cerr << "}";
}

/* ---------- Unordered Multiset ---------- */
template <class T>
void _print(const unordered_multiset<T> &s)
{
    cerr << "{ ";
    for (const auto &x : s)
    {
        _print(x);
        cerr << " ";
    }
    cerr << "}";
}

/* ---------- Map ---------- */
template <class T, class V>
void _print(const map<T, V> &m)
{
    cerr << "{ ";
    for (const auto &x : m)
    {
        _print(x);
        cerr << " ";
    }
    cerr << "}";
}

/* ---------- Multimap ---------- */
template <class T, class V>
void _print(const multimap<T, V> &m)
{
    cerr << "{ ";
    for (const auto &x : m)
    {
        _print(x);
        cerr << " ";
    }
    cerr << "}";
}

/* ---------- Unordered Map ---------- */
template <class T, class V>
void _print(const unordered_map<T, V> &m)
{
    cerr << "{ ";
    for (const auto &x : m)
    {
        _print(x);
        cerr << " ";
    }
    cerr << "}";
}

/* ---------- Unordered Multimap ---------- */
template <class T, class V>
void _print(const unordered_multimap<T, V> &m)
{
    cerr << "{ ";
    for (const auto &x : m)
    {
        _print(x);
        cerr << " ";
    }
    cerr << "}";
}

/* ---------- Stack ---------- */
template <class T, class Container>
void _print(stack<T, Container> s)
{
    cerr << "[ ";
    while (!s.empty())
    {
        _print(s.top());
        cerr << " ";
        s.pop();
    }
    cerr << "]";
}

/* ---------- Queue ---------- */
template <class T, class Container>
void _print(queue<T, Container> q)
{
    cerr << "[ ";
    while (!q.empty())
    {
        _print(q.front());
        cerr << " ";
        q.pop();
    }
    cerr << "]";
}

/* ---------- Priority Queue ---------- */
template <class T, class Container, class Compare>
void _print(priority_queue<T, Container, Compare> pq)
{
    cerr << "[ ";
    while (!pq.empty())
    {
        _print(pq.top());
        cerr << " ";
        pq.pop();
    }
    cerr << "]";
}

/* ---------- Deque ---------- */
template <class T>
void _print(const deque<T> &d)
{
    cerr << "[ ";
    for (const auto &x : d)
    {
        _print(x);
        cerr << " ";
    }
    cerr << "]";
}

/* ---------- List ---------- */
template <class T>
void _print(const list<T> &l)
{
    cerr << "[ ";
    for (const auto &x : l)
    {
        _print(x);
        cerr << " ";
    }
    cerr << "]";
}

/* ---------- Forward List ---------- */
template <class T>
void _print(const forward_list<T> &l)
{
    cerr << "[ ";
    for (const auto &x : l)
    {
        _print(x);
        cerr << " ";
    }
    cerr << "]";
}

/* ---------- Bitset ---------- */
template <size_t N>
void _print(const bitset<N> &b)
{
    cerr << b;
}

/* ---------- Tuple ---------- */
template <class Tuple, size_t... Is>
void _print_tuple(const Tuple &t, index_sequence<Is...>)
{
    cerr << "(";
    ((_print(get<Is>(t)), cerr << (Is + 1 == sizeof...(Is) ? "" : ", ")), ...);
    cerr << ")";
}

template <class... T>
void _print(const tuple<T...> &t)
{
    _print_tuple(t, index_sequence_for<T...>{});
}

/* ---------- Optional ---------- */
template <class T>
void _print(const optional<T> &x)
{
    if (x.has_value())
    {
        cerr << "optional(";
        _print(*x);
        cerr << ")";
    }
    else
    {
        cerr << "nullopt";
    }
}

/* ---------- Variant ---------- */
template <class... T>
void _print(const variant<T...> &v)
{
    visit([](const auto &x)
          { _print(x); }, v);
}

/* ---------- C-style Array ---------- */
template <class T, size_t N>
void _print(const T (&a)[N])
{
    cerr << "[ ";
    for (size_t i = 0; i < N; i++)
    {
        _print(a[i]);
        cerr << " ";
    }
    cerr << "]";
}

/* ---------- Multiple Arguments ---------- */
template <typename T, typename... V>
void _print(T t, V... v)
{
    _print(t);
    if constexpr (sizeof...(v) > 0)
    {
        cerr << ", ";
        _print(v...);
    }
}

#else

#define debug(x)
#define debug2(x, y)
#define debug3(x, y, z)

#endif

/* ================================================== */

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

// ALWAYS USE cout << fixed << setprecision(value) <<NUMBER; WHILE OUTPUTTING FLOATS
// const int max_n = 1e7 + 3;
// int dp[max_n];

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
    for (int i = 0; i < n - 4; i++)
    {
        mp[nums[i] + nums[i + 2] - nums[i + 4]]++;
        if (i + 6 < n)
        {
            if (nums[i] + nums[i + 2] - nums[i + 4] == nums[i + 2] + nums[i + 4] - nums[i + 6])
            {
                ans--;
            }
        }
        if (i + 8 < n)
        {
            if (nums[i] + nums[i + 2] - nums[i + 4] == nums[i + 6] + nums[i + 4] - nums[i + 8])
            {
                ans--;
            }
        }
    }
    for (auto &it : mp)
    {
        if (it.second > 1)
        {
            ans += ((it.second - 1) * it.second) / 2;
        }
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