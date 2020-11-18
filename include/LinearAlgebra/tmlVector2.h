#ifndef tmlVector2_h__
#define tmlVector2_h__

template<typename T> class tmlVector2
{
public:
  enum { ElementCount = 2 };

  tmlVector2();
  tmlVector2(T val);
  tmlVector2(T _x, T _y);
  tmlVector2(const tmlVector2<T> &copy);
  tmlVector2(tmlVector2<T> &&move);

  template<typename T2> explicit tmlVector2(T2 val);
  template<typename T2> tmlVector2(T2 _x, T2 _y);
  template<typename T2> tmlVector2(const tmlVector2<T2> &copy);

  static tmlVector2<T> zero();
  static tmlVector2<T> one();

  const tmlVector2<T>& assign(T x, T y);
  const tmlVector2<T>& assign(const tmlVector2<T> &rhs);

  template<typename T2> const tmlVector2<T>& assign(T2 x, T2 y);
  template<typename T2> const tmlVector2<T>& assign(const tmlVector2<T2> &rhs);

  T* data();
  const T* data() const;
  T& operator[](int64_t index);
  const T& operator[](int64_t index) const;

  tmlVector2<T> operator-() const;
  tmlVector2<T> operator+(const tmlVector2<T> &rhs) const;
  tmlVector2<T> operator-(const tmlVector2<T> &rhs) const;
  tmlVector2<T> operator*(const tmlVector2<T> &rhs) const;
  tmlVector2<T> operator/(const tmlVector2<T> &rhs) const;
  tmlVector2<T> operator%(const tmlVector2<T> &rhs) const;

  const tmlVector2<T>& operator+=(const tmlVector2<T> &rhs);
  const tmlVector2<T>& operator-=(const tmlVector2<T> &rhs);
  const tmlVector2<T>& operator*=(const tmlVector2<T> &rhs);
  const tmlVector2<T>& operator/=(const tmlVector2<T> &rhs);
  const tmlVector2<T>& operator%=(const tmlVector2<T> &rhs);
  const tmlVector2<T>& operator=(const tmlVector2<T> &rhs);

  bool operator==(const tmlVector2<T> &rhs) const;
  bool operator!=(const tmlVector2<T> &rhs) const;

  tmlVector2<T> Add(const tmlVector2<T> &rhs) const;
  tmlVector2<T> Sub(const tmlVector2<T> &rhs) const;
  tmlVector2<T> Mul(const tmlVector2<T> &rhs) const;
  tmlVector2<T> Div(const tmlVector2<T> &rhs) const;

  T Mag() const;
  T Length() const;
  T Dot(const tmlVector2<T> &rhs) const;
  T Angle(const tmlVector2<T> &rhs) const;

  tmlVector2<T> Normalize() const;
  tmlVector2<T> Reflect(const tmlVector2<T> &norm) const;
  tmlVector2<T> Project(const tmlVector2<T> &to) const;

  // Returns a vector with where each component is the max of this and the input vectors components.
  tmlVector2<T> Max(const tmlVector2<T> &b) const;

  // Returns a vector with where each component is the min of this and the input vectors components.
  tmlVector2<T> Min(const tmlVector2<T> &b) const;

  // Returns a vector with where each component is clamped to the min/max of this and the input vectors components
  tmlVector2<T> Clamp(const tmlVector2<T> &min, const tmlVector2<T> &max) const;

  static T Mag(const tmlVector2<T> &rhs);
  static T Length(const tmlVector2<T> &rhs);
  static T Dot(const tmlVector2<T> &lhs, const tmlVector2<T> &rhs);
  static T Angle(const tmlVector2<T> &lhs, const tmlVector2<T> &rhs);

  static tmlVector2<T> Project(const tmlVector2<T> &vec, const tmlVector2<T> &to);
  static tmlVector2<T> Reflect(const tmlVector2<T> &dir, const tmlVector2<T> &norm);
  static tmlVector2<T> Normalize(const tmlVector2<T> &rhs);

  // Returns a vector with where each component is the max of the input vectors components.
  static tmlVector2<T> Max(const tmlVector2<T> &a, const tmlVector2<T> &b);

  // Returns a vector with where each component is the min of the input vectors components.
  static tmlVector2<T> Min(const tmlVector2<T> &a, const tmlVector2<T> &b);

  // Returns a vector with where each component is clamped to the min/max of the input vectors components
  static tmlVector2<T> Clamp(const tmlVector2<T> &vec, const tmlVector2<T> &min, const tmlVector2<T> &max);

  T* begin();
  T* end();
  const T* begin() const;
  const T* end() const;

  union
  {
    struct
    {
      T x;
      T y;
    };

    T m[ElementCount];
  };
};

#include "tmlVector2.inl"

#endif // tmlVector2_h__
