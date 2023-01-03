//
// Created by 吴明洋 on 2023/1/3.
//

#include "iostream"
#include "iomanip"
using namespace std;

const int N = 1e6+10;
double n, l, r, mid;
bool flag;

double q(double a)
{
    // 三次方
    return a * a * a;
}

int main(){
    cin >> n;
    l = -1e5, r = 1e5;
    while(r - l >= 1e-7){
        mid = (l + r)/2;
        if(q(mid) >= n) r = mid;
        else l = mid;
    }
    cout << fixed << setprecision(6) << l;
    return 0;
}