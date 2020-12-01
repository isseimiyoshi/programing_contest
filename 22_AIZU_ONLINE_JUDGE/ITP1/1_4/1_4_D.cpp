#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin >> n;
    ll max_n, min_n, sum_n;
    max_n = -1000010; min_n = 1000010; sum_n = 0;
    for(int i=0; i<n; i++){
        ll ai;
        cin >> ai;
        if(max_n<ai) max_n = ai;
        if(min_n>ai) min_n = ai;
        sum_n += ai;
    }
    printf("%d %d %ld\n", min_n, max_n, sum_n);
}