/********************************************************************************
* @author: Mingyang Wu
* @date: 2023/1/7 5:26 PM
* @version: 1.0
* @description: 829.模拟队列
 * int q[N], hh, tt = -1;   在队尾插入元素，在队头弹出元素
 * q[++ tt] = x;            插入元素
 * h ++                     弹出
 * if (hh <= tt) not empty  判断是否为空
 * q[hh]                    取出队头元素
 *
 * 常见模型：找出滑动窗口中最大值/最小值
********************************************************************************/
#include <iostream>

using namespace std;

const int N = 1000010;

int m, hh, tt = -1;  // 队头指针，队尾指针
int q[N];

int main(){
    cin >> m;

    while(m --){
        string op;
        int x;

        cin >> op;
        if(op == "push"){
            cin >> x;
            q[++ tt] = x;
        }
        else if (op == "pop") hh ++;
        else if (op == "empty"){
            if(hh <= tt) puts("NO");
            else puts("YES");
        }
        else cout << q[hh] << endl;
    }

    return 0;
}

