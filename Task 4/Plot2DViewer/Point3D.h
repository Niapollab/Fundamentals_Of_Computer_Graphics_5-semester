#pragma once

template<class T>
class Point3D
{
private:
    T _x;
    T _y;
    T _z;

public:
    Point3D();
    Point3D(const T& x, const T& y, const T& z);

    const T& x() const;
    T& x();
    const T& y() const;
    T& y();
    const T& z() const;
    T& z();
};

template<class T>
Point3D<T>::Point3D() : _x(T()), _y(T()), _z(T())
{
}

template<class T>
Point3D<T>::Point3D(const T& x, const T& y, const T& z) : _x(x), _y(y), _z(z)
{
}

template<class T>
const T& Point3D<T>::x() const
{
    return _x;
}

template<class T>
T& Point3D<T>::x()
{
    return _x;
}

template<class T>
const T& Point3D<T>::y() const
{
    return _y;
}

template<class T>
T& Point3D<T>::y()
{
    return _y;
}

template<class T>
const T& Point3D<T>::z() const
{
    return _z;
}

template<class T>
T& Point3D<T>::z()
{
    return _z;
}