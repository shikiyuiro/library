---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../NumberTheory/BaseConversion.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0306\"\
    \n\n#include \"../../template/template.cpp\"\n\n#include \"../../NumberTheory/BaseConversion.cpp\"\
    \n\nint main(){\n    BaseConversion bc;\n    long w; cin >> w;\n    long t = 1;\n\
    \    while(w >= t){\n        t *= 3;\n        t += 1;\n    }\n    string S = bc.from10(w\
    \ + t, 3);\n    long siz = S.size();\n    long i = 0;\n    bool notzerofirst =\
    \ false;\n    for(long i = 0; i < siz; i++){\n        if(S[i] == '2') cout <<\
    \ \"+\", notzerofirst = true;\n        if(S[i] == '1' && notzerofirst) cout <<\
    \ \"0\";\n        if(S[i] == '0') cout << \"-\", notzerofirst = true;\n    }\n\
    \    cout << endl;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/verify/BaseConversion.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/verify/BaseConversion.test.cpp
layout: document
redirect_from:
- /verify/test/verify/BaseConversion.test.cpp
- /verify/test/verify/BaseConversion.test.cpp.html
title: test/verify/BaseConversion.test.cpp
---
