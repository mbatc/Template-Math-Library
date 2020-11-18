
template<typename T>
inline tmlVector2<T>::tmlVector2()
  : x(0)
  , y(0)
{}

template<typename T>
inline tmlVector2<T>::tmlVector2(T val)
  : x(val)
  , y(val)
{}

template<typename T>
inline tmlVector2<T>::tmlVector2(T _x, T _y)
  : x(_x)
  , y(_y)
{}

template<typename T>
inline tmlVector2<T>::tmlVector2(const tmlVector2<T> &copy)
  : x(copy.x)
  , y(copy.y)
{}

template<typename T>
inline tmlVector2<T>::tmlVector2(tmlVector2<T> &&move)
  : x(move.x)
  , y(move.y)
{}

template<typename T>
template<typename T2>
inline tmlVector2<T>::tmlVector2(T2 val)
  : x((T)val)
  , y((T)val)
{}

template<typename T>
template<typename T2>
inline tmlVector2<T>::tmlVector2(T2 _x, T2 _y)
  : x((T)_x)
  , y((T)_y)
{}

template<typename T>
template<typename T2> 
inline tmlVector2<T>::tmlVector2(const tmlVector2<T2> &copy)
  : x((T)copy.x)
  , y((T)copy.y)
{}

template<typename T>
inline tmlVector2<T> tmlVector2<T>::zero()
{
  return tmlVector2<T>(0);
}

template<typename T>
inline tmlVector2<T> tmlVector2<T>::one()
{
  return tmlVector2<T>(1);
}

template<typename T>
inline const tmlVector2<T>& tmlVector2<T>::assign(T x, T y)
{
  this->x = x;
  this->y = y;
  return *this;
}

template<typename T>
template<typename T2>
inline const tmlVector2<T>& tmlVector2<T>::assign(T2 x, T2 y)
{
  this->x = (T)x;
  this->y = (T)y;
  return *this;
}

template<typename T>
inline const tmlVector2<T>& tmlVector2<T>::assign(const tmlVector2<T> &rhs)
{
  x = rhs.x;
  y = rhs.y;
  return *this;
}

template<typename T>
template<typename T2>
inline const tmlVector2<T>& tmlVector2<T>::assign(const tmlVector2<T2> &rhs)
{
  x = (T)rhs.x;
  y = (T)rhs.y;
  return *this;
}

template<typename T>
inline tmlVector2<T> tmlVector2<T>::Normalize() const
{
  return Normalize(*this);
}

template<typename T>
inline T tmlVector2<T>::Length(const tmlVector2<T> &rhs)
{
  return rhs.x * rhs.x + rhs.y * rhs.y;
}

template<typename T>
inline T tmlVector2<T>::Dot(const tmlVector2<T> &lhs, const tmlVector2<T> &rhs)
{
  return  lhs.x * rhs.x +
    lhs.y * rhs.y +
    lhs.z * rhs.z;
}

template<typename T>
inline T tmlVector2<T>::Angle(const tmlVector2<T> &lhs, const tmlVector2<T> &rhs)
{
  return tmlACos(Dot(lhs, rhs) / (lhs.Mag() * rhs.Mag()));
}

template<typename T>
inline tmlVector2<T> tmlVector2<T>::Project(const tmlVector2<T> &vec, const tmlVector2<T> &to)
{
  return vec * to.Normalize();
}

template<typename T>
inline tmlVector2<T> tmlVector2<T>::Reflect(const tmlVector2<T> &dir, const tmlVector2<T> &norm)
{
  return dir - norm * Dot(dir, norm) * 2;
}

template<typename T>
inline tmlVector2<T> tmlVector2<T>::Max(const tmlVector2<T> &a, const tmlVector2<T> &b)
{
  return tmlVector2<T>(atMax(a.x, b.x), tmlMax(a.y, b.y));
}

template<typename T>
inline tmlVector2<T> tmlVector2<T>::Min(const tmlVector2<T> &a, const tmlVector2<T> &b)
{
  return tmlVector2<T>(atMin(a.x, b.x), tmlMin(a.y, b.y));
}

template<typename T>
inline tmlVector2<T> tmlVector2<T>::Clamp(const tmlVector2<T> &vec, const tmlVector2<T> &min, const tmlVector2<T> &max)
{
  return Max(min, Min(vec, max));
}

template<typename T>
inline tmlVector2<T> tmlVector2<T>::Add(const tmlVector2<T> &rhs) const
{
  return *this + rhs;
}

template<typename T>
inline tmlVector2<T> tmlVector2<T>::Sub(const tmlVector2<T> &rhs) const
{
  return *this - rhs;
}

template<typename T>
inline tmlVector2<T> tmlVector2<T>::Mul(const tmlVector2<T> &rhs) const
{
  return *this * rhs;
}

template<typename T>
inline tmlVector2<T> tmlVector2<T>::Div(const tmlVector2<T> &rhs) const
{
  return *this / rhs;
}

template<typename T>
inline T tmlVector2<T>::Mag() const
{
  return Mag(*this);
}

template<typename T>
inline T tmlVector2<T>::Length() const
{
  return Length(*this);
}

template<typename T>
inline T tmlVector2<T>::Dot(const tmlVector2<T> &rhs) const
{
  return Dot(*this, rhs);
}

template<typename T>
inline T tmlVector2<T>::Angle(const tmlVector2<T> &rhs) const
{
  return Angle(*this, rhs);
}

template<typename T>
inline tmlVector2<T> tmlVector2<T>::Reflect(const tmlVector2<T> &norm) const
{
  return Reflect(*this, norm);
}

template<typename T>
inline tmlVector2<T> tmlVector2<T>::Project(const tmlVector2<T> &to) const
{
  return Project(*this, to);
}

template<typename T>
inline tmlVector2<T> tmlVector2<T>::Max(const tmlVector2<T> &b) const
{
  return Max(*this, b);
}

template<typename T>
inline tmlVector2<T> tmlVector2<T>::Min(const tmlVector2<T> &b) const
{
  return Min(*this, b);
}

template<typename T>
inline tmlVector2<T> tmlVector2<T>::Clamp(const tmlVector2<T> &min, const tmlVector2<T> &max) const
{
  return Clamp(*this, min, max);
}

template<typename T>
inline T tmlVector2<T>::Mag(const tmlVector2<T> &rhs)
{
  return tmlSqrt(Length(rhs));
}

template<typename T>
inline tmlVector2<T> tmlVector2<T>::Normalize(const tmlVector2<T> &rhs)
{
  return rhs / rhs.Mag();
}

template<typename T>
inline const T* tmlVector2<T>::end() const
{
  return data() + 2;
}

template<typename T>
inline const T* tmlVector2<T>::begin() const
{
  return data();
}

template<typename T>
inline T* tmlVector2<T>::end()
{
  return data() + 2;
}

template<typename T>
inline T* tmlVector2<T>::begin()
{
  return data();
}

template<typename T>
inline T* tmlVector2<T>::data()
{
  return m;
}

template<typename T>
inline const T* tmlVector2<T>::data() const
{
  return m;
}

template<typename T>
inline T& tmlVector2<T>::operator[](int64_t index)
{
  return data()[index];
}

template<typename T>
inline const T& tmlVector2<T>::operator[](int64_t index) const
{
  return data()[index];
}

template<typename T>
inline tmlVector2<T> tmlVector2<T>::operator-() const
{
  return tmlVector2<T>(-x, -y);
}

template<typename T>
inline tmlVector2<T> tmlVector2<T>::operator+(const tmlVector2<T> &rhs) const
{
  return tmlVector2<T>(x + rhs.x, y + rhs.y);
}

template<typename T>
inline tmlVector2<T> tmlVector2<T>::operator-(const tmlVector2<T> &rhs) const
{
  return tmlVector2<T>(x - rhs.x, y - rhs.y);
}

template<typename T>
inline tmlVector2<T> tmlVector2<T>::operator*(const tmlVector2<T> &rhs) const
{
  return tmlVector2<T>(x * rhs.x, y * rhs.y);
}

template<typename T>
inline tmlVector2<T> tmlVector2<T>::operator/(const tmlVector2<T> &rhs) const
{
  return tmlVector2<T>(x / rhs.x, y / rhs.y);
}

template<typename T>
inline tmlVector2<T> tmlVector2<T>::operator%(const tmlVector2<T> &rhs) const
{
  return tmlVector2<T>(atMod(x, rhs.x), tmlMod(y, rhs.y));
}

template<typename T>
inline const tmlVector2<T>& tmlVector2<T>::operator+=(const tmlVector2<T> &rhs)
{
  return assign(*this + rhs);
}

template<typename T>
inline const tmlVector2<T>& tmlVector2<T>::operator-=(const tmlVector2<T> &rhs)
{
  return assign(*this - rhs);
}

template<typename T>
inline const tmlVector2<T>& tmlVector2<T>::operator*=(const tmlVector2<T> &rhs)
{
  return assign(*this * rhs);
}

template<typename T>
inline const tmlVector2<T>& tmlVector2<T>::operator/=(const tmlVector2<T> &rhs)
{
  return assign(*this / rhs);
}

template<typename T>
inline const tmlVector2<T>& tmlVector2<T>::operator%=(const tmlVector2<T> &rhs)
{
  return assign(*this % rhs);
}

template<typename T>
inline const tmlVector2<T>& tmlVector2<T>::operator=(const tmlVector2<T> &rhs)
{
  return assign(rhs); }

template<typename T>
inline bool tmlVector2<T>::operator==(const tmlVector2<T> &rhs) const
{
  return x == rhs.x && y == rhs.y;
}

template<typename T>
inline bool tmlVector2<T>::operator!=(const tmlVector2<T> &rhs) const
{
  return !(*this == rhs);
}

template<typename T>
inline T tmlATan2(const tmlVector2<T> &pos)
{
  return tmlATan2(pos.x, pos.y);
}

template<typename T>
inline tmlVector2<T> operator*(const T &lhs, const tmlVector2<T>& rhs)
{
  return rhs * lhs;
}

template<typename T>
inline tmlVector2<T> operator/(const T &lhs, const tmlVector2<T>& rhs)
{
  return tmlVector2<T>(lhs / rhs.x, lhs / rhs.y);
}
