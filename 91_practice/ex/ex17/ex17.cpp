#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, S;
    cin >> N >> S;
    vector <int> apples(N);
    vector <int> pines(N);
    for(int i=0; i<N; i++) cin >> apples[i];
    for(int i=0; i<N; i++) cin >> pines[i];
    // りんごとパイナップルの値段が同じものをカウントする変数
    int count = 0;
    for(int apple: apples){
        for(int pine: pines){
            if((apple + pine) == S) count += 1;
        }
    }
    cout << count << endl;
}