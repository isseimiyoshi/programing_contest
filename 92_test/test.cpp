#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;

int main(){
    /*
    // 実行にかかる時間を計測する
    int ti = clock();
    rep(i,100000) cout << i << endl;
    printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
    */

    set<int> S;
    S.insert(3);
    S.insert(5);
    S.insert(18);
    S.insert(12);
    S.insert(14);
    for(auto itr = S.begin(); itr != S.end(); itr++){
        cout << (*itr) << endl;
    }
    cout << (*(S.lower_bound(10))) << endl;

    int N = 100000;
    //assert(N<=10000);

    vector<int> A;
    rep(i,100){
        if(i > 50) A.push_back(-1);
        else A.push_back(i);
    }
    cout << count(A.begin(), A.end(), -1) << endl;
    cout << find(A.begin(), A.end(), 30) - A.begin() << endl;

    return 0;
}