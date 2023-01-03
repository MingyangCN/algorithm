// 788_逆序对的数量, 归并排序
// Created by 吴明洋 on 2023/1/2.
// 给定一个长度为 n 的整数数列，请你计算数列中的逆序对的数量
// notion：小心报int  最大的逆序对个数为：倒叙， 5 * 10（9）

#include<iostream>
using namespace std;

typedef long long LL;

const int N = 1e6+10;

int q[N], tmp[N];
int n;

LL merge_sort(int q[], int l, int r){
    // LL 数据类型，倒叙会溢出
    if (l >= r) return 0;

    int mid = l + r >> 1;                                       // 中间值
    LL res = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);    // 全在左边，全在右边的查找

    // 归并的过程
     int k = 0, i = l, j = mid + 1;
     while(i <= mid && j <= r){
         if (q[i] <= q[j]) tmp[k++] = q[i++];
         else{
             tmp[k++] = q[j++];
             res += mid - i + 1;
         }
     }

     // 扫尾，收尾
     while (i <= mid) tmp[k++] = q[i++];
     while (j <= r) tmp[k++] = q[j++];

     // 放回原处
     for (int i = l, j = 0; i <= r ; i++, j++) q[i] = tmp[j];

     return res;
}


int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> q[i];

    cout << merge_sort(q, 0, n - 1) << endl;

    return 0;
}
