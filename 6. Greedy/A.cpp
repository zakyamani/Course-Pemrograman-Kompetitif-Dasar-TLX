#include <bits/stdc++.h>
#define ll long long 

using namespace std;

int main(){
    ll N, B;
    cin >> N >> B;
    ll bebek[10001];
    for(ll i=0; i<=10000; i++){
        bebek[i] = 0;
    }
    ll H;
    for(ll i=0; i<N; i++){
        cin >> H;
        bebek[H]++;
    }
    ll totalBerat = 0;
    ll totalBebek = 0;
    ll beratSekarang = 10000;
    while(totalBerat < B){
        if(bebek[beratSekarang] > 0){
            totalBerat += beratSekarang;
            totalBebek++;
            bebek[beratSekarang]--;
        }else{
            beratSekarang--;
        }
    }
    cout << totalBebek;
}