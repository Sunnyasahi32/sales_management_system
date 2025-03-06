//expireID.c
#include <stdio.h>
#include <string.h>
#include "main.h"

// グローバル変数
extern int m;
extern Query queries[MAX_QUERIES];

void expireID(Query *queries, int count) {
    int seller_id = queries[count].seller.id; // 現在の販売員ID
    int sale_id = queries[count].id; // 販売許可ID
    Time sale_time = queries[count].time; // 販売要求の時刻

    for (int i = 0; i < count; i++) {
        if (strcmp(queries[i].type, "request-sale:") == 0) {
            // **1. 同じ販売員から次の販売要求が来たら失効**
            if (queries[i].seller.id == seller_id && i > count) {
                queries[count].permission = 1; // 販売許可失効
                return;
            }

            // **2. 日付が変わったら失効**
            if ((queries[i].time.year != sale_time.year ||
                 queries[i].time.month != sale_time.month ||
                 queries[i].time.day != sale_time.day) &&
                i > count) {
                queries[count].permission = 1; // 販売許可失効
                return;
            }

            // **3. 販売完了済みなら失効**
            if (queries[i].id == sale_id && queries[i].sale_complited == 1) {
                queries[count].permission = 1; // 販売許可失効
                return;
            }
        }
    }
}
