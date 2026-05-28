#include <bits/stdc++.h>

using namespace std;

void merge(int S[], int D[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int LS[n1], RS[n2], LD[n1], RD[n2];

    for(int i=0; i<n1; i++){
        LS[i] = S[left + i];
        LD[i] = D[left + i];
    }
    for(int i=0; i<n2; i++){
        RS[i] = S[mid + 1 + i];
        RD[i] = D[mid + 1 + i];
    }

    int i=0;
    int j=0;
    int k=left;

    while((i < n1) && (j < n2)){
        if(LD[i] <= RD[j]){
            D[k] = LD[i];
            S[k] = LS[i];
            i++;
        }else{
            D[k] = RD[j];
            S[k] = RS[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        D[k] = LD[i];
        S[k] = LS[i];
        k++;
        i++;
    }

    while(j < n2){
        D[k] = RD[j];
        S[k] = RS[j];
        k++;
        j++;
    }
}

void mergeSort(int S[], int D[], int left, int right){
    if(left >= right){
        return;
    }

    int mid = left - (left - right)/2;
    mergeSort(S,D,left, mid);
    mergeSort(S,D,mid+1, right);
    merge(S,D,left, mid, right);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;

    int S[N], D[N];
    for(int i=0; i<N; i++){
        cin >> S[i] >> D[i];
        D[i] += S[i];
    }
    mergeSort(S, D, 0, N-1);

    int total = 0;
    int waktuSekarang = -1;

    for(int i=0; i<N; i++){
        if(S[i] >= waktuSekarang){
            waktuSekarang = D[i];
            total++;
        }
    }
    cout << total << endl;



}