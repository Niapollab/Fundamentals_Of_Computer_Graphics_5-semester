#pragma once

template<class T>
class Point2D
{
private:
    T _x;
    T _y;

public:
    Point2D();
    Point2D(const T& x, const T& y);

    const T& x() const;
    T& x();
    const T& y() const;
    T& y();
};

template<class T>
Point2D<T>::Point2D() : _x(T()), _y(T())
{
}

template<class T>
Point2D<T>::Point2D(const T& x, const T& y) : _x(x), _y(y)
{
}

template<class T>
const T& Point2D<T>::x() const
{
    return _x;
}

template<class T>
T& Point2D<T>::x()
{
    return _x;
}

template<class T>
const T& Point2D<T>::y() const
{
    return _y;
}

template<class T>
T& Point2D<T>::y()
{
    return _y;
}