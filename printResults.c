#include <stdio.h>
#include <string.h>
#include "main.h"

// printResults関数: register-item の処理結果を出力
void printResults() {
    for (int i = 0; i < m; i++) {
        printf("クエリ %d:\n", i);
        printf("  type = %s\n", queries[i].type);
        printf("  id = %d\n", queries[i].id);
        printf("  permission = %d\n", queries[i].permission);
        printf("  sale_complited = %d\n", queries[i].sale_complited);
        printf("  時刻: %04d/%02d/%02d-%02d:%02d:%02d\n",
            queries[i].time.year, queries[i].time.month, queries[i].time.day,
            queries[i].time.hour, queries[i].time.minute, queries[i].time.second);
        printf("  販売員: id=%d, name=%s, selling_price=%d, total_selling_price=%d, profit_rate=%.2f\n",
            queries[i].seller.id, queries[i].seller.name,
            queries[i].seller.selling_price, queries[i].seller.total_selling_price,
            queries[i].seller.profit_rate);
        printf("  商品: id=%d, name=%s, purchase_price=%d, total_purchase_price=%d, regular_price=%d, deleted=%d, profit_rate=%.2f\n",
            queries[i].item.id, queries[i].item.name, queries[i].item.purchase_price,
            queries[i].item.total_purchase_price, queries[i].item.regular_price,
            queries[i].item.deleted, queries[i].item.profit_rate);
        printf("-------------------------------\n");
    }
}


