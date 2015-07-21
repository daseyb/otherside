#pragma once
template<typename T>
inline int Cmp(Value op1, Value op2) {
  T a = *(T*)op1.Memory;
  T b = *(T*)op2.Memory;
  return a < b ? -1 : a == b ? 0 : 1;
}

template<typename T>
inline T Add(Value op1, Value op2) {
  T a = *(T*)op1.Memory;
  T b = *(T*)op2.Memory;
  return a + b;
}

template<typename T>
inline T Sub(Value op1, Value op2) {
  T a = *(T*)op1.Memory;
  T b = *(T*)op2.Memory;
  return a - b;
}

template<typename T>
inline T Div(Value op1, Value op2) {
  T a = *(T*)op1.Memory;
  T b = *(T*)op2.Memory;
  return a / b;
}

template<typename T>
inline T Mul(Value op1, Value op2) {
  T a = *(T*)op1.Memory;
  T b = *(T*)op2.Memory;
  return a * b;
}

template<typename S, typename D>
inline D Convert(Value op) {
  return (D)*(S*)op.Memory;
}
