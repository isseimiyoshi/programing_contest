#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

/* 大文字を小文字に変換 */
char tolower(char c) {return (c + 0x20);}
/* 小文字を大文字に変換 */
char toupr(char c) {return (c - 0x20);}

// if('A'<=s[i] && s[i]<='Z') s[i] += 'a'-'A';

/*
string s = "abcdefg"
s.substr(4) "efg"
s.substr(0,3) "abc"
s.substr(2,4) "cdef"
*/

struct NapSack {
    double v_per_w;
    double v;
    double w;

    NapSack(){
        v_per_w = 0; v = 0; w = 0;
    }

    NapSack(double in_v_p_w, double in_v, double in_w){
        v_per_w = in_v_p_w;
        v = in_v;
        w = in_w;
    }

    bool operator >= (const NapSack &p) const {
        if(v_per_w >= p.v_per_w) return true;
        else return false;
    }

    bool operator > (const NapSack &p) const {
        if(v_per_w > p.v_per_w) return true;
        else return false;
    }

    bool operator < (const NapSack &p) const {
        if(v_per_w < p.v_per_w) return true;
        else return false;
    }

    bool operator <= (const NapSack &p) const {
        if(v_per_w <= p.v_per_w) return true;
        else return false;
    }

};

int main()
{
    int N; double W; cin >> N >> W;
    vector<NapSack> napsacks(N);
    for(int i=0; i<N; i++){
        double vi, wi; cin >> vi >> wi;
        double vi_per_wi = vi / wi;    // 重さ１あたりの価値
        NapSack np(vi_per_wi, vi, wi);
        napsacks[i] = np;
    }
    sort(napsacks.begin(), napsacks.end(), greater<NapSack>()); //1重さあたりの価値の降順で並び替え
    double sum = 0.0;
    for(auto np: napsacks){
        if(np.w <= W){
            sum += np.v;
            W -= np.w;
        }else{
            sum += np.v_per_w*W;
            break;
        }
        // printf("%.5lf %.5lf %.5lf\n", np.v_per_w, np.v, np.w);
    }
    printf("%.5lf\n", sum);
}