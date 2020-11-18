#ifndef tmlQuaternion_h__
#define tmlQuaternion_h__

#include "tmlMatrix4.h"

template<typename T>
class tmlQuaternion
{
public:
  tmlQuaternion();
  tmlQuaternion(const T &x, const T &y, const T &z, const T &w);
  tmlQuaternion(const tmlVector3<T> &axis, const T &angle);
  tmlQuaternion(const T &eulerX, const T &eulerY, const T &eulerZ);
  explicit tmlQuaternion(const atMatrix4x4<T> &rotation);

  void Set(const T &x, const T &y, const T &z, const T &w);
  void Set(const tmlVector3<T> &axis, const T &angle);
  void Set(const T &eulerX, const T &eulerY, const T &eulerZ);
  void Set(const atMatrix4x4<T> &rotation);

  static tmlQuaternion<T> zero();
  static tmlQuaternion<T> Identity();

  static tmlQuaternion<T> Normalize(const tmlQuaternion<T> &quat);
  static tmlQuaternion<T> Inverse(const tmlQuaternion<T> &quat);
  static tmlQuaternion<T> Mul(const tmlQuaternion<T> &lhs, const tmlQuaternion<T> &rhs);
  static tmlQuaternion<T> Mul(const tmlQuaternion<T> &lhs, const T &rhs);
  static tmlQuaternion<T> Add(const tmlQuaternion<T> &lhs, const tmlQuaternion<T> &rhs);
  static tmlQuaternion<T> Sub(const tmlQuaternion<T> &lhs, const tmlQuaternion<T> &rhs);
  static tmlQuaternion<T> Div(const tmlQuaternion<T> &lhs, const T &rhs);

  static T AngleTo(const tmlQuaternion<T> &from, const tmlQuaternion<T> &to);
  static T Angle(const tmlQuaternion<T> &quat);
  static T Length(const tmlQuaternion<T> &quat);
  static T Mag(const tmlQuaternion<T> &quat);
  static T Dot(const tmlQuaternion<T> &lhs, const tmlQuaternion<T> &rhs);

  static tmlVector3<T> Rotate(const tmlQuaternion<T> &quat, const tmlVector3<T> &vec);
  static tmlVector3<T> Axis(const tmlQuaternion<T> &quat);
  static tmlVector3<T> EulerAngles(const tmlQuaternion<T> &quat);

  tmlQuaternion<T> Slerp(const tmlQuaternion &to, const T &factor) const;
  tmlQuaternion<T> Normalize() const;
  tmlQuaternion<T> Inverse() const;
  tmlQuaternion<T> Mul(const tmlQuaternion<T> &rhs) const;
  tmlQuaternion<T> Mul(const T &rhs) const;
  tmlQuaternion<T> Add(const tmlQuaternion<T> &rhs) const;
  tmlQuaternion<T> Sub(const tmlQuaternion<T> &rhs) const;
  tmlQuaternion<T> Div(const T &rhs) const;

  T AngleTo(const tmlQuaternion<T> &to) const;
  T Angle() const;
  T Length() const;
  T Mag() const;
  T Dot(const tmlQuaternion<T> &rhs) const;

  tmlVector3<T> EulerAngles() const;
  tmlVector3<T> Axis() const;
  tmlVector3<T> Rotate(const tmlVector3<T> &vec) const;

  bool operator==(const tmlQuaternion<T> &rhs) const;
  bool operator!=(const tmlQuaternion<T> &rhs) const;

  tmlQuaternion<T> operator*(const tmlQuaternion<T> &rhs) const;
  tmlQuaternion<T> operator-(const tmlQuaternion<T> &rhs) const;
  tmlQuaternion<T> operator+(const tmlQuaternion<T> &rhs) const;
  tmlQuaternion<T> operator*(const T &rhs) const;
  tmlQuaternion<T> operator/(const T &rhs) const;
  tmlQuaternion<T> operator-() const;

  const tmlQuaternion<T>& operator=(const tmlQuaternion<T> &rhs);
  const tmlQuaternion<T>& operator*=(const tmlQuaternion<T> &rhs);
  const tmlQuaternion<T>& operator*=(const T &rhs);

  const T& at(int64_t index) const;
  const T& operator[](int64_t index) const;
  T& at(int64_t index);
  T& operator[](int64_t index);

  const T* begin() const;
  const T* end() const;
  T* begin();
  T* end();

  T x;
  T y;
  T z;
  T w;
};

template<typename T> tmlQuaternion<T> operator*(const tmlVector3<T> &lhs, const tmlQuaternion<T> &rhs);
template<typename T> tmlQuaternion<T> operator*(const tmlQuaternion<T> &lhs, const tmlVector3<T> &rhs);

#include "tmlQuaternion.inl"

#endif // tmlQuaternion_h__
