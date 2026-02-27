#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll N;
    cin >> N;
    char pesan1_asli[N], pesan1_ubah[N], pesan2_asli[N], pesan2_ubah[N];

    for(ll i=0; i<N; i++){
        cin >> pesan1_asli[i];
    }
    for(ll i=0; i<N; i++){
        cin >> pesan1_ubah[i];
    }

    for(ll i=0; i<N; i++){
        cin >> pesan2_ubah[i];
    }

    for(ll i=0; i<N; i++){
        char huruf;
        for(ll j=0; j<N; j++){
            if(pesan2_ubah[i] == pesan1_ubah[j]){
                huruf = pesan1_asli[j];
                break;
            }else if(j == N-1){
                huruf = '?';
            }
        }
        pesan2_asli[i] = huruf;
        
    }

    bool denklekbingung = 0;
    for(ll i=0; i<N; i++){
        for(ll j=0; j<N; j++){
            if((pesan1_asli[i] == pesan1_asli[j]) && (pesan1_ubah[i] != pesan1_ubah[j])){
                denklekbingung = 1;
            }
            if((pesan1_asli[i] != pesan1_asli[j]) && (pesan1_ubah[i] == pesan1_ubah[j])){
                denklekbingung = 1;
            }
        }
    }
    if(denklekbingung == 0){
        for(ll i=0; i<N; i++){
            cout << pesan2_asli[i];
        }
        return 0;
    }

    cout << "Pak Dengklek bingung";
    

}