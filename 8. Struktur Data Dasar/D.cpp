#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    int N; cin >> N;
    ll total = 0;
    stack <int> H;
    stack <int> idx;
    idx.push(0);
    for(int i=1; i<=N; i++){
        int x; cin >> x;
        while((H.size()) && (x >= H.top())){
            H.pop();
            idx.pop();
        }
        H.push(x);
        total += (i - idx.top());
        idx.push(i);

    }

    cout << total << endl;
}