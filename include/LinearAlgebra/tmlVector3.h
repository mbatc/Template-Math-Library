#ifndef tmlVector3_h__
#define tmlVector3_h__

#include "tmlVector2.h"

template<typename T> class tmlVector3
{
public:
  enum { ElementCount = 3 };

  tmlVector3();
  tmlVector3(T val);
  tmlVector3(T _x, T _y, T _z);
  tmlVector3(T _x, const atVector2<T> &yz);
  tmlVector3(const atVector2<T> &xy, T _z);
  tmlVector3(const tmlVector3<T> &copy);
  tmlVector3(tmlVector3<T> &&move);

  template<typename T2> tmlVector3(T2 _x, T2 _y, T2 _z);
  template<typename T2> tmlVector3(T2 _x, const atVector2<T2> &yz);
  template<typename T2> tmlVector3(const atVector2<T2> &xy, T2 _z);
  template<typename T2> tmlVector3(tmlVector3<T2> copy);
  template<typename T2> explicit tmlVector3(T2 val);

  static tmlVector3<T> zero();
  static tmlVector3<T> one();

  template<typename T2> const tmlVector3<T>& assign(T2 _x, T2 _y, T2 _z);
  template<typename T2> const tmlVector3<T>& assign(const tmlVector3<T2> &rhs);

  const tmlVector3<T>& assign(T _x, T _y, T _z);
  const tmlVector3<T>& assign(const tmlVector3<T> &rhs);

  T& operator[](int64_t index);
  const T& operator[](int64_t index) const;

  tmlVector3<T> operator-() const;
  tmlVector3<T> operator+(const tmlVector3<T> &rhs) const;
  tmlVector3<T> operator-(const tmlVector3<T> &rhs) const;
  tmlVector3<T> operator*(const tmlVector3<T> &rhs) const;
  tmlVector3<T> operator/(const tmlVector3<T> &rhs) const;
  tmlVector3<T> operator%(const tmlVector3<T> &rhs) const;

  const tmlVector3<T>& operator+=(const tmlVector3<T> &rhs);
  const tmlVector3<T>& operator-=(const tmlVector3<T> &rhs);
  const tmlVector3<T>& operator*=(const tmlVector3<T> &rhs);
  const tmlVector3<T>& operator/=(const tmlVector3<T> &rhs);
  const tmlVector3<T>& operator%=(const tmlVector3<T> &rhs);
  const tmlVector3<T>& operator=(const tmlVector3<T> &rhs);

  bool operator==(const tmlVector3<T> &rhs) const;
  bool operator!=(const tmlVector3<T> &rhs) const;

  atVector2<T> xy() const;
  atVector2<T> xz() const;
  atVector2<T> yz() const;

  T Mag() const;
  T Length() const;
  T Dot(const tmlVector3<T> &rhs) const;
  T Angle(const tmlVector3<T> &rhs) const;

  tmlVector3<T> Add(const tmlVector3<T> &rhs);
  tmlVector3<T> Sub(const tmlVector3<T> &rhs);
  tmlVector3<T> Mul(const tmlVector3<T> &rhs);
  tmlVector3<T> Div(const tmlVector3<T> &rhs);

  tmlVector3<T> Normalize() const;
  tmlVector3<T> Reflect(const tmlVector3<T> &norm) const;
  tmlVector3<T> Cross(const tmlVector3<T> &rhs) const;
  tmlVector3<T> Project(const tmlVector3<T> &to) const;

  // Returns a vector with where each component is the max of this and the input vectors components.
  tmlVector3<T> Max(const tmlVector3<T> &b) const;

  // Returns a vector with where each component is the min of this and the input vectors components.
  tmlVector3<T> Min(const tmlVector3<T> &b) const;

  // Returns a vector with where each component is clamped to the min/max of this and the input vectors components
  tmlVector3<T> Clamp(const tmlVector3<T> &min, const tmlVector3<T> &max) const;

  static T Mag(const tmlVector3<T> &rhs);
  static T Length(const tmlVector3<T> &rhs);
  static T Dot(const tmlVector3<T> &lhs, const tmlVector3<T> &rhs);
  static T Angle(const tmlVector3<T> &lhs, const tmlVector3<T> &rhs);

  static tmlVector3<T> Normalize(const tmlVector3<T> &rhs);
  static tmlVector3<T> Cross(const tmlVector3<T> &lhs, const tmlVector3<T> &rhs);
  static tmlVector3<T> Reflect(const tmlVector3<T> &dir, const tmlVector3<T> &norm);
  static tmlVector3<T> Project(const tmlVector3<T> &vec, const tmlVector3<T> &to);

  // Returns a vector with where each component is the max of the input vectors components.
  static tmlVector3<T> Max(const tmlVector3<T> &a, const tmlVector3<T> &b);

  // Returns a vector with where each component is the min of the input vectors components.
  static tmlVector3<T> Min(const tmlVector3<T> &a, const tmlVector3<T> &b);

  // Returns a vector with where each component is clamped to the min/max of the input vectors components
  static tmlVector3<T> Clamp(const tmlVector3<T> &vec, const tmlVector3<T> &min, const tmlVector3<T> &max);

  T* begin();
  T* end();
  const T* begin() const;
  const T* end() const;

  T* data();
  const T* data() const;

  union
  {
    struct
    {
      T x;
      T y;
      T z;
    };

    T m[ElementCount];
  };
};

#include "tmlVector3.inl"

#endif // tmlVector3_h__
