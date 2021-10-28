## 使い方
#### $Element$には集合の要素の型を代入してください。  
- `CoordinateConpless(vector<Element>& Before)`：コンストラクタ。配列$Before$を座標圧縮する。  
- `vector<long> After`：座標圧縮後の配列が格納される。  
- `map<Element, long> BtoA`：配列$Before$の要素を配列$After$の要素に変換する。  
- `map<long, Element> AtoB`：配列$After$の要素を配列$Before$の要素に変換する。

## 計算量
配列の要素数をNとするとき  
構築:$\mathrm{O}(N)$   
