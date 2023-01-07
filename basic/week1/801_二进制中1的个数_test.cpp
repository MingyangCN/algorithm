//
// Created by 吴明洋 on 2023/1/6.
//

#include<iostream>

using namespace std;

int main(){
    int n = 10;

    // n的各个位数的表示，从最高位开始
    for (int k = 3; k >=0; k--) cout<< (n >> k & 1) << " ";

    return 0;
}