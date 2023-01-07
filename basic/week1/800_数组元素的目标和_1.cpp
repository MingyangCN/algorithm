//
// Created by 吴明洋 on 2023/1/6.
// 800_数组元素的目标和_暴力 	Time Limit Exceeded
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e5 + 10;

int n, m, x;
int A[N], B[N];

int main(){
    vector<PII> pair;
    cin >> n >> m >> x;
    for (int i = 0; i < n; i ++) cin >> A[i];

    for (int i = 0; i < m; i ++) cin >> B[i];

//    int len = max(n, m);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j ++){
            if((A[i] + B[j]) == x){
                pair.push_back({i, j});
                break;
            }

        }
    }

    for(auto item : pair){
        cout << item.first << " " << item.second << endl;
    }

    return 0;
}



