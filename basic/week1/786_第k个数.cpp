// 786_第k个数， 基于快速排序
// Created by 吴明洋 on 2023/1/2.
#include<iostream>
using namespace std;

const int N = 1e6 + 10;
int q[N], n, m;

void quick_sort(int q[], int l, int r){
    if (l >= r) return;
    int x = q[l + r >> 1], i = l - 1, j = r + 1;

    while(i < j){
        do i++; while(q[i] < x);
        do j--; while(q[j] > x);
        if(i < j) swap(q[i], q[j]);
    }

    quick_sort(q, l, j);
    quick_sort(q, j+1, r);
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> q[i];

    quick_sort(q, 0, n - 1);

    cout << q[m - 1] << endl;
    return 0;
}