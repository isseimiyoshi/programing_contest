#include<iostream>
#include <bits/stdc++.h>
using namespace std;


/*
input

5
1 2 4 6 8
3 5 7 9 10
*/

int main()
{
    int n;
    cin >> n;   // 仕事の個数
    int s[n];
    int t[n];
    // 各仕事のStart時間と終わり時間を格納する
    for(int i=0; i<n; i++) cin >> s[i];
    for(int i=0; i<n; i++) cin >> t[i];
    vector<pair<int, int>> time;
    for(int i=0; i<n; i++){
        int diff = t[i]-s[i];
        time.push_back(make_pair(diff, i));
    }
    sort(time.begin(), time.end());
    int count = 0;
    set<int> used;
    for(auto w: time){
        int num = w.second;
        bool dupli = false;
        for(int i=s[num]+1; i<=t[num]; i++){
            if(used.count(i)) dupli = true;
        }
        if(!dupli){
            for(int i=s[num]+1; i<=t[num]; i++){
                used.insert(i);
            }
            count += 1;
        }
    }
    printf("%d\n", count);
}