//
// Created by Miles on 2/10/16.
//

#ifndef ENGINE_VEC2_H
#define ENGINE_VEC2_H

#include <cmath>

template <class T>  class vec2
{
public:
    T x, y;

    vec2(): x(0), y(0) {}

    vec2(T x, T y): x(x), y(y) {}

    vec2(const vec2& v): x(v.x), y(v.y) {}

    vec2& operator=(const vec2& v)
    {
        x = v.x;
        y = v.y;
        return *this;
    }

    vec2 operator+(vec2 v)
    {
        return vec2(x + v.x, y + v.y);
    }
    vec2 operator-(vec2 v)
    {
        return vec2(x - v.x, y - v.y);
    }

    vec2 operator+=(vec2 v)
    {
        x += v.x;
        y += v.y;
        return *this;
    }


    vec2& operator-=(vec2 v)
    {
        x -= v.x;
        y -= v.y;
        return *this;
    }
    vec2 operator+(double s)
    {
        return vec2(x + s, y + s);
    }

    vec2 operator*(vec2 s)
    {
        return vec2(x * s.x, y * s.y);
    }

    vec2 operator-(double s)
    {
        return vec2(x - s, y - s);
    }

    vec2 operator*(double s)
    {
        return vec2(x * s, y * s);
    }

    vec2 operator*(unsigned int s)
    {
        return vec2(x * s, y * s);
    }

    vec2 operator/(double s)
    {
        return vec2(x / s, y / s);
    }

    vec2 operator/(vec2 s)
    {
        return vec2(x / s.x, y / s.y);
    }

    vec2& operator+=(double s)
    {
        x += s;
        y += s;
        return *this;
    }
    vec2& operator-=(double s)
    {
        x -= s;
        y -= s;
        return *this;
    }
    vec2& operator*=(double s)
    {
        x *= s;
        y *= s;
        return *this;
    }
    vec2& operator/=(double s)
    {
        x /= s;
        y /= s;
        return *this;
    }

    void set(T x, T y)
    {
        this->x = x;
        this->y = y;
    }

    void rotate(double deg)
    {
        double theta = deg / 180.0 * M_PI;
        double c = cos(theta);
        double s = sin(theta);
        double tx = x * c - y * s;
        double ty = x * s + y * c;
        x = tx;
        y = ty;
    }

    vec2 normal()
    {
        if (length() == 0) return *this;
        *this *= (1.0 / length());
        return *this;
    }

    vec2 negative()
    {
        vec2 neg(this->x * -1, this->y * -1);
        return neg;
    }

    float distance(vec2 v) const
    {
        vec2 d(v.x - x, v.y - y);
        return d.length();
    }

    float length() const
    {
        return std::sqrt(x * x + y * y);
    }

    void truncate(double length)
    {
        double angle = atan2f(y, x);
        x = length * cos(angle);
        y = length * sin(angle);
    }

    vec2 orthog() const
    {
        return vec2(y, -x);
    }

    static float dot(vec2 v1, vec2 v2)
    {
        return v1.x * v2.x + v1.y * v2.y;
    }
    static float cross(vec2 v1, vec2 v2)
    {
        return (v1.x * v2.y) - (v1.y * v2.x);
    }
};

typedef vec2<int> vec2i;
typedef vec2<float> vec2f;
typedef vec2<double> vec2d;
#define zvec2i vec2i(0, 0)
#define uvec2i vec2i(1, 1)
#define zvec2f vec2f(0, 0)
#define uvec2f vec2f(1, 1)
#define zvec2d vec2d(0, 0)
#define uvec2d vec2d(1, 1)
#define uvec2i_mapper [](vec2i v) { return v; }
#define uvec2f_mapper [](vec2f v) { return v; }
#define uvec2d_mapper [](vec2d v) { return v; }

#endif
