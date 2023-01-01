// 排序（快速排序 归并排序）
// 二分（整数二分，浮点数二分）
// 理解并记忆代码模版，锻炼熟练度：一道题写3-5次
// 注意边界问题
#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int n;
int q[N];

// 快排模版
void quick_sort(int q[], int l, int r)
{
    if (l >= r) return;  // 只有一个数字
    // x = q[l] 会产生边界死循环，当下面取到i+1 和 i
    // x = q[(l + r + 1) / 2]
    int x = q[l], i = l -1, j = r + 1;  // 两个伪指针，指向两侧，不管怎么样都是往中间移动一格
    // 调整位置
    while(i < j)
    {
        do i ++ ; while(q[i] < x);      // q[i] 站好位置
        do j -- ; while(q[j] > x);
        if(i < j) swap(q[i], q[j]);     // 交换两个数
//        if(i < j){
//            int t = q[i];
//            q[i] = q[j];
//            q[j] = q[i];
//        }
    }

    // 递归处理左右两边
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

int main()
{
    scanf("%d", &n);  // 当输入的数较多的时候，选择一种比较快的输入方式
//    int l = 0, r = n - 1;
    for(int i = 0; i < n; i++) scanf("%d", &q[i]);

    quick_sort(q, 0, n - 1);

    for(int i = 0; i < n; i++) printf("%d ", q[i]);

    return 0;
}