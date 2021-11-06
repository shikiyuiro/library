---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/Atcoder.test.cpp
    title: test/verify/Atcoder.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u30FB\u9045\u5EF6\u8A55\u4FA1"
    links: []
  bundledCode: "#line 1 \"DataStructure/LazySegmentTree.cpp\"\ntemplate < typename\
    \ Element = long >\nclass LazySegmentTree {\nprivate:\n    Element e;\n    long\
    \ vsiz;\n    long tsiz;\n    long queryL = -1, queryR = -1, queryV = -1;\n   \
    \ vector<Element> Table;\n    vector<long> TableL, TableR;\n    vector<Element>\
    \ lazy;\n    vector<bool> lazyFlag;\n    function<Element(Element)> lazyDeal;\n\
    \    function<Element(Element, Element)> operation;\n    \n    long opera_rec(long\
    \ vis = 1){\n        if(queryR <= TableL[vis] or TableR[vis] <= queryL){\n   \
    \         return e;\n        }\n        lazyEval(vis);\n        if(queryL <= TableL[vis]\
    \ and TableR[vis] <= queryR){\n            return Table[vis];\n        }\n   \
    \     return operation(opera_rec(vis * 2), opera_rec(vis * 2 + 1));\n    }\n \
    \   \n    void update_rec(long vis = 1){\n        lazyEval(vis);\n        if(queryR\
    \ <= TableL[vis] or TableR[vis] <= queryL){\n            return;\n        }\n\
    \        if(queryL <= TableL[vis] and TableR[vis] <= queryR){\n            lazy[vis]\
    \ = queryV;\n            lazyFlag[vis] = true;\n            lazyEval(vis);\n \
    \           return;\n        }\n        update_rec(vis * 2);\n        update_rec(vis\
    \ * 2 + 1);\n        Table[vis] = operation(Table[vis * 2], Table[2 * vis + 1]);\n\
    \    }\n    \n    void lazyEval(long vis) {\n        if (not lazyFlag.at(vis))\
    \ return;\n        Table[vis] = lazy[vis];\n        if (vis < tsiz / 2) {\n  \
    \          lazy[2 * vis + 1] = lazy[2 * vis] = lazyDeal(lazy[vis]);\n        \
    \    lazyFlag[2 * vis + 1] = lazyFlag[2 * vis] = true;\n        }\n        lazyFlag[vis]\
    \ = false;\n    }\n    \npublic:\n    LazySegmentTree(vector<Element> v, Element\
    \ e, function<Element(Element, Element)> operation, function<Element(Element)>\
    \ lazyDeal = [](Element a){return a;}) : e(e), operation(operation), lazyDeal(lazyDeal){\n\
    \        vsiz = v.size();\n        tsiz = 1;\n        while(tsiz < vsiz) tsiz\
    \ *= 2;\n        tsiz *= 2;\n        Table.resize(tsiz, e);\n        TableL.resize(tsiz,\
    \ e);\n        TableR.resize(tsiz, e);\n        lazy.resize(tsiz, e);\n      \
    \  lazyFlag.resize(tsiz, false);\n        for(long vi = 0; vi < tsiz / 2; vi++){\n\
    \            if(vi < vsiz) Table[vi + tsiz / 2] = v[vi];\n            TableL[vi\
    \ + tsiz / 2] = vi;\n            TableR[vi + tsiz / 2] = vi + 1;\n        }\n\
    \        for(long p = tsiz / 2 - 1; p >= 1; p--){\n            Table[p] = operation(Table[p\
    \ * 2], Table[p * 2 + 1]);\n            TableL[p] = TableL[p * 2];\n         \
    \   TableR[p] = TableR[p * 2 + 1];\n        }\n    }\n    \n    Element query_opera(long\
    \ l, long r/*\u534A\u958B\u533A\u9593*/){\n        queryL = l; queryR = r;\n \
    \       return opera_rec();\n    }\n    \n    void query_update(long l, long r/*\u534A\
    \u958B\u533A\u9593*/, Element value){\n        queryL = l; queryR = r; queryV\
    \ = value;\n        return update_rec();\n    }\n};\n/**\n * @brief \u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728\u30FB\u9045\u5EF6\u8A55\u4FA1\n */\n"
  code: "template < typename Element = long >\nclass LazySegmentTree {\nprivate:\n\
    \    Element e;\n    long vsiz;\n    long tsiz;\n    long queryL = -1, queryR\
    \ = -1, queryV = -1;\n    vector<Element> Table;\n    vector<long> TableL, TableR;\n\
    \    vector<Element> lazy;\n    vector<bool> lazyFlag;\n    function<Element(Element)>\
    \ lazyDeal;\n    function<Element(Element, Element)> operation;\n    \n    long\
    \ opera_rec(long vis = 1){\n        if(queryR <= TableL[vis] or TableR[vis] <=\
    \ queryL){\n            return e;\n        }\n        lazyEval(vis);\n       \
    \ if(queryL <= TableL[vis] and TableR[vis] <= queryR){\n            return Table[vis];\n\
    \        }\n        return operation(opera_rec(vis * 2), opera_rec(vis * 2 + 1));\n\
    \    }\n    \n    void update_rec(long vis = 1){\n        lazyEval(vis);\n   \
    \     if(queryR <= TableL[vis] or TableR[vis] <= queryL){\n            return;\n\
    \        }\n        if(queryL <= TableL[vis] and TableR[vis] <= queryR){\n   \
    \         lazy[vis] = queryV;\n            lazyFlag[vis] = true;\n           \
    \ lazyEval(vis);\n            return;\n        }\n        update_rec(vis * 2);\n\
    \        update_rec(vis * 2 + 1);\n        Table[vis] = operation(Table[vis *\
    \ 2], Table[2 * vis + 1]);\n    }\n    \n    void lazyEval(long vis) {\n     \
    \   if (not lazyFlag.at(vis)) return;\n        Table[vis] = lazy[vis];\n     \
    \   if (vis < tsiz / 2) {\n            lazy[2 * vis + 1] = lazy[2 * vis] = lazyDeal(lazy[vis]);\n\
    \            lazyFlag[2 * vis + 1] = lazyFlag[2 * vis] = true;\n        }\n  \
    \      lazyFlag[vis] = false;\n    }\n    \npublic:\n    LazySegmentTree(vector<Element>\
    \ v, Element e, function<Element(Element, Element)> operation, function<Element(Element)>\
    \ lazyDeal = [](Element a){return a;}) : e(e), operation(operation), lazyDeal(lazyDeal){\n\
    \        vsiz = v.size();\n        tsiz = 1;\n        while(tsiz < vsiz) tsiz\
    \ *= 2;\n        tsiz *= 2;\n        Table.resize(tsiz, e);\n        TableL.resize(tsiz,\
    \ e);\n        TableR.resize(tsiz, e);\n        lazy.resize(tsiz, e);\n      \
    \  lazyFlag.resize(tsiz, false);\n        for(long vi = 0; vi < tsiz / 2; vi++){\n\
    \            if(vi < vsiz) Table[vi + tsiz / 2] = v[vi];\n            TableL[vi\
    \ + tsiz / 2] = vi;\n            TableR[vi + tsiz / 2] = vi + 1;\n        }\n\
    \        for(long p = tsiz / 2 - 1; p >= 1; p--){\n            Table[p] = operation(Table[p\
    \ * 2], Table[p * 2 + 1]);\n            TableL[p] = TableL[p * 2];\n         \
    \   TableR[p] = TableR[p * 2 + 1];\n        }\n    }\n    \n    Element query_opera(long\
    \ l, long r/*\u534A\u958B\u533A\u9593*/){\n        queryL = l; queryR = r;\n \
    \       return opera_rec();\n    }\n    \n    void query_update(long l, long r/*\u534A\
    \u958B\u533A\u9593*/, Element value){\n        queryL = l; queryR = r; queryV\
    \ = value;\n        return update_rec();\n    }\n};\n/**\n * @brief \u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728\u30FB\u9045\u5EF6\u8A55\u4FA1\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/LazySegmentTree.cpp
  requiredBy: []
  timestamp: '2021-11-06 17:21:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/Atcoder.test.cpp
documentation_of: DataStructure/LazySegmentTree.cpp
layout: document
redirect_from:
- /library/DataStructure/LazySegmentTree.cpp
- /library/DataStructure/LazySegmentTree.cpp.html
title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u30FB\u9045\u5EF6\u8A55\u4FA1"
---
