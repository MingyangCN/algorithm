// Created by 吴明洋 on 2023/1/1.
// 787 归并排序，分治，以整个数组的中间部分来分，分为左边和右边。
// 1， 确定分界点，mid = (l + r) / 2, 递归排序左边和右边
// 2， 把两个有序的数组合并成一个有序的数组(把两个有序的序列合二为一) 双指针算法
// 奇数的话 向下取整。 合并两个有序的列表（链表合并算法, 稳定算法, O(n)）
// 两个有序的序列，分别先指向最小值
//
// 一个是将数组一分为二,一个无序的数组成为两个数组.
// 另外一个操作就是,合二为一,将两个有序数组合并成为一个有序数组.

#include<iostream>
using namespace std;

const int N = 1000010;
int n;
int q[N], tmp[N];

void merge_sort(int q[], int l, int r){
    // 区间中的元素个数是1个或者没有的话
    if (l >= r) return;
    // 确定中间点, 分界点, divide 2
    int mid = l + r >> 1;
    // 递归，排左边和右边, 排完之后左右两边都有序了
    merge_sort(q, l ,mid), merge_sort(q, mid + 1, r);

    // 归并排序, k temp中合并了几个数, i 左边起点, j 右边起点
    int k = 0, i = l, j = mid + 1;
    while(i <= mid && j <= r)               // 当左半边和右半边都没有循环空的时候
    {
        if(q[i] <= q[j]) tmp[k++] = q[i++];
        else tmp[k++] = q[j++];             // 否则将j指向的拿过来
    }

    // 把剩下的拿过来，判断左半边和右半边是不是循环完
    while(i <= mid) tmp[k++] = q[i++];
    while(j <= r) tmp[k++] = q[j++];

    // 拿回结果, tmp中的复制回q, l = 0
    for(i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j];
}


int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> q[i];

    merge_sort(q, 0 , n - 1);

    for(int i = 0; i < n; i++) cout << q[i] << ' ';

    return 0;
}