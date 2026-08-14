

#include <bits/stdc++.h>
#include <algorithm>

#define ll long long

using namespace std;
// ll ceil_div(ll a, ll b) {
//     return (a + b - 1) / b;
// }
// int isprime(ll a){
//     if(a==1) return 0;
   
//      for(ll i=2; i*i<=a; i++){
//         if(a%i==0){
//             return 0;
//         }
//      }
//      return 1;

// }
// int ispftsq(ll a){
//     ll b=sqrtl(a);
//     if(b*b==a) return 1;
//     else return 0;
// }

int main() {
  ll t;
  cin>>t;
  int n[t],srt[t];
  for(int i=0; i<t; i++){
    cin>>n[i];
  }
  for(int i=0; i<t; i++){
     srt[i]=n[i];
  }
  sort(srt,srt+t);
  int k; cin>>k;
   ll sum[t];
    sum[0]=n[0];
    for(int i=1; i<t; i++){
        sum[i]=sum[i-1]+n[i];
     }
      ll sumsrt[t];
    sumsrt[0]=srt[0];
    for(int i=1; i<t; i++){
        sumsrt[i]=sumsrt[i-1]+srt[i];
     }
  while(k--){
    int type; 
    cin>>type;
            int l,r;
        cin>>l>>r;
    if(type==2){
        if(l>=2) cout<<sumsrt[r-1]-sumsrt[l-2]<<endl;
        else cout<<sumsrt[r-1]<<endl;
    }
    else{
         if(l>=2) cout<<sum[r-1]-sum[l-2]<<endl;
        else cout<<sum[r-1]<<endl;
    } 
       
       
  }
}
