#include <stdio.h>
#include <string.h>
#include "main.h"

// グローバル変数を参照
extern int m;
extern Query queries[MAX_QUERIES];

void completeSale(Query *queries, int count) {
    int seller_id = queries[count].seller.id; // 販売員ID
    int sale_id = queries[count].id; // 販売許可ID

    // **1. 販売許可IDに対応する販売が存在しない場合**
    int sale_index = -1;
    for (int i = 0; i < m; i++) {
        if (queries[i].id == sale_id && strcmp(queries[i].type, "request-sale:") == 0) {
            sale_index = i;
            break;
        }
    }
    if (sale_index == -1) {
        printf("complete-sale: no such sale\n");
        return;
    }

    // **2. 販売許可IDに対応する販売要求を行った販売員が異なる場合**
    if (queries[sale_index].seller.id != seller_id) {
        printf("complete-sale: unauthorized operation\n");
        return;
    }

    // **3. 販売許可がすでに失効している場合**
    if (queries[sale_index].permission == 1) {
        printf("complete-sale: permission expired\n");
        return;
    }

    // **4. 販売完了の登録**
    queries[sale_index].sale_complited = 1; // 販売完了マーク
    printf("complete-sale: ok\n");
}
