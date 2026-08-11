#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string koin;
    cin >> koin;
    ll num;
    char koin1, koin2;
    ll jum1 = 0, jum2 = 0;
    koin1 = koin[0];
    for(int i=0; i<koin.length(); i++){
        if(koin[i] != koin1){
            koin2 = koin[i];
            jum2++;
        }else{
            jum1++;
        }
    }
    char koinPalsu = koin2;
    if(jum1 == 1){
        koinPalsu = koin1;
    }
    for(int i=0; i<koin.length(); i++){
        if(koin[i] == koinPalsu){
            num = i + 1;
            break;
        }
    }
    cout << num << endl;
}