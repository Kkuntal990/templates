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


struct Node{

    ll pre, suf, tot, sub;

    Node(){
    
        pre=suf=tot=sub= -inf;
    
    }


};

Node Merge(Node lchild,Node rchild){

    Node parent;

    parent.pre = max(lchild.pre, lchild.tot+ rchild.pre);
    parent.tot = lchild.tot + rchild.tot;
    parent.suf = max(rchild.suf, lchild.suf + rchild.tot);
    parent.sub = max3(rchild.sub, lchild.sub, rchild.pre + lchild.suf);

    return parent;
}



void init(Node * tree, ll start, ll end, ll arr[], ll index){


    if (start == end){
        
        tree[index].tot = arr[start];
        tree[index].pre = arr[start];
    
        tree[index].sub = arr[start];

        tree[index].suf = arr[start];
        return;
    }


    ll mid = (start + end)/2;

    init(tree, start, mid, arr, 2*index);
    init(tree, mid+1, end, arr, 2*index+1);
    tree[index] = Merge(tree[2*index], tree[2*index+1]);

}


Node * construcTree(ll arr[], ll n){

    ll x = (ll)(ceil(log2(n)));

    ll max_size = 2*(ll)pow(2,x) - 1;

    Node * tree = new Node[max_size];
    init(tree, 0, n-1, arr, 1);

    return tree;
}



Node queryUtil(Node* tree, ll ss, ll se, ll qs, ll qe, ll idx){

    if (qe < ss || se < qs ){
    
        Node nullnode;
        return nullnode;
    }

    if (qe >= se && qs <=ss){
        
        return tree[idx];
    
    }

    ll mid = (se + ss)/2;
    
    Node left = queryUtil(tree, ss, mid, qs, qe, 2*idx);
    Node right = queryUtil(tree, mid+1, se, qs, qe, 2*idx+1);
    Node parent = Merge(left, right);

    return parent;

}


ll query(Node* tree, ll start, ll end, ll n){
    Node ans = queryUtil(tree, 0, n-1, start, end, 1);
    return ans.sub;

}



int main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin >> n;

    ll arr[n];
    repc(i, n){
        cin >> arr[i];
    
    }

    Node* tree = construcTree(arr, n);
    ll m, s, e; cin >> m;
    while(m--){
        cin >> s >> e;
        cout <<  query(tree, s, e, n) << endl;
    
    }
    
    
    
    return 0;
 
 
}
 
 
 

