#include <bits/stdc++.h>
#define ll long long

using namespace std;

void cetak(ll tombol[], ll K){
    for(ll i = 0; i<K; i++){
        cout << tombol[i]<< " ";
    }
    cout << endl;
}

int main(){
    ll N,K;
    cin >> N >> K;

    ll tombol[K];
    for(ll i=0; i<K; i++){
        tombol[i] = i + 1;
    }// 1 2

    bool kelar = false;
    bool lanjut = true;
    ll kedalaman = K - 1; 
    while(!kelar){
        kelar = true;
        ll nilaiakhir = N;
        for(int i=K-1; i>=0; i--){
            if(tombol[i] != nilaiakhir){
                kelar = false;
            }
            nilaiakhir--;
        }
        
        while(lanjut){
            cetak(tombol, K);
            tombol[kedalaman]++;
            if((kedalaman == K-1) && (tombol[kedalaman] > N)){
                lanjut = false;
            }
        }
        if(N == K){
            break;
        }
        tombol[kedalaman]--;
        ll bisageser;
        if(K == 1){
            break;
        }
        for(ll i=K-2; i>=0; i--){
            if(tombol[i] != tombol[i+1] - 1){
                bisageser = i;
                break;
            }
        }
        //cout << "debug: " << bisageser << endl;
        //cout <<"debug: " << tombol[0]<< " " << tombol[1]<< " "<< tombol[2] << endl;
        tombol[bisageser]++;
        for(ll i=bisageser + 1; i<K; i++){
            tombol[i] = tombol[i-1] + 1;
        }
        lanjut = true;
        
    }
    //cout << "debug: " << tombol[0]<< " " << tombol[1]<< " "<< tombol[2] << endl;
    
}
