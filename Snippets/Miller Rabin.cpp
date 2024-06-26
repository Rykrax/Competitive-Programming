ll mul(ll a, ll b, ll m) {
    ll res = 0;
    while(b) {
        if (b&1) res = (res+a) % m;
        a = (2*a) % m;
        b >>= 1;
    }
    return res;
}
 
ll binpow(ll a, ll b, ll m) {
    ll res = 1;
    while(b) {
        if (b&1) res = mul(res,a,m);
        a = mul(a,a,m);
        b >>= 1;
    }
    return res;
}
 
bool check(ll n, ll a, ll d, int s) {
    ll x = binpow(a,d,n);
    if (x == 1 || x == n-1) return false;
    for (int i=1; i<s; i++) {
        x = mul(x,x,n);
        if (x == n-1) return false;
    }
    return true;
}
 
bool miller_rabin(ll n) {
    if (n<4) return (n==2 || n==3);
    int s = 0;
    ll d = n-1;
    while((d&1) == 0) {
        d >>= 1;
        s++;
    }
 
    vector<int> v = {2,3,5,7,11,13,17,19,23,29,31,37};
    for (int a : v) {
        if (n==a) return true;
        if (check(n,a,d,s)) return false;
    }
    return true;
}
