#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[20];

bool dfs(int i, int sum){
    // n個決め終わったら、今までの和sumがkと等しいかを返す
    if(i == n) return sum == k;

    // a[i]を使わない場合
    if(dfs(i+1, sum)) return true;

    // a[i]を使う場合
    if(dfs(i+1, sum+a[i])) return true;

    // a[i]を使う使わないにかかわらずkが作れないのでfalseを返す
    return false;
}

/*
入力

4
1
2
4
7
13
*/

/*
入力

4
1
2
4
7
15
*/

int main()
{
    cin >> n;
    // int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cin >> k;
    if(dfs(0, 0)) printf("Yes\n");
    else printf("No\n");
}