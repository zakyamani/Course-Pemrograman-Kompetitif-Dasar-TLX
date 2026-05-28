#include <bits/stdc++.h>
#define ll long long

using namespace std;

void merge(ll H[], ll B[], ll left, ll mid, ll right){
    ll n1 = mid - left + 1;
    ll n2 = right - mid;
    
    ll LH[n1];
    ll RH[n2];
    ll LB[n1];
    ll RB[n2];

    for(ll i=0; i<n1; i++){
        LH[i] = H[left + i];
        LB[i] = B[left + i];
    }
    for(ll i=0; i<n2; i++){
        RH[i] = H[mid + 1 + i];
        RB[i] = B[mid + 1 + i];
    }

    ll i = 0;
    ll j = 0;
    ll k = left;
    
    while((i < n1) && (j < n2)){
        if(LH[i] <= RH[j]){
            H[k] = LH[i];
            B[k] = LB[i];
            i++;
        }else{
            H[k] = RH[j];
            B[k] = RB[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        H[k] = LH[i];
        B[k] = LB[i];
        i++;
        k++;
    }
    while(j < n2){
        H[k] = RH[j];
        B[k] = RB[j];
        j++;
        k++;
    }
}

void mergeSort(ll H[], ll B[], ll left, ll right){
    if(left >= right){
        return;
    }

    ll mid = left + (right - left)/2;
    mergeSort(H, B, left, mid);
    mergeSort(H, B, mid + 1, right);
    merge(H, B, left, mid, right);
}

int main(){
    ll N, D;
    cin >> N >> D;
    ll H[N], B[N];
    for(ll i=0; i<N; i++){
        cin >> H[i] >> B[i];
    }
    mergeSort(H, B, 0, N - 1);
    ll totalBebek = 0;
    for(ll i=0; i<N; i++){
        if((D/H[i] < B[i])){
            totalBebek += (D / H[i]);
            break;
        }else{
            totalBebek += B[i];
            D -= (H[i] * B[i]);
        }
    }
    cout << totalBebek;

}