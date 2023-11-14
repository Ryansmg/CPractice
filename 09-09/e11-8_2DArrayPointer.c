#include <stdio.h>

int main()
{
    int m[3][3] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int *pt;
    pt = m[0];

    printf("m = %p\n", m);
    printf("m[0] = %p\n", m[0]); //ù ��° �ּҰ�
    printf("m[1] = %p\n", m[1]); //�� ��°�� �ּҰ�
    printf("m[2] = %p\n", m[2]); //�� ��°�� �ּҰ�
    
    printf("m[0] = %d\n", *m[0]); //ù �� �����
    printf("m[1] = %d\n", *m[1]); //��° �� �����
    printf("m[2] = %d\n", *m[2]); //��° �� �����

    printf("&m[0][0] = %p\n", &m[0][0]); //ù° �� ���� �ּҰ�
    printf("&m[1][0] = %p\n", &m[1][0]); //��° �� ���� �ּҰ�
    printf("&m[2][0] = %p\n", &m[2][0]); //��° �� ���� �ּҰ�

    int i;
    for(i=0; i<9; i++)
        printf("m[%d] = %d\n", i, *(pt+i));
    for(i=0; i<9; i++)
        printf("m[%d] = %d\n", i, pt[i]);
    return 0;
}
