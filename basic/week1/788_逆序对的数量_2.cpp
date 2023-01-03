// 分而治之
// 我们将序列从中间分开，将逆序对分成三类：
// 两个元素都在左边；
// 两个元素都在右边；
// 两个元素一个在左一个在右；
//
// 因此这就是我们算法的大致框架：
// 计算逆序对的数量（序列）：
//1. 递归算左边的；
//2. 递归算右边的；
//3. 算一个左一个右的；
//4. 把他们加到到一起。

#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100010;
int array[N], nums;
unsigned long res = 0;

void merge_sort(int array[], int l, int r){
    if (l >= r ) return;

    int mid = (l + r) / 2;
    merge_sort(array, l, mid), merge_sort(array, mid+1, r);

    int tmp[r - l + 1];
    int lptr = l, rptr = mid + 1, tempptr = 0;

    while(lptr <= mid && rptr <= r){
        if(array[lptr] <= array[rptr]) tmp[tempptr ++] = array[lptr ++];
        else{
            tmp[tempptr ++] = array[rptr ++];
            res += (mid - lptr + 1);
        }
    }
    while (lptr <= mid) tmp[tempptr ++] = array[lptr ++];
    while (rptr <= r) tmp[tempptr ++] = array[rptr ++];

    for (int i = l ,j = 0; i <= r; i++ , j++) array[i] = tmp[j];
}

int main(){
    cin >> nums;

    for (int i = 0; i < nums; i++ ) cin >> array[i];

    merge_sort(array, 0, nums-1);

    cout << res << endl;

    return 0;
}
