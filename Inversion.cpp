#include<bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;

long long countAndMerge(vector<int>&a, int left, int mid, int right){
    int sizeLeft = mid - left + 1, sizeRight = right - mid;
    long long result = 0;
    vector<int> leftArr(sizeLeft), rightArr(sizeRight);
    for(int i = 0; i < sizeLeft; ++i){
        leftArr[i] = a[left + i];
    }
    for(int i = 0; i < sizeRight; ++i){
        rightArr[i] = a[mid + 1 + i];
    }
    int k = left, iL = 0, iR = 0;
    while(iL < sizeLeft && iR < sizeRight){
        if(leftArr[iL] <= rightArr[iR]){
            a[k++] = leftArr[iL++];
        }else{
            a[k++] = rightArr[iR++];
            result += (sizeLeft - iL);
        }
    }
    while(iL < sizeLeft){
        a[k++] = leftArr[iL++];
    }
    while(iR < sizeRight){
        a[k++] = rightArr[iR++];
    }
    return result;
}

long long countInversion(vector<int>&a, int left, int right){
    long long result = 0;
    if(left < right){
        int mid = left + (right - left)/2;
        result += countInversion(a, left, mid);
        result += countInversion(a, mid + 1, right);
        result += countAndMerge(a, left, mid, right);
    }
    return result;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    cout << countInversion(a, 0, n - 1) % MOD;
}
