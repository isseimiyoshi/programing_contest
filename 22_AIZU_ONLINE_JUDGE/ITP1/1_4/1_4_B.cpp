#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 円周率：M_PI（STLのライブラリの中に含まれている）

int main()
{
    double r;
    cin >> r;
    printf("%.5f %.5f\n", r*r*M_PI, 2*r*M_PI);
}