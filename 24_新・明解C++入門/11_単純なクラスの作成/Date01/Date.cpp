#include <cstdio>
#include <ctime>
#include <sstream>
#include <iostream>
#include "Date.h"

using namespace std;

Date::Date(){
  time_t current = time(NULL);    // 現在の歴時刻を取得
  struct tm* local = localtime(&current); // 要素別の時刻に変換

  y = local->tm_year + 1900;
  m = local->tm_mon + 1;
  d = local->tm_mday;
}

Date::Date(int yy, int mm, int dd){
  y = yy;
  m = mm;
  d = dd;
}

// 前日の日付を返却（うるう年に非対応)
Date Date::preceding_day() const {
  int dmax[] = {31,28,31,30,31,30,31,31,30,31,30,31};
  Date temp = *this;  // 同一の日付

  if(temp.d > 1){
    temp.d--;
  }else{
    if(--temp.m<1){
      temp.y--;
      temp.m = 12;
    }
    temp.d = dmax[temp.m-1];
  }
  return temp;
}

string Date::to_string() const {
  ostringstream s;
  s << y << "年" << m << "月" << d << "日";
  return s.str(); 
}

ostream& operator<<(ostream& s, const Date& x){
  return s << x.to_string();
}

istream& operator>>(istream& s, Date& x){
  int yy,mm,dd;
  char ch;
  s>>yy>>ch>>mm>>ch>>dd;
  x = Date(yy,mm,dd);
  return s;
}

