#include <stdio.h>
#include <string.h>

int main(){
    /*
    int day, count;
    int i, j;
    printf("1���� ���� �����Դϱ�(0~6)? ");
    scanf(" %d", &day);
    printf("�� ��ĥ�Դϱ�? ");
    scanf(" %d", &count);

    printf("�� �� ȭ �� �� �� ��\n");
    for(i=0; i<day; i++) printf("   ");
    for(i=1; i<=count; i++){
        printf("%2d ", i);
        if(++day == 7) {
            printf("\n");
            day = 0;
        }
    }
    
    /*

    int input;
    printf("1. �Ͽ���\n2. ������\n3. ȭ����\n4. ������\n5. �����\n6. �ݿ���\n7. �����\n���� �Է��ϼ��� : ");
    scanf("%d", &input);
    switch(input){
        case 2:
        case 4:
        case 6: printf("�б� ���� ��"); break;
        case 1:
        case 3:
        case 5:
        case 7: printf("�б� �� ���� ��"); break;
        default: printf("�߸� �ԷµǾ����ϴ�."); break;
    }

    /*
    int i, j, k, l;

    for(i=1; i<=9; i++) {
        if(i > 5) l=10-i;
        else l=i;

        for(k=1; k<=5-l; k++) printf("  ");
        for(j=1; j<=l; j++) printf("%2d", j);
        printf("\n");
    }

    /*
    int i, j;
    for(i=1; i<=7; i++) {
        for(j=1; j<=10; j++){
            printf("%2d ", i*j);
        }
        printf("\n");
    }

    /*
    int a, b, temp;
    int i, j;
    printf("�� ���� ������ �Է��Ͽ���: ");
    scanf("%d %d", &a, &b);

    if(a > b) {
        temp = a;
        a = b;
        b = temp;
    }

    for(i=1; i<10; i++){
        for(j=a; j<=b; j++){
            printf("%d*%d=%d\t", j, i, j*i);
        }
        printf("\n");
    }

    /*
    char repeat;
    int i,j;
    char c1, c2;
    do {
   
    printf("���ڸ� �Է��϶� ? ");
    scanf(" %c %c", &c1, &c2);

    if(c1 >= 97 && c1 <= 122) { 
        for(i = c1; i <= c2; i++) {
            printf("%c", i-32);
        }
    } else {
        for(i = c1; i <= c2; i++) {
            printf("%c", i+32);
        }
    }

    printf("�ٽ� �����ұ��(Y/N)?" );
    scanf(" %c", &repeat);

    } while (repeat == 'Y' || repeat == 'y');

    /*
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    a = (((a > b) ? a : b) > c) ? ((a > b) ? a : b) : c;

    printf("%d", a);

    /*
    char word[100];
    printf("���� ���̰� 10�� �Ѵ� ���ڿ��� �Է��� ������.");
    fgets(word, sizeof(word), stdin);
    printf("�Է¹��� %d���� ����: %s", sizeof(word), word);

    /*
    char name[100];
    printf("���ڿ��� �Է��Ͻÿ�:");
    gets(name);

    printf("����� �̸� = %s �Դϴ�.", name);

    /*
    char ch, word[100];
    printf("���� �ϳ��� �Է��ϼ���: ");
    scanf("%c", &ch);

    printf("�ܾ� �ϳ��� �Է��ϼ���: ");
    scanf(" %s", word);

    printf("��� =%c %s \n", ch, word);

    /*
    int a;
    float b;
    char k;
    printf("���� �ϳ��� �Ǽ� �ϳ�, ���� �� ���� �Է��Ͻÿ�. ");
    scanf("%c %f %d", &k, &b, &a); //Ű����κ��� �Է¹޴� �Լ�

    printf("���= %c    %1f     %d", k, b, a);
    */
    
    int a, b, c=3, d=5, e, f;
    a = c | d;
    b = c & d;
    e = c ^ d;
    f = ~d;
    printf("c|d= %d c&d= %d \n", a, b);
    printf("c^d= %d ~d= %d", e, f);

    /*
    int a, b;
    a=0x41;
    b=0x42;
    printf("%d %o %x %c \n", a, a, a, a);
    printf("%d %o %x %c", b, b, b, b);
    */
}