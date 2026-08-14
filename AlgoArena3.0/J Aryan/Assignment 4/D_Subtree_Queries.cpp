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

struct FenwickTree{
    vector<ll> bit;
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void add(int i, ll val) {
        for (; i <= n; i += i & -i) bit[i] += val;
    }

    ll query(int i) {
        ll sum = 0;
        for (; i > 0; i -= i & -i) sum += bit[i];
        return sum;
    }

    ll query(int L, int R) {
        return query(R) - query(L - 1);
    }
};

int timer = 0;

void dfs(vector<vector<int>> &adj, vector<int> &in, vector<int> &out, int u, int p){
    timer++;
    in[u] = timer;
    
    for(int v : adj[u]){
        if(v==p) continue;
        dfs(adj,in,out,v,u);
    }
    out[u] = timer;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1; 
    while(t--){
        int n,q; cin>>n>>q;
        vector<vector<int>> adj(n+1);
        vector<ll> value(n+1,0);
        for(int i=1;i<=n;i++) cin>>value[i];
        for(int i=2;i<=n;i++){
            int x,y; cin>>x>>y;
            adj[y].push_back(x);
            adj[x].push_back(y);
        }
        vector<int> in(n+1,0);
        vector<int> out(n+1,0);

        dfs(adj,in,out,1,-1);

        FenwickTree one(n);
        for(int i=1;i<=n;i++){
            one.add(in[i],value[i]);
        }


        while(q--){
            int type,s; cin>>type>>s;
            if(type==1){
                ll x; cin>>x;
                ll val = x - value[s];
                one.add(in[s],val);
                value[s] = x;
            }
            else{
                cout<<one.query(in[s],out[s])<<'\n';
            }
        }
    }
    return 0;
}
