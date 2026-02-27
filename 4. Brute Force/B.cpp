#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll N, K;
    cin >> N >> K;
    ll kunci[K+2];
    ll min[K+1];
    ll total = 0;
    for(ll i=1; i<=K; i++){
        kunci[i] = i;
        min[i] = i;
        total += kunci[i];
    }
    kunci[K+1] = N+1;

    
    ll total_max = 0;
    for(ll i=N; i>N-K; i--){
        total_max+=i;
    }


    ll indeks = K;
    
    
    while(total < total_max){
        cout<<indeks<< " bhap "<< min[indeks] << " " << kunci[indeks+1]<< endl;
        for(ll i=min[indeks]; i<kunci[indeks+1]; i++){
            kunci[indeks] = i;
            for(ll j=1; j<=K; j++){
                cout << kunci[j] <<" ";
            }
            cout << endl;
        }
        min[indeks]++;
        if(indeks == K){
            indeks--;
        }else{
            if(kunci[indeks])
        }
        min[indeks]++;
        for(ll i=1; i<=K; i++){
            kunci[i] = min[i];
        }
        total = 0;
        for(ll i=1; i<=K; i++){
            total += kunci[i];
        }
    }



}