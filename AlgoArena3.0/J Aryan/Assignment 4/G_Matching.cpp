#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pp = pair<ll,ll>;

#define ff first
#define ss second

const ll MOD = 1e9 + 7;

// ll memo[502][3][1024][2];
// string s;

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

// struct FenwickTree{
//     vector<ll> bit;
//     int n;

//     FenwickTree(int n) {
//         this->n = n;
//         bit.assign(n + 1, 0);
//     }

//     void add(int i, ll val) {
//         for (; i <= n; i += i & -i) bit[i] += val;
//     }

//     ll query(int i) {
//         ll sum = 0;
//         for (; i > 0; i -= i & -i) sum += bit[i];
//         return sum;
//     }

//     ll query(int L, int R) {
//         return query(R) - query(L - 1);
//     }
// };

void dfs1(vector<vector<int>> &adj, vector<bool> &vis, stack<int> &st, int u){
    vis[u] = true;

    for(int v : adj[u]){
        if(!vis[v]) dfs1(adj,vis,st,v);
    }

    st.push(u);
}

void dfs2(vector<vector<int>> &adj, vector<bool> &vis, vector<ll> &cost, int u, ll &id, ll &mcost){
    vis[u] = true;
    if(cost[u] < mcost){
        id=1;
        mcost = cost[u];
    }
    else if(cost[u] == mcost) id++;

    for(int v : adj[u]){
        if(!vis[v]) dfs2(adj,vis,cost,v,id,mcost);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1; 
    while(t--){
        int n; cin>>n;
        vector<vector<int>> a(n, vector<int> (n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        vector<ll> dp(1<<n,0);
        dp[0] = 1;

        for(int mask = 1; mask < (1<<n); mask++){
            int i = __builtin_popcount(mask)-1;
            for(int j=0;j<n;j++){
                if((mask & (1<<j)) && a[i][j]){
                    int prev = mask ^ (1<<j);
                    dp[mask] = (dp[mask] + dp[prev]) % MOD;
                }
            }
        }
        cout<<dp[(1<<n)-1] % MOD<<'\n';
    }
    return 0;
}
