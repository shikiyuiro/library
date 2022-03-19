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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../DataStructure/SparseTable_Compact.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"../../template/template.cpp\"\n\n#include \"../../DataStructure/SparseTable_Compact.cpp\"\
    \n\nlong op(long a, long b){ return min(a, b);}\nlong e() { return LONG_MAX;}\n\
    \nint main(){\n    long N, Q; cin >> N >> Q;\n    vector<long> A(N);\n    for(long\
    \ i = 0; i < N; i++) cin >> A[i];\n    \n    Compact_Sparse_Table<long, op, e>\
    \ STA(A);\n    while(Q--){\n        long u, v; cin >> u >> v;\n        cout <<\
    \ STA.query(u, v) << endl;\n    }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/verify/SparseTable_Compact.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/verify/SparseTable_Compact.test.cpp
layout: document
redirect_from:
- /verify/test/verify/SparseTable_Compact.test.cpp
- /verify/test/verify/SparseTable_Compact.test.cpp.html
title: test/verify/SparseTable_Compact.test.cpp
---
