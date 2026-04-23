#include <bits/stdc++.h>
#define ll long long 

using namespace std;

void cetak(ll num[], ll N){
    for(ll i=0; i<N; i++){
        cout << num[i];
    }
    cout << endl;
}

bool zigzag(ll num[], ll N){
    bool result = true;
    for(ll i=1; i<=N-2; i++){
        if(((num[i] >= num[i-1])||(num[i] >= num[i+1])) && ((num[i] <= num[i-1])||(num[i] <= num[i+1]))){
            result = false;
        }
    }
    return result;
}

int main(){
    ll N;
    cin >> N;
    ll num[N];
    for(ll i=0; i<N; i++){
        num[i] = i+1;
    }

    bool kelar = false;
    //ll total = 0;
    ll kedalaman = N - 2;
    while(!kelar){
        if(kedalaman == N - 2){
            //total++;
            //cout <<"debug: " << zigzag(num, N) << endl;
            if(zigzag(num, N)){
                cetak(num, N);
            }
            
        }
        
        kelar = true;
        for(ll i=0; i<N; i++){
            if(num[i] != N-i){
                kelar = false;
            }
        }
        ll terkecil = N + 1;
        ll idx_terkecil;
        for(ll i=kedalaman + 1; i<N; i++){
            if((num[i] > num[kedalaman]) && (num[i] < terkecil)){
                terkecil = num[i];
                idx_terkecil = i;
            }
        }
        if(terkecil != (N+1)){
            swap(num[kedalaman], num[idx_terkecil]);
            sort(num + kedalaman + 1, num+N);
            if(kedalaman != N-2){
                kedalaman = N-2;
            }
        }else{
            kedalaman--;
        }

    }
    //cout << total;
}

/*
12345
12354
12435
12453
12534
12543
13245
*/
