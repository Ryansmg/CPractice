#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    /*
    char arr[5][5] = {
        '4', ' ', ' ', ' ', ' ',
        '4', ' ', ' ', '4', ' ',
        '4', ' ', ' ', '4', ' ',
        '4', '4', '4', '4', '4', 
        ' ', ' ', ' ', '4', ' '
    };
    int i, j;
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            printf("%c", arr[4-j][i]);
        }
        printf("\n");
    }
    printf("\n");

    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            printf("%c", arr[4-j][4-i]);
        }
        printf("\n");
    }
    printf("\n");

    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            printf("%c", arr[4-i][4-j]);
        }
        printf("\n");
    }
    printf("\n");
    */
    
    int firstInput = 0;
    int secondInput;
    char str[100] = "", inputStr[20];

    while(firstInput != 5){
        printf("\n���� ���ڿ� : %s \n", str);
        printf("1.���� 2.�κк��� 3.�߰� 4.�κ��߰� 5.����\n");
        printf("��ȣ�� �Է��ϼ���: ");
        scanf(" %d", &firstInput);
        fflush(stdin);

        switch(firstInput){
            case 1:
                printf("���ڿ�: ");
                fgets(inputStr, sizeof(inputStr), stdin);
                strncpy(str, inputStr, strlen(inputStr)-1);
                break;

            case 2:
                printf("���ڿ�: ");
                fgets(inputStr, sizeof(inputStr), stdin);
                printf("��: ");
                scanf(" %d", &secondInput);
                strncpy(str, inputStr, secondInput);
                break;
            
            case 3:
                printf("���ڿ�: ");
                fgets(inputStr, sizeof(inputStr), stdin);
                strncat(str, inputStr, strlen(inputStr)-1);
                break;

            case 4:
                printf("���ڿ�: ");
                fgets(inputStr, sizeof(inputStr), stdin);
                printf("��: ");
                scanf(" %d", &secondInput);
                strncat(str, inputStr, secondInput);
                break;
        }
    }
    /*
    char str[20] = "hello world";
    printf("%s\n", str);
    strrev(str);
    printf("%s", str);

    /*
    int a;
    char b[20];
    scanf("%s", b);
    a = atoi(b); //requires <stdlib.h>
    printf("%d", a);

    /*
    int a;
    char b[20];
    printf("���ڿ��� ������ ������ �Է��ϼ���: ");
    scanf("%d", &a);
    _itoa(a, b, 10); //10������ ��ȯ
    printf("10���� ��ȯ: %s\n", b);
    _itoa(a, b, 16); //16������ ��ȯ
    printf("16���� ��ȯ: %s\n", b);
    _itoa(a, b, 2); //2������ ��ȯ
    printf("2���� ��ȯ: %s\n", b);

    /*
    char str[20], str2[20];
    printf("��ȣ�� �Է��ϼ���: ");
    scanf(" %s", str);
    printf("�ٽ� ��ȣ�� �Է��ϼ���: ");
    scanf(" %s", str2);
    if(strcmp(str, str2) == 0){
        if(strcmp(str, "password0") == 0) printf("ȯ���մϴ�.\n");
        else printf("��ȣ�� �߸��Ǿ����ϴ�.\n");
    }
    else printf("��ȣ�� �ٸ��� �Է��ϼ̽��ϴ�.");

    /*
    char a[] = "computer", b[] = "computergame";
    int same = strncmp(a, b, 9);
    printf("%d", same);

    /*
    char a[20] = "first", b[20] = "second", c[20] = "third";

    strcat(a, b);
    strcat(a, c);

    printf("%s", a);

    /*
	char a[20] = "�ȳ��ϼ���", b[20], c[20];

	strcpy(b, a);
	printf("a:%s, b:%s\n", a, b);

    strncpy(c, a, 6);
    printf("c:%s", c);

	/*
	char str[100];
	int a;

	fgets(str, sizeof(str), stdin);
	a = strlen(str);
	printf("Sizeof str: %2d", a);
	*/

	return 0;
}