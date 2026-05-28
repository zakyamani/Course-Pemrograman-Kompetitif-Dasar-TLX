#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    char S1[N];
    int gunting1 = 0;
    int batu1 = 0;
    int kertas1 = 0;
    for(int i=0; i<N; i++){
        cin >> S1[i];
        if(S1[i] == 'G'){
            gunting1++;
        }else if(S1[i] == 'B'){
            batu1++;
        }else{
            kertas1++;
        }
    }
    char S2[N];
    int gunting2 = 0;
    int batu2 = 0;
    int kertas2 = 0;
    for(int i=0; i<N; i++){
        cin >> S2[i];
        if(S2[i] == 'G'){
            gunting2++;
        }else if(S2[i] == 'B'){
            batu2++;
        }else{
            kertas2++;
        }
    }

    int hasil = min(gunting1, kertas2) + min(batu1, gunting2) + min(kertas1, batu2);
    cout << hasil;


}