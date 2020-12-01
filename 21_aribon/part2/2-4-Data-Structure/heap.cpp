#include<iostream>
#include <bits/stdc++.h>
using namespace std;

/*
input

4 29 10
10 10
14 5
20 2
21 4
*/

typedef long long ll;
int main()
{
    int N, L, P;
    cin >> N >> L >> P;
    int A[N], B[N];
    priority_queue<int> pque;
    for(int i=0; i<N; i++){
        int Ai, Bi; cin >> Ai >> Bi;
        A[i] = Ai; B[i] = Bi;
    }
    int pos = 0, ans = 0;
    // 最初の燃料を使い切る
    pos += P; P = 0;
    for(int i=0; i<N; i++){
        if(A[i] <= pos) pque.push(B[i]);
    }
    while(true){
        int ori_pos = pos;
        int max_P = pque.top(); pque.pop();
        ans += 1; pos += max_P;
        if(pos >= L) break;
        for(int i=0; i<N; i++){
            if(ori_pos < A[i] && A[i] <= pos) pque.push(B[i]);
        }
        if(pque.empty()){
            ans = -1;
            break;
        }
    }
    cout << ans << endl;
}