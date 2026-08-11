#include <bits/stdc++.h>

using namespace std;

int main(){
    int N; cin >> N;
    bool mungkin = false;
    int A;
    for(int i=0; i<N; i++){
        cin >> A;
        if(A % 2 == 0){
            mungkin = true;
        }
    }
    if(mungkin){
        cout << "YA" << endl;
    }else{
        cout << "TIDAK" << endl;
    }
}