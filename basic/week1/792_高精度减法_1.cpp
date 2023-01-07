//
// Created by 吴明洋 on 2023/1/4.
// 高精度减法, 假定两个都是正整数。绝对值相减和绝对值相加，存在负数的话
#include<iostream>
#include<vector>

using namespace std;

const int N = 1e6 + 10;

// 判断是否有A >= B
bool cmp(vector<int> &A, vector<int> &B){
    // 首先判断位数; A，B位数不同，A位数大则大
    if(A.size() != B.size()) return A.size() > B.size();

    // 否则，比较各个位数
    for(int i = A.size() - 1; i >= 0; i --)
        if (A[i] != B[i])
            return A[i] > B[i];
    return true;
}

vector<int> sub(vector<int> &A, vector<int> &B){
    vector<int> C;
    // 保证A>B, t 借位
    for(int i = 0, t = 0; i < A.size(); i ++)
    {
        t = A[i] - t;
        // 判断B有没有越界，是否有这个位
        if(i < B.size()) t -= B[i];
        C.push_back((t + 10) % 10); // t >= 10 -> t; else t < 0 -> t + 10;  综合在一块
        if (t < 0) t = 1;           // 有借位
        else t = 0;
    }

    // 需要取到前导0, C的位数不是1位， 最后一位等于0的话 留上一位; 最后一位干掉
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main(){
    string a, b;
    vector<int> A, B;

    cin >> a >> b;

    for(int i = a.size() - 1; i >=0; i--) A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i >=0; i--) B.push_back(b[i] - '0');

    // 判断两个大整数, 谁大
    if (cmp(A, B)){
        auto C = sub (A, B);
        // 直接算，输出
        for(int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
    }
    else{
        vector<int> C = sub(B, A);
        printf("-");        // 输出一个负号
        for(int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
    }

    return 0;
}

