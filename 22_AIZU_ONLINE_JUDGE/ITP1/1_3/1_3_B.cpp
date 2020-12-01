#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int MAX_X = 10010;
    for(int i=0; i<MAX_X; i++){
        int x;
        cin >> x;
        if(x == 0){
            break;
        }else{
            printf("Case %d: %d\n", i+1, x);
        }
    }
}