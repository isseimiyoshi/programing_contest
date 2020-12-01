#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int a, b;
    char op;
    while(true){
        cin >> a >> op >> b;
        if(op == '+') printf("%d\n", a+b);
        else if(op == '-') printf("%d\n", a-b);
        else if(op == '*') printf("%d\n", a*b);
        else if(op == '/') printf("%d\n", a/b);
        else if(op == '?') break;
    }
}