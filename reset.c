//reset.c
#include "main.h"
#include <stdio.h>
#include <string.h>  // `memset()` を使用するため

void reset() {
    // 許容利益率を初期化
    rate = 0.0;

    // 商品IDカウントをリセット
    item_count = 0;

    // 販売員数とクエリ数をリセット
    n = 0;
    m = 0;

    // **クエリ配列の各要素を初期化**
    for (int i = 0; i < MAX_QUERIES; i++) {
        strcpy(queries[i].type, "");  // クエリの種類を空文字にする
        queries[i].id = 0;  // ✅ 販売許可IDを 0 にリセット
        queries[i].sale_complited = 0;  // 販売完了フラグをリセット
        queries[i].permission = 0;  // 販売許可変数をリセット

        // **時刻情報の初期化**
        queries[i].time.year = 0;
        queries[i].time.month = 0;
        queries[i].time.day = 0;
        queries[i].time.hour = 0;
        queries[i].time.minute = 0;
        queries[i].time.second = 0;

        // **販売員情報の初期化**
        strcpy(queries[i].seller.name, "");
        queries[i].seller.id = 0;  // ✅ 販売員 ID を 0 にリセット
        queries[i].seller.selling_price = 0;
        queries[i].seller.total_selling_price = 0;
        queries[i].seller.profit_rate = 0.0;

        // **商品情報の初期化**
        queries[i].item.id = 0;  // ✅ 商品 ID を 0 にリセット
        strcpy(queries[i].item.name, "");
        queries[i].item.purchase_price = 0;
        queries[i].item.total_purchase_price = 0;
        queries[i].item.regular_price = 0;
        queries[i].item.deleted = 0;
        queries[i].item.profit_rate = 0;
    }

    // **確認用の `printf()`（全てのクエリを表示）**
    printf("=== reset() 実行後の変数状態 ===\n");
    printf("rate = %.2f\n", rate);
    printf("item_count = %d\n", item_count);
    printf("n (販売員数) = %d\n", n);
    printf("m (クエリ数) = %d\n", m);
    printf("===========================\n");

    // // **全 `queries` 配列を表示**
    // for (int i = 0; i < MAX_QUERIES; i++) {
    //     printf("クエリ %d:\n", i);
    //     printf("  type = %s\n", queries[i].type);
    //     printf("  id = %d\n", queries[i].id);
    //     printf("  sale_complited = %d\n", queries[i].sale_complited);
    //     printf("  時刻: %04d/%02d/%02d-%02d:%02d:%02d\n",
    //            queries[i].time.year, queries[i].time.month, queries[i].time.day,
    //            queries[i].time.hour, queries[i].time.minute, queries[i].time.second);
    //     printf("  販売員: id=%d, name=%s, selling_price=%d, total_selling_price=%d, profit_rate=%.2f\n",
    //            queries[i].seller.id, queries[i].seller.name,
    //            queries[i].seller.selling_price, queries[i].seller.total_selling_price,
    //            queries[i].seller.profit_rate);
    //     printf("  商品: id=%d, name=%s, purchase_price=%d, total_purchase_price=%d, regular_price=%d, deleted=%d, profit_rate=%d\n",
    //            queries[i].item.id, queries[i].item.name, queries[i].item.purchase_price,
    //            queries[i].item.total_purchase_price, queries[i].item.regular_price,
    //            queries[i].item.deleted, queries[i].item.profit_rate);
    //     printf("-------------------------------\n");
    // }
}

