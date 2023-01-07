//
// Created by 吴明洋 on 2023/1/5.
// 高精度除法
#include<iostream>
#include<vector>
#include "algorithm"
using namespace std;

// A / b = C ... r
// 除法的存储也是倒着来存, 从最高位开始看
vector<int> div(vector<int> &A, int b, int &r){
    vector<int> C;
    r = 0;

    for(int i = A.size() - 1; i >= 0; i --){
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }

    // C 0 存最高位，C 1 存最低位，大整数乘法逆序
    // 最后输出显示是逆序的
    // 在除法运算中，高位到低位运算，因此C的前导零都在vector的前面而不是尾部。我们将C翻转，这样0就位于数组尾部，可以使用pop函数删除前导0
    reverse(C.begin(), C.end());
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main(){
    string a;
    int b, r = 0;               // 被除数 和 余数
    vector<int> A;

    cin >> a >> b;

    for(int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');

    auto C = div(A, b, r);

    //
    for(int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
    cout << endl << r << endl;
    return 0;
}

