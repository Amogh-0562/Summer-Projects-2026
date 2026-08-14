

#include <bits/stdc++.h>
#include <algorithm>

#define ll long long

using namespace std;
ll cc(ll n){
    return n*(n-1)/2;
}
int main(){
    int t;
    cin>>t; 
    while(t--){
        int n; cin>>n;
        int ar[n];
        for(int i=0; i<n;i ++){
            char c;
            cin>>c;
           
            ar[i]=c-'0';
        } 
        ll pre[n],mat[n+1];
        mat[0]=0;
        pre[0]=ar[0];
        if(n==1){
            if(ar[0]==1) cout<<n<<endl;
            else cout<<n-1<<endl; 
            continue;        }
        for(int i=1; i<n;i++) pre[i]=pre[i-1]+ar[i];
        for(int i=1; i<=n;i++) mat[i]=pre[i-1]-i;
        map<ll,ll> m;
        for(int i=0; i<=n;i++) m[mat[i]]+=1;
        // if(mat[1]!=0)  m[mat[0]]+=1;
        ll ans=0;
        for(auto &x : m){
            if(x.second>1){
                ans+=cc(x.second);
              
            }
        }
        cout<<ans<<endl;
    }
}