## きもち

フェニック木です。あとでかきます。  

## 使い方  
- `FenwickTree(long siz)`：コンストラクタ。サイズsizの配列におけるフェニック木を構築する。  
- `long sum(long index)`：配列の0番目からindex番目までの要素の和を求める。  
- `void add(long index, long value)`：配列のindex番目の要素にvalueを加算する  

## 計算量
サイズをNとして、  
sumクエリ:$\mathrm{O}(N)$  
addクエリ:$\mathrm{O}(logN)$  

## Tips

加算だけでなく、モノイドをなす演算に拡張できる。  
また、累積和の要領で始点が0番目でないときの区間和も求められる。  
