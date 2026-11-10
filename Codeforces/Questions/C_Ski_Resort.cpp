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
bool isPrime(int n) { if (n < 2) return false;if (n == 2)return true; if (n % 2 == 0)return false; for (int i = 3; i * i <= n; i += 2) { if (n % i == 0)return false;}return true;}

void solve() {
    ll n,k,q;
    cin>>n>>k>>q;
    vector<ll>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    ll l=0,r=0,ans=0;
    for(;r<n;r++){
        if(nums[r]>q){
            l=r+1;
        }
        if(r-l+1>=k){
            ans+=r-l+1-k+1;
        }
    }
    cout<<ans<<endl;
    

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


void display(vector<ll>&nums){ for(int i=0;i<nums.size();i++){ cout<<nums[i]<<' ';}}