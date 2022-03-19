---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/Utility/CoordinateCompless.md
    document_title: "\u5EA7\u6A19\u5727\u7E2E"
    links: []
  bundledCode: "#line 1 \"Utility/CoordinateCompless.cpp\"\ntemplate < typename Element\
    \ = long >\nclass CoordinateCompless{\nprivate:\n    long index = 0;\n    vector<Element>\
    \ uniq;\npublic:\n    vector<long> After;\n    map<Element, long> BtoA;\n    map<long,\
    \ Element> AtoB;\n    \n    CoordinateCompless(vector<Element>& Before){\n   \
    \     uniq = Before;\n        sort(uniq.begin(), uniq.end());\n        uniq.erase(unique(uniq.begin(),\
    \ uniq.end()), uniq.end());\n        for(auto &e : uniq){\n            BtoA.insert(make_pair(e,\
    \ index));\n            AtoB.insert(make_pair(index, e));\n            index++;\n\
    \        }\n        for(auto &e : Before) After.push_back(BtoA.at(e));\n    }\n\
    };\n/**\n * @brief \u5EA7\u6A19\u5727\u7E2E\n * @docs docs/Utility/CoordinateCompless.md\n\
    \ */\n"
  code: "template < typename Element = long >\nclass CoordinateCompless{\nprivate:\n\
    \    long index = 0;\n    vector<Element> uniq;\npublic:\n    vector<long> After;\n\
    \    map<Element, long> BtoA;\n    map<long, Element> AtoB;\n    \n    CoordinateCompless(vector<Element>&\
    \ Before){\n        uniq = Before;\n        sort(uniq.begin(), uniq.end());\n\
    \        uniq.erase(unique(uniq.begin(), uniq.end()), uniq.end());\n        for(auto\
    \ &e : uniq){\n            BtoA.insert(make_pair(e, index));\n            AtoB.insert(make_pair(index,\
    \ e));\n            index++;\n        }\n        for(auto &e : Before) After.push_back(BtoA.at(e));\n\
    \    }\n};\n/**\n * @brief \u5EA7\u6A19\u5727\u7E2E\n * @docs docs/Utility/CoordinateCompless.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/CoordinateCompless.cpp
  requiredBy: []
  timestamp: '2021-10-28 19:08:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/CoordinateCompless.cpp
layout: document
redirect_from:
- /library/Utility/CoordinateCompless.cpp
- /library/Utility/CoordinateCompless.cpp.html
title: "\u5EA7\u6A19\u5727\u7E2E"
---
## 使い方
#### $Element$には集合の要素の型を代入してください。  
- `CoordinateConpless(vector<Element>& Before)`：コンストラクタ。配列$Before$を座標圧縮する。  
- `vector<long> After`：座標圧縮後の配列が格納される。  
- `map<Element, long> BtoA`：配列$Before$の要素を配列$After$の要素に変換する。  
- `map<long, Element> AtoB`：配列$After$の要素を配列$Before$の要素に変換する。

## 計算量
配列の要素数をNとするとき  
構築:$\mathrm{O}(N)$   
