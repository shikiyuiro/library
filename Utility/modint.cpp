template <uint_fast64_t Modulus> class modint {
    using u64 = uint_fast64_t;
    
public:
    u64 a;
    
    constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}
    constexpr u64 &value() noexcept { return a; }
    constexpr const u64 &value() const noexcept { return a; }
    constexpr modint operator+(const modint rhs) const noexcept {
        return modint(*this) += rhs;
    }
    constexpr modint operator-(const modint rhs) const noexcept {
        return modint(*this) -= rhs;
    }
    constexpr modint operator*(const modint rhs) const noexcept {
        return modint(*this) *= rhs;
    }
    constexpr modint operator/(const modint rhs) const noexcept {
        return modint(*this) /= rhs;
    }
    constexpr modint &operator+=(const modint rhs) noexcept {
        a += rhs.a;
        if (a >= Modulus) {
            a -= Modulus;
        }
        return *this;
    }
    constexpr modint &operator-=(const modint rhs) noexcept {
        if (a < rhs.a) {
            a += Modulus;
        }
        a -= rhs.a;
        return *this;
    }
    constexpr modint &operator*=(const modint rhs) noexcept {
        a = a * rhs.a % Modulus;
        return *this;
    }
    constexpr modint &operator/=(modint rhs) noexcept {
        u64 exp = Modulus - 2;
        while (exp) {
            if (exp % 2) {
                *this *= rhs;
            }
            rhs *= rhs;
            exp /= 2;
        }
        return *this;
    }
    friend ostream &operator<<(ostream& os, const modint& rhs){
        return os << rhs.a;
    }
    friend istream &operator>>(istream& is, modint& rhs){
        u64 t;
        is >> t;
        rhs = modint(t);
        return (is);
    }
    modint pow(long n) {
        modint res = 1, p = a;
        if(n < 0) return modint(1) / pow(-n);
        while (n > 0) {
            if (n & 1) res *= p;
            p *= p;
            n >>= 1;
        }
        return res;
    }
};
/**
 * @brief modint
 * @docs docs/Utility/modint.md
 */
