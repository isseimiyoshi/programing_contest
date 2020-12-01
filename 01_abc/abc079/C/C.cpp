#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int abcd;
    int a, b, c, d;
    cin >> abcd;
    // 各変数に値を代入する
    a = abcd / 1000;
    abcd -= 1000*a;
    b = abcd / 100;
    abcd -= 100*b;
    c = abcd / 10;
    abcd -= c*10;
    d = abcd;
    // cout << a << endl << b << endl << c << endl << d << endl;
    string op1, op2, op3;
    int ab, ab_c, abc_d;
    bool isSeven = false;;
    // 考えられる符号の８パターンを試行する
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            for(int k=0; k<2; k++){
                if(i == 0) ab = a + b;
                else ab = a - b;
                if(j == 0) ab_c = ab + c;
                else ab_c = ab - c;
                if(k == 0) abc_d = ab_c + d;
                else abc_d = ab_c - d;
                if(abc_d == 7){
                    isSeven = true;
                    if(i == 0) op1 = "+";
                    else op1 = "-";
                    if(k == 0) op3 = "+";
                    else op3 = "-";
                    if(j == 0) op2 = "+";
                    else op2 = "-";
                }
            }
        }
    }
    if(isSeven) cout << a << op1 << b << op2 << c << op3 << d << "=7" << endl;
    else cout << "No" << endl;
}