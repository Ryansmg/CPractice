#include <stdio.h>
typedef struct MENU{
    char name[20];
    int cnt, price;
} menu;

int main()
{
    menu bunsik[] = {
        {"placeholder", 0, 0},
        {"�佺Ʈ", 0, 1500},
        {"������", 0, 3500},
        {"�ֵ���", 0, 1000},
        {"��ġ������", 0, 6500},
        {"�ߴٸ�", 0, 4000}
    };
    for(int i=1; i<sizeof(bunsik)/sizeof(menu); i++){
        printf("%d. %s (%d��)\n", i, bunsik[i].name, bunsik[i].price);
    }
    printf("�� ���� �޴��� �Է��Ͻðڽ��ϱ�? ");
    int order_cnt;
    scanf("%d", &order_cnt);
    for(int i=0; i<order_cnt; i++) {
        int menu_num, menu_cnt;
        printf("�޴� ��ȣ: ");
        scanf("%d", &menu_num);
        printf("����: ");
        scanf("%d", &menu_cnt);
        bunsik[menu_num].cnt = menu_cnt;
    }
    int is_coupon = 0;
    {
        char inp;
        printf("������ ����Ͻðڽ��ϱ�? (y/n)");
        scanf(" %c", &inp);
        if(inp == 'y' || inp == 'Y')
            is_coupon = 1;
    }
    int sum = 0;
    int most_expensive = 0;
    for(int i=1; i<sizeof(bunsik)/sizeof(menu); i++){
        sum+= bunsik[i].cnt * bunsik[i].price;
    }
    printf("���� �� �ֹ� �ݾ��� %d���Դϴ�.\n", sum);
    if(is_coupon) {
        most_expensive = 0;
        for(int i=1; i<sizeof(bunsik)/sizeof(menu);i++)
            if(bunsik[i].cnt > 0 && most_expensive < bunsik[i].price)
                most_expensive = bunsik[i].price;
    }
    printf("���� ���� �ݾ��� %d���Դϴ�.", sum - most_expensive/10);
}