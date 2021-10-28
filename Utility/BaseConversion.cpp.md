---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/BaseConversion.test.cpp
    title: test/verify/BaseConversion.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/Utility/BaseConversion.md
    document_title: "\u9032\u6570\u5909\u63DB"
    links: []
  bundledCode: "#line 1 \"Utility/BaseConversion.cpp\"\nclass BaseConversion {\nprivate:\n\
    \    string symbol = \"0123456789ABCDEF\";\n    long to_num[128];\npublic:\n \
    \   BaseConversion(){\n        long basemax = symbol.length();\n        for(long\
    \ i = 0; i < basemax; i++) to_num[(long)symbol[i]] = i;\n    }\n    \n    string\
    \ from10(long num, long base) {\n        if(num == 0) return \"0\";\n        string\
    \ res = \"\";\n        while(num > 0){\n            res = symbol[num % base] +\
    \ res;\n            num /= base;\n        }\n        return res;\n    }\n    \n\
    \    long to10(string num, long base) {\n        long res = 0;\n        long numsize\
    \ = num.length();\n        for(long i = 0; i < numsize; ++i) res = res * base\
    \ + to_num[(long)num[i]];\n        return res;\n    }\n};\n/**\n * @brief \u9032\
    \u6570\u5909\u63DB\n * @docs docs/Utility/BaseConversion.md\n */\n"
  code: "class BaseConversion {\nprivate:\n    string symbol = \"0123456789ABCDEF\"\
    ;\n    long to_num[128];\npublic:\n    BaseConversion(){\n        long basemax\
    \ = symbol.length();\n        for(long i = 0; i < basemax; i++) to_num[(long)symbol[i]]\
    \ = i;\n    }\n    \n    string from10(long num, long base) {\n        if(num\
    \ == 0) return \"0\";\n        string res = \"\";\n        while(num > 0){\n \
    \           res = symbol[num % base] + res;\n            num /= base;\n      \
    \  }\n        return res;\n    }\n    \n    long to10(string num, long base) {\n\
    \        long res = 0;\n        long numsize = num.length();\n        for(long\
    \ i = 0; i < numsize; ++i) res = res * base + to_num[(long)num[i]];\n        return\
    \ res;\n    }\n};\n/**\n * @brief \u9032\u6570\u5909\u63DB\n * @docs docs/Utility/BaseConversion.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/BaseConversion.cpp
  requiredBy: []
  timestamp: '2021-10-28 18:42:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/BaseConversion.test.cpp
documentation_of: Utility/BaseConversion.cpp
layout: document
redirect_from:
- /library/Utility/BaseConversion.cpp
- /library/Utility/BaseConversion.cpp.html
title: "\u9032\u6570\u5909\u63DB"
---
## 使い方

- `BaseConversion()`：コンストラクタ。  
- `string from10(long num, long base)`：$base$進数の$num$を10進数に変換する。  
- `long to10(string num, long base)`：10進数の$num$を$base$進数に変換する。  
 
## 計算量

構築:$\mathrm{O}(N)$  
クエリ:$\mathrm{O}(logN)$  

## Tips  

$private$内の$symbol$を書き換えることで17進数以上にも対応できます。  
