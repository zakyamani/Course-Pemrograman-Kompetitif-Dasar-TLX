#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    int N; cin >> N;
    ll x[N], y[N];
    for(int i=0; i<N; i++){
        cin >> x[i] >> y[i];
    }
    ll defMin = LLONG_MAX; 
    ll min = defMin;
    bool ada = false;

    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            for(int k=j+1; k<N; k++){
                ll firstCount = x[i] * y[j] + x[j] * y[k] + x[k] * y[i];
                ll secCount = y[i] * x[j] + y[j] * x[k] + y[k] * x[i];
                ll res;
                if(firstCount > secCount){
                    res = (firstCount - secCount);
                }else{
                    res = (secCount - firstCount);
                }
                if((min > res) && (res > 0)){
                    min = res;
                    ada = true;
                }else if(min == res){
                    ada = false;
                }
            }
        }
    }
    double res = (double)min/2;
    if(!ada){
        res = -1;
    }
    cout << fixed << setprecision(2) << res << endl;
}