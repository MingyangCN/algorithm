/********************************************************************************
* @author: Mingyang Wu
* @date: 2023/1/7 8:21 PM
* @version: 1.0
* @description: 800_数组元素的目标和_双指针算法, 寻找单调性
    类似于夹逼，在i在增大的时候，j的正解只能是减小的 (i从前往后一定，j从后往前移动)
 * 对于每个i而言，都找一个j，使得A[i] + B[j] >= x
 * 双指针算法：先写出暴力算法，再观察有没有单调性，如果有就
********************************************************************************/
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;

int n, m, x;
int A[N], B[N];

int main(){
    cin >> n >> m >> x;
    for (int i = 0; i < n; i ++) cin >> A[i];
    for (int i = 0; i < m; i ++) cin >> B[i];

    // 时间复杂度 O(n + m)
    for (int i = 0, j = m - 1; i < n; i++){
        while(j >= 0 && (A[i] + B[j]) > x) j --;
        if(A[i] + B[j] == x) {
            cout << i << " " << j;
            break;
        }
    }

    return 0;
}


