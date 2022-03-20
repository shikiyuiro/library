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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../template/template.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"../../template/template.cpp\"\n#include \"../../DataStructure/SparseTable.cpp\"\
    \n\nint64_t op(int64_t a, int64_t b){\n    return min(a, b);\n}\n\nint64_t e(){\n\
    \    return INT64_MAX;\n}\n\nint main(){\n    cin.tie(nullptr)->ios::sync_with_stdio(false);\n\
    \    int64_t N, Q; cin >> N >> Q;\n    vector<int64_t> A(N);\n    for(int64_t\
    \ i = 0; i < N; i++) cin >> A[i];\n    SparseTable<int64_t, op, e> sp(A);\n  \
    \  while(Q--){\n        int64_t l, r; cin >> l >> r;\n        cout << sp.fold(l,\
    \ r) << '\\n';\n    }\n}\n\n"
  dependsOn: []
  isVerificationFile: true
  path: verify/SparseTable.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/SparseTable.test.cpp
layout: document
redirect_from:
- /verify/verify/SparseTable.test.cpp
- /verify/verify/SparseTable.test.cpp.html
title: verify/SparseTable.test.cpp
---
