#include <iostream>
#include <algorithm>


using namespace std;



int main(){
    int N;
    cin>>N;
    
    int D[N];
    for(int i=0; i<N; i++){
        cin>>D[i];
    }

    int num=1;
    int keterangan=0;
    
    while(keterangan<N){
    keterangan=0;    
    for(int i=0; i<N; i++){
        if(num%D[i]==0){
            keterangan++;
        }
    }
    num++;
    }

    cout<<num-1;
    
}