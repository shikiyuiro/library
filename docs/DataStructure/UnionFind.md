## Union-Find

#### 概要

素集合を根付き木として管理することで以下のクエリを高速に実行できる。  
$Union$クエリ:与えられた2頂点を含む集合を連結にする。  
$Find$クエリ:与えられた2頂点の根を参照し、2頂点が連結であるか判定する。  

#### 使い方

-`Union_find(long size)`：頂点数sizeの素集合を構築する。  
-`long root(long x)`：頂点xの根を返す。  
-`void unite(long x, long y)`：頂点xを含む集合と頂点yを含む集合を連結にする。  
-`bool same(long x, long y)`：頂点xと頂点yが連結であるかどうかを返す。  

#### 計算量

構築:$\mathrm{O}(N)$  
クエリ:$\mathrm{O}(log N)$。  
上手に実装すると$\mathrm{O}(log N)$より速くなるらしいです。精進します。  
