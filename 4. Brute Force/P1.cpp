#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll N;
    cin >> N;

    vector <ll> digit;
    while(N > 0){
        digit.push_back(N % 10);
        N /= 10;
    }

    for(int i=0; i<digit.size()/2; i++){
        swap(digit[digit.size()-i-1], digit[i]);
    }

    ll tanda[digit.size()]; // 0 untuk +, 1 untuk -, 2 untuk merge
    for(int i=0; i<digit.size(); i++){
        tanda[i] = 0;
    }

    vector <ll> hasil;
    bool lanjut = true;
    while(lanjut){
        lanjut = false;
        tanda[0]++;
        for(int i=0; i<digit.size() - 1; i++){
            if(tanda[i] > 2){
                tanda[i] -= 3;
                tanda[i+1]++;
            }
            if(tanda[i] != 0){
                lanjut = true;
            }
        }

        ll result = 0;
        ll sementara = digit[0];
        bool tambah = true;
        
        for(int i=0; i<digit.size()-1; i++){
            if(tanda[i] == 0){
                result += sementara;
                sementara = digit[i+1];
                tambah = true;
            }else if(tanda[i] == 1){
                result += sementara;
                sementara = -digit[i+1];
                tambah = false;
            }else{
                sementara *= 10;
                if(tambah){
                    sementara += digit[i+1];
                }else{
                    sementara -= digit[i+1];
                }
                
            }
        }
        result += sementara;
        bool sama = false;
        for(int i=0; i<hasil.size(); i++){
            if(result == hasil[i]){
                sama = true;
                break;
            }
        }
        if(!sama){
            hasil.push_back(result);
        }
    }
    cout << hasil.size();
    //12345
    //12+34-5
    //-5+34+12
    //abcde
    //1020
    //edcba
    //-e+dc+b+a
    //2210
    //e

    //abcde
    //1020
    //a-b+cd+e
}
