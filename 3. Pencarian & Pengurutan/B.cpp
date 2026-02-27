#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin>>N;
    int num[N];

    for(int i = 0; i<N; i++){
        cin >> num[i];
    }

    
    int ftable[101];

    for(int i=1; i<101; i++){ //bikin semua frekuensi jadi 0
        ftable[i] = 0;
    }
    
    for(int i=0; i<N; i++){ //ngisi frekuensi setiap numnya
        ftable[num[i]]++;
    }
    double sorted[N];
    int index = 0;

    for(int i = 1; i < 101; i++){
        for(int j=1; j<=ftable[i]; j++){
            sorted[index] = i;
            index++;
        }
    }

    double median;
    cout<<fixed<<setprecision(1);

    if(N%2 == 0){
        median = (sorted[(N/2)-1] + sorted[N/2])/2;
    }else{
        median = sorted[(N-1)/2];
    }
    cout<<median;





}