/********************************************************************************
* @author: Mingyang Wu
* @date: 2023/1/8 3:24 AM
* @version: 1.0
* @description: 
********************************************************************************/
#include <iostream>

using namespace std;

const int N = 100010;

int e[N], l[N], r[N], idx;

void init(){
    r[0] = 1;               // 0 是左端点， 1是有端点
    l[1] = 0;
    idx = 2;                // 0 和 1被用过，第一个插入点的下标是2，第二插入点的下标是3
}

void insert(int k, int x){
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;          // 不能反
    r[k] = idx;
    idx ++;
}

void remove(int k){
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

int main(){
    int m;
    cin >> m;

    init();

    while(m --){
        string op;
        cin >> op;

        int k, x;
        if(op == "L"){
            cin >> x;
            insert(0, x);
        }
        else if(op == "R"){
            cin >> x;
            insert(l[1], x);    // 右端点的左侧
        }
        else if(op == "D"){
            cin >> k;
            remove(k + 1);      // 涉及k的改为 k + 1
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

    // 左端点不输出，从左端点下一个点输出
    for (int i = r[0]; i != 1; i = r[i]) cout << e[i] << " ";
    cout << endl;
    return 0;
}


