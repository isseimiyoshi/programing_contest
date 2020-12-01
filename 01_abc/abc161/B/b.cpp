#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> A_i(N);
    int sum = 0;
    for(int i=0; i<N; i++){
        cin >> A_i[i];
        sum += A_i[i];
    }   
    int popular_count = 0;
    double judge_num = sum / (4.0*M);
    for(int i=0; i<N; i++){
        if(judge_num <= A_i[i]){
            popular_count += 1;
        }
    }
    if(popular_count >= M) cout << "Yes" << endl;
    else cout << "No" << endl;
}