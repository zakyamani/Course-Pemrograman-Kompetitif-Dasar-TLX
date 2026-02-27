#include <bits/stdc++.h>
#define ll long long


using namespace std;

int main(){
    ll N; cin>>N;
    
    ll prima[1000000];
    prima[1] = 2;
    prima[2] = 3;
    
    ll prima_ke = 3;
    bool apakah_prima;
    ll num = 5;
    
    while(num <= N){
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
    
    ll i = 1;
    
    while(i < prima_ke){
        int pangkat = 0;
        
        while(N % prima[i] == 0){
            pangkat++;
            N /= prima[i];
        }
        if(N == 1){
            if(pangkat == 1){
                cout << prima[i];
            }else if(pangkat > 1){
                cout << prima[i] << "^" << pangkat;
            }
        }else{
            if(pangkat == 1){
                cout << prima[i] << " x ";
            }else if(pangkat > 1){
                cout << prima[i] << "^" << pangkat << " x ";
            }
        }
        i++;
    }
    
    if(N > 1){
        cout<<N;
    }
    
}