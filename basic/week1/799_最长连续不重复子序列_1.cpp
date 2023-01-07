// 最长连续不重复子序列：给定一个长度为 n  的整数序列，请找出最长的不包含重复的数的连续区间，输出它的长度。
// Created by 吴明洋 on 2023/1/6.
// 双指针算法，把两个有序的序列合并，归并排序
// 计数排序

#include<iostream>

using namespace std;

const int N = 1e5 + 10;
int n, m = 0;
int a[N];
int s[N]; // 当前j到i区间里面每个数出现的次数

int main(){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    int res = 0;
    for (int i = 0, j =0; i < n; i++){
        s[a[i]] ++; // 每次加入这个数是a[i]
        while(s[a[i]] > 1){ // 新加的数有重复的话，一直循环，当[j, i]区间内一直有重复的a[i]的话,得一直循环，j++
            // 重复的数是a[i]
            s[a[j]] --;     // 要把j拿出去，剔除之前的值
            j ++;
        }
        res = max(res, i - j + 1);
    }

    cout << res << endl;

    return 0;
}
