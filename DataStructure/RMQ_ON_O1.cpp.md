---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SparseTable.cpp
    title: "\u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/RMQ_ON_O1.test.cpp
    title: verify/RMQ_ON_O1.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/DataStructure/RMQ_ON_O1.md
    document_title: "\u533A\u9593\u6700\u5C0F\u5024( \u69CB\u7BC9$\\mathrm{O}(N)$\u30FB\
      \u30AF\u30A8\u30EA$\\mathrm{O}(1)$ )"
    links: []
  bundledCode: "#line 2 \"DataStructure/RMQ_ON_O1.cpp\"\n\n#line 2 \"DataStructure/SparseTable.cpp\"\
    \n\ntemplate<class S, S (*op)(S, S), S (*e)()>\nclass SparseTable{\npublic:\n\
    \    explicit SparseTable() = default;\n    SparseTable(vector<S>& v){\n     \
    \   isiz = v.size();\n        jsiz = 32 - __builtin_clz(isiz);\n        table.resize(isiz\
    \ * jsiz, e());\n        for(int32_t i = 0; i < isiz; i++) table[i] = v[i];\n\
    \        for(int32_t j = 1; j < jsiz; j++){\n            for(int32_t i = 0; i\
    \ + (1 << (j - 1)) < isiz; i++){\n                table[i + isiz * j] = op(table[i\
    \ + isiz * (j - 1)], table[i + (1 << (j - 1)) + isiz * (j - 1)]);\n          \
    \  }\n        }\n    }\n    S fold(int32_t L, int32_t R){\n        if(L == R)\
    \ return e();\n        int32_t b = 32 - __builtin_clz(R - L) - 1;\n        return\
    \ op(table[L + isiz * b], table[R - (1 << b) + isiz * b]);\n    }\nprivate:\n\
    \    vector<S> table;\n    int32_t isiz;\n    int32_t jsiz;\n};\n/**\n * @brief\
    \ \u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB\n * @docs docs/DataStructure/SparseTable.md\n\
    \ */\n#line 4 \"DataStructure/RMQ_ON_O1.cpp\"\n\ntemplate<class S, S (*op)(S,\
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
    \ */\n"
  code: "#pragma once\n\n#include \"../DataStructure/SparseTable.cpp\"\n\ntemplate<class\
    \ S, S (*op)(S, S), S (*e)()>\nclass RMQ_ON_O1{\n    int32_t Bsiz = 5;\n    int32_t\
    \ Bcmpl = 31;\npublic:\n    explicit RMQ_ON_O1() = default;\n    RMQ_ON_O1(vector<S>\
    \ &_v) : v(_v){\n        v.resize((v.size() | Bcmpl) + 1, e());\n        b.resize(v.size());\n\
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
    \ */\n"
  dependsOn:
  - DataStructure/SparseTable.cpp
  isVerificationFile: false
  path: DataStructure/RMQ_ON_O1.cpp
  requiredBy: []
  timestamp: '2022-03-30 09:59:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/RMQ_ON_O1.test.cpp
documentation_of: DataStructure/RMQ_ON_O1.cpp
layout: document
redirect_from:
- /library/DataStructure/RMQ_ON_O1.cpp
- /library/DataStructure/RMQ_ON_O1.cpp.html
title: "\u533A\u9593\u6700\u5C0F\u5024( \u69CB\u7BC9$\\mathrm{O}(N)$\u30FB\u30AF\u30A8\
  \u30EA$\\mathrm{O}(1)$ )"
---
## 使い方  
- <a href="https://atcoder.github.io/ac-library/production/document_ja/segtree.html" target="_blank">テンプレートの定義はACLのSegtreeに準じる。 ただし、opは比較関数でなければならない。</a>  
- `RMQ_ON_O1(vector<S> &_v)`：配列_vをもとにデータ構造を構築する。  
- `S fold(int32_t L, int32_t R)`：半開区間\[L, R)に対して演算結果を返す。  

## 使用例
<a href="https://judge.yosupo.jp/submission/84078" target="_blank">yosupo judge - Static RMQ</a>

## 参考文献
<a href="https://qiita.com/okateim/items/e2f4a734db4e5f90e410" target="_blank">Range Minimum Query(@okateimさんの記事)</a>
