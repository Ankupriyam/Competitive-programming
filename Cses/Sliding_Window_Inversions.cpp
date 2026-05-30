#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
using namespace std; using namespace __gnu_pbds; template <typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
#define pii pair<int,int> 
#define all(nums) nums.begin(),nums.end()
#define ll long long
#define pb push_back 
#define fast ios::sync_with_stdio(false); cin.tie(NULL);
long long gcd(long long a, long long b) {while (b) {a %= b;swap(a, b);}return a;} 
long long lcm(long long a, long long b) {return (a / gcd(a, b)) * b;}
long long nCr(ll n,ll r) {if (r > n) return 0; if (r > n - r) r = n - r; ll res = 1;for (ll i = 0; i < r; i++) {res = res * (n - i) / (i + 1);}return res;}
vector<bool> sieve(int n) {vector<bool> isPrime(n + 1, true);isPrime[0] = isPrime[1] = false; for (long long i = 2; i * i <= n; i++) { if (isPrime[i]) {for (long long j = i * i; j <= n; j += i) {isPrime[j] = false;}}}return isPrime;}

void solve() {
    int n,k;
    cin>>n>>k;
    vector<long long>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }


}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}