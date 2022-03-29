---
data:
  _extendedDependsOn: []
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
    document_title: "( \u69CB\u7BC9$\\mathrm{O}(N)$\u30FB\u30AF\u30A8\u30EA$\\mathrm{O}(1)$\
      \ )"
    links: []
  bundledCode: "#line 1 \"DataStructure/RMQ_ON_O1.cpp\"\ntemplate<class S, S (*op)(S,\
    \ S), S (*e)()>\nclass RMQ_ON_O1{\n    const int32_t Bsiz = 5;\n    const int32_t\
    \ Bcmpl = 31;\npublic:\n    explicit RMQ_ON_O1() = default;\n    RMQ_ON_O1(vector<S>\
    \ &_v) : v(_v){\n        v.resize(((v.size()>>Bsiz)+1)<<Bsiz, e());\n        b.resize(v.size());\n\
    \        for(int32_t i = 0; i < (int32_t)v.size(); i++){\n            stack<S>\
    \ st;\n            while(true){\n                while(not st.empty()){\n    \
    \                if(op(v[i], v[st.top()]) != v[i]) break;\n                  \
    \  st.pop();\n                }\n                b[i] = st.empty() ? 0 : b[st.top()]\
    \ | (1 << st.top());\n                if((i & Bcmpl) == Bcmpl) break;\n      \
    \          st.push(i++);\n            }\n            v_mini.push_back(fold_mini(i-Bcmpl,i+1));\n\
    \        }\n        sp = SparseTable<S,op,e>(v_mini);\n    }\n    S fold(int32_t\
    \ L, int32_t R){\n        int32_t Lu = (L & ~Bcmpl) + Bcmpl + 1;\n        int32_t\
    \ Rd = (R & ~Bcmpl);\n        if(Lu > Rd) return fold_mini(L, R);\n        S res\
    \ = e();\n        res = op(res, fold_mini(L, Lu));\n        res = op(res, sp.fold(Lu>>Bsiz,\
    \ Rd>>Bsiz));\n        res = op(res, fold_mini(Rd, R));\n        return res;\n\
    \    }\nprivate:\n    vector<S> v;\n    vector<S> v_mini;\n    vector<int32_t>\
    \ b;\n    SparseTable<S,op,e> sp;\n    S fold_mini(int32_t L, int32_t R){\n  \
    \      if(L == R) return e();\n        int32_t masked = (b[R-1] >> (L & Bcmpl))\
    \ << (L & Bcmpl);\n        int32_t lsb = __builtin_ctzll(masked);\n        if(masked\
    \ == 0) return v[R-1];\n        else return v[lsb + (L & ~Bcmpl)];\n    }\n};\n\
    /**\n * @brief ( \u69CB\u7BC9$\\mathrm{O}(N)$\u30FB\u30AF\u30A8\u30EA$\\mathrm{O}(1)$\
    \ )\n * @docs docs/DataStructure/RMQ_ON_O1.md\n */\n"
  code: "template<class S, S (*op)(S, S), S (*e)()>\nclass RMQ_ON_O1{\n    const int32_t\
    \ Bsiz = 5;\n    const int32_t Bcmpl = 31;\npublic:\n    explicit RMQ_ON_O1()\
    \ = default;\n    RMQ_ON_O1(vector<S> &_v) : v(_v){\n        v.resize(((v.size()>>Bsiz)+1)<<Bsiz,\
    \ e());\n        b.resize(v.size());\n        for(int32_t i = 0; i < (int32_t)v.size();\
    \ i++){\n            stack<S> st;\n            while(true){\n                while(not\
    \ st.empty()){\n                    if(op(v[i], v[st.top()]) != v[i]) break;\n\
    \                    st.pop();\n                }\n                b[i] = st.empty()\
    \ ? 0 : b[st.top()] | (1 << st.top());\n                if((i & Bcmpl) == Bcmpl)\
    \ break;\n                st.push(i++);\n            }\n            v_mini.push_back(fold_mini(i-Bcmpl,i+1));\n\
    \        }\n        sp = SparseTable<S,op,e>(v_mini);\n    }\n    S fold(int32_t\
    \ L, int32_t R){\n        int32_t Lu = (L & ~Bcmpl) + Bcmpl + 1;\n        int32_t\
    \ Rd = (R & ~Bcmpl);\n        if(Lu > Rd) return fold_mini(L, R);\n        S res\
    \ = e();\n        res = op(res, fold_mini(L, Lu));\n        res = op(res, sp.fold(Lu>>Bsiz,\
    \ Rd>>Bsiz));\n        res = op(res, fold_mini(Rd, R));\n        return res;\n\
    \    }\nprivate:\n    vector<S> v;\n    vector<S> v_mini;\n    vector<int32_t>\
    \ b;\n    SparseTable<S,op,e> sp;\n    S fold_mini(int32_t L, int32_t R){\n  \
    \      if(L == R) return e();\n        int32_t masked = (b[R-1] >> (L & Bcmpl))\
    \ << (L & Bcmpl);\n        int32_t lsb = __builtin_ctzll(masked);\n        if(masked\
    \ == 0) return v[R-1];\n        else return v[lsb + (L & ~Bcmpl)];\n    }\n};\n\
    /**\n * @brief ( \u69CB\u7BC9$\\mathrm{O}(N)$\u30FB\u30AF\u30A8\u30EA$\\mathrm{O}(1)$\
    \ )\n * @docs docs/DataStructure/RMQ_ON_O1.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/RMQ_ON_O1.cpp
  requiredBy: []
  timestamp: '2022-03-29 16:57:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/RMQ_ON_O1.test.cpp
documentation_of: DataStructure/RMQ_ON_O1.cpp
layout: document
redirect_from:
- /library/DataStructure/RMQ_ON_O1.cpp
- /library/DataStructure/RMQ_ON_O1.cpp.html
title: "( \u69CB\u7BC9$\\mathrm{O}(N)$\u30FB\u30AF\u30A8\u30EA$\\mathrm{O}(1)$ )"
---
## 使い方  
- <a href="https://atcoder.github.io/ac-library/production/document_ja/segtree.html" target="_blank">テンプレートの定義はACLのSegtreeに準じる。</a>  
- `RMQ_ON_O1(vector<S> &_v)`：配列_vをもとにデータ構造を構築する。  
- `S fold(int32_t L, int32_t R)`：半開区間\[L, R)に対して演算結果を返す。  

## 使用例
<a href="https://judge.yosupo.jp/submission/84078" target="_blank">yosupo judge - Static RMQ</a>
