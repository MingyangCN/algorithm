//
// Created by 吴明洋 on 2023/1/6.
//

#include<iostream>

using namespace std;

int main(){
    int n = 10;
//    cin >> n;

    unsigned int x = -n;        // 无符号整数
    unsigned int y = -n + 1;

    for(int i = 31; i >= 0; i --) cout << (x >> i & 1); // 反码
    cout << endl;
    for(int i = 31; i >= 0; i --) cout << (y >> i & 1); // 补码

    return 0;
}