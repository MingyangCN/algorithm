/********************************************************************************
* @author: Mingyang Wu
* @date: 2023/1/8 12:49 AM
* @version: 1.0
* @description: 829.模拟队列
********************************************************************************/
#include<iostream>

using namespace std;

const int N = 100010;

int q[N], l, r, n;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;

    while(n --){
        string op;
        cin >> op;

        if(op == "push"){
            cin >> q[r];
            r = (r == N - 1 ? 0 : r + 1);    // 更新队尾指针
//            q[ ++ tt]
        }
        else if(op == "pop"){
            l = (l == N - 1? 0 : l + 1);
        }
        else if(op == "empty"){
            puts(l == r ? "YES" : "NO");
        }
        else{
            cout << q[l] << endl;
        }
    }

    return 0;
}



