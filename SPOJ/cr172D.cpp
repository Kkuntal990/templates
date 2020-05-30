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



ll n;
const int MAXN = 1e6 +6;
ll inp[MAXN] = {0},riMax[MAXN] = {0}, leMax[MAXN] = {0};
stack<ll> mx;


void solve(){

    ll ans = 0;

    FOR(i,0, n){
        riMax[i] = i;
        while(!mx.empty() && inp[mx.top()] < inp[i]){
            riMax[mx.top()] = i;
            mx.pop();
        }
        leMax[i] = (!mx.empty())?mx.top():-1;
        mx.push(i);
    }
    while(!mx.empty()){
        riMax[mx.top()] = n;
        mx.pop();
    }
    FOR(i,0,n){
        ans = max3(ans,(riMax[i]!=n)?inp[i]^inp[riMax[i]]:0, (leMax[i]!=-1)?inp[i]^inp[leMax[i]]:0);
    }

    cout << ans << endl;
} 
 
int main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
 
    cin >> n;
    repc(i,n){
        cin >> inp[i];
    }
    solve();
 
    return 0;
 
 
}
