
#include <stdio.h>
#include <string.h>

// 建立書籍結構
typedef struct Books {
    int id;
    int price;
    char title[100];
} book_t;

// 計算所有書籍總價
int total_price(book_t books[], int n) {
    int total = 0;

    for (int i = 0; i < n; i++) {
        total += books[i].price;
    }

    return total;
}

// 輸出書籍資料
void list_books(book_t books[], int n) {
    printf("\n========== Book List ==========\n");

    for (int i = 0; i < n; i++) {
        printf("ID: %d\n", books[i].id);
        printf("Price: %d\n", books[i].price);
        printf("Title: %s\n", books[i].title);
        printf("------------------------------\n");
    }
}

int main() {

    // 建立六本書的資料
    book_t books[6] = {
        {1, 1000, "All the Light We Cannot See"},
        {2, 300, "The 38 Letters from J.D. Rockefeller to his son"},
        {3, 1000, "The Ballad of Songbirds and Snakes"},
        {4, 550, "Killers of the Flower Moon"},
        {5, 870, "Elon Musk"},
        {6, 1344, "Milk and Honey 12-Month 2024"}
    };

    int n = 6;

    // 將書籍資料寫入 Book.bin
    FILE *fp = fopen("Book.bin", "wb");

    if (fp == NULL) {
        printf("無法建立 Book.bin！\n");
        return 1;
    }

    fwrite(books, sizeof(book_t), n, fp);

    fclose(fp);

    // 從 Book.bin 讀取資料
    book_t read_books[6];

    fp = fopen("Book.bin", "rb");

    if (fp == NULL) {
        printf("無法讀取 Book.bin！\n");
        return 1;
    }

    int count = fread(read_books, sizeof(book_t), 6, fp);

    fclose(fp);

    // 計算總價
    int total = total_price(read_books, count);

    // 輸出書籍資料
    list_books(read_books, count);

    printf("\nTotal Price: %d\n", total);

    return 0;
}
