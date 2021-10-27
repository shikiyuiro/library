## きもち

素集合を根付き木の集合として管理することで以下のクエリを高速に実行できる。  
$Union$クエリ:与えられた2頂点を含む集合を連結にする。  
$Find$クエリ:与えられた頂点の根を求める。  
$Same$クエリ:与えられた2頂点が連結であるか判定する。  
$Size$クエリ:与えられた頂点を含む集合の大きさを求める。

## 使い方

- `UnionFind(long size)`：頂点数sizeの素集合を構築する。  
- `long find(long x)`：頂点xの根を返す。  
- `void unite(long x, long y)`：頂点xを含む集合と頂点yを含む集合を連結にする。  
- `bool same(long x, long y)`：頂点xと頂点yが連結であるならば$true$、そうでなければ$false$を返す。  
- `long size(long x, long y)`：頂点xを含む集合の大きさを返す。  

## 計算量

構築:$\mathrm{O}(N)$  
クエリ:$\mathrm{O}(\alpha(N))$(償却・$\alpha$はアッカーマン関数の逆関数)   

## Tips
  
グリッドなどの連結判定にも利用できる。
