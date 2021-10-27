---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: NumberTheory/BaseConversion.cpp
    title: "\u9032\u6570\u5909\u63DB"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0306
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0306
  bundledCode: "#line 1 \"test/verify/BaseConversion.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0306\"\n\n#line 1 \"\
    template/template.cpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n#line\
    \ 4 \"test/verify/BaseConversion.test.cpp\"\n\n#line 1 \"NumberTheory/BaseConversion.cpp\"\
    \nclass BaseConversion {\nprivate:\n    string symbol = \"0123456789ABCDEF\";\n\
    \    long to_num[128];\npublic:\n    BaseConversion(){\n        long basemax =\
    \ symbol.length();\n        for(long i = 0; i < basemax; i++) to_num[(long)symbol[i]]\
    \ = i;\n    }\n    \n    string from10(long num, long base) {\n        if(num\
    \ == 0) return \"0\";\n        string res = \"\";\n        while(num > 0){\n \
    \           res = symbol[num % base] + res;\n            num /= base;\n      \
    \  }\n        return res;\n    }\n    \n    long to10(string num, long base) {\n\
    \        long res = 0;\n        long numsize = num.length();\n        for(long\
    \ i = 0; i < numsize; ++i) res = res * base + to_num[(long)num[i]];\n        return\
    \ res;\n    }\n};\n/**\n * @brief \u9032\u6570\u5909\u63DB\n * @docs docs/NumberTheory/BaseConversion.md\n\
    \ */\n#line 6 \"test/verify/BaseConversion.test.cpp\"\n\nint main(){\n    BaseConversion\
    \ bc;\n    long w; cin >> w;\n    long t = 1;\n    while(w >= t){\n        t *=\
    \ 3;\n        t += 1;\n    }\n    string S = bc.from10(w + t, 3);\n    long siz\
    \ = S.size();\n    long i = 0;\n    bool notzerofirst = false;\n    for(long i\
    \ = 0; i < siz; i++){\n        if(S[i] == '2') cout << \"+\", notzerofirst = true;\n\
    \        if(S[i] == '1' && notzerofirst) cout << \"0\";\n        if(S[i] == '0')\
    \ cout << \"-\", notzerofirst = true;\n    }\n    cout << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0306\"\
    \n\n#include \"../../template/template.cpp\"\n\n#include \"../../NumberTheory/BaseConversion.cpp\"\
    \n\nint main(){\n    BaseConversion bc;\n    long w; cin >> w;\n    long t = 1;\n\
    \    while(w >= t){\n        t *= 3;\n        t += 1;\n    }\n    string S = bc.from10(w\
    \ + t, 3);\n    long siz = S.size();\n    long i = 0;\n    bool notzerofirst =\
    \ false;\n    for(long i = 0; i < siz; i++){\n        if(S[i] == '2') cout <<\
    \ \"+\", notzerofirst = true;\n        if(S[i] == '1' && notzerofirst) cout <<\
    \ \"0\";\n        if(S[i] == '0') cout << \"-\", notzerofirst = true;\n    }\n\
    \    cout << endl;\n}\n"
  dependsOn:
  - template/template.cpp
  - NumberTheory/BaseConversion.cpp
  isVerificationFile: true
  path: test/verify/BaseConversion.test.cpp
  requiredBy: []
  timestamp: '2021-10-27 14:25:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/BaseConversion.test.cpp
layout: document
redirect_from:
- /verify/test/verify/BaseConversion.test.cpp
- /verify/test/verify/BaseConversion.test.cpp.html
title: test/verify/BaseConversion.test.cpp
---
