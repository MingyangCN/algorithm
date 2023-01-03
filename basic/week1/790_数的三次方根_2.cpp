//
// Created by 吴明洋 on 2023/1/3.
//

#include<iostream>
using namespace std;

const int N = 1e5 + 10;

int main(){
    double num, x;
    cin >> num;
    if (num <= 0) x = -num;
    else x = num;

    // 确定边界
    double l = 0, r = x;
    // 注意循环条件处理精度问题
    while(r - l > 1e-8){
        // 1. 找中间值
        double mid = (l + r) / 2;
        // 2. 根据性质判断
        if(mid * mid * mid < x ) l = mid;
        else r = mid;
    }
    if(num<0){
        printf("%.6f", -r);
    }
    else printf("%.6f", r);

    return 0;
}