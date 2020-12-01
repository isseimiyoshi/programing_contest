#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x = 1;
    int *p;
    p = &x;
    *p = 2;
    cout << x << endl;

    int y;
    y = *p;
    cout << y << endl;
}