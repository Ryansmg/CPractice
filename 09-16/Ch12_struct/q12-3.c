#include <stdio.h>

struct chulpansa {
    int code;
    char name[20];
    char tel[15];
};

struct bookname {
    char b_name[20];
    char w_name[20];
    char year[12];
    int price;
    int su;
};

struct book_store {
    struct chulpansa chull;
    struct bookname book;
};

int main()
{
    struct book_store sale = {10, "�������ǻ�", "031-912-2398", "���ֽ���C���", "�Ǳ⼮", "1998/04/02", 10000, 5};
    int ssang = sale.book.price*sale.book.su;
    printf("���ǻ� : %s\n���� : %s\n�Ǹűݾ� : %d\n", sale.chull.name, sale.book.b_name, ssang);
}