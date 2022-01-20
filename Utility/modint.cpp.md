---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/verify/Heavy_Light_Decomposition.test.cpp
    title: test/verify/Heavy_Light_Decomposition.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/Utility/modint.md
    document_title: modint
    links: []
  bundledCode: "#line 1 \"Utility/modint.cpp\"\ntemplate <uint_fast64_t Modulus> class\
    \ modint {\n    using u64 = uint_fast64_t;\n    \npublic:\n    u64 a;\n    \n\
    \    constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}\n    constexpr\
    \ u64 &value() noexcept { return a; }\n    constexpr const u64 &value() const\
    \ noexcept { return a; }\n    constexpr modint operator+(const modint rhs) const\
    \ noexcept {\n        return modint(*this) += rhs;\n    }\n    constexpr modint\
    \ operator-(const modint rhs) const noexcept {\n        return modint(*this) -=\
    \ rhs;\n    }\n    constexpr modint operator*(const modint rhs) const noexcept\
    \ {\n        return modint(*this) *= rhs;\n    }\n    constexpr modint operator/(const\
    \ modint rhs) const noexcept {\n        return modint(*this) /= rhs;\n    }\n\
    \    constexpr modint &operator+=(const modint rhs) noexcept {\n        a += rhs.a;\n\
    \        if (a >= Modulus) {\n            a -= Modulus;\n        }\n        return\
    \ *this;\n    }\n    constexpr modint &operator-=(const modint rhs) noexcept {\n\
    \        if (a < rhs.a) {\n            a += Modulus;\n        }\n        a -=\
    \ rhs.a;\n        return *this;\n    }\n    constexpr modint &operator*=(const\
    \ modint rhs) noexcept {\n        a = a * rhs.a % Modulus;\n        return *this;\n\
    \    }\n    constexpr modint &operator/=(modint rhs) noexcept {\n        u64 exp\
    \ = Modulus - 2;\n        while (exp) {\n            if (exp % 2) {\n        \
    \        *this *= rhs;\n            }\n            rhs *= rhs;\n            exp\
    \ /= 2;\n        }\n        return *this;\n    }\n    friend ostream &operator<<(ostream&\
    \ os, const modint& rhs){\n        return os << rhs.a;\n    }\n    friend istream\
    \ &operator>>(istream& is, modint& rhs){\n        u64 t;\n        is >> t;\n \
    \       rhs = modint(t);\n        return (is);\n    }\n    modint pow(long n)\
    \ {\n        modint res = 1, p = a;\n        if(n < 0) return modint(1) / pow(-n);\n\
    \        while (n > 0) {\n            if (n & 1) res *= p;\n            p *= p;\n\
    \            n >>= 1;\n        }\n        return res;\n    }\n};\n/**\n * @brief\
    \ modint\n * @docs docs/Utility/modint.md\n */\n"
  code: "template <uint_fast64_t Modulus> class modint {\n    using u64 = uint_fast64_t;\n\
    \    \npublic:\n    u64 a;\n    \n    constexpr modint(const u64 x = 0) noexcept\
    \ : a(x % Modulus) {}\n    constexpr u64 &value() noexcept { return a; }\n   \
    \ constexpr const u64 &value() const noexcept { return a; }\n    constexpr modint\
    \ operator+(const modint rhs) const noexcept {\n        return modint(*this) +=\
    \ rhs;\n    }\n    constexpr modint operator-(const modint rhs) const noexcept\
    \ {\n        return modint(*this) -= rhs;\n    }\n    constexpr modint operator*(const\
    \ modint rhs) const noexcept {\n        return modint(*this) *= rhs;\n    }\n\
    \    constexpr modint operator/(const modint rhs) const noexcept {\n        return\
    \ modint(*this) /= rhs;\n    }\n    constexpr modint &operator+=(const modint\
    \ rhs) noexcept {\n        a += rhs.a;\n        if (a >= Modulus) {\n        \
    \    a -= Modulus;\n        }\n        return *this;\n    }\n    constexpr modint\
    \ &operator-=(const modint rhs) noexcept {\n        if (a < rhs.a) {\n       \
    \     a += Modulus;\n        }\n        a -= rhs.a;\n        return *this;\n \
    \   }\n    constexpr modint &operator*=(const modint rhs) noexcept {\n       \
    \ a = a * rhs.a % Modulus;\n        return *this;\n    }\n    constexpr modint\
    \ &operator/=(modint rhs) noexcept {\n        u64 exp = Modulus - 2;\n       \
    \ while (exp) {\n            if (exp % 2) {\n                *this *= rhs;\n \
    \           }\n            rhs *= rhs;\n            exp /= 2;\n        }\n   \
    \     return *this;\n    }\n    friend ostream &operator<<(ostream& os, const\
    \ modint& rhs){\n        return os << rhs.a;\n    }\n    friend istream &operator>>(istream&\
    \ is, modint& rhs){\n        u64 t;\n        is >> t;\n        rhs = modint(t);\n\
    \        return (is);\n    }\n    modint pow(long n) {\n        modint res = 1,\
    \ p = a;\n        if(n < 0) return modint(1) / pow(-n);\n        while (n > 0)\
    \ {\n            if (n & 1) res *= p;\n            p *= p;\n            n >>=\
    \ 1;\n        }\n        return res;\n    }\n};\n/**\n * @brief modint\n * @docs\
    \ docs/Utility/modint.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/modint.cpp
  requiredBy: []
  timestamp: '2022-01-19 22:35:34+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/verify/Heavy_Light_Decomposition.test.cpp
documentation_of: Utility/modint.cpp
layout: document
redirect_from:
- /library/Utility/modint.cpp
- /library/Utility/modint.cpp.html
title: modint
---
## modintです。
[のしさんからパクりました。](https://noshi91.hatenablog.com/entry/2019/03/31/174006)   
いずれ自分で書き直したいです。  
