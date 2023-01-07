//
// Created by 吴明洋 on 2023/1/4.
// 给定两个非负整数(不含前导0)
// 高精度 X 低精度

#include<iostream>
#include<vector>
using namespace std;

const int N = 1e6 + 10;

vector<int> mul(vector<int> &A, int b){
    vector<int> C;
    int t = 0;

    for(int i = 0; i < A.size(); i++){
        // 与乘法 加法类似。要么i没有循环完，要么是t不为0
        if(i < A.size()) t += A[i] * b;                         // 当前位结果
//        t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;                                                // 往前移动一位，进位
    }

    while(t){                                                   // 处理最后剩余的 t
        C.push_back(t % 10);
        t/= 10;
    }

    while(C.size() > 1 && C.back() == 0) C.pop_back();           // 去掉前导0, 扫尾
    return C;
}

int main(){
    string a;
    int b;                  // 小的数字
    vector<int> A;

    cin >> a >> b;

    // 逆序输入，数组中 123 变成了 321存储
    for(int i = a.size() - 1; i >= 0 ; i--) A.push_back(a[i] - '0');

    auto C = mul(A, b);

    for(int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
    return 0;
}

