// Created by 吴明洋 on 2023/1/3.
// 高精度加法：给定两个正整数（不含前导 0），计算它们的和。大整数类, 1000位
// 大整数相加：A + B 位数1e6
// 乘法: A * a -> len(A) <= 1e6, a <= 1e5
// 大整数除偏小的
// 利用数组

#include <iostream>
#include <vector>       // 表示数组的长度

using namespace std;

const int N = 1e6 + 10; // 防止出现边界问题，保险点，习惯定义整数的范围

// C = A + B
vector<int> add(vector<int> &A, vector<int> &B){    // 加引用提高效率，加上引用就不会拷贝整个数组了
    // 大整数A，大整数B，用数组表示（倒着表示）
    vector<int> C;      // 答案存储
    int t = 0;          // 进位： Ai + Bi + t(上一位的进位)

    for(int i = 0; i < A.size() || i < B.size(); i++){
        if(i < A.size()) t += A[i];
        if(i < B.size()) t += B[i];
        C.push_back(t % 10 );                       // t 要大于10的话，保留取余数
        t /= 10;                                    // t > 10，进位
    }

    if(t) C.push_back(1);                           // 判断最高位 是否有进位
    return C;
}

int main(){
    string a, b;        // 太长了，利用字符串读入
    vector<int> A, B;   // 存储在vector中

    cin >> a >> b;      // a = "123456"

    // 大整数用数组存储下来，逆序，从后往前遍历每一位
    // for(auto c : a), C++ for 循环可以范围遍历 一个list 或者 迭代器；
    for(int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');    // 字母转成数字，存储的要是数字 A = [6, 5, 4 ,3 ,2, 1]
    for(int i = b.size() - 1; i >= 0; i --) B.push_back(b[i] - '0');

    // 模版函数，auto 编译器会自己推断返回类型是什么，
    auto C = add(A, B);

    // 输出，也要倒着输出，最高位，次高位
    for(int i = C.size() - 1; i >= 0 ; i --) printf("%d", C[i]);
    return 0;
}