/*
   Author: Anku 
    created: 20:08:27 02-05-2026
*/

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
 
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize("Ofast,unroll-loops,O3,no-stack-protector,fast-math")
#pragma GCC target("avx,avx2,fma,sse4")
 
// ╭──────────────────────────────╮
// │         ALIASES ZONE         │
// ╰──────────────────────────────╯
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
typedef unsigned long long ull;
typedef long double lld;
 
// ╭──────────────────────────────╮
// │         MACROS ZONE          │
// ╰──────────────────────────────╯
#define ll                long long
#define int               long long
#define eb                emplace_back
#define mp                make_pair
#define ff                first
#define ss                second
#define pb                push_back
#define lb                lower_bound
#define ub                upper_bound
#define all(x)            x.begin(), x.end()
#define rall(x)           x.rbegin(),x.rend()
#define ins               insert
#define ln                '\n'
#define endl              "\n"
#define endlf             "\n" << flush;
#define yes               cout << "YES\n"
#define no                cout << "NO\n"
#define fr(i,n)           for(int i = 0; i < n; ++i)
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define getunique(v)      {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define NP(a)             next_permutation(all(a))
#define sz(x)             (int)((x).size())
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll
 
// ╭──────────────────────────────╮
// │         I/O                  │
// ╰──────────────────────────────╯
template<typename T1, typename T2> istream& operator>>(istream& in, pair<T1, T2>& p) { return in >> p.first >> p.second; }
template<typename T1, typename T2> ostream& operator<<(ostream& out, const pair<T1, T2>& p) { return out << "(" << p.first << ", " << p.second << ")"; }
template<typename T> istream& operator>>(istream& in, vector<T>& v) { for (auto& x : v) in >> x; return in; }
template<typename T> ostream& operator<<(ostream& out, const vector<T>& v) { for (const auto& x : v) out << x << " "; return out; }
template<typename T> istream& operator>>(istream& in, vector<vector<T>>& v) { for (auto& row : v) in >> row; return in; }
template<typename T> ostream& operator<<(ostream& out, const vector<vector<T>>& v) { for (const auto& row : v) out << row << '\n'; return out; }
 
 
// ╭────────────────────────────────────────────╮
// │      PBDS/ Ordered Set && Priority Queue   │
// ╰────────────────────────────────────────────╯
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update >pbds; // find_by_order, order_of_key
template <typename T>
using os = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using oms = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
 
// ╭──────────────────────────────╮
// │         CONSTANTS            │
// ╰──────────────────────────────╯
const ll inf = 2e18 + 5;
const ll ninf = -2e18 - 5;
const ll mod = 1e9 + 7;
const ll M=998244353;
const int MAXN = 2e5 + 5;
#define PI 3.1415926535897932384626433832795
 
// ╭──────────────────────────────╮
// │       DEBUG MACRO ZONE       │
// ╰──────────────────────────────╯
#ifndef ONLINE_JUDGE
#define dbg(...) \
    do { cerr << "Line(" << __LINE__ << "): " << #__VA_ARGS__ << " = ";  _print(__VA_ARGS__);cerr << endl;} while(0)
#else
    #define dbg(...) do {} while(0)
#endif
 
void _print(ll t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(unordered_set <T> v);
template <class T, class V> void _print(unordered_map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <typename T>
void _print(const os<T>& v) {
    cerr << "[ ";
    for (const auto &it : v) {
        _print(it);
        cerr << " ";
    }
    cerr << "]";
}
template <typename T>
void _print(const oms<T>& v) {
    cerr << "[ ";
    for (const auto &it : v) {
        _print(it);
        cerr << " ";
    }
    cerr << "]";
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//Bits
string decToBinary(ll n){string s="";ll i = 0;while (n > 0) {s =to_string(n % 2)+s;n = n / 2;i++;}return s;}
ll binaryToDecimal(string n){string num = n;ll dec_value = 0;int base = 1;int len = num.length();for(int i = len - 1; i >= 0; i--){if (num[i] == '1')dec_value += base;base = base * 2;}return dec_value;}
 
//Check
bool isPrime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
bool isPowerOfTwo(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
bool isPerfectSquare(ll x){if (x >= 0) {ll sr = sqrt(x);return (sr * sr == x);}return false;}
 
// Sieve of Eratosthenes
vector<int> sieve(int n) {
    vector<int> primes(n + 1, 1), res;
    primes[0] = primes[1] = 0;
    for (int i = 2; i * i <= n; i++) {
        if (primes[i]) {
            for (int j = i * i; j <= n; j += i) primes[j] = 0;
        }
    }
    for (int i = 2; i <= n; i++)
        if (primes[i]) res.pb(i);
    return res;
}
 
// ╭──────────────────────────────╮
// │      MODULAR ARITHMETIC      │
// ╰──────────────────────────────╯
int add(int a, int b) { return (a + b) % mod; }
int sub(int a, int b) { return (a - b + mod) % mod; }
int mul(int a, int b) { return (a * b) % mod; }
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll power(ll a, ll b, ll m = mod) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_inv(ll a, ll m = mod) { return power(a, m - 2, m); }
ll div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);}
 
// ╭──────────────────────────────╮
// │        FACTORIAL ZONE        │
// ╰──────────────────────────────╯
int fact[MAXN+1], invFact[MAXN+1];
void precomp_fact() {
    fact[0] = invFact[0] = 1;
    for(int i = 1; i <= MAXN; i++){
        fact[i] = mul(fact[i - 1], i);
        invFact[i] = mod_inv(fact[i],mod);
    }
}
int nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return mul(fact[n], mul(invFact[r], invFact[n - r]));
}
 
 
// ╭──────────────────────────────╮
// │      DISJOINT SET UNION      │
// ╰──────────────────────────────╯
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
        sz[b] = sz[a];
        return true;
    }
};
// ╭──────────────────────────────╮
// │      GLOBAL ZONE             │
// ╰──────────────────────────────╯
// ALWAYS USE cout << fixed << setprecision(value) <<NUMBER; WHILE OUTPUTTING FLOATS
// const int max_n = 1e7 + 3;
// int dp[max_n];
 
 
 
// ╭──────────────────────────────╮
// │        SOLVER ZONE           │
// ╰──────────────────────────────╯
void solve(){
 
    ll n;
    cin>>n;
    
    
 
 
 
 
}
// ╭──────────────────────────────╮
// │             MAIN             │
// ╰──────────────────────────────╯
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // precomp_fact();  // Enable if using nCr or factorials
    int _=1;
    cin>>_;
    while(_--){
        solve();
        cout<<"\n";
    }
}