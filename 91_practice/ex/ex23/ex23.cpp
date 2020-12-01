#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    priority_queue<int> nums;
    for(int i=0; i<N; i++){
        int Ai;
        cin >> Ai;
        nums.push(Ai);
    }
    int max_count = 0;
    int count = 0;
    int64_t max_num = 0;
    int64_t ori_top = 2000000000000;
    for(int i=0; i<N; i++){
        int top_num = nums.top();
        if(ori_top > top_num){
            if(max_count <= count){
                    if(ori_top == 2000000000000){
                        max_count = 1;
                        max_num = top_num;
                    }else{
                        max_count = count;
                        max_num = ori_top;
                    }
                }
            ori_top = top_num;
            count = 1;
        }else{
            count += 1;
        }
        nums.pop();
    }
    if(nums.empty()) cout << max_num << " " << max_count << endl;
}