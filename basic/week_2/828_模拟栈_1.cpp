/********************************************************************************
* @author: Mingyang Wu
* @date: 2023/1/7 5:26 PM
* @version: 1.0
* @description: 模拟栈: 实现一个栈，栈初始为空，支持四种操作：push, pop, empty(判断栈是否为空), query(查询栈顶元素)
 * 常见模型：找出每个数左边离它最近的比它 大/小 的数
********************************************************************************/
#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int m, x, tt;                               // tt表示栈底坐标
int stack[N];

int main(){
    cin >> m;

    while(m --){
        string op;
        cin >> op;

        if(op == "push"){
            cin >> x;
            stack[++ tt] = x;               // 插入栈，加入新的元素
        }
        else if(op == "pop") -- tt;         // 删除
        else if(op == "empty") cout << (tt ? "NO" : "YES") << endl;     // tt > 0 not empty else tt = 0 is empty
//        else cout << stack[tt] << endl;
    }

    return 0;
}


