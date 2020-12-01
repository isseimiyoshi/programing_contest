#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int, int>;

int main()
{
    int x, y; cin >> x >> y;
    int a = (x+y)/2;
    int b = (x-y)/2;
    printf("%d %d\n", a, b);
}