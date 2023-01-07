/********************************************************************************
* @author: Mingyang Wu
* @date: 2023/1/7 9:02 PM
* @version: 1.0
* @description: 2816_判断子序列_双指针算法
 * 整个过程中，j指针不断扫描b数组并且向后移动，相当于不断给i指针所指向的a数组创建匹配的机会，
 * 只有匹配成功时i指针才会向后移动一位，当i == n时，说明全部匹配成功。
********************************************************************************/
#include<iostream>

using namespace std;

const int N = 1e6 + 10;
int n , m;
int a[N], b[N];

int main(){
    cin >> n >> m;
    for (int i = 0; i < n; i ++) cin >> a[i];
    for (int i = 0; i < m; i ++) cin >> b[i];

    int i = 0;
    for(int j = 0; j < m; j++){
        if(i < n && a[i] == b[j]) i ++;
    }
    if (i == n) printf("Yes");
    else printf("No");

    return 0;
}




