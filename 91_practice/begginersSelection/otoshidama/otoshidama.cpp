#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, Y;
    cin >> N >> Y;
    int manN=0;
    int gosenN=0;
    int senN=0;
    for(int i=0; i<=N; i++){
        if(10000*i > Y){
            break;
        }else if(10000*i < Y){
            for(int j=0; j<=N-i; j++){
                if(5000*j > Y-10000*i){
                    break;
                }else if(5000*j < Y-10000*i){
                    int sum;
                    sum = 10000*i + 5000*j + 1000*(N-i-j);
                    if(sum == Y){
                        manN = i;
                        gosenN = j;
                        senN = N - i - j;
                    }else{
                        continue;
                    }
                }else{
                    if(N == i + j){
                        manN = i;
                        gosenN = j;
                        senN = 0;
                        break;
                    }
                }
            }
        }else{
            if(N == i){
                manN = i;
                gosenN = 0;
                senN = 0;
                break;
            }
        }
    }
    if((manN == 0) && (gosenN == 0) && (senN == 0)){
        cout << "-1 -1 -1" << endl;
    }else{
        cout << manN << " " << gosenN << " " << senN << endl;
    }
}