//
// Created by 吴明洋 on 2023/1/4.
// 高精度 X 高精度
#include<iostream>
#include<vector>
using namespace std;

vector<int> mul(vector<int> &A, vector<int> &B){
    vector<int> C(A.size() + B.size() + 7, 0);  // 初始化为 0，C的size可以大一点
    int t = 0;

    for (int i = 0; i < A.size(); i++ )
        for (int j = 0; j < B.size(); j ++ )
            C[i + j] += A[i] * B[j];                    // 先获得各个位数上的值

    // 处理进位
    for (int i = 0; i < C.size(); i ++){                // i = C.size() - 1时 t 一定小于 10
        t += C[i];
        // C.push_back(t % 10);
        C[i] = t % 10;
        t /= 10;
    }

    while(C.size() > 1 && C.back() == 0) C.pop_back();  // 必须要去前导 0，因为最高位很可能是 0，最前面。
    return C;
}

int main(){
    string a, b;
    vector<int> A, B;

    cin >> a >> b;

    for(int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i >= 0; i -- ) B.push_back(b[i] - '0');

    auto C = mul(A, B);

    for(int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
    return 0;
}
