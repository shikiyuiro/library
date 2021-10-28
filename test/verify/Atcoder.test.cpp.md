---
data:
  _extendedDependsOn:
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
    \nint main(){\n    long A, B; cin >> A >> B;\n    cout << A + B << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../template/template.cpp\"\n\n#include \"../../Utility/CoordinateCompless.cpp\"\
    \n//\u4EE5\u4E0B\u306E\u554F\u984C\u3067\u52D5\u4F5C\u78BA\u8A8D\u6E08\u307F\u3067\
    \u3059\u3002\n//https://atcoder.jp/contests/abc036/submissions/26855886\n\nint\
    \ main(){\n    long A, B; cin >> A >> B;\n    cout << A + B << endl;\n}\n"
  dependsOn:
  - template/template.cpp
  - Utility/CoordinateCompless.cpp
  isVerificationFile: true
  path: test/verify/Atcoder.test.cpp
  requiredBy: []
  timestamp: '2021-10-28 19:18:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/Atcoder.test.cpp
layout: document
redirect_from:
- /verify/test/verify/Atcoder.test.cpp
- /verify/test/verify/Atcoder.test.cpp.html
title: test/verify/Atcoder.test.cpp
---
