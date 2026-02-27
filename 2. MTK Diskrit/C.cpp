#include <bits/stdc++.h>
#define ll long long


using namespace std;

int main(){
    ll T; cin>>T;
    ll K[T+1];
    ll maxK = 0;
    for(ll i=1; i<=T; i++){
        cin>>K[i];
        if(maxK < K[i]){
            maxK = K[i];
        }
    }
    ll prima[maxK + 1];
    prima[1] = 2;
    prima[2] = 3;
    
    ll prima_ke = 3;
    bool apakah_prima;
    ll num = 5;
    
    while(prima_ke <= maxK){
        apakah_prima = 1;
        for(ll i = 1; prima[i] <= sqrt(num); i++){
            if(num % prima[i] == 0){
                apakah_prima = 0;
                break;
            }
        }
        if(apakah_prima == 1){
            prima[prima_ke] = num;
            prima_ke++;
        }
        num+=2;
    }
    
    for(ll i=1; i<=T; i++){
        cout<<prima[K[i]]<<endl;
    }
    
}