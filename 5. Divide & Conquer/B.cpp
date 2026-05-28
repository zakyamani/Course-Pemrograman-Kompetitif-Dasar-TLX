#include <bits/stdc++.h>
#define ll long long

using namespace std;

void merge(ll A[], ll left, ll mid, ll right, ll &total){
    ll n1 = mid - left + 1;
    ll n2 = right - mid;

    ll L[n1];
    ll R[n2];

    for(ll i=0; i < n1; i++){
        L[i] = A[left + i];
    }
    for(ll i=0; i<n2; i++){
        R[i] = A[mid + 1 + i];
    }

    ll i=0;
    ll j=0;
    ll k = left;

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
            total += (n1 - i);
        }
        k++;
    }
    while(i < n1){
        A[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        A[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(ll A[], ll left, ll right, ll &total){
    if(left >= right){
        return;
    }

    ll mid = (left + right)/2;
    mergeSort(A, left, mid, total);
    mergeSort(A, mid + 1, right, total);
    merge(A, left, mid, right, total);
}

int main(){
    ll N;
    cin >> N;
    ll A[N];
    for(ll i=0; i<N; i++){
        cin >> A[i];
    }
    ll total = 0;
    mergeSort(A, 0, N-1, total);
    cout << total;
}