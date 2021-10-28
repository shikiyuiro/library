---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Utility/CoordinateCompless.cpp\"\ntemplate < typename Element\
    \ = long >\nclass CoordinateCompless{\nprivate:\n    long index = 0;\n    vector<Element>\
    \ uniq;\npublic:\n    vector<Element> After;\n    map<Element, long> BtoA;\n \
    \   map<long, Element> AtoB;\n    \n    CoordinateCompless(vector<Element>& Before){\n\
    \        uniq = Before;\n        sort(uniq.begin(), uniq.end());\n        uniq.erase(unique(uniq.begin(),\
    \ uniq.end()), uniq.end());\n        for(auto &e : uniq){\n            BtoA.insert(make_pair(e,\
    \ index));\n            AtoB.insert(make_pair(index, e));\n            index++;\n\
    \        }\n        After = Before;\n        for(auto &e : After) e = BtoA.at(e);\n\
    \    }\n};\n"
  code: "template < typename Element = long >\nclass CoordinateCompless{\nprivate:\n\
    \    long index = 0;\n    vector<Element> uniq;\npublic:\n    vector<Element>\
    \ After;\n    map<Element, long> BtoA;\n    map<long, Element> AtoB;\n    \n \
    \   CoordinateCompless(vector<Element>& Before){\n        uniq = Before;\n   \
    \     sort(uniq.begin(), uniq.end());\n        uniq.erase(unique(uniq.begin(),\
    \ uniq.end()), uniq.end());\n        for(auto &e : uniq){\n            BtoA.insert(make_pair(e,\
    \ index));\n            AtoB.insert(make_pair(index, e));\n            index++;\n\
    \        }\n        After = Before;\n        for(auto &e : After) e = BtoA.at(e);\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/CoordinateCompless.cpp
  requiredBy: []
  timestamp: '2021-10-28 18:38:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/CoordinateCompless.cpp
layout: document
redirect_from:
- /library/Utility/CoordinateCompless.cpp
- /library/Utility/CoordinateCompless.cpp.html
title: Utility/CoordinateCompless.cpp
---
