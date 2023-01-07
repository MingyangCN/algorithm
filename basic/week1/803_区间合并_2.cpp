//
// Created by 吴明洋 on 2023/1/7.
// 区间合并
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;

pair<int, int> a[N];
int n, cnt;

int main(){
    cin >> n;

    for (int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + 1 + n);

    cnt = n;

    for (int i = 0; i < n; i++){
        if (a[i].second >= a[i+1].first){
            cnt --;
            a[i + 1].first = a[i].first;
//            a[i].second = a[i + 1].second;
            a[i + 1].second = max(a[i+1].second, a[i].second);
        }
    }
    cout << cnt;
    return 0;
}