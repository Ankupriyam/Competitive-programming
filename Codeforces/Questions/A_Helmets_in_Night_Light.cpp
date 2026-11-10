#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define all(nums) nums.begin(),nums.end()
#define ll long long
#define pb push_back 
#define fast ios::sync_with_stdio(false); cin.tie(NULL);
long long gcd(long long a, long long b) {while (b) {a %= b;swap(a, b);}return a;} long long lcm(long long a, long long b) {return (a / gcd(a, b)) * b;}
long long nCr(ll n,ll r) {if (r > n) return 0; if (r > n - r) r = n - r; ll res = 1;for (ll i = 0; i < r; i++) {res = res * (n - i) / (i + 1);}return res;}
vector<bool> sieve(int n) {vector<bool> isPrime(n + 1, true);isPrime[0] = isPrime[1] = false; for (long long i = 2; i * i <= n; i++) { if (isPrime[i]) {for (long long j = i * i; j <= n; j += i) {isPrime[j] = false;}}}return isPrime;}
vector<int> firstNPrimes(int n) {if (n <= 0) return {};int limit;if (n < 6){limit = 15;}else{limit = n * (log(n) + log(log(n))) + 10;}vector<bool> isPrime(limit + 1, true);isPrime[0] = isPrime[1] = false;for (int i = 2; i * i <= limit; i++) {if (isPrime[i]) {for (int j = i * i; j <= limit; j += i)isPrime[j] = false;}}vector<int> primes;for (int i = 2; i <= limit && primes.size() < n; i++) {if (isPrime[i]){primes.push_back(i);}}return primes;}
void solve() {
    int n, p;
    cin >> n >> p;

    vector<pair<ll,ll>> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i].first; 
    }
    for(int i = 0; i < n; i++) {
        cin >> nums[i].second; 
    }

    sort(nums.begin(), nums.end(), [](pair<ll,ll> a, pair<ll,ll> b) {
        return a.second < b.second;
    });

    ll left = n - 1;
    ll cost = p;

    for(int i = 0; i < n; i++) {
        if(left <= 0) break;

        if(nums[i].second >= p) break; 

        ll use = min(nums[i].first, left);
        cost += use * nums[i].second;
        left -= use;
    }

    cost += left * p;
    cout << cost << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}