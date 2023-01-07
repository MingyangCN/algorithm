//
// Created by 吴明洋 on 2023/1/4.
// 高精度 乘法 与 高精度加法
#include<iostream>
#include <algorithm>
#include "vector"
using namespace std;

vector<int> mul(vector<int> &A, vector<int> &B){
    vector<int> C(A.size() + B.size() + 7 , 0);
    int t = 0;

    for (int i = 0; i < A.size(); i++)
        for (int j = 0; j < B.size(); j ++){
            C[i + j] += A[i] * B[j];
        }

    for (int i = 0; i< C.size(); i++){
        t += C[i];                          // 进位相加
        C[i] = t % 10;
        t /= 10;
    }

    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

vector<int> add(vector<int> &A, vector<int> &B){
//    vector<int> C(max(A.size(), B.size()) + 10, 0);
    vector<int> C;
    int t = 0;

    for (int i = 0; i < A.size() || i < B.size(); i ++){
        if(i < A.size()) t += A[i];                         // 判断谁的位数高
        if(i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }

    while(C.size() > 1 && C.back() == 0) C.pop_back();      // 处理前导0

    reverse(C.begin(), C.end());
    return C;
}

int main(){
    string a, b;
    vector<int> A, B;

    cin >> a >> b;

    for(int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i >= 0; i -- ) B.push_back(b[i] - '0');

    auto C = add(A, B);
    cout << a << "+" << b << "=";
    for(int i = 0; i < C.size(); i ++ ) cout << C[i];
    cout << endl;

    C = mul(A, B);
    cout << a << "*" << b << "=";
    for(int i = C.size() - 1; i >= 0 ; i -- ) cout << C[i];
    cout << endl;

    return 0;
}


