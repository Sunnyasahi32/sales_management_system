//register-item.c
#include <stdio.h>
#include <string.h>
#include "main.h"

extern Query queries[MAX_QUERIES]; //クエリの情報

void registerItem(Query *queries, int count) {

    // **2. 既存の登録商品をチェック**
    for (int i = 0; i < count; i++) {
        if (i != count && queries[i].item.id != 0 && strcmp(queries[i].item.name, queries[count].item.name) == 0) {
            printf("register-item: duplicated item\n");
            return;
        }
    }

    // **3. 利益率を計算**
    queries[count].item.profit_rate = (float)(queries[count].item.regular_price - queries[count].item.purchase_price) / queries[count].item.regular_price;
    if (queries[count].item.profit_rate < rate) {
        printf("register-item: too cheap price\n");
        printf("%f\n",queries[count].item.profit_rate);
        return;
    }

    // **4. 商品を登録**
    if (m < MAX_ITEMS) {
        item_count++;
        queries[count].item.id = item_count;
        printf("register-item: %d\n",queries[count].item.id);
        return;
    }

   
}