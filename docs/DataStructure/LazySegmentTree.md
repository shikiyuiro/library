## きもち  
区間演算と、区間更新を両方高速に行うことができるデータ構造。  
演算£がモノイドをなし、任意の元 X に対して、Y £ Y = X なる Y(これ抽象代数で名前ついてますか?) が計算できる必要がある

## 使い方  
#### $Element$には集合の要素の型を代入してください。
- `LazySegmentTree(vector<Element> v, Element e, function<Element(Element, Element)> operation, 
function<Element(Element)> lazyDeal = [](Element a){return a;})`：コンストラクタ。  
配列v, 演算の単位元e, 演算operationのスパーステーブルを構築する。  
lazyDeal関数は演算を£として、Xが与えられた時に、Y£Y=Xを満たすようなYを返す関数。  
- `Element query_opera(long l, long r)`：半開区間\[l, r)に対する演算結果を返す。  
- `Element query_update(long l, long r, Element value)`：半開区間\[l, r)にvalueを代入する。一様加算もできる。

## 計算量

構築:$\mathrm{O}(NlogN)$  
クエリ:$\mathrm{O}(logN)$  
