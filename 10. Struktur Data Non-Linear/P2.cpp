#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N, P, Q;
vector<pair<ll, ll>> bebek;

ll searchEgo(ll X){
    ll left = 0;
    ll right = N-1;
    ll mid;
    while(left <= right){
        mid = left + (right - left)/2;
        if(bebek[mid].first > X){
            right = mid - 1;
        }else if(bebek[mid].first < X){
            left = mid + 1;
        }else{
            break;
        }
    }
    while((mid < N-1) && (bebek[mid].first <= X)){
        mid++;
    }
    while((mid > 0) && (bebek[mid].first > X)){
        mid--;
    }
    return mid;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> P >> Q;
    for(int i=0; i<N; i++){
        ll E;
        cin >> E;
        bebek.push_back({E, i+1});
    }
    sort(bebek.begin(), bebek.end());
    ll posisi[N+1];
    for(int i=0; i<N; i++){
        posisi[bebek[i].second] = i;
    }
    vector<ll> banyakBebek(N);
    for(int i=0; i<N; i++){
        ll kiri = i;
        ll kanan = searchEgo(bebek[kiri].first + P);
        while((kanan < N-1) && (bebek[kanan].first == bebek[kanan + 1].first)){
            kanan++;
        }
        banyakBebek[i] = kanan - kiri + 1;
    }
    while(Q--){
        ll X; cin >> X;
        ll maxTotal = -1;
        ll idxX = posisi[X];
        ll kiri = searchEgo(bebek[idxX].first - P);
        while(kiri <= idxX){
            maxTotal = max(maxTotal, banyakBebek[kiri]);
            kiri++;
        }
        cout << maxTotal << endl;
    }
}