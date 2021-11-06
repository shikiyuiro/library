---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/LazySegmentTree.cpp
    title: DataStructure/LazySegmentTree.cpp
  - icon: ':heavy_check_mark:'
    path: Utility/CoordinateCompless.cpp
    title: "\u5EA7\u6A19\u5727\u7E2E"
  - icon: ':heavy_check_mark:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://atcoder.jp/contests/abc036/submissions/26855886
    - https://atcoder.jp/contests/typical90/submissions/27052694
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/verify/Atcoder.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n\n#line 1 \"template/template.cpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n#line 4 \"test/verify/Atcoder.test.cpp\"\n\n#line 1 \"Utility/CoordinateCompless.cpp\"\
    \ntemplate < typename Element = long >\nclass CoordinateCompless{\nprivate:\n\
    \    long index = 0;\n    vector<Element> uniq;\npublic:\n    vector<long> After;\n\
    \    map<Element, long> BtoA;\n    map<long, Element> AtoB;\n    \n    CoordinateCompless(vector<Element>&\
    \ Before){\n        uniq = Before;\n        sort(uniq.begin(), uniq.end());\n\
    \        uniq.erase(unique(uniq.begin(), uniq.end()), uniq.end());\n        for(auto\
    \ &e : uniq){\n            BtoA.insert(make_pair(e, index));\n            AtoB.insert(make_pair(index,\
    \ e));\n            index++;\n        }\n        for(auto &e : Before) After.push_back(BtoA.at(e));\n\
    \    }\n};\n/**\n * @brief \u5EA7\u6A19\u5727\u7E2E\n * @docs docs/Utility/CoordinateCompless.md\n\
    \ */\n#line 6 \"test/verify/Atcoder.test.cpp\"\n//\u4EE5\u4E0B\u306E\u554F\u984C\
    \u3067\u52D5\u4F5C\u78BA\u8A8D\u6E08\u307F\u3067\u3059\u3002\n//https://atcoder.jp/contests/abc036/submissions/26855886\n\
    \n#line 1 \"DataStructure/LazySegmentTree.cpp\"\ntemplate < typename Element =\
    \ long >\nclass LazySegmentTree {\nprivate:\n    Element e;\n    long vsiz;\n\
    \    long tsiz;\n    long queryL = -1, queryR = -1, queryV = -1;\n    vector<Element>\
    \ Table;\n    vector<long> TableL, TableR;\n    vector<Element> lazy;\n    vector<bool>\
    \ lazyFlag;\n    function<Element(Element)> lazyDeal;\n    function<Element(Element,\
    \ Element)> operation;\n    \n    long opera_rec(long vis = 1){\n        if(queryR\
    \ <= TableL[vis] or TableR[vis] <= queryL){\n            return e;\n        }\n\
    \        lazyEval(vis);\n        if(queryL <= TableL[vis] and TableR[vis] <= queryR){\n\
    \            return Table[vis];\n        }\n        return operation(opera_rec(vis\
    \ * 2), opera_rec(vis * 2 + 1));\n    }\n    \n    void update_rec(long vis =\
    \ 1){\n        lazyEval(vis);\n        if(queryR <= TableL[vis] or TableR[vis]\
    \ <= queryL){\n            return;\n        }\n        if(queryL <= TableL[vis]\
    \ and TableR[vis] <= queryR){\n            lazy[vis] = queryV;\n            lazyFlag[vis]\
    \ = true;\n            lazyEval(vis);\n            return;\n        }\n      \
    \  update_rec(vis * 2);\n        update_rec(vis * 2 + 1);\n        Table[vis]\
    \ = operation(Table[vis * 2], Table[2 * vis + 1]);\n    }\n    \n    void lazyEval(long\
    \ vis) {\n        if (not lazyFlag.at(vis)) return;\n        Table[vis] = lazy[vis];\n\
    \        if (vis < tsiz / 2) {\n            lazy[2 * vis + 1] = lazy[2 * vis]\
    \ = lazyDeal(lazy[vis]);\n            lazyFlag[2 * vis + 1] = lazyFlag[2 * vis]\
    \ = true;\n        }\n        lazyFlag[vis] = false;\n    }\n    \npublic:\n \
    \   LazySegmentTree(vector<Element> v, Element e, function<Element(Element, Element)>\
    \ operation, function<Element(Element)> lazyDeal = [](Element a){return a;}) :\
    \ e(e), operation(operation), lazyDeal(lazyDeal){\n        vsiz = v.size();\n\
    \        tsiz = 1;\n        while(tsiz < vsiz) tsiz *= 2;\n        tsiz *= 2;\n\
    \        Table.resize(tsiz, e);\n        TableL.resize(tsiz, e);\n        TableR.resize(tsiz,\
    \ e);\n        lazy.resize(tsiz, e);\n        lazyFlag.resize(tsiz, false);\n\
    \        for(long vi = 0; vi < tsiz / 2; vi++){\n            if(vi < vsiz) Table[vi\
    \ + tsiz / 2] = v[vi];\n            TableL[vi + tsiz / 2] = vi;\n            TableR[vi\
    \ + tsiz / 2] = vi + 1;\n        }\n        for(long p = tsiz / 2 - 1; p >= 1;\
    \ p--){\n            Table[p] = operation(Table[p * 2], Table[p * 2 + 1]);\n \
    \           TableL[p] = TableL[p * 2];\n            TableR[p] = TableR[p * 2 +\
    \ 1];\n        }\n    }\n    \n    Element query_opera(long l, long r/*\u534A\u958B\
    \u533A\u9593*/){\n        queryL = l; queryR = r;\n        return opera_rec();\n\
    \    }\n    \n    void query_update(long l, long r/*\u534A\u958B\u533A\u9593*/,\
    \ Element value){\n        queryL = l; queryR = r; queryV = value;\n        return\
    \ update_rec();\n    }\n};\n#line 10 \"test/verify/Atcoder.test.cpp\"\n//\u4EE5\
    \u4E0B\u306E\u554F\u984C\u3067\u52D5\u4F5C\u78BA\u8A8D\u6E08\u307F\u3067\u3059\
    \u3002\n//https://atcoder.jp/contests/typical90/submissions/27052694\n\nint main(){\n\
    \    long A, B; cin >> A >> B;\n    cout << A + B << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../template/template.cpp\"\n\n#include \"../../Utility/CoordinateCompless.cpp\"\
    \n//\u4EE5\u4E0B\u306E\u554F\u984C\u3067\u52D5\u4F5C\u78BA\u8A8D\u6E08\u307F\u3067\
    \u3059\u3002\n//https://atcoder.jp/contests/abc036/submissions/26855886\n\n#include\
    \ \"../../DataStructure/LazySegmentTree.cpp\"\n//\u4EE5\u4E0B\u306E\u554F\u984C\
    \u3067\u52D5\u4F5C\u78BA\u8A8D\u6E08\u307F\u3067\u3059\u3002\n//https://atcoder.jp/contests/typical90/submissions/27052694\n\
    \nint main(){\n    long A, B; cin >> A >> B;\n    cout << A + B << endl;\n}\n"
  dependsOn:
  - template/template.cpp
  - Utility/CoordinateCompless.cpp
  - DataStructure/LazySegmentTree.cpp
  isVerificationFile: true
  path: test/verify/Atcoder.test.cpp
  requiredBy: []
  timestamp: '2021-11-06 17:18:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/Atcoder.test.cpp
layout: document
redirect_from:
- /verify/test/verify/Atcoder.test.cpp
- /verify/test/verify/Atcoder.test.cpp.html
title: test/verify/Atcoder.test.cpp
---
