// 790. 数的三次方根
// Created by 吴明洋 on 2023/1/3.
// 给定一个浮点数 n, 求它的三次方根。 浮点数 不需要考虑+1

#include<iostream>
using namespace std;

const int N = 1e5 + 10;

int main(){
    double x;
    cin >> x;

    // 确定边界
    double l = -1e5, r = 1e5;
    // 注意循环条件处理精度问题
    while(r - l > 1e-8){
        // 1. 找中间值
        double mid = (l + r) / 2;
        // 2. 根据性质判断
        if(mid * mid * mid < x ) l = mid;
        else r = mid;
    }
    printf("%.6f", r);

    return 0;
}



