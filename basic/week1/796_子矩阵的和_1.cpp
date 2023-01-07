//
// Created by 吴明洋 on 2023/1/5.
// 矩阵和:对于每个询问输出子矩阵中所有数的和。
#include<iostream>
#include<vector>

using namespace std;

const int N = 1010;     // n,m范围很重要
int n, m, q;            // 询问次数
int a[N][N], s[N][N];   // 前缀和数组

int main(){
    scanf("%d%d%d", &n, &m, &q);
    // 前缀和数组
    for(int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);

    for(int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];            // 求前缀和

    while(q -- ){
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        printf("%d\n", s[x2][y2] - s[x1 - 1][y2] - s[x2][y1-1] + s[x1-1][y1-1]);        // 算部分和，算子矩阵和数
    }

    return 0;
}

