/********************************************************************************
* @author: Mingyang Wu
* @date: 2023/1/7 3:03 PM
* @version: 1.0
* @description: 827.双链表
 * 最左侧插入一个点
 * 最右侧插入一个点
 * 删除第k个插入数
 * 在第k个插入的数左侧插入一个数
 * 在第k个插入的数右侧插入一个数
********************************************************************************/
#include<iostream>

using namespace std;

const int N = 1e6 + 10;

int m;
int e[N], l[N], r[N], idx;      // 当前用到哪个数的下标

// 初始化操作，0是左端点，1是右端点
void init(){
    r[0] = 1;
    l[1] = 0;
    idx = 2;
}

// 在节点a的右边插入一个数
// 头部插入，head 右侧
void insert(int a, int x){
    e[idx] = x;                 // 值
    r[idx] = r[a], l[idx] = a;

    l[r[a]] = idx;
    r[a] = idx;
    idx ++;
}

// 删除节点a
void remove(int a){
    r[l[a]] = r[a];
    l[r[a]] = l[a];
}

int main(){
    cin >> m;

    init();

    while(m --){
        string op;
        cin >> op;

        int x, k;
        if(op == "L"){
            cin >> x;
            insert(0, x);
        }
        else if(op == "R"){
            cin >> x;
            insert(l[1], x);
        }
        else if(op == "D"){
            // 将第k个插入数删除，从0开始计算
            cin >> k;
            remove(k + 1);      // idx 从2开始
        }
        else if(op == "IL"){
            cin >> k >> x;
            insert(l[k + 1], x);
        }
        else{
            cin >> k >> x;
            insert(k + 1, x);
        }
    }

    for(int i = r[0]; i != 1; i = r[i]) cout << e[i] << " ";
    return 0;
}


