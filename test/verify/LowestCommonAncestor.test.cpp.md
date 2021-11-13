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
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../DataStructure/SparseTable.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include \"../../template/template.cpp\"\
    \n\n#include \"../../Graph/LowestCommonAncestor.cpp\"\n\nint main(){\n    long\
    \ N, Q; cin >> N >> Q;\n    vector<vector<long>> tree(N);\n    for(long i = 1;\
    \ i <= N - 1; i++){\n        long p; cin >> p;\n        tree[i].push_back(p);\n\
    \        tree[p].push_back(i);\n    }\n    \n    LowestCommonAncestor lca(tree,\
    \ 0);\n    while(Q--){\n        long u, v; cin >> u >> v;\n        cout << lca.query(u,\
    \ v) << endl;\n    }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/verify/LowestCommonAncestor.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/verify/LowestCommonAncestor.test.cpp
layout: document
redirect_from:
- /verify/test/verify/LowestCommonAncestor.test.cpp
- /verify/test/verify/LowestCommonAncestor.test.cpp.html
title: test/verify/LowestCommonAncestor.test.cpp
---
