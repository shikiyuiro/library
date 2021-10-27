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
  bundledCode: "#line 1 \"NumberTheory/BaseConversion.cpp\"\nclass BaseConversion\
    \ {\nprivate:\n    string symbol = \"0123456789ABCDEF\";\n    long to_num[128];\n\
    public:\n    BaseConversion(){\n        long basemax = symbol.length();\n    \
    \    for(long i = 0; i < basemax; i++) to_num[(long)symbol[i]] = i;\n    }\n \
    \   \n    string from10(long num, long base) {\n        if(num == 0) return \"\
    0\";\n        string res = \"\";\n        while(num > 0){\n            res = symbol[num\
    \ % base] + res;\n            num /= base;\n        }\n        return res;\n \
    \   }\n    \n    long to10(string num, long base) {\n        long res = 0;\n \
    \       long numsize = num.length();\n        for(long i = 0; i < numsize; ++i)\
    \ res = res * base + to_num[(long)num[i]];\n        return res;\n    }\n};\n"
  code: "class BaseConversion {\nprivate:\n    string symbol = \"0123456789ABCDEF\"\
    ;\n    long to_num[128];\npublic:\n    BaseConversion(){\n        long basemax\
    \ = symbol.length();\n        for(long i = 0; i < basemax; i++) to_num[(long)symbol[i]]\
    \ = i;\n    }\n    \n    string from10(long num, long base) {\n        if(num\
    \ == 0) return \"0\";\n        string res = \"\";\n        while(num > 0){\n \
    \           res = symbol[num % base] + res;\n            num /= base;\n      \
    \  }\n        return res;\n    }\n    \n    long to10(string num, long base) {\n\
    \        long res = 0;\n        long numsize = num.length();\n        for(long\
    \ i = 0; i < numsize; ++i) res = res * base + to_num[(long)num[i]];\n        return\
    \ res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: NumberTheory/BaseConversion.cpp
  requiredBy: []
  timestamp: '2021-10-27 13:22:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: NumberTheory/BaseConversion.cpp
layout: document
redirect_from:
- /library/NumberTheory/BaseConversion.cpp
- /library/NumberTheory/BaseConversion.cpp.html
title: NumberTheory/BaseConversion.cpp
---
