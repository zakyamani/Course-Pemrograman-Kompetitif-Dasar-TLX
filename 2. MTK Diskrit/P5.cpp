#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll B,C,D;
    ll kemungkinan = 0;

    cin >> B >> C >> D;

    ll blyat = 2 * floor(sqrt(C-D)) + 1;
    ll faktor[blyat];
    ll faktor_ke = 1;

    if((C-D == 0) && (B > C)){
        cout << B-C;
        return 0;
    }

    for(ll i=1; (i<=sqrt(C-D) && i<=B); i++){
        if((C-D) % i == 0){
            faktor[faktor_ke] = i;
            faktor_ke++;
        }
    }
    ll jumlah_faktor_sementara = faktor_ke - 1;

    for(ll i=1; i<=jumlah_faktor_sementara; i++){
        if((((C-D)/faktor[i]) != faktor[i]) && ((C-D)/faktor[i] <= B)){
            faktor[faktor_ke] = (C-D)/faktor[i];
            faktor_ke++;
        }
        
    }

    jumlah_faktor_sementara = faktor_ke - 1;
    ll jumlah_akhir = 0;

    for(ll i=1; i<=jumlah_faktor_sementara; i++){
        if((faktor[i] > D)){
            jumlah_akhir++;
        }
    }

    cout << jumlah_akhir;

}