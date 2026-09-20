#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define Oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define Mset tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ll long long
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

bool isPowerOfTwo(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
bool isPerfectSquare(ll x){if (x >= 0) {ll sr = sqrt(x);return (sr * sr == x);}return false;}


//--------------------------------------------------SEGMENT TREE (POINT UPDATE)-----------------------------------
class sg {
    // USAGE :-
    // vector<ll> arr = {1, 2, 3, 4, 5};
    // sg tree(arr);
    // cout << tree.query(1, 3) << '\n';  // indices 1..3
    // tree.update(2, 10);                 // arr[2] = 10
    // cout << tree.query(1, 3) << '\n';

    int n;
    vector<ll> tree;

    void build(int node, int l, int r, const vector<ll>& a) {

        if (l == r) {
            tree[node] = a[l];
            return;
        }

        int mid = (l + r) / 2;

        build(2 * node + 1, l, mid, a);
        build(2 * node + 2, mid + 1, r, a);

        // SUM
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];

        // MIN
        // tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);

        // MAX
        // tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);

        // GCD
        // tree[node] = gcd(tree[2 * node + 1], tree[2 * node + 2]);

        // LCM
        // tree[node] = lcm(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void update(int node, int l, int r, int index, ll value) {

        if (l == r) {
            tree[node] = value;
            return;
        }

        int mid = (l + r) / 2;

        if (index <= mid)
            update(2 * node + 1, l, mid, index, value);
        else
            update(2 * node + 2, mid + 1, r, index, value);

        // SUM
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];

        // MIN
        // tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);

        // MAX
        // tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);

        // GCD
        // tree[node] = gcd(tree[2 * node + 1], tree[2 * node + 2]);

        // LCM
        // tree[node] = lcm(tree[2 * node + 1], tree[2 * node + 2]);
    }

    ll query(int node, int l, int r, int ql, int qr) {

        // No overlap
        if (r < ql || qr < l) {

            // SUM
            return 0;

            // MIN
            // return LLONG_MAX;

            // MAX
            // return LLONG_MIN;

            // GCD
            // return 0;

            // LCM
            // return 1;
        }

        // Complete overlap
        if (ql <= l && r <= qr) return tree[node];

        int mid = (l + r) / 2;

        ll left = query(2 * node + 1,l,mid,ql,qr);

        ll right = query(2 * node + 2,mid + 1,r,ql,qr);

        // SUM
        return left + right;

        // MIN
        // return min(left, right);

        // MAX
        // return max(left, right);

        // GCD
        // return gcd(left, right);

        // LCM
        // return lcm(left, right);
    }

public:

    sg(const vector<ll>& a) {
        n = a.size();
        tree.resize(4 * n);
        build(0, 0, n - 1, a);
    }

    void update(int index, ll value) {
        update(0,0,n - 1,index,value);
    }

    ll query(int l, int r) {
        return query(0,0,n - 1,l,r);
    }
};
//------------------------------------------------------------------------------------------------------------------


//--------------------------------------------------SEGMENT TREE LAZY PROPAGATION-----------------------------------

class sgl {
    // USAGE:-
    // vector<ll> a = {1, 2, 3, 4, 5};
    // sgl st(a);
    // st.update(1, 3, 10);          
    // cout << st.query(1, 3) << '\n';

    int n;
    vector<ll> tree;
    vector<ll> lazy;

    void build(int node, int l, int r, const vector<ll>& a) {

        if (l == r) {
            tree[node] = a[l];
            return;
        }

        int mid = (l + r) / 2;

        build(2 * node + 1, l, mid, a);
        build(2 * node + 2, mid + 1, r, a);

        // SUM
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];

        // MIN
        // tree[node] = min(tree[2 * node + 1],
        //                   tree[2 * node + 2]);

        // MAX
        // tree[node] = max(tree[2 * node + 1],
        //                   tree[2 * node + 2]);
    }

    void push(int node, int l, int r) {

        if (lazy[node] == 0)
            return;

        // SUM + RANGE ADD
        tree[node] += lazy[node] * (r - l + 1);

        // MIN + RANGE ADD
        // tree[node] += lazy[node];

        // MAX + RANGE ADD
        // tree[node] += lazy[node];

        if (l != r) {
            lazy[2 * node + 1] += lazy[node];
            lazy[2 * node + 2] += lazy[node];
        }

        lazy[node] = 0;
    }

    void update(int node, int l, int r,
                int ql, int qr, ll value) {

        push(node, l, r);

        // No overlap
        if (r < ql  qr < l)
            return;

        // Complete overlap
        if (ql <= l && r <= qr) {
            lazy[node] += value;
            push(node, l, r);
            return;
        }

        int mid = (l + r) / 2;

        update(2 * node + 1,l,mid,ql,qr,value);

        update(2 * node + 2,mid + 1,r,ql,qr,value);

        // SUM
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];

        // MIN
        // tree[node] = min(tree[2 * node + 1],
        //                   tree[2 * node + 2]);

        // MAX
        // tree[node] = max(tree[2 * node + 1],
        //                   tree[2 * node + 2]);
    }

    ll query(int node, int l, int r, int ql, int qr) {

        push(node, l, r);

        // No overlap
        if (r < ql  qr < l) {

            // SUM
            return 0;

            // MIN
            // return LLONG_MAX;

            // MAX
            // return LLONG_MIN;
        }

        // Complete overlap
        if (ql <= l && r <= qr)
            return tree[node];

        int mid = (l + r) / 2;

        ll left = query(2 * node + 1,l,mid,ql,qr);

        ll right = query(2 * node + 2,mid + 1,r,ql,qr);

        // SUM
        return left + right;

        // MIN
        // return min(left, right);

        // MAX
        // return max(left, right);
    }

public:

    sgl(const vector<ll>& a) {
        n = a.size();

        tree.resize(4 * n);
        lazy.assign(4 * n, 0);

        build(0, 0, n - 1, a);
    }

    void update(int l, int r, ll value) {
        update(0,0,n - 1,l,r,value);
    }

    ll query(int l, int r) {
        return query(0,0,n - 1,l,r);
    }
};
//------------------------------------------------------------------------------------------------------------------


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

struct DSU {
    vector<int> parent, sz;
    DSU(int n) {
        parent.resize(n + 1);
        sz.assign(n + 1, 1);
        iota(all(parent), 0);
    }
    int find(int x) { return x == parent[x] ? x : parent[x] = find(parent[x]); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }
};


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