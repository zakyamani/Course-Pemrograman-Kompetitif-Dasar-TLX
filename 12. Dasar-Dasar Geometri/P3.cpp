#include <bits/stdc++.h>

using namespace std;

int main(){
    int A,B,C;
    cin >> A >> B >> C;
    int sisiMax = max(A,B);
    sisiMax = max(sisiMax, C);
    if((A+B+C - sisiMax) > sisiMax){
        cout << 0;
    }else{
        cout << sisiMax - (A+B+C - sisiMax) + 1;
    }
}