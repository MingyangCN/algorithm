// 整数二分(边界点)
// 有单调性的话，一定可以二分；二分不一定需要单调性。二分：找到一个性质，使得右半边满足，而左半边不满足这种性质。二分就是寻找性质的边界
// 1. mid = (l + r ) / 2  找到中间值; if  check_mid 判断中间值是否满足某些性质
// 2. 思考该如何更新 上下界[l, r]
// 模版1 check()的区间内找到左边界，红绿的绿色的左边界
// 关心更新区间的时候 l = mid [(l+r+1)/2] or r = mid  if(check(mid)) = true

#include<iostream>
using namespace std;

const int N = 1e6+10;
int n, m;
int q[N];


int main(){
    // 在数组中查找某元素，找不到就输出−1
    // 找到了就输出不小于该元素的最小位置和不大于该元素的最大位置
    cin >> n >> m;
//    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) cin >> q[i];

    // 存在m个质询
    while(m --){
        int x;
        cin >> x;

        // 查找不小于x的最小位置
        int l = 0, r = n - 1;
        // 每次二分的时候一定要保证我们区间 里面是有答案的；当区间长度=1时，答案就在这个区间里面了
        // 模版1，边界的一个性质在右半区符合（这个数的开始边界），在左半区不符合，要找到符合右半区的左边界
        while(l < r){
            int mid = l + r >> 1;               // 先除以2，后面是否需要+1再另外考虑. 需要考虑一下分类的性质
            // 判断mid是否满足性质
            if(q[mid] >= x) r = mid;            // 边界在左边 [l, mid], 左边界右侧的数字都 >= x, 右边界左侧的数字都 <= x
            else l = mid + 1;                   // [l, r] 被分成 [l, mid], [mid + 1, r].
        }

        // 判断第一个满足大于等于x的数, 不满足时
        if(q[l] != x) cout << "-1 -1" << endl;
        else{
            cout << l << " ";                   // while循环结束 l = r

            // 查找不大于x的最大位置， 模版2
            // 边界的一个性质在右半区不符合，在左半区符合（这个数的结束边界），要找到符合左半区的右边界
            int l = 0, r = n - 1;
            while(l < r){
                int mid = l + r + 1 >> 1;       // 防止死循环，
                if(q[mid] <= x) l = mid;        // mid在左半区，[mid, (x), r], l = mid
                else r = mid - 1;               // 范围[l, r]被分成[l, mid - 1], [mid, r]
            }

            cout << l << endl;
        }
    }

    return 0;
}

