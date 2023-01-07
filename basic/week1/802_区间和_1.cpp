// 802_区间和；离散化 (整数的离散化)
// Created by 吴明洋 on 2023/1/6.
// 前缀和做法
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int ,int> PII;

const int N = 3e5 +10;      // 开的大小

int n, m;
int a[N], s[N];             // 存储的数，前缀和

vector<int> alls;           // 存所有要离散化的值
vector<PII> add, query;     // 所有插入操作（加上一个数， 求）

// 二分找出x对应的离散化的值
int find(int x){
    // 找到第一个大于等于x 的位置
    int l = 0, r = alls.size() - 1;

    while(l < r){
        int mid = l + r >> 1;            // 每次取中间点, 后面使用二分的第一个模版
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1;                       // 把x的所有的数 映射到从1开始的自然数，因为前缀和。映射到:1, 2, 3, 4, 5 .... n.
}

vector<int>::iterator unique(vector<int> &a){
    // 返回vector int 的一个迭代器，实现方法：双指针算法
    // 满足每一段相同元素的第一个元素的性质：它是第一个 or 它跟前一个元素不一样a[i] != a[i-1]
    // i 遍历所有的数，j 存下当前存到了第几个不同的数
    int j = 0;
    // 从[0, j-1] 存了所有不同的数， a[0] - a[j-1] 所有a中不重复的数
    for (int i = 0; i < a.size(); i++ ){
        if(!i || a[i] != a[i-1]){
            a[j ++ ] = a[i];
        }
    }

    return a.begin() + j;
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < n ;i ++){
        int x, c;
        cin >> x >> c;
        add.push_back({x, c}); // 某个位置x上的数加上C。

        alls.push_back(x);  // 下标x放入到带离散化的数组里面去
    }

    for (int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;

        query.push_back({l, r});

        alls.push_back(l);
        alls.push_back(r);
    }

    // 给alls数组里的数去重
    sort(alls.begin(), alls.end()); // 将所有值排序
    alls.erase(unique(alls.begin(), alls.end()), alls.end());   // 去重，将begin-end的重复数删掉，不重复的数都放在前面去，返回新数组最后一个位置。删除冗余元素

    // alls.erase(unique(alls), alls.end());

    // 处理插入
    for (auto item : add){                      // 遍历add
        int x = find(item.first);               // x离散化后的值
        a[x] += item.second;                    // 离散化之后的坐标位置上 加上要处理的数
    }

    // 预处理前缀和，映射到从[1, alls.size()]
    for (int i = 1; i <= alls.size(); i++) s[i] = s[i - 1] + a[i];

    // 处理质询
    for (auto item : query){
        int l = find(item.first), r = find(item.second);    // first: 左区间原来的值，右端点离散化的值
        cout << s[r] - s[l - 1] << endl;
    }

    return 0;
}

