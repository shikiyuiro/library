---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../DataStructure/LazySegmentTree.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../template/template.cpp\"\n\n#include \"../../Utility/CoordinateCompless.cpp\"\
    \n//\u4EE5\u4E0B\u306E\u554F\u984C\u3067\u52D5\u4F5C\u78BA\u8A8D\u6E08\u307F\u3067\
    \u3059\u3002\n//https://atcoder.jp/contests/abc036/submissions/26855886\n\n#include\
    \ \"../../DataStructure/LazySegmentTree.cpp\"\n//\u4EE5\u4E0B\u306E\u554F\u984C\
    \u3067\u52D5\u4F5C\u78BA\u8A8D\u6E08\u307F\u3067\u3059\u3002\n//https://atcoder.jp/contests/typical90/submissions/27052694\n\
    \n#include \"../../DataStructure/WaveletMatrix_Weighted.cpp\"\n//\u4EE5\u4E0B\u306E\
    \u554F\u984C\u3067\u52D5\u4F5C\u78BA\u8A8D\u6E08\u307F\u3067\u3059\u3002\n//https://atcoder.jp/contests/abc133/submissions/28651189\n\
    \n#include \"../../DataStructure/MergeTree.cpp\"\n//\u4EE5\u4E0B\u306E\u554F\u984C\
    \u3067\u52D5\u4F5C\u78BA\u8A8D\u6E08\u307F\u3067\u3059\u3002\n//https://atcoder.jp/contests/abc183/submissions/28824947\n\
    \nint main(){\n    long A, B; cin >> A >> B;\n    cout << A + B << endl;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/verify/Atcoder.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/verify/Atcoder.test.cpp
layout: document
redirect_from:
- /verify/test/verify/Atcoder.test.cpp
- /verify/test/verify/Atcoder.test.cpp.html
title: test/verify/Atcoder.test.cpp
---
