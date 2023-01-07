/********************************************************************************
* @author: Mingyang Wu
* @date: 2023/1/7 9:34 PM
* @version: 1.0
* @description: 2816_判断子序列_双指针算法，调整法
 * 双指针做法：可以找到一种匹配方式
 * 若存在一种匹配，（存在一个子序列），则上述算法，必然可以找出一组匹配
 * 通过给定的一组匹配，构造出双指针算法可以找到的合理匹配。
********************************************************************************/
#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;

int n, m;
int a[N], b[N];

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i ++) scanf("%d", &b[i]);

    int i = 0, j = 0;
    while(i < n  && j < m){
        if (a[i] == b[j]) i ++ ;    // 匹配的话i指针往后走
        j ++;                       // 每次不管匹不匹配，j都往后走
    }

    if(i == n) puts("Yes");
    else puts("No");

    return 0;
}


