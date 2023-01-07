// 803_区间合并; 区间合并
// Created by 吴明洋 on 2023/1/6.
// 相似题：格子染色
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> PII; // 区间左右端点，多个区间的存储

const int N = 100010;

int n;
vector<PII> segs;

void merge(vector<PII> &segs){
    // 区间合并
    vector<PII> res;

    sort(segs.begin(), segs.end());     // 所有区间排序，pair在c++中会优先左端点排序 再右端点排序

    int st = -2e9, ed = -2e9;            // 初始化边界值，
    for(auto seg:segs){
        if(ed < seg.first){             // 当前区间-维护的区间的右端点是严格小于，在枚举区间的左边的。 区间之间没有任何交集
            if (st != -2e9) res.push_back({st, ed});    // 维护区间放在答案中，但是不能是一开始的初始的区间
            st = seg.first, ed = seg.second;
        }
        else{
            // 否则，是有交集的, 求并集
            ed = max(ed, seg.second);
        }
    }
    // 防止输入为空的集合
    if (st != -2e9) res.push_back({st, ed});

    segs = res;
}

int main(){
    cin >> n;
    // 读入区间的左右端点
    for (int i = 0; i < n; i ++){
        int l, r;
        cin >> l >> r;
        segs.push_back({l, r});
    }

    merge(segs);

    cout << segs.size() <<endl;

    return 0;
}


