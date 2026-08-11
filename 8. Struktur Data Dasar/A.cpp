#include <bits/stdc++.h>

using namespace std;

int main(){
    vector <vector<int>> arr(2,vector<int>(1,-1));
    int Q; cin >> Q;
    while(Q--){
        string q; cin >> q;
        if(q == "add"){
            int L, X, Y; cin >> L >> X >> Y;
            if(arr[L].size() == 0){
                arr[L].push_back(-1);
            }
            while(Y--){
                arr[L].push_back(X);
            }
        }else if(q == "out"){
            int L, Z; cin >> L >> Z;
            cout << arr[L][Z] << endl;
        }else{
            arr.resize(arr.size() + 1);
        }
    }
}