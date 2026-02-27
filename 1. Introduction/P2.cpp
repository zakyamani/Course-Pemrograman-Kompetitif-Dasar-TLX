#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll R, C;
    cin >> R >> C;

    char blok[R][C];

    for(ll i=0; i<R; i++){
        for(ll j=0; j<C; j++){
            cin >> blok[i][j];
        }
    }

    bool sudahselesai = 0;
    bool runtuh;

    while(sudahselesai == 0){
        
        ll runtuhterendah=0;
        runtuh = 0;
        ll jumlahblok = 0;
        for(ll i=0; i<R; i++){
            jumlahblok = 0;
            for(ll j=0; j<C; j++){
                if(blok[i][j] == '1'){
                    jumlahblok++;
                    
                }
            }
            if(jumlahblok == C){
                runtuhterendah = i;
                for(ll j=0; j<C; j++){
                    blok[i][j] = '0';
                    
                }
            }
        }
        ll totalturun = 0;
        ll turun = 0;
        for(ll i=runtuhterendah; i>=0; i--){
            for(ll j=0; j<C; j++){
                turun = 0;
                if(blok[i][j] == '1'){
                    for(ll k=i+1; k<R; k++){
                        if(blok[k][j] == '0'){
                            turun++;
                            totalturun++;
                        }else{
                            break;
                        }
                    }
                    swap(blok[i][j], blok[i+turun][j]);
                }
                
            }
        }

        if(totalturun == 0){
            sudahselesai = 1;
        }
    }

    for(ll i=0; i<R; i++){
        for(ll j=0; j<C; j++){
            cout << blok[i][j];
        }
        cout<<endl;
    }




}