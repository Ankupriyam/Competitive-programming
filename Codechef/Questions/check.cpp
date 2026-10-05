/*ncrmod*/ const int MAXN = 1e6 + 5;
ll fact[MAXN], invFact[MAXN];
ll power(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
void precompute()
{
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAXN - 1] = power(fact[MAXN - 1], MOD - 2);
    for (int i = MAXN - 2; i >= 0; i--)
    {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}
ll ncrmod(ll n, ll r)
{
    if (r < 0 || r > n)
        return 0;
    return (fact[n] * invFact[r] % MOD * invFact[n - r] % MOD) % MOD;
}
