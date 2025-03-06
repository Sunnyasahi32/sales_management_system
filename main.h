//main.h
#ifndef MAIN_H
#define MAIN_H

#define MAX_NAME_LEN 22
#define MAX_SELLERS 2001
#define MAX_ITEMS 2001
#define MAX_QUERIES 2001

typedef struct {
    int year, month, day, hour, minute, second;
} Time;

typedef struct {
    char name[MAX_NAME_LEN]; //販売員名
    int id; //販売員ID
    int selling_price; //販売価格
    int total_selling_price; //この人の総販売価格
    float profit_rate; //この販売員の利益率
} Seller;

typedef struct {
    int id; //商品ID
    char name[MAX_NAME_LEN + 1]; //商品名
    int purchase_price; //原価
    int total_purchase_price; //総原価
    int regular_price; //定価
    int deleted; // 1なら削除済み、0なら有効
    float profit_rate; //商品利益率
} Item;

typedef struct {
    char type[MAX_NAME_LEN]; //クエリの種類
    int id; //販売許可ID
    int permission; //販売許可変数
    int sale_complited; //販売完了変数
    Time time; //時刻の情報
    Seller seller; //販売員の情報
    Item item; //商品の情報
} Query;



// グローバル変数
extern float rate; //許容利益率
extern int n, m; //販売員数、クエリ数
extern Query queries[MAX_QUERIES]; //クエリの情報
extern int item_count; //商品id計算用
extern int permission_count; //販売許可ID計算用





// 関数プロトタイプ宣言
void reset();
void readRate();
void readSellers();
void readQueryCount();
void readQueries();
void printResults();
void registerItem(Query *queries, int count);
void requestSale(Query *queries, int count);
void completeSale(Query *queries, int count);
void expireID(Query *queries, int count);


#endif
