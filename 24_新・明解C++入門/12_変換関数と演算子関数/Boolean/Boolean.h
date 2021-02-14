#ifndef ___Class_Boolean
#define ___Class_Boolean

#include <iostream>

class Boolean {
public:
  enum boolean { False, True};

private:
  boolean v;  // 真理値

public:
  // デフォルトコンストラクタ
  Boolean() : v(False){}
  // コンストラクタ
  Boolean(int val): v(val == 0 ? False : True) {}

  // int型への変換関数
  operator int() const { return v; }
  // const char*型への変換関数
  operator const char* () const { return v == False ? "False" : "True"; }
};

inline std::ostream& operator<<(std::ostream& s, Boolean& x){
  return s << static_cast<const char*>(x); 
}

#endif