---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SparseTable.cpp
    title: "\u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/DataStructure/SparseTable_compact.md
    document_title: "\u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB(<O(N),O(1)>)"
    links: []
  bundledCode: "#line 1 \"DataStructure/SparseTable.cpp\"\ntemplate<class S, S (*op)(S,\
    \ S), S (*e)()>\nclass SparseTable{\npublic:\n    vector<vector<S>> table;\n \
    \   vector<long> cf;\n    \n    explicit SparseTable() = default;\n    \n    SparseTable(vector<S>&\
    \ v){\n        long isiz = v.size();\n        long jsiz = 0;\n        while((1\
    \ << jsiz) <= isiz) jsiz++;\n        table.resize(isiz, vector<S>(jsiz, e()));\n\
    \        for(long i = 0; i < isiz; i++) table[i][0] = v[i];\n        for(long\
    \ j = 1; j < jsiz; j++){\n            for(long i = 0; i + (1 << (j - 1)) < isiz;\
    \ i++){\n                table[i][j] = op(table[i][j - 1], table[i + (1 << (j\
    \ - 1))][j - 1]);\n            }\n        }\n        cf.resize(isiz + 1);\n  \
    \      for(long i = 2; i <= isiz; i++) cf[i] = cf[i >> 1] + 1;\n    }\n    \n\
    \    S query(long l, long r/*\u534A\u958B\u533A\u9593*/){\n        if(l == r)\
    \ return e();\n        long b = cf[r - l];\n        return op(table[l][b], table[r\
    \ - (1 << b)][b]);\n    }\n};\n/**\n * @brief \u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\
    \u30D6\u30EB\n * @docs docs/DataStructure/SparseTable.md\n */\n#line 2 \"DataStructure/Compact_Sparse_Table.cpp\"\
    \n\ntemplate<class S, S (*op)(S, S), S (*e)()>\nclass Compact_Sparse_Table{\n\
    public:\n    long W = 8;\n    vector<S> A;\n    vector<S> Lfold, Rfold;\n    SparseTable<S,\
    \ op, e> st;\n    \n    explicit Compact_Sparse_Table() = default;\n    \n   \
    \ Compact_Sparse_Table(vector<S> &A) : A(A){\n        A.resize(A.size() + W -\
    \ ((A.size() - 1) % W + 1), e());\n        vector<long> BLOCK(A.size() / W, e());\n\
    \        Lfold.resize(A.size(), e());\n        Rfold.resize(A.size(), e());\n\
    \        for(long b = 0; b < BLOCK.size(); b++){\n            BLOCK[b] = A[W *\
    \ b];\n            Lfold[W * b] = A[W * b];\n            Rfold[W * (b + 1) - 1]\
    \ = A[W * (b + 1) - 1];\n            for(long i = 1; i < W; i++){\n          \
    \      BLOCK[b] = op(BLOCK[b], A[W * b + i]);\n                Lfold[W * b + i]\
    \ = op(Lfold[W * b + i - 1], A[W * b + i]);\n                Rfold[W * (b + 1)\
    \ - 1 - i] = op(Rfold[W * (b + 1) - i], A[W * (b + 1) - 1 - i]);\n           \
    \ }\n        }\n        st = SparseTable<S, op, e> (BLOCK);\n    }\n    S query(long\
    \ L, long R/*\u534A\u958B\u533A\u9593*/){\n        R--;\n        long lb = (L\
    \ - (L % W) + W) / W;\n        long rb = (R - (R % W)) / W;\n        if(rb > lb){\n\
    \            return op(st.query(lb, rb), op(Lfold[R],Rfold[L]));\n        }\n\
    \        if(rb == lb){\n            return op(Lfold[R],Rfold[L]);\n        }\n\
    \        S res = e();\n        for(long i = L; i <= R; i++) res = op(res, A[i]);\n\
    \        return res;\n    }\n};\n/**\n * @brief \u30B9\u30D1\u30FC\u30B9\u30C6\
    \u30FC\u30D6\u30EB(<O(N),O(1)>)\n * @docs docs/DataStructure/SparseTable_compact.md\n\
    \ */\n"
  code: "#include \"../DataStructure/SparseTable.cpp\"\n\ntemplate<class S, S (*op)(S,\
    \ S), S (*e)()>\nclass Compact_Sparse_Table{\npublic:\n    long W = 8;\n    vector<S>\
    \ A;\n    vector<S> Lfold, Rfold;\n    SparseTable<S, op, e> st;\n    \n    explicit\
    \ Compact_Sparse_Table() = default;\n    \n    Compact_Sparse_Table(vector<S>\
    \ &A) : A(A){\n        A.resize(A.size() + W - ((A.size() - 1) % W + 1), e());\n\
    \        vector<long> BLOCK(A.size() / W, e());\n        Lfold.resize(A.size(),\
    \ e());\n        Rfold.resize(A.size(), e());\n        for(long b = 0; b < BLOCK.size();\
    \ b++){\n            BLOCK[b] = A[W * b];\n            Lfold[W * b] = A[W * b];\n\
    \            Rfold[W * (b + 1) - 1] = A[W * (b + 1) - 1];\n            for(long\
    \ i = 1; i < W; i++){\n                BLOCK[b] = op(BLOCK[b], A[W * b + i]);\n\
    \                Lfold[W * b + i] = op(Lfold[W * b + i - 1], A[W * b + i]);\n\
    \                Rfold[W * (b + 1) - 1 - i] = op(Rfold[W * (b + 1) - i], A[W *\
    \ (b + 1) - 1 - i]);\n            }\n        }\n        st = SparseTable<S, op,\
    \ e> (BLOCK);\n    }\n    S query(long L, long R/*\u534A\u958B\u533A\u9593*/){\n\
    \        R--;\n        long lb = (L - (L % W) + W) / W;\n        long rb = (R\
    \ - (R % W)) / W;\n        if(rb > lb){\n            return op(st.query(lb, rb),\
    \ op(Lfold[R],Rfold[L]));\n        }\n        if(rb == lb){\n            return\
    \ op(Lfold[R],Rfold[L]);\n        }\n        S res = e();\n        for(long i\
    \ = L; i <= R; i++) res = op(res, A[i]);\n        return res;\n    }\n};\n/**\n\
    \ * @brief \u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB(<O(N),O(1)>)\n * @docs\
    \ docs/DataStructure/SparseTable_compact.md\n */\n"
  dependsOn:
  - DataStructure/SparseTable.cpp
  isVerificationFile: false
  path: DataStructure/Compact_Sparse_Table.cpp
  requiredBy: []
  timestamp: '2022-01-17 10:50:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/Compact_Sparse_Table.cpp
layout: document
redirect_from:
- /library/DataStructure/Compact_Sparse_Table.cpp
- /library/DataStructure/Compact_Sparse_Table.cpp.html
title: "\u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB(<O(N),O(1)>)"
---
## きもち


構築O(N), クエリO(1)のスパーステーブルだよ。  
通常のスパーステーブルの3倍くらい速いよ。  
たぶん厳密には構築O(N)じゃないかもしれない。  
ビットベクトルをガチャガチャすると理論的にO(N)になるらしい。  
これも見て　->　[noshi91さんの記事](https://noshi91.hatenablog.com/entry/2018/08/16/125415)

## 使い方  
#### template<S, op, e> ここで、Sは区間の要素の型、opは区間に対する演算、eはopの単位元。 
- `Compact_Sparse_Table(vector<S> &A)`：コンストラクタ。配列Aをもとにスパーステーブルを構築する。  
- `Element query(long L, long R)`：半開区間\[L, R)に対して演算結果を返す。  

## 計算量

構築:$\mathrm{O}(N)$  
クエリ:$\mathrm{O}(1)$  

## Tips

todo:ここに使用例を書く
