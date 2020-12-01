#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int MAX_N = 20000;
vector<int> L(MAX_N+1, 50001);
int N; int total_l = 0;
int cost = 0;

/*
input

5
3 4 5 1 2

3
8 5 8

*/

int separate(){
    sort(L.begin(), L.end());
    if(L[0] == total_l){
        return 0;
    }else{
        int l1 = L[0]; int l2 = L[1];
        cost += l1+l2;
        L[0] = l1+l2; L[1] = 50001;
        separate();
        return 0;
    }
}

int main()
{
    cin >> N;
    for(int i=0; i<N; i++){
        int l;
        cin >> l;
        L[i] = l;
        total_l += l;
    }
    separate();
    cout << cost << endl;
}