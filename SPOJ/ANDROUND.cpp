#include<bits/stdc++.h>
#define clr(a) memset(a, 0, sizeof(a))
#define sz(x) x.size()
#define rep(n) for (ll i = 0; i < n; i++)
#define repc(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, x, y) for (ll i = x; i < y; i++)
#define DEC(i, x, y) for (ll i = x; i >= y; i--)
#define all(v) v.begin(), v.end()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define alla(a, n) a, a + n
 
using namespace std;
 
// Some typedef's
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
 
template <typename T>
T modpow(T base, T exp, T modulus) {
  base %= modulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}
 
ll lcm(ll a, ll b) { return (a * (b / __gcd(a, b))); }
 
// Some contants
const ll inf = 1e12 + 7;
const double eps = 1e-9;
const double pi = 1.00 * acos(-1.00);

ll op(ll lc ,ll rc){

    return (lc&rc);

}


void init(ll * tree, ll arr[], ll s, ll e, ll idx){


    if (s == e){
        tree[idx] = arr[s];
        return;
    }

    ll m = (s+e)/2;

    init(tree, arr, s, m, 2*idx);
    init(tree, arr, m+1, e, 2*idx+1);

    tree[idx] = op(tree[2*idx], tree[2*idx+1]);


}


ll * con(ll arr[], ll n){

    ll x = (ll)(ceil(log2(n)));
    ll MAXN = 2*pow(2,x) -1;

    ll * tree = new ll[MAXN];

    init(tree, arr, 0, n-1, 1);
    return tree;

}



ll query(ll* tree, ll ss, ll se, ll qs, ll qe, ll idx){

    if (qe < ss || se < qs ){
    
        return -1;
    }

    if (qe >= se && qs <=ss){
        
        return tree[idx];
    
    }

    ll mid = (se + ss)/2;
    
    ll left = query(tree, ss, mid, qs, qe, 2*idx);
    ll right = query(tree, mid+1, se, qs, qe, 2*idx+1);
    

    
    ll ans = op(left,right);

    return ans;

}





int main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
   
    ll t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        ll arr[n];
        repc(i, n){
            cin >> arr[i];
        
        }
        ll * tree = con(arr, n);

        k = min(k,n-1);

        for(ll i = 0; i < n; i++) {
			ll s = (i - k + n) % n;
			ll e = (i + k) % n;
			ll res = -1;
			if(s < i) res &= query(tree , 0, n - 1, s, i, 1);
			else res &= query(tree, 0, n - 1, 0, i,1) & query(tree, 0, n - 1, s, n - 1, 1);
			if(e > i) res &= query(tree, 0, n - 1, i, e, 1);
			else res &= query(tree, 0, n - 1, i, n - 1, 1) & query(tree, 0, n - 1, 0, e, 1);
			if(i) printf(" "); printf("%lld", res);
		}
		printf("\n");
    }
   
    return 0;
 
 
}
 
 
 

