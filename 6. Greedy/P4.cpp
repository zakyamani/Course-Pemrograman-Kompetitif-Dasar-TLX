#include <bits/stdc++.h>

#define ll long long

using namespace std;

void merge(ll P[], ll C[], ll left, ll mid, ll right){
    ll n1 = mid - left + 1;
    ll n2 = right - mid;

    ll LP[n1], LC[n1], RP[n2], RC[n2];
    for(ll i=0; i<n1; i++){
        LP[i] = P[left + i];
        LC[i] = C[left + i];
    }
    for(ll i=0; i<n2; i++){
        RP[i] = P[mid + 1 + i];
        RC[i] = C[mid + 1 + i];
    }

    ll i = 0, j = 0, k = left;
    while((i < n1) && (j < n2)){
        if(LC[i] <= RC[j]){
            C[k] = LC[i];
            P[k] = LP[i];
            i++;
        }else{
            C[k] = RC[j];
            P[k] = RP[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        C[k] = LC[i];
        P[k] = LP[i];
        i++;
        k++;
    }

    while(j < n2){
        C[k] = RC[j];
        P[k] = RP[j];
        j++;
        k++;
    }
}

void mergeSort(ll P[], ll C[], ll left, ll right){
    if(left >= right){
        return;
    }

    ll mid = left - (left - right)/2;
    mergeSort(P, C, left, mid);
    mergeSort(P, C, mid+1, right);
    merge(P,C,left,mid,right);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll K;
    cin >> K;
    ll P[K], C[K];
    for(ll i=0; i<K; i++) cin >> P[i];
    for(ll i=0; i<K; i++) cin >> C[i];
    mergeSort(P, C, 0, K-1);

    ll N; cin >> N;
    ll B[N];
    for(ll i=0; i<N; i++) cin >> B[i];
    sort(B, B+N);

    ll total = 0;
    ll idx = 0;

    for(ll i=N-1; i>=0; i--){
        if(P[idx] == 0){
            idx++;
        }
        total += (C[idx] * B[i]);
        P[idx]--;
    }

    cout << total << endl;

}