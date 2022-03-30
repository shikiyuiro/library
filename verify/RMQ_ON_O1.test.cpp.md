---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: DataStructure/RMQ_ON_O1.cpp
    title: "\u533A\u9593\u6700\u5C0F\u5024( \u69CB\u7BC9$\\mathrm{O}(N)$\u30FB\u30AF\
      \u30A8\u30EA$\\mathrm{O}(1)$ )"
  - icon: ':question:'
    path: DataStructure/SparseTable.cpp
    title: "\u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB"
  - icon: ':question:'
    path: DataStructure/SparseTable.cpp
    title: "\u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB"
  - icon: ':question:'
    path: template/template.cpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"verify/RMQ_ON_O1.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
    \n\n#line 1 \"template/template.cpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n/**\n * @brief \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @docs docs/template/template.md\n\
    \ */\n#line 1 \"DataStructure/SparseTable.cpp\"\ntemplate<class S, S (*op)(S,\
    \ S), S (*e)()>\nclass SparseTable{\npublic:\n    explicit SparseTable() = default;\n\
    \    SparseTable(vector<S>& v){\n        isiz = v.size();\n        jsiz = 32 -\
    \ __builtin_clz(isiz);\n        table.resize(isiz * jsiz, e());\n        for(int32_t\
    \ i = 0; i < isiz; i++) table[i] = v[i];\n        for(int32_t j = 1; j < jsiz;\
    \ j++){\n            for(int32_t i = 0; i + (1 << (j - 1)) < isiz; i++){\n   \
    \             table[i + isiz * j] = op(table[i + isiz * (j - 1)], table[i + (1\
    \ << (j - 1)) + isiz * (j - 1)]);\n            }\n        }\n    }\n    S fold(int32_t\
    \ L, int32_t R){\n        if(L == R) return e();\n        int32_t b = 32 - __builtin_clz(R\
    \ - L) - 1;\n        return op(table[L + isiz * b], table[R - (1 << b) + isiz\
    \ * b]);\n    }\nprivate:\n    vector<S> table;\n    int32_t isiz;\n    int32_t\
    \ jsiz;\n};\n/**\n * @brief \u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB\n\
    \ * @docs docs/DataStructure/SparseTable.md\n */\n#line 1 \"DataStructure/SparseTable.cpp\"\
    \ntemplate<class S, S (*op)(S, S), S (*e)()>\nclass SparseTable{\npublic:\n  \
    \  explicit SparseTable() = default;\n    SparseTable(vector<S>& v){\n       \
    \ isiz = v.size();\n        jsiz = 32 - __builtin_clz(isiz);\n        table.resize(isiz\
    \ * jsiz, e());\n        for(int32_t i = 0; i < isiz; i++) table[i] = v[i];\n\
    \        for(int32_t j = 1; j < jsiz; j++){\n            for(int32_t i = 0; i\
    \ + (1 << (j - 1)) < isiz; i++){\n                table[i + isiz * j] = op(table[i\
    \ + isiz * (j - 1)], table[i + (1 << (j - 1)) + isiz * (j - 1)]);\n          \
    \  }\n        }\n    }\n    S fold(int32_t L, int32_t R){\n        if(L == R)\
    \ return e();\n        int32_t b = 32 - __builtin_clz(R - L) - 1;\n        return\
    \ op(table[L + isiz * b], table[R - (1 << b) + isiz * b]);\n    }\nprivate:\n\
    \    vector<S> table;\n    int32_t isiz;\n    int32_t jsiz;\n};\n/**\n * @brief\
    \ \u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB\n * @docs docs/DataStructure/SparseTable.md\n\
    \ */\n#line 2 \"DataStructure/RMQ_ON_O1.cpp\"\n\ntemplate<class S, S (*op)(S,\
    \ S), S (*e)()>\nclass RMQ_ON_O1{\n    int32_t Bsiz = 5;\n    int32_t Bcmpl =\
    \ 31;\npublic:\n    explicit RMQ_ON_O1() = default;\n    RMQ_ON_O1(vector<S> &_v)\
    \ : v(_v){\n        v.resize((v.size() | Bcmpl) + 1, e());\n        b.resize(v.size());\n\
    \        for(int32_t i = 0; i < (int32_t)v.size(); i++){\n            stack<int32_t>\
    \ st;\n            while(true){\n                while(not st.empty()){\n    \
    \                if(op(v[i], v[st.top()]) != v[i]) break;\n                  \
    \  st.pop();\n                }\n                b[i] = st.empty() ? 0 : b[st.top()]\
    \ | (1 << (st.top() & Bcmpl));\n                if((i & Bcmpl) == Bcmpl) break;\n\
    \                st.push(i++);\n            }\n            v_mini.push_back(fold_mini(i-Bcmpl,i+1));\n\
    \        }\n        sp = SparseTable<S,op,e>(v_mini);\n    }\n    S fold(int32_t\
    \ L, int32_t R){\n        int32_t Lu = (L | Bcmpl) + 1;\n        int32_t Rd =\
    \ (R & ~Bcmpl);\n        if(Lu > Rd) return fold_mini(L, R);\n        S res =\
    \ e();\n        res = op(res, fold_mini(L, Lu));\n        res = op(res, sp.fold(Lu>>Bsiz,\
    \ Rd>>Bsiz));\n        res = op(res, fold_mini(Rd, R));\n        return res;\n\
    \    }\nprivate:\n    vector<S> v;\n    vector<S> v_mini;\n    vector<int32_t>\
    \ b;\n    SparseTable<S,op,e> sp;\n    S fold_mini(int32_t L, int32_t R){\n  \
    \      if(L == R) return e();\n        int32_t masked = (b[R-1] >> (L & Bcmpl))\
    \ << (L & Bcmpl);\n        int32_t lsb = __builtin_ctz(masked);\n        if(masked\
    \ == 0) return v[R-1];\n        else return v[lsb + (L & ~Bcmpl)];\n    }\n};\n\
    /**\n * @brief \u533A\u9593\u6700\u5C0F\u5024( \u69CB\u7BC9$\\mathrm{O}(N)$\u30FB\
    \u30AF\u30A8\u30EA$\\mathrm{O}(1)$ )\n * @docs docs/DataStructure/RMQ_ON_O1.md\n\
    \ */\n#line 6 \"verify/RMQ_ON_O1.test.cpp\"\n\nint32_t op(int32_t a, int32_t b){\n\
    \    return min(a, b);\n}\n\nint32_t e(){\n    return INT32_MAX;\n}\n\nint main(){\n\
    \    cin.tie(nullptr)->ios::sync_with_stdio(false);\n    int32_t N, Q; cin >>\
    \ N >> Q;\n    vector<int32_t> A(N); for(auto& e : A) cin >> e;\n    RMQ_ON_O1<int32_t,op,e>\
    \ sp(A);\n    while(Q--){\n        int32_t l, r; cin >> l >> r;\n        cout\
    \ << sp.fold(l, r) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"../template/template.cpp\"\n#include \"../DataStructure/SparseTable.cpp\"\n\
    #include \"../DataStructure/RMQ_ON_O1.cpp\"\n\nint32_t op(int32_t a, int32_t b){\n\
    \    return min(a, b);\n}\n\nint32_t e(){\n    return INT32_MAX;\n}\n\nint main(){\n\
    \    cin.tie(nullptr)->ios::sync_with_stdio(false);\n    int32_t N, Q; cin >>\
    \ N >> Q;\n    vector<int32_t> A(N); for(auto& e : A) cin >> e;\n    RMQ_ON_O1<int32_t,op,e>\
    \ sp(A);\n    while(Q--){\n        int32_t l, r; cin >> l >> r;\n        cout\
    \ << sp.fold(l, r) << '\\n';\n    }\n}\n"
  dependsOn:
  - template/template.cpp
  - DataStructure/SparseTable.cpp
  - DataStructure/RMQ_ON_O1.cpp
  - DataStructure/SparseTable.cpp
  isVerificationFile: true
  path: verify/RMQ_ON_O1.test.cpp
  requiredBy: []
  timestamp: '2022-03-30 09:50:37+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/RMQ_ON_O1.test.cpp
layout: document
redirect_from:
- /verify/verify/RMQ_ON_O1.test.cpp
- /verify/verify/RMQ_ON_O1.test.cpp.html
title: verify/RMQ_ON_O1.test.cpp
---
