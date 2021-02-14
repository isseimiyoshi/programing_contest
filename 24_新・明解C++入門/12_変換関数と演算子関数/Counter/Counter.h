#ifndef ___Class_Counter
#define ___Class_Counter

#include <climits>

class Counter {
  unsigned cnt;

public:
  Counter() : cnt(0){}  // コンストラクタ初期化子で初期化

  void increment() { if(cnt<UINT_MAX) cnt++; }
  void decrement() { if(cnt>0) cnt--; }
  unsigned value() { return cnt; }  // cntのゲッタ

  // unsigned型への変換関数
  operator unsigned() const { return cnt; }
  bool operator!() const { return cnt == 0; }
  // 前置演算子
  Counter& operator++() {
    if(cnt<UINT_MAX) cnt++;
    return *this; // インクリメント後の自分自身への参照を返却するために*thisを返却
  }
  // 後置演算子
  Counter operator++(int){
    Counter x = *this;
    ++(*this);
    return x;
  }

  Counter& operator--(){
    if(cnt>0){ cnt--; }
    return *this;
  }

  Counter operator--(int){
    Counter x = *this;
    --(*this);
    return x;
  }

};

#endif