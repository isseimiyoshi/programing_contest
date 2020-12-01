#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll a, b, d, r;
    double f;
    cin >> a >> b;
    d = a / b;
    r = a % b;
    f = (double)a / (double)b;
    // ここのprinfの書き方をしっかり見ておく
    printf("%d %d %.5f\n", d, r, f);
}