// 和高精度加法差不多，值得注意的是
//      减法的借位处理
//      相减为负数的处理
//      前导0的处理
#include<iostream>
#include<vector>

using namespace std;

const int N = 1e6 + 10;

bool cmp(vector<int> A, vector<int> B){
    if(A.size() != B.size()) return A.size() > B.size();

    for(int i = A.size() - 1; i >= 0 ; i--){
        if(A[i] != B[i]){
            return A[i] > B[i];
        }
    }
    return true;
}

// 大数-小数
vector<int> sub(vector<int> &A, vector<int> &B){
    vector<int> C;

    for(int i = 0, t = 0; i < A.size(); i ++){
        t = A[i] - t;                                   // 去除借位
        if(i < B.size()) t -= B[i];
            C.push_back((t+10) % 10);                   // 保证正数

        if(t < 0) t = 1;                                //
        else t = 0;
    }

    // 0003
    while(C.size() > 1 && C.back() == 0) C.pop_back();  //去掉前导0
    return C;
}


int main(){
    string a, b;
    vector<int> A, B;

    cin >> a >> b;

    // 逆序
    for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

    if(cmp(A, B)){
        vector<int> C = sub(A, B);
        for(int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
    }
    else{
        vector<int> C =sub(B, A);
        printf("-");
        for(int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
    }

    return 0;
}