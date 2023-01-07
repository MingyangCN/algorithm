//
// Created by 吴明洋 on 2023/1/5.
// 前缀和
#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int a[N], s[N];

int main(){
    // ios::sync_with_stdio(false);                         // 不需要同步；提高cin的读取速度，坏处是 不能用scanf
    // scanf 如果输入大量的数字
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];     // 前缀和的初始化

    while(m --){
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", s[r] - s[l-1]);                      // 区间和的计算
    }

    return 0;
}

