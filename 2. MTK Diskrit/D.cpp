#include <iostream>

using namespace std;

int main(){
    long long A,B,C,D;
    
    cin>>A>>B;
    cin>>C>>D;
    
    long long E = A*D+C*B;
    long long F = B*D;

// CARI FPB
    long long terbesar = E;
    long long terkecil = F;
    if(E<F){
        terbesar = F;
        terkecil = E;
    }
    
    while(terbesar>0 && terkecil>0){
        while(terbesar>0){
        terbesar = terbesar - terkecil;
        if(terbesar<0){
            terbesar = terbesar +terkecil;
            break;
        }
        }
        long long sementara = terbesar;
        terbesar = terkecil;
        terkecil = sementara;
        
    }
    long long gcd = terbesar;

    E = E/gcd;
    F = F/gcd;

    cout<<E<<" "<<F;

    
}