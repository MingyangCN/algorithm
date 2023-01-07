// 801_二进制中1的个数
// Created by 吴明洋 on 2023/1/6.
// 位运算: n的二进制表示中，第k位是几。
// 给定一个长度为n的数列，求出数列中每个数的二进制表示中1的个数。

#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int n;

// lowbit 操作
int lowbit(int x){
    return x & (-x);
}

int main(){
    cin >> n;

    while(n --){
        int x;
        cin >> x;

        int res = 0;
        while(x) x -= lowbit(x), res ++;        // 每次减去x的最后一位1

        cout << res << " ";
    }

    return 0;
}

