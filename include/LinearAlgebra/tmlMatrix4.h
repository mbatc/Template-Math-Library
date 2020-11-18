#ifndef tmlMatrix4_h__
#define tmlMatrix4_h__

#include "tmlVector4.h"
#include "tmlQuaternion.h"

template<typename T> inline T atMatrixDet2x2(T a, T b, T c, T d);
template<typename T> inline T atMatrixDet3x3(T a, T b, T c, T d, T e, T f, T g, T h, T i);

template<typename T> class tmlMatrix4
{
public:
  tmlMatrix4(
    T _00 = 1, T _01 = 0, T _02 = 0, T _03 = 0,
    T _10 = 0, T _11 = 1, T _12 = 0, T _13 = 0,
    T _20 = 0, T _21 = 0, T _22 = 1, T _23 = 0,
    T _30 = 0, T _31 = 0, T _32 = 0, T _33 = 1);

  tmlMatrix4(tmlMatrix4<T> &&move);
  tmlMatrix4(const tmlMatrix4<T> &copy);

  template<typename T2> tmlMatrix4(const tmlMatrix4<T2> &copy);

  tmlMatrix4<T> Transpose() const;
  tmlMatrix4<T> Cofactors() const;
  tmlMatrix4<T> Inverse() const;

  T Determinate() const;

  tmlMatrix4<T> Mul(const T &rhs) const;
  tmlMatrix4<T> Sub(const T &rhs) const;
  tmlMatrix4<T> Add(const T &rhs) const;
  tmlMatrix4<T> AddDiagonal(const T &rhs) const;
  tmlMatrix4<T> Mul(const tmlMatrix4<T> &rhs) const;
  tmlVector4<T> Mul(const tmlVector4<T> &rhs) const;
  tmlVector3<T> Mul(const tmlVector3<T> &rhs) const;
  tmlMatrix4<T> Apply(T(*func)(const T &)) const;

  tmlVector3<T> GetTranslation() const;
  tmlVector3<T> GetRotation() const;
  tmlVector3<T> GetScale() const;
  tmlQuaternion<T> GetOrientation() const;

  void Decompose(tmlVector3<T> *pTranslation, tmlVector3<T> *pRotation, tmlVector3<T> *pScale) const;

  static tmlMatrix4<T> Identity();
  static tmlMatrix4<T> Projection(const T aspect, const T FOV, const T nearPlane, const T farPlane, const T zClipNear = 0, const T zClipFar = 1);
  static tmlMatrix4<T> Ortho(const T width, const T height, const T nearPlane, const T farPlane);
  static tmlMatrix4<T> Ortho(const T left, const T right, const T top, const T bottom, const T nearPlane, const T farPlane);
  static tmlMatrix4<T> RotationX(const T rads);
  static tmlMatrix4<T> RotationY(const T rads);
  static tmlMatrix4<T> RotationZ(const T rads);
  static tmlMatrix4<T> Rotation(const tmlVector3<T> &axis, T rads);
  static tmlMatrix4<T> Rotation(const tmlQuaternion<T> &quat);
  static tmlMatrix4<T> YawPitchRoll(const T yaw, const T pitch, const T roll);
  static tmlMatrix4<T> YawPitchRoll(const tmlVector3<T> &ypr);
  static tmlMatrix4<T> Translation(const tmlVector3<T> &translation);
  static tmlMatrix4<T> Scale(const tmlVector3<T> &scale);
  static tmlMatrix4<T> Scale(const tmlVector4<T> &scale);
  static tmlMatrix4<T> ScaleUniform(const T &scale);

  tmlVector4<T> operator*(const tmlVector4<T> &rhs) const;
  tmlVector3<T> operator*(const tmlVector3<T> &rhs) const;
  tmlMatrix4<T> operator*(const T &rhs) const;
  tmlMatrix4<T> operator*(const tmlMatrix4<T> &rhs) const;

  bool operator==(const tmlMatrix4<T> &rhs) const;
  bool operator!=(const tmlMatrix4<T> &rhs) const;
  const tmlMatrix4<T> &operator=(const tmlMatrix4<T> &copy);

  T& operator[](const int64_t index);
  const T& operator[](const int64_t index) const;

  union
  {
    T m[16];
    tmlVector4<T> row[4];
  };
};

#include "tmlMatrix4.inl"

#endif // tmlMatrix4_h__