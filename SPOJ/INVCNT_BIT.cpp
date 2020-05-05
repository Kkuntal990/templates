#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
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
typedef vector<int> vi;
typedef vector<ll> vlli;
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

const ll MAXA = 1<<20;
vlli arr(MAXA), inp(200000) , fake(200000);
map<ll, ll> M;
 
ll read(ll idx){
    ll sum = 0;
    while(idx > 0){
        sum+=arr[idx];
        idx -= (idx & -idx);
 
    }
 
    return sum;
 
}
 
 
void update(ll idx, ll value, ll n){
 
    while(idx <= n){
        arr[idx] += value;
        idx += (idx & - idx);
 
    }
 
}
 
 
int main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
 
    ll t, n;   
    cin >> t;
    while(t--){
    	cin >> n;
        inp.clear();
        arr.clear(); fake.clear();
        arr.assign(n, 0);
        M.clear();
        ll tmp;
        repc(i,n){
            cin >> tmp;
            inp.pb(tmp);
            fake.pb(tmp);
        }
        sort(all(fake));
        ii tmp2;
        for(int j = 0; j < n; j++){
        	tmp2 = mp(fake[j], j);
        	M.insert(tmp2);
 
        }
        
        ll cnt = 0;
        //cout << inp[0] << endl;
        for(int i = n-1; i>=0; i--){
        //    cout << inp[i] << endl;
      //      cout << "here " << endl;
    		ll pos = M.find(inp[i])->second;
            ll tmp1 = read(pos);
            cnt += tmp1;
            update(pos+1, 1, n);
        }
 
        cout << cnt << endl;
 
    }
 
    return 0;
 
 
}
 
  


