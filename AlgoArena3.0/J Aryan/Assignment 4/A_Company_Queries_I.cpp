#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pp = pair<ll,ll>;

#define ff first
#define ss second

// ll memo[502][3][1024][2];
// string s;
const ll MOD = 1e9 + 7;

// ll digit_dp(int idx, int tight,int rem, int mask, int lz){
//     if(idx==s.length()){
//         if(lz) return 0;
//         int a = rem % 3 == 0 ? 1 : 0;
//         int b = mask & 1<<3 ? 1 : 0;
//         int c = __builtin_popcount(mask)==3 ? 1 : 0;

//         if(a+b+c==1) return 1;
//         return 0;
//     }
//     if(memo[idx][rem][mask][lz]!=-1 && tight==0) return memo[idx][rem][mask][lz];

//     ll ans = 0;
//     int limit = tight ? (s[idx]-'0') : 9;

//     for(int d=0;d<=limit;d++){
//         int new_tight = (tight && d==limit) ? 1 : 0;
//         int new_lz = (lz && d==0) ? 1 : 0;
//         int new_mask = mask;
//         if(!new_lz) new_mask |= (1<<d);
//         int new_rem = (rem+d)%3;

//         ans += digit_dp(idx+1,new_tight,new_rem,new_mask,new_lz);
//         ans %= MOD;
//     }
//     if(tight==0) memo[idx][rem][mask][lz] = ans;
//     return ans;
// }

// void solve(){
//     cin>>s;
//     memset(memo,-1,sizeof(memo));
//     cout<<digit_dp(0,1,0,0,1);
// }
int pow(int n, int m, int mod){
    ll ans = 1;
    ll mul = n;
    while(m>0){
        if(m & 1) ans = (ans * mul) % mod;
        mul = (mul * mul) % mod;
        m >>= 1;
    }
    int lol = ans;
    return lol;
}

void dfs(vector<vector<int>> &adj, vector<vector<int>> &par, int u, int p){
    par[u][0] = p;
    for(int j=1;j<=22;j++){
        if(par[u][j-1]==-1 || par[par[u][j-1]][j-1] == -1) break;
        par[u][j] = par[par[u][j-1]][j-1];
    }

    for(int v : adj[u]){
        if(v==p) continue;
        dfs(adj,par,v,u);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1; 
    while(t--){
        int n,q; cin>>n>>q;
        vector<vector<int>> adj(n+1);
        for(int i=2;i<=n;i++){
            int x; cin>>x;
            adj[i].push_back(x);
            adj[x].push_back(i);
        }
        vector<vector<int>> par(n+1, vector<int> (23,-1));

        dfs(adj,par,1,-1);

        while(q--){
            int x,k; cin>>x>>k;
            for(int j=0;j<=22;j++){
                if(k & (1 << j)){ 
                    x = par[x][j];
                    if(x == -1) break;
                }
            }
            cout<<x<<'\n';
        }
    }
    return 0;
}
