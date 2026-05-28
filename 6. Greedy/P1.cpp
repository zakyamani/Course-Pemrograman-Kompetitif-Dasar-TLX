#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    ll bebek[N];
    ll sepatu[M];
    ll jumlahSepatu[10001];
    ll jumlahBebek[10001];
    for(int i=0; i<=10000; i++){
        jumlahSepatu[i] = 0;
        jumlahBebek[i] = 0;
    }
    for(int i=0; i<N; i++){
        cin >> bebek[i];
        jumlahBebek[bebek[i]]++;
    }
    for(int i=0; i<M; i++){
        cin >> sepatu[i];
        jumlahSepatu[sepatu[i]]++;
    }

    ll hasil = 0;

    for(int i=10000; i>0; i--){
        int subs = min(jumlahBebek[i], jumlahSepatu[i]);
        hasil += subs;
        jumlahBebek[i] -= subs;
        jumlahSepatu[i] -= subs;
        if(i > 1){
            subs = min(jumlahBebek[i-1], jumlahSepatu[i]);
            hasil += subs;
            jumlahBebek[i-1] -= subs;
            jumlahSepatu[i] -= subs;
        }
    }

    cout << hasil << endl;
    
}