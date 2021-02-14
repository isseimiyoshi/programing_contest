#include <string>
#include <iostream>

class Date{
  int y,m,d;
public:
  Date();
  Date(int yy, int mm=1, int dd=1);
  int year() const { return y; }
  int month() const { return m; }
  int day() const { return d; }

  Date preceding_day() const;

  std::string to_string() const;
};
std::ostream& operator<<(std::ostream& s, const Date& x); // 挿入子
std::istream& operator>>(std::istream& s, Date& x); // 抽出子