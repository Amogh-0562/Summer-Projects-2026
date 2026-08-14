

#include <bits/stdc++.h>
#include <algorithm>

#define ll long long

using namespace std;
// ll ceil_div(ll a, ll b) {
//     return (a + b - 1) / b;
// }
int isprime(ll a){
    if(a==1) return 0;
    // int org=a;
    // int k=0;
    // a--;
    //  while(k==0){
    //     a++;
    //     k=ispftsq(a);
    //  }
    //  int t=sqrt(a);
     for(ll i=2; i*i<=a; i++){
        if(a%i==0){
            return 0;
        }
     }
     return 1;

}
int ispftsq(ll a){
    ll b=sqrtl(a);
    if(b*b==a) return 1;
    else return 0;
}

int main() {
  ll t;
  cin>>t;
  while(t--){
    ll n;
    cin>>n;
    if(ispftsq(n)){
        ll ar=sqrtl(n);
        if(ar==1){ cout<<"NO"<<endl;continue;}
        if(isprime(ar)){
            cout<<"YES"<<endl;
            continue;
        }
        else{
            cout<<"NO"<<endl;
            continue;
        } 
    }
    else cout<<"NO"<<endl;
  }
}
