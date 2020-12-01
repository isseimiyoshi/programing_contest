#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;

const int MX = 1000005;

struct Sieve{
    int n;
    vector<int> f, primes;
    Sieve(int n=1):n(n), f(n+1){
        f[0] = f[1] = -1;
        for(ll i=2; i<n; ++i){
            if(f[i]) continue;
            primes.push_back(i);
            f[i] = i;
            for(ll j=i*i; j<=n; j+=i){
                if(!f[j]) f[j] = i;
            }
        }
    }
    bool isPrime(int x){
        return f[x] == x;
    }
    vector<int> factor(int x){
        vector<int> res;
        while(x != 1){
            res.push_back(f[x]);
            x /= f[x];
        }
        return res;
    }
    vector<P> factor
};

int main()
{
    
}