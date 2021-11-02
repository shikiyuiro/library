## 使い方

- `BaseConversion()`：コンストラクタ。  
- `string from10(long num, long base)`：10進数の$num$を$base$進数に変換する。  
- `long to10(string num, long base)`：$base$進数の$num$を10進数に変換する。  
 
## 計算量

構築:$\mathrm{O}(N)$  
クエリ:$\mathrm{O}(logN)$  

## Tips  

$private$内の$symbol$を書き換えることで17進数以上にも対応できます。  
