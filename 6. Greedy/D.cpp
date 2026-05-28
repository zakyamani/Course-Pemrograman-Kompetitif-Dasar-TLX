#include <bits/stdc++.h>

using namespace std;

void merge(double harga[], double W[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    double LHarga[n1];
    double RHarga[n2];
    double LW[n1];
    double RW[n2];

    for(int i=0; i<n1; i++){
        LHarga[i] = harga[left + i];
        LW[i] = W[left + i];
    }
    for(int i=0; i<n2; i++){
        RHarga[i] = harga[mid + 1 + i];
        RW[i] = W[mid + 1 + i];
    }

    int i=0, j=0, k=left;
    while((i < n1) && (j < n2)){
        if(LHarga[i] <= RHarga[j]){
            harga[k] = LHarga[i];
            W[k] = LW[i];
            i++;
        }else{
            harga[k] = RHarga[j];
            W[k] = RW[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        harga[k] = LHarga[i];
        W[k] = LW[i];
        k++; i++;
    }
    while(j < n2){
        harga[k] = RHarga[j];
        W[k] = RW[j];
        k++; j++;
    }
}

void mergeSort(double harga[], double W[], int left, int right){
    if(left >= right){
        return;
    }

    int mid = left + (right - left)/2;

    mergeSort(harga, W, left, mid);
    mergeSort(harga, W, mid + 1, right);
    merge(harga, W, left, mid, right);
}
int main(){
    int N, X;
    cin >> N >> X;
    double W[N], C[N];
    double harga[N];
    double totalHarga = 0;

    for(int i=0; i<N; i++){
        cin >> W[i];
    }

    for(int i=0; i<N; i++){
        cin >> C[i];
        harga[i] = C[i]/W[i];
    }
    
    mergeSort(harga, W, 0, N-1);

    for(int i=N-1; i>=0; i--){
        if(X >= W[i]){
            totalHarga += (harga[i] * W[i]);
            X -= W[i];
        }else{
            totalHarga += (harga[i] * X);
            X -= X;
        }
    }

    cout << fixed << setprecision(5) << totalHarga << endl;



}