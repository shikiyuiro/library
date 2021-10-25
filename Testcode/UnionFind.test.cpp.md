---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: shikiyuiro/Library/DataStructure/UnionFind.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#include \"shikiyuiro/Library/DataStructure/UnionFind.cpp\"\
    \n\nint main(){\n    long N, Q; cin >> N >> Q;\n    Union_find uf(N);\n    long\
    \ t, u, v;\n    while(Q--){\n        cin >> t >> u >> v;\n        if(t == 0) uf.unite(u,\
    \ v);\n        if(t == 1) cout << (uf.same(u, v) ? 1 : 0) << endl;\n    }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: Testcode/UnionFind.test.cpp
  requiredBy: []
  timestamp: '2021-10-25 16:40:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Testcode/UnionFind.test.cpp
layout: document
redirect_from:
- /verify/Testcode/UnionFind.test.cpp
- /verify/Testcode/UnionFind.test.cpp.html
title: Testcode/UnionFind.test.cpp
---
