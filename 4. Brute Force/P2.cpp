#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll M;
    cin >> M;
    ll bebek[M+1];
    for(int i=1; i<=M; i++) cin >> bebek[i];
    sort(bebek+1, bebek + M+1);
    ll N; cin >> N;
    ll anggota = M/N;
    ll batas[N+1];
    batas[0] = 0;
    batas[N] = M;
    for(int i=1; i<N; i++){
        batas[i] = batas[i-1] + anggota;
    }
    bool lanjut = true;
    while(lanjut){
        lanjut = false;
        for(int i=N-1; i>=1; i--){
            if((batas[i+1] - batas[i] > anggota + 1) || (batas[i] - batas[i-1] < anggota) || (bebek[batas[i]] == bebek[batas[i]+1])){
                batas[i]++;
                lanjut = true;
            }
        }
    }
    for(int i=1; i<N; i++){
        cout << bebek[batas[i]] + 1 << " ";
    }
}
