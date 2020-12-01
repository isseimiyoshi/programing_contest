#include<iostream>
#include <bits/stdc++.h>
using namespace std;

/*
input

6
10
1 7 15 20 30 50
*/

int main()
{
    int N, R;
    cin >> N >> R;
    queue<int> X;
    for(int i=0; i<N; i++){
        int x;
        cin >> x;
        X.push(x);
    }
    // cout << X.front() << endl;
    int count = 0;
    while(!X.empty()){
        int s_num = X.front(); X.pop();
        //cout << s_num << endl;
        //cout << count << endl;
        if(X.empty()){
            count += 1;
            break;
        }
        // cout << X.front() << endl;
        int last_num;   // 最後に取り出した数字
        while(true){
            int diff = X.front() - s_num;
            if(diff > R){
                break;
            }else{
                last_num = X.front(); X.pop();
                if(X.empty()) break;
            }
        }
        if(X.empty()){
            count += 1;
            break;
        }
        while(true){
            if(X.front() - last_num <= R) {
                X.pop();
                if(X.empty()){
                    count += 1;
                    break;
                }
            }else{
                count+= 1;
                break;
            }
        }
    }
    cout << count << endl;
}