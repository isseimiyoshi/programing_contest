#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;

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

// イテレータ要素のインデックス
distance(A.begin(), itr);
*/

int main()
{
    int n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    sort(a.begin(), a.end());

    if(a[n-1]<0 || a[0]>=0){   // 配列に0未満の整数のみ
        if(a[n-1]<0) reverse(a.begin(), a.end());
        ll cnt = 0;
        ll ori_n = n;
        n-=1;
        while(k>n){
            k -= n;
            cnt++;
            n -= 1;
        }
        cout << a[cnt]*a[cnt+k] << endl;
    }else{
        ll pnum = 0, mnum = 0;
        vector<ll> pv, mv;
        rep(i,n){
            if(a[i]>=0){
                pnum++;
                pv.push_back(a[i]);
            }else{
                mnum++;
                mv.push_back(a[i]);
            }

        }
        if(k<=pnum*mnum){
            if(k%pnum == 0){
                cout << mv[k/pnum-1]*pv[pnum-1] << endl;
            }else{
                cout << mv[k/pnum]*pv[k%pnum-1] << endl;
            }
        }else{
            vector<pair<ll,ll> > lv;
            rep(i,pnum){
                lv.push_back(make_pair(pv[i],1));
            }
            rep(i,mnum){
                lv.push_back(make_pair(-mv[i], -1));
            }

            sort(lv.begin(), lv.end());

            int ori_pnum = pnum;
            int ori_mnum = mnum;
            pnum--, mnum--;

            vector<ll> ruiseki;
            for(auto l : lv){
                ll ln = l.first, li = l.second;
                if(li == 1){
                    ruiseki.push_back(pnum);
                    pnum--;
                }else{
                    ruiseki.push_back(mnum);
                    mnum--;
                }
            }


            k -= ori_pnum*ori_mnum;

            // cout << k << endl;

            int in1;
            int in2;
            int lvs = lv.size();
            rep(i,ruiseki.size()){
                if(i == 0) continue;
                ruiseki[i] = ruiseki[i] + ruiseki[i-1];

                if(ruiseki[i] == k){
                    in1 = i;
                    if(ruiseki[i] == ruiseki[i-1]) in2 = ruiseki[i]-ruiseki[i-2];
                    else in2 = ruiseki[i]-ruiseki[i-1];
                    break;
                }else if(ruiseki[i]>k){
                    in1 = i;
                    in2 = k-ruiseki[i-1];
                    break;
                }
                if(i == ruiseki.size()-1){
                    if(pv[pnum-1] >= mv[mnum-1]) cout << pv[pnum-1]*pv[pnum-2] << endl;
                    else cout << mv[mnum-1]*pv[mnum-2] << endl;
                    return 0;
                }
                
            }

            ll n1 = lv[in1].first;
            bool isok = false;
            if(lv[in1].second == 1){
                int cnt = 0;
                rep(i,(int)pv.size()){
                    if(pv[i] == n1){
                        isok = true;
                        continue;
                    }
                    if(isok) cnt++;
                    if(cnt == in2){
                        cout << n1*pv[i] << endl;
                        return 0;
                    }
                }
            }else{
                int cnt = 0;
                rep(i,(int)mv.size()){
                    if(mv[i] == n1){
                        isok = true;
                        continue;
                    }
                    if(isok) cnt++;
                    if(cnt == in2){
                        cout << n1*mv[i] << endl;
                        return 0;
                    }
                }
            }
            

        }
    }
}