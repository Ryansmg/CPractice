#include <stdio.h>
#include <string.h>

int main(){
    int arr[10][10] = {0}, x=0, y=5, n=1, t=0;
    int i, j;
    for(i=0; i<5; i++){
        for(j=0; j<n; j++){
            arr[j][n-1-j] = ++t;
        }
        n++;
    }
    t=26;
    n=1;
    for(i=0; i<4; i++){
        for(j=0; j<n; j++){
            arr[4-j][4-(n-1-j)] = --t;
        }
        n++;
    }

    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            if(arr[i][j]==0) printf("   ");
            else printf("%3d", arr[i][j]);
        }
        printf("\n");
    }

    /*
    int arr[100][100]={0}, x=0, y=5;
    int n, cnt=26, i, j;
    scanf("%d", &n);
    while(n>0){
        for(i=0; i<n; i++) arr[x][--y] = --cnt;
        n--;
        for(i=0; i<n; i++) arr[++x][y] = --cnt;
        for(i=0; i<n; i++) arr[x][++y] = --cnt;
        n--;
        for(i=0; i<n; i++) arr[--x][y] = --cnt;
    }

    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            if(arr[i][j]==0) printf("   ");
            else printf("%3d", arr[i][j]);
        }
        printf("\n");
    }
    /*
    //���̾Ƹ��, �𷡽ð� ���
    int arr[5][5]={0}, a=2, b=2, i, j, n=0;
    for(i=0; i<5; i++){
        for(j=a; j<=b; j++) arr[4-j][4-i] = ++n;
        if(i<2) {
            a--; b++;
        }
        else {
            a++; b--;
        }
    }

    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            if(arr[i][j]==0) printf("   ");
            else printf("%3d", arr[i][j]);
        }
        printf("\n");
    }

    int arr1[5][5] = {0};
    n=0; a=0; b=4;

    for(i=0; i<5; i++){
        for(j=a; j<=b; j++) arr1[i][j] = ++n;
        if(i<2) {
            a++; b--;
        }
        else {
            a--; b++;
        }
    }

    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            if(arr1[i][j]==0) printf("   ");
            else printf("%3d", arr1[i][j]);
        }
        printf("\n");
    }

    /*
    int arr[5][5] = {0};
    int i, j, left=0, n=0;
    for(i=0; i<5; i++){
        if(left==0){
            for(j=0; j<5; j++){
                arr[i][j] = ++n;
            }
            left=1;
        } else {
            for(j=0; j<5; j++){
                arr[i][4-j] = ++n;
            }
            left=0;
        }
    }

    for(i=0; i<5; i++){
      for(j=0; j<5; j++){
            printf("%3d", arr[i][j]);
       }
       printf("\n");
    }

    /*
    int arr[5][5] = {0};
    int i, j, n=0;
    for(i=0; i<5; i++){
        for(j=i; j<5; j++){
            arr[i][j] = ++n;
        }
    }

    for(j=0; j<5; j++){
        for(i=0; i<5; i++){
            if(arr[i][j]==0) printf("   ");
            else printf("%3d", arr[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    int arr1[5][5] = {0};
    n=0;
    for(i=0; i<5; i++){
        for(j=0; j<i+1; j++){
            arr1[i][j] = ++n;
        }
    }

    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            if(arr1[4-i][4-j]==0) printf("   ");
            else printf("%3d", arr1[4-i][4-j]);
        }
        printf("\n");
    }

    printf("\n");

    for(j=0; j<5; j++){
        for(i=0; i<5; i++){
            if(arr1[i][j]==0) printf("   ");
            else printf("%3d", arr1[i][j]);
        }
        printf("\n");
    }
    /*
    char a[] = "Hello software";
    printf("%c \n", a[6]);
    printf("%d \n", sizeof(a));
    printf("%d \n", a[14]);
    printf("%s \n", a);
    a[6] = 'S';
    printf("%s \n", a);

    /*
    int n, div=2, index=0, i;
    int arr[32];
    scanf(" %d", &n);

    if(n==0) printf("0");
    while(n!=0){
        if(n%div>0){
            n-=div/2;
            arr[index] = 1;
        } else {
            arr[index] = 0;
        }
        div *= 2;
        index++;
    }

    for(i=0; i<index; i++){
        printf("%d", arr[index-i-1]);
    }

    /*
    int n; 
    scanf(" %d", &n);
    int arr[100];
    int i, j, temp;
    for(i=0; i<n; i++) scanf(" %d", &arr[i]);

    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            if(arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    int ans;
    scanf(" %d", &ans);
    printf("%d", arr[ans]);

    /*
    int n; //ī���� ��ü �� ��
    scanf(" %d", &n);
    int arr[100]; //�ִ� ī��
    int i;
    for(i=0; i<n-1; i++) scanf(" %d", &arr[i]);

    int sum=0;
    for(i=1; i<=n; i++) sum += i;
    for(i=0; i<n-1; i++) sum -= arr[i];
    printf("%d", sum);

/*
    int arr[] = {10, 20, 30, 25, 15, 5, 11, 22, 9, 17};
    int i, j;
    for(i=0; i<10; i++){
        printf("%-2d ", arr[i]);
        for(j=0; j<arr[i]; j++) printf("*");
        printf("\n");
    }
    

    /*

    char arr[] = {'c', 'o', 'm', 'p', 'u', 't', 'e', 'r'};
    int i, size;
    size = strlen(arr);
    for(i=0; i<size; i++){
        printf("%c", arr[i]);
    }

    /*
    char arr[] = "Hello\0World\0";
    char arr2[] = { 'A', 'B', 'C', '\0' };

    printf("���ڿ� �Ϻ� %s \n", arr);
    printf("���� �Ϻ� %s \n", arr2);
    printf("���ڿ� �迭�� ũ�� = %d \n", sizeof(arr));
    printf("���� �迭�� ũ�� = %d \n", sizeof(arr2));

    /*
    int a1[1000], a2[1000], count, i, j, temp;
    printf("������ ������ �Է��ϼ���: ");
    scanf(" %d", &count);
    for(i=0; i<count; i++){
        scanf(" %d", &a1[i]);
        a2[i] = a1[i];
    }

    for(i=0; i<count; i++){
        for(j=i+1; j<count; j++){
            if(a1[i] > a1[j]) {
                temp = a1[i];
                a1[i] = a1[j];
                a1[j] = temp;
            }
        }
    }

    printf("��������:\n");
    for(i=0; i<count; i++)
        printf("%3d", a1[i]);


    for(i=0; i<count-1; i++){
        for(j=0; j<count-1-i; j++){
            if(a2[j] > a2[j+1]){
                temp = a2[j];
                a2[j] = a2[j+1];
                a2[j+1] = temp;
            }
        }
    }

    printf("\nBubble Sort:\n");
    for(i=0; i<count; i++)
        printf("%3d", a2[i]);
    /*
    int day, count;
    int i, j;
    printf("1���� ���� �����Դϱ�(0~6)? ");
    scanf(" %d", &day);
    printf("�� ��ĥ�Դϱ�? ");
    scanf(" %d", &count);

    printf("�� �� ȭ �� �� �� ��\n");
    for(i=0; i<6-day; i++) printf("   ");
    for(i=1; i<=count; i++){
        printf("%2d ", i);
        if(++day == 7) {
            printf("\n");
            day = 0;
        }
    }
    


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

    /*
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