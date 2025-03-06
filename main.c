//main.c
#include <stdio.h>
#include <string.h>
#include "main.h"

// グローバル変数
float rate = 0.0;  //許容利益率
int n = 0, m = 0;  //販売員数、クエリ数
Query queries[MAX_QUERIES];  //クエリ情報の実体を確保
int item_count = 0;  //商品ID計算用
int permission_count = 0; //販売許可ID計算用


int main() {
    reset(); //初期化
    readRate();  //許容利益率の取得
    readSellers();  //販売員の人数と名前の取得
    readQueries(); //クエリの数と内容の取得

    //クエリの実行
    for(int i=0; i<m; i++){
    if (strcmp(queries[i].type, "register-item:") == 0) {
        registerItem(queries,i);
    }else if (strcmp(queries[i].type, "request-sale:") == 0) {
        requestSale(queries,i);
    }else if (strcmp(queries[i].type, "complete-sale:") == 0) {
        completeSale(queries,i);
    }else{
        printf("erorr");
    }
    }

    //結果出力
    printResults();

    return 0;
}
