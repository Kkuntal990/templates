#include<bits/stdc++.h>
using namespace std;
#define FastIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;

int n, mn;
const int MAXN = 1005;
int inp[MAXN] = {0}, vis[MAXN]={0};
vector<int> cy;
map<int, int> M;
vector<int> s;
vector<vector<int>> cycles;

int go(vector<int> &v){
    int sum = 0;
    if(v.size()==1)return 0;
    int currMn = *min_element(v.begin(), v.end());
    //printf("%d\n", (int)v.size());
    for(int i=0; i < v.size(); i++){
        sum += v[i];
        //cout << v[i] << endl;
    }
    sum+= (v.size()-2)*currMn;
    if(currMn>mn){

        sum = min(sum, sum - (currMn-mn)*((int)v.size()-1)+2*(currMn + mn));
    }
    return sum;
}
int t;
void solve(){ 
    int cnt = 0;
    for(int i=1; i <= n; i++){
        if(vis[i])continue;
        int temp = inp[i];
        vis[i] = 1;
        cy.clear();
        while(true){
            //cout << temp << endl;
            cy.push_back(temp);
            if(vis[M[temp]])break;
            //cout << temp << endl;
            vis[M[temp]]=1;
            temp = inp[M[temp]];
            
            //cout << "hi\n";
        }
        cnt += go(cy);
    }
    printf("Case %d: %d\n",t, cnt);
    printf("\n");
} 





int main()
{
 
    FastIO 

    t = 0;
    while(true){
        t++;
        mn = MAXN;
        scanf("%d", &n);
        if(n==0)break;
        M.clear();
        s.clear();
        memset(inp, 0, sizeof(inp)); memset(vis, 0, sizeof(vis));
        for(int i =1; i <= n; i++){
            scanf("%d", inp+i);
            s.push_back(inp[i]);
            mn = min(mn, inp[i]);
        }
        sort(s.begin(), s.end());
        for(int i =0; i < s.size(); i++){
            M[s[i]] = i+1;
        }
        solve();
    }
    


    return 0;
        
}
 
  




