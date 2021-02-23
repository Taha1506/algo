struct point {
    long long  x, y;
    point() {}
    point(long long x, long long y): x(x), y(y) {}
    point& operator+=(const point &t) {
        x += t.x;
        y += t.y;
        return *this;
    }
    point& operator-=(const point &t) {
        x -= t.x;
        y -= t.y;
        return *this;
    }
    point& operator*=(long long t) {
        x *= t;
        y *= t;
        return *this;
    }
    point& operator/=(long long t) {
        x /= t;
        y /= t;
        return *this;
    }
    point operator+(const point &t) const {
        return point(*this) += t;
    }
    point operator-(const point &t) const {
        return point(*this) -= t;
    }
    point operator*(long long t) const {
        return point(*this) *= t;
    }
    point operator/(long long t) const {
        return point(*this) /= t;
    }
};