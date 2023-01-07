/********************************************************************************
* @author: Mingyang Wu
* @date: 2023/1/7 3:02 PM
* @version: 1.0
* @description: 数据结构_Acwing_826_单向链表，数组模拟邻接表，静态链表，算法题绝对不考虑内存泄漏的问题
********************************************************************************/
#include <iostream>

using namespace std;

const int N = 100010;

// head 表示头节点的下标（指向头节点的指针），e[i]表示节点i的值，ne[i] 表示节点i的next指针是多少，idx表示存储 当前用到哪个点
// head = head_pointer
int head, e[N], ne[N], idx;

// 初始化
void init(){
    head = -1;
    idx = 0;
}

// 插入：将x插入到头节点后. 把一个新的点插入到头节点之后
void add_to_head(int x){
    e[idx] = x;
    ne[idx] = head;         // 指向head指向的值
    head = idx++;
//    idx ++;                 // idx 指向下一个指针
}

// 将x插入到下标是k的点之后
void add(int k, int x){
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx ++;
//    idx ++;
}

// 删除操作， 将下表是k后面的点删除
void remove(int k){
    ne[k] = ne[ne[k]];      // 链表里的空间是不连续的
}

int main(){
    int m;
    cin >> m;

    init();                 // 初始化

    while(m --){
        int k, x;
        char op;

        cin >> op;
        if(op == 'H'){
            cin >> x;
            add_to_head(x);
        }
        else if (op == 'D'){
            cin >> k;
            // 特判：删除头节点
            if(!k) head = ne[head];         //
            remove(k - 1);              // important, 0 号点是第一个插入点
        }
        else{
            cin >> k >> x;
            add(k - 1, x);
        }
    }

    // 遍历
    for(int i = head; i != -1; i = ne[i]) cout << e[i] << ' ';
    cout << endl;

    return 0;
}


