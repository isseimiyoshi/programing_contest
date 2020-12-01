#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int K;
    cin >> K;
    queue<int64_t> que;
    // push 1~9 numbers firstly
    for(int i=1; i<10; i++){
        que.push(i);
    }
    int count = 0;
    int64_t print_num;
    while(true){
        int64_t x = que.front();
        que.pop();
        count += 1;
        if(count == K){
            print_num = x;
            break;
        }
        if(x % 10 == 0){
            que.push(x * 10);
            que.push(x*10 + 1);
        }else if(x % 10 == 9){
            que.push(x*10 + (x%10-1));
            que.push(x*10 + x%10);
        }else{
            que.push(x*10 + (x%10 - 1));
            que.push(x*10 + x%10);
            que.push(x*10 + (x%10 + 1));
        }
    }
    cout << print_num << endl;
}