#include<bits/stdc++.h>
using namespace std;
#define FastIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;

int a , b;
vector<int> primes;
vector<int> adj[10000+5];
queue<int> Q;
int vis[10000+5] = {0}, len[10000+5] = {0};

bool checkdig(int a, int b){
    int diff = abs(a-b);
    if(diff<10){
        if(a/10 == b/10)return true;
        return false;
    }
    if(diff<100){
        if(diff%10==0 && a/100 == b/100)return true;
        return false;
    }
    if(diff<1000 && diff%100==0 && a/1000 == b/1000)return true;
    if(diff%1000==0){
        return true;
    }
    return false;
}
void precompute(){
    bool prime[10001];
    memset(prime, true, sizeof(prime));

    for(int i=2; i*i <10000;i++){
        if(prime[i]){
            for(int j=i*i; j < 10000; j+=i){
                prime[j] = false;
            }
        }
    }
    for(int i=2; i < 10000; i++){
        if(prime[i] && i >=1000){
            primes.push_back(i);
        }
    }
    //printf("%d",(int) primes.size());
    for(auto x:primes){
        for(auto y:primes){
            if(x==y)continue;
            if(checkdig(x,y)){
                adj[x].push_back(y);
                adj[y].push_back(x);            
            }
        }
    }
}
void BFS(int u){
    len[u] =0;
    vis[u] = 1;
    Q.push(u);
    while(!Q.empty()){
        int temp = Q.front();
        Q.pop();
        for(auto i : adj[temp]){
            if(vis[i])continue;
            vis[i] = 1;
            len[i] = len[temp] + 1;
            Q.push(i);
        }
    }
}
void solve(){ 
    scanf("%d %d", &a, &b);
    memset(len, 0, sizeof(len)); memset(vis, 0, sizeof(vis));
    BFS(a);
    printf("%d\n", len[b]);

} 





int main()
{
 
    FastIO 


    int t;
    scanf("%d", &t);
    precompute();
    while(t--){
        solve();    
    }


    return 0;
        
}
 
  




