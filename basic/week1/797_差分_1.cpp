// 797_差分
// Created by 吴明洋 on 2023/1/6.
// 前缀和的逆运算；在序列[l, r]之间的数加上c
#include<iostream>

using namespace std;

const int N = 100010;

int n, m;
int a[N], b[N];             // 原数组，差分数组

// [l, r] 之间 加上c
void insert(int l, int r, int c){
    b[l] += c;
    b[r + 1] -= c;
}


int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    // a数组中 从前往后插入数字进去，输出的b[n] 为差分数组
    for (int i = 1; i <= n; i++) insert(i, i, a[i]);

    // m个质询
    while(m --){
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        // 往差分数组其中插入c 就可以改变
        insert(l, r, c);
    }

    // 求一下原来数组的值，对于差分数组 求一遍前缀和。b数组变成自己的前缀和
    for (int i = 1; i <= n; i ++) b[i] += b[i - 1];

    for (int i = 1; i <= n; i ++) printf("%d ", b[i]);

    return 0;
}
