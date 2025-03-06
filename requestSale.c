//requestSale.c
#include <stdio.h>
#include <string.h>
#include "main.h"

// グローバル変数を参照
extern int item_count;
extern int permission_count;
extern int m;
extern float rate;
extern Query queries[MAX_QUERIES];

void requestSale(Query *queries, int count) {
    expireID(queries, count);  // 販売許可の失効チェック

    int seller_id = queries[count].seller.id; // 販売員ID
    int item_id = queries[count].item.id; // 商品ID
    int selling_price = queries[count].seller.selling_price; // 販売価格

    // **1. 商品が存在しない、または削除済み**
    int item_index = -1;
    for (int i = 0; i < m; i++) {
        if (queries[i].item.id == item_id && queries[i].item.deleted == 0) {
            item_index = i;
            break;
        }
    }
    if (item_index == -1) {
        queries[count].sale_complited = 0;  // 販売不可
        printf("request-sale: no such item\n");
        return;
    }

    // **2. 販売価格が定価より高額**
    if (selling_price > queries[item_index].item.regular_price) {
        queries[count].sale_complited = 0;  // 販売不可
        printf("request-sale: too expensive price\n");
        return;
    }

    // **3. 販売要求が許可される条件をチェック**
    
    // (1) 販売価格が商品原価以上であるか
    if (selling_price < queries[item_index].item.purchase_price) {
        queries[count].permission = 0;  // 販売不可
        printf("request-sale: too cheap price\n");
        return;
    }

    // (2) 販売完了後の販売員の利益率を計算
    float new_total_selling_price = queries[seller_id].seller.total_selling_price + selling_price;
    float new_seller_profit_rate = (new_total_selling_price - queries[seller_id].seller.total_selling_price) / new_total_selling_price;

    if (new_seller_profit_rate < rate) {
        queries[count].permission = 0;  // 販売不可
        printf("request-sale: too cheap price\n");
        return;
    }

    // (3) 販売完了後の商品の利益率を計算
    float new_total_purchase_price = queries[item_index].item.total_purchase_price + queries[item_index].item.purchase_price;
    float new_item_profit_rate = (new_total_selling_price - new_total_purchase_price) / new_total_selling_price;

    if (new_item_profit_rate < rate) {
        queries[count].permission = 0;  // 販売不可
        printf("request-sale: too cheap price\n");
        return;
    }

    // **4. 販売を許可**
    queries[count].id = permission_count + 1;  // 販売許可ID
    permission_count++;
    queries[seller_id].seller.total_selling_price = new_total_selling_price; // 販売員の総売上金額を更新
    queries[seller_id].seller.profit_rate = new_seller_profit_rate; // 販売員の利益率を更新
    queries[item_index].item.total_purchase_price = new_total_purchase_price; // 商品の総原価を更新
    queries[item_index].item.profit_rate = new_item_profit_rate; // 商品の利益率を更新

    printf("request-sale: %d\n", queries[count].id);
}
