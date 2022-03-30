---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Classic/Inversion.cpp
    title: "\u8EE2\u5012\u6570"
  - icon: ':heavy_check_mark:'
    path: template/template.cpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://atcoder.jp/contests/chokudai_S001/submissions/30509909
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/Inversion.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n\n#line 1 \"template/template.cpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n/**\n * @brief \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @docs docs/template/template.md\n\
    \ */\n#line 1 \"Classic/Inversion.cpp\"\nint64_t inversion(vector<int64_t> &v){\n\
    \    vector<int64_t> st = v;\n    sort(st.begin(), st.end());\n    st.erase(unique(st.begin(),\
    \ st.end()), st.end());\n    vector<int64_t> table(st.size()+1);\n    for(auto\
    \ e : v){\n        int64_t a = st.size() + (st.begin() - lower_bound(st.begin(),\
    \ st.end(), e)), b = a - 1;\n        for(;a < table.size(); a += (a & -a)) ++table[a];\n\
    \        for(;b > 0; b -= (b & -b)) table[0] += table[b];\n    }\n    return table[0];\n\
    }\n/**\n * @brief \u8EE2\u5012\u6570\n * @docs docs/Classic/Inversion.md\n */\n\
    #line 5 \"verify/Inversion.test.cpp\"\n//\u4EE5\u4E0B\u306E\u554F\u984C\u3067\u52D5\
    \u4F5C\u78BA\u8A8D\u6E08\u307F\u3067\u3059\u3002\n//https://atcoder.jp/contests/chokudai_S001/submissions/30509909\n\
    \nint main(){\n    int64_t A, B; cin >> A >> B;\n    cout << A + B << '\\n';\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../template/template.cpp\"\n#include \"../Classic/Inversion.cpp\"\n//\u4EE5\u4E0B\
    \u306E\u554F\u984C\u3067\u52D5\u4F5C\u78BA\u8A8D\u6E08\u307F\u3067\u3059\u3002\
    \n//https://atcoder.jp/contests/chokudai_S001/submissions/30509909\n\nint main(){\n\
    \    int64_t A, B; cin >> A >> B;\n    cout << A + B << '\\n';\n}\n"
  dependsOn:
  - template/template.cpp
  - Classic/Inversion.cpp
  isVerificationFile: true
  path: verify/Inversion.test.cpp
  requiredBy: []
  timestamp: '2022-03-27 20:12:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/Inversion.test.cpp
layout: document
redirect_from:
- /verify/verify/Inversion.test.cpp
- /verify/verify/Inversion.test.cpp.html
title: verify/Inversion.test.cpp
---
