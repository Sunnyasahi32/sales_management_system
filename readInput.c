//readInput.c
#include <stdio.h>
#include <string.h>
#include "main.h"


// **1. 許容利益率を取得**
void readRate() {
    scanf("%f", &rate);
}

// **2. 販売員の人数と名前を取得**
void readSellers() {
    int i;
    scanf("%d", &n);
    getchar();  //改行対策

    for (i = 0; i < n; i++) {
        fgets(queries[i].seller.name, sizeof(queries[i].seller.name), stdin);
        queries[i].seller.name[strcspn(queries[i].seller.name, "\n")] = 0; //改行対策
        queries[i].seller.id = i+1; //販売員id付与
    }
}

// **3. クエリの数と内容を取得**
void readQueries() {
    scanf("%d", &m);
    getchar();

    int i;
    char buffer[256];

    for (i = 0; i < m; i++) {
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = 0;
        sscanf(buffer, "%[^:]s", queries[i].type);
        strcat(queries[i].type, ":"); // `:` を手動で追加


        if (strcmp(queries[i].type, "register-item:") == 0) {
            sscanf(buffer, "%s %d/%d/%d-%d:%d:%d %s %d %d",
                queries[i].type,
                &queries[i].time.year, &queries[i].time.month, &queries[i].time.day,
                &queries[i].time.hour, &queries[i].time.minute, &queries[i].time.second,
                queries[i].item.name,
                &queries[i].item.purchase_price, &queries[i].item.regular_price);
        }

        if (strcmp(queries[i].type, "request-sale:") == 0) {
            sscanf(buffer, "%s %d/%d/%d-%d:%d:%d %d %d %d",
                queries[i].type,
                &queries[i].time.year, &queries[i].time.month, &queries[i].time.day,
                &queries[i].time.hour, &queries[i].time.minute, &queries[i].time.second,
                &queries[i].seller.id,
                &queries[i].item.id, &queries[i].seller.selling_price);
        }

        if (strcmp(queries[i].type, "complete-sale:") == 0) {
            sscanf(buffer, "%s %d/%d/%d-%d:%d:%d %d %d",
                queries[i].type,
                &queries[i].time.year, &queries[i].time.month, &queries[i].time.day,
                &queries[i].time.hour, &queries[i].time.minute, &queries[i].time.second,
                &queries[i].seller.id,
                &queries[i].id);
        }
    }
}
