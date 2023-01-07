//
// Created by 吴明洋 on 2023/1/6.
//
#include<iostream>

using namespace std;

const int N = 1e6+10;

int n;
int a[N], s[N];

int main(){
    cin >> n;
    int res = 0;

    for(int i = 0, j = 0; i < n ; i++){
        cin >> a[i];
        ++ s[a[i]];

        while(s[a[i]] > 1){
            s[a[j ++]] -- ;
        }
        res = max(res, i - j + 1);
    }

    cout << res << endl;

    return 0;
}
