---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SegmentTree.cpp
    title: DataStructure/SegmentTree.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/Heavy_Light_Decomposition.cpp
    title: "HL\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: Utility/modint.cpp
    title: modint
  - icon: ':heavy_check_mark:'
    path: template/template.cpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/vertex_set_path_composite
  bundledCode: "#line 1 \"test/verify/Heavy_Light_Decomposition.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\n\n#line\
    \ 1 \"template/template.cpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\
    /**\n * @brief \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @docs docs/template/template.md\n\
    \ */\n#line 4 \"test/verify/Heavy_Light_Decomposition.test.cpp\"\n\n#line 1 \"\
    Utility/modint.cpp\"\ntemplate <uint_fast64_t Modulus> class modint {\n    using\
    \ u64 = uint_fast64_t;\n    \npublic:\n    u64 a;\n    \n    constexpr modint(const\
    \ u64 x = 0) noexcept : a(x % Modulus) {}\n    constexpr u64 &value() noexcept\
    \ { return a; }\n    constexpr const u64 &value() const noexcept { return a; }\n\
    \    constexpr modint operator+(const modint rhs) const noexcept {\n        return\
    \ modint(*this) += rhs;\n    }\n    constexpr modint operator-(const modint rhs)\
    \ const noexcept {\n        return modint(*this) -= rhs;\n    }\n    constexpr\
    \ modint operator*(const modint rhs) const noexcept {\n        return modint(*this)\
    \ *= rhs;\n    }\n    constexpr modint operator/(const modint rhs) const noexcept\
    \ {\n        return modint(*this) /= rhs;\n    }\n    constexpr modint &operator+=(const\
    \ modint rhs) noexcept {\n        a += rhs.a;\n        if (a >= Modulus) {\n \
    \           a -= Modulus;\n        }\n        return *this;\n    }\n    constexpr\
    \ modint &operator-=(const modint rhs) noexcept {\n        if (a < rhs.a) {\n\
    \            a += Modulus;\n        }\n        a -= rhs.a;\n        return *this;\n\
    \    }\n    constexpr modint &operator*=(const modint rhs) noexcept {\n      \
    \  a = a * rhs.a % Modulus;\n        return *this;\n    }\n    constexpr modint\
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
    \ docs/Utility/modint.md\n */\n#line 6 \"test/verify/Heavy_Light_Decomposition.test.cpp\"\
    \n\n#line 1 \"DataStructure/SegmentTree.cpp\"\ntemplate<class S, S (*op)(S, S),\
    \ S (*e)()>\nclass SegmentTree{\npublic:\n    explicit SegmentTree() = default;\n\
    \    \n    vector<S> table;\n    long size = 1;\n    SegmentTree(vector<S> &vec){\n\
    \        while(size < vec.size()) size <<= 1;\n        table.resize(size << 1,\
    \ e());\n        for(long i = 0; i < (long)vec.size(); i++) table[i + size] =\
    \ vec[i];\n        for(long i = size - 1; i >= 1; i--) table[i] = op(table[i<<1|0],table[i<<1|1]);\n\
    \    }\n    S fold(long l, long r){\n        l += size; r += size;\n        S\
    \ Lres = e(), Rres = e();\n        while(l < r){\n            if(l & 1) Lres =\
    \ op(Lres, table[l++]);\n            if(r & 1) Rres = op(table[--r], Rres);\n\
    \            l >>= 1; r >>= 1;\n        }\n        return op(Lres, Rres);\n  \
    \  }\n    void set(long p, S x){\n        p += size;\n        table[p] = x;\n\
    \        while(p >>= 1) table[p] = op(table[p<<1|0],table[p<<1|1]);\n    }\n};\n\
    #line 8 \"test/verify/Heavy_Light_Decomposition.test.cpp\"\n\n#line 1 \"Graph/Heavy_Light_Decomposition.cpp\"\
    \nclass Heavy_Light_Decomposition{\npublic:\n    \n    Heavy_Light_Decomposition(vector<vector<long>>\
    \ &tree, long root = 0) : tree(tree), root(root){\n        depth.resize(tree.size(),\
    \ 0);\n        heavy.resize(tree.size(), -1);\n        subtree_size.resize(tree.size(),\
    \ 1);\n        calc_depth(root, -1);\n        table_index.resize(tree.size(),\
    \ -1);\n        terminal.resize(tree.size(), {root, -1});\n        tour();\n \
    \   }\n    \n    vector<long> get_table(){\n        return table;\n    }\n   \
    \ long get_pos(long p){\n        return table_index[p];\n    }\n    \n    vector<pair<long,long>>\
    \ path_decomp(long u, long v, bool edge_is_weighted = false){\n        vector<pair<long,long>>\
    \ res;\n        stack<pair<long,long>> ser;\n        while(terminal[u].first !=\
    \ terminal[v].first){\n            auto [TermiU, TransU] = terminal[u];\n    \
    \        auto [TermiV, TransV] = terminal[v];\n            if(depth[TermiU] >=\
    \ depth[TermiV]){\n                res.push_back({table_index[u], table_index[TermiU]});\n\
    \                u = TransU;\n            }else{\n                ser.push({table_index[TermiV],\
    \ table_index[v]});\n                v = TransV;\n            }\n        }\n \
    \       if(edge_is_weighted){\n            if(u == v) return res;\n          \
    \  if(table_index[u] < table_index[v]) res.push_back({table_index[heavy[u]], table_index[v]});\n\
    \            else res.push_back({table_index[u], table_index[heavy[v]]});\n  \
    \      }else{\n            res.push_back({table_index[u], table_index[v]});\n\
    \        }\n        while(not ser.empty()){\n            auto p = ser.top(); ser.pop();\n\
    \            res.push_back(p);\n        }\n        return res;\n    }\n    \n\
    \    pair<long,long> subtree_decomp(long v){\n        return {table_index[v],\
    \ table_index[v] + subtree_size[v] - 1};\n    }\n    \nprivate:\n    long root\
    \ = 0;\n    vector<vector<long>> &tree;\n    vector<long> depth;\n    vector<long>\
    \ heavy;\n    vector<long> subtree_size;\n    vector<long> table;\n    vector<long>\
    \ table_index;\n    vector<pair<long,long>> terminal;\n    void calc_depth(long\
    \ vis, long prev){\n        if(prev != -1) depth[vis] = depth[prev] + 1;\n   \
    \     long max_subtree_size = 0;\n        for(auto nex : tree[vis]){\n       \
    \     if(nex == prev) continue;\n            calc_depth(nex, vis);\n         \
    \   subtree_size[vis] += subtree_size[nex];\n            if(subtree_size[nex]\
    \ <= max_subtree_size) continue;\n            max_subtree_size = subtree_size[nex];\n\
    \            heavy[vis] = nex;\n        }\n    }\n    void tour(){\n        stack<long>\
    \ Q; Q.push(root);\n        while(not Q.empty()){\n            long t = Q.top();\
    \ Q.pop();\n            table.push_back(t);\n            table_index[t] = table.size()\
    \ - 1;\n            for(auto nex : tree[t]){\n                if(depth[nex] <\
    \ depth[t]) continue;\n                if(nex == heavy[t]) continue;\n       \
    \         Q.push(nex);\n                terminal[nex] = {nex, t};\n          \
    \  }\n            if(heavy[t] != -1){\n                Q.push(heavy[t]);\n   \
    \             terminal[heavy[t]] = terminal[t];\n            }\n        }\n  \
    \  }\n};\n/**\n * @brief HL\u5206\u89E3\n * @docs docs/Graph/Heavy_Light_Decomposition.md\n\
    \ */\n#line 10 \"test/verify/Heavy_Light_Decomposition.test.cpp\"\n\nusing mint\
    \ = modint<998244353>;\n\npair<mint,mint> op(pair<mint,mint> a, pair<mint,mint>\
    \ b){\n    return {b.first * a.first, b.first * a.second + b.second};\n}\npair<mint,mint>\
    \ e(){\n    return {1, 0};\n}\n\nint main(){\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    long N, Q; cin >> N >> Q;\n    vector<pair<mint,mint>>\
    \ A(N);\n    for(long i = 0; i < N; i++) cin >> A[i].first >> A[i].second;\n \
    \   vector<vector<long>> tree(N);\n    for(long i = 0; i < N - 1; i++){\n    \
    \    long u, v; cin >> u >> v;\n        tree[u].push_back(v);\n        tree[v].push_back(u);\n\
    \    }\n    Heavy_Light_Decomposition HLD(tree);\n    auto tbl = HLD.get_table();\n\
    \    vector<pair<mint,mint>> tbl_w(tbl.size());\n    for(long i = 0; i < tbl.size();\
    \ i++) tbl_w[i] = A[tbl[i]];\n    SegmentTree<pair<mint,mint>, op, e> seg(tbl_w);\n\
    \    reverse(tbl_w.begin(), tbl_w.end());\n    SegmentTree<pair<mint,mint>, op,\
    \ e> ges(tbl_w);\n    while(Q--){\n        long q, a, b, c; cin >> q >> a >> b\
    \ >> c;\n        if(q == 0){\n            seg.set(HLD.get_pos(a), {b, c});\n \
    \           ges.set(tree.size() - HLD.get_pos(a) - 1, {b, c});\n        }else{\n\
    \            pair<mint,mint> res = {1, 0};\n            auto v = HLD.path_decomp(a,\
    \ b);\n            for(auto [x, y] : v){\n                if(x < y) res = op(res,\
    \ seg.fold(x, y+1));\n                else res = op(res, ges.fold(tree.size()\
    \ - x - 1, tree.size() - y));\n            }\n            cout << res.first *\
    \ c + res.second << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n\n#include \"../../template/template.cpp\"\n\n#include \"../../Utility/modint.cpp\"\
    \n\n#include \"../../DataStructure/SegmentTree.cpp\"\n\n#include \"../../Graph/Heavy_Light_Decomposition.cpp\"\
    \n\nusing mint = modint<998244353>;\n\npair<mint,mint> op(pair<mint,mint> a, pair<mint,mint>\
    \ b){\n    return {b.first * a.first, b.first * a.second + b.second};\n}\npair<mint,mint>\
    \ e(){\n    return {1, 0};\n}\n\nint main(){\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    long N, Q; cin >> N >> Q;\n    vector<pair<mint,mint>>\
    \ A(N);\n    for(long i = 0; i < N; i++) cin >> A[i].first >> A[i].second;\n \
    \   vector<vector<long>> tree(N);\n    for(long i = 0; i < N - 1; i++){\n    \
    \    long u, v; cin >> u >> v;\n        tree[u].push_back(v);\n        tree[v].push_back(u);\n\
    \    }\n    Heavy_Light_Decomposition HLD(tree);\n    auto tbl = HLD.get_table();\n\
    \    vector<pair<mint,mint>> tbl_w(tbl.size());\n    for(long i = 0; i < tbl.size();\
    \ i++) tbl_w[i] = A[tbl[i]];\n    SegmentTree<pair<mint,mint>, op, e> seg(tbl_w);\n\
    \    reverse(tbl_w.begin(), tbl_w.end());\n    SegmentTree<pair<mint,mint>, op,\
    \ e> ges(tbl_w);\n    while(Q--){\n        long q, a, b, c; cin >> q >> a >> b\
    \ >> c;\n        if(q == 0){\n            seg.set(HLD.get_pos(a), {b, c});\n \
    \           ges.set(tree.size() - HLD.get_pos(a) - 1, {b, c});\n        }else{\n\
    \            pair<mint,mint> res = {1, 0};\n            auto v = HLD.path_decomp(a,\
    \ b);\n            for(auto [x, y] : v){\n                if(x < y) res = op(res,\
    \ seg.fold(x, y+1));\n                else res = op(res, ges.fold(tree.size()\
    \ - x - 1, tree.size() - y));\n            }\n            cout << res.first *\
    \ c + res.second << '\\n';\n        }\n    }\n}\n"
  dependsOn:
  - template/template.cpp
  - Utility/modint.cpp
  - DataStructure/SegmentTree.cpp
  - Graph/Heavy_Light_Decomposition.cpp
  isVerificationFile: true
  path: test/verify/Heavy_Light_Decomposition.test.cpp
  requiredBy: []
  timestamp: '2022-01-19 22:47:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/Heavy_Light_Decomposition.test.cpp
layout: document
redirect_from:
- /verify/test/verify/Heavy_Light_Decomposition.test.cpp
- /verify/test/verify/Heavy_Light_Decomposition.test.cpp.html
title: test/verify/Heavy_Light_Decomposition.test.cpp
---
