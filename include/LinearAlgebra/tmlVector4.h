#ifndef tmlVector4_h__
#define tmlVector4_h__

#include "tmlVector3.h"

template<typename T> class tmlVector4
{
public:
  enum { ElementCount = 4 };

  tmlVector4();
  tmlVector4(T val);
  tmlVector4(T _x, T _y, T _z, T _w);
  tmlVector4(const tmlVector3<T> &xyz, T _w);
  tmlVector4(T _x, const tmlVector3<T> &yzw);
  tmlVector4(T _x, T _y, const tmlVector2<T> &zw);
  tmlVector4(T _x, const tmlVector2<T> &yz, T _w);
  tmlVector4(const tmlVector2<T> &xy, T _z, T _w);
  tmlVector4(const tmlVector2<T> &xy, const tmlVector2<T> &yw);

  template<typename T2> explicit tmlVector4(T2 val);
  template<typename T2> tmlVector4(T2 _x, T2 _y, T2 _z, T2 _w);
  template<typename T2> tmlVector4(const tmlVector3<T2> &xyz, T2 _w);
  template<typename T2> tmlVector4(T2 _x, const tmlVector3<T2> &yzw);
  template<typename T2> tmlVector4(T2 _x, T2 _y, const tmlVector2<T2> &zw);
  template<typename T2> tmlVector4(T2 _x, const tmlVector2<T2> &yz, T2 _w);
  template<typename T2> tmlVector4(const tmlVector2<T2> &xy, T2 _z, T2 _w);
  template<typename T2> tmlVector4(const tmlVector2<T2> &xy, const tmlVector2<T2> &yw);
  template<typename T2> tmlVector4(tmlVector4<T2> copy);

  tmlVector4(const tmlVector4<T> &copy);
  tmlVector4(tmlVector4<T> &&move);

  static tmlVector4<T> zero();
  static tmlVector4<T> one();

  template<typename T2> const tmlVector4<T>& assign(T2 _x, T2 _y, T2 _z, T2 _w);
  template<typename T2> const tmlVector4<T>& assign(const tmlVector4<T2> &rhs);
  const tmlVector4<T>& assign(T x, T y, T z, T w);
  const tmlVector4<T>& assign(const tmlVector4<T> &rhs);

  T& operator[](const int64_t index);
  const T& operator[](const int64_t index) const;

  tmlVector4<T> operator-() const;
  tmlVector4<T> operator+(const tmlVector4<T> &rhs) const;
  tmlVector4<T> operator-(const tmlVector4<T> &rhs) const;
  tmlVector4<T> operator*(const tmlVector4<T> &rhs) const;
  tmlVector4<T> operator/(const tmlVector4<T> &rhs) const;
  tmlVector4<T> operator%(const tmlVector4<T> &rhs) const;
  const tmlVector4<T>& operator+=(const tmlVector4<T> &rhs);
  const tmlVector4<T>& operator-=(const tmlVector4<T> &rhs);
  const tmlVector4<T>& operator*=(const tmlVector4<T> &rhs);
  const tmlVector4<T>& operator/=(const tmlVector4<T> &rhs);
  const tmlVector4<T>& operator%=(const tmlVector4<T> &rhs);
  const tmlVector4<T>& operator=(const tmlVector4<T> &rhs);
  bool operator==(const tmlVector4<T> &rhs) const;
  bool operator!=(const tmlVector4<T> &rhs) const;

  tmlVector2<T> xy() const;
  tmlVector2<T> xz() const;
  tmlVector2<T> xw() const;
  tmlVector2<T> yz() const;
  tmlVector2<T> yw() const;
  tmlVector2<T> zw() const;
  tmlVector3<T> xyz() const;
  tmlVector3<T> xzw() const;
  tmlVector3<T> xyw() const;
  tmlVector3<T> yzw() const;

  tmlVector4<T> Add(const tmlVector4<T> &rhs) const;
  tmlVector4<T> Sub(const tmlVector4<T> &rhs) const;
  tmlVector4<T> Mul(const tmlVector4<T> &rhs) const;
  tmlVector4<T> Div(const tmlVector4<T> &rhs) const;

  T Mag() const;
  T Length() const;
  T Dot(const tmlVector4<T> &rhs) const;
  T Angle(const tmlVector4<T> &rhs) const;

  tmlVector4<T> Normalize() const;
  tmlVector4<T> Reflect(const tmlVector4<T> &norm) const;
  tmlVector4<T> Project(const tmlVector4<T> &to) const;

  // Returns a vector with where each component is the max of this and the input vectors components.
  tmlVector4<T> Max(const tmlVector4<T> &b) const;

  // Returns a vector with where each component is the min of this and the input vectors components.
  tmlVector4<T> Min(const tmlVector4<T> &b) const;

  // Returns a vector with where each component is clamped to the min/max of this and the input vectors components
  tmlVector4<T> Clamp(const tmlVector4<T> &min, const tmlVector4<T> &max) const;

  static T Mag(const tmlVector4<T> &rhs);
  static T Length(const tmlVector4<T> &rhs);
  static T Dot(const tmlVector4<T> &lhs, const tmlVector4<T> &rhs);
  static T Angle(const tmlVector4<T> &lhs, const tmlVector4<T> &rhs);

  static tmlVector4<T> Reflect(const tmlVector4<T> &dir, const tmlVector4<T> &norm);
  static tmlVector4<T> Normalize(const tmlVector4<T> &rhs);
  static tmlVector4<T> Project(const tmlVector4<T> &vec, const tmlVector4<T> &to);

  // Returns a vector with where each component is the max of the input vectors components.
  static tmlVector4<T> Max(const tmlVector4<T> &a, const tmlVector4<T> &b);

  // Returns a vector with where each component is the min of the input vectors components.
  static tmlVector4<T> Min(const tmlVector4<T> &a, const tmlVector4<T> &b);

  // Returns a vector with where each component is clamped to the min/max of the input vectors components
  static tmlVector4<T> Clamp(const tmlVector4<T> &vec, const tmlVector4<T> &min, const tmlVector4<T> &max);

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
      T w;
    };

    T m[ElementCount];
  };
};

template<typename T> inline tmlVector4<T> operator*(const T &lhs, const tmlVector4<T> &rhs);
template<typename T> inline tmlVector4<T> operator/(const T &lhs, const tmlVector4<T> &rhs);

#include "tmlVector4.inl"

#endif // tmlVector4_h__
