#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char exam_result(int m, int f, int r){
    if(m == -1 || f == -1) return 'F';
    else if(m + f >= 80) return 'A';
    else if(m + f >= 65) return 'B';
    else if(m + f >= 50) return 'C';
    else if(m + f >= 30) if(r>=50)return 'C';else return 'D';
    else return 'F';
}

int main()
{
    while(true){
        int m, f, r;
        scanf("%d %d %d", &m, &f, &r);
        if(m == -1 && f == -1 && r == -1) break;
        else cout << exam_result(m, f, r) << endl;
    }
}