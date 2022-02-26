#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable :4996)
#pragma warning(disable :6031)
#pragma warning(disable : 6054)
typedef struct Student
{
    char id[20];
    char pw[20];
    int majorN, majorC, ectN, ectC;//����, ����, ����, ����
    double mn, mc, en, ec; //(����)����, ����, ����, ����
    double average; // (����)���

}Student;

Student std[20];
Student std_dest[20];
Student temp;

void choice_menu();
void menu_1();
void menu_2();
void menu_3();
void menu_4();
void menu_5();
void menu_6();
void menu_7();
double cal(int score);
void check1();
void processMenu(char choice);
int checkid(char*);
void myflush();
char pw1[20] = "";
int len = 0;

int main()
{
    while (1) {
        printf("���� ������ ��й�ȣ�� �����Ͻÿ�(4�ڸ� ����):");
        scanf("%s", pw1);
        if (strlen(pw1) > 4) { continue; }
        else if(strlen(pw1)==4) {
            break;
        }
        else {
            continue;
        }
    }
  
    printf("\n\n");

    char ch = NULL;

    choice_menu();
    while (1)
    {
        scanf("%c", &ch);
        if (ch == 'q') { break; }// �߰��ڵ�**
        else {
            processMenu(ch);
        }
    }

    printf("���α׷� ����\n");
    return 0;
}





void choice_menu() //�޴�
{
    printf("          �������� ���α׷� \n\n");
    printf("---------------M E N U---------------\n\n");
    printf("1.�л� ���� �Է� \n\n");
    printf("2.�л� ������ �ش� ���� ���� ���� \n\n");
    printf("3.�л� ������ ��� ���� \n\n");
    printf("4.��ü �л��� ���� ��� (������ ���� �ʿ�) \n\n");
    printf("5.��ü �л��� ������ ��� (������ ���� �ʿ�) \n\n");
    printf("6.�л� ������ ������ ���� \n\n");
    printf("7.�л� ���� ���� (������ ���� �ʿ�)\n\n");
    printf("�޴��� �Է��ϼ���('q' �Է½� ����): ");
}



void check1()
{
    char input[20];
    printf("���� ������ ��й�ȣ�� �Է��Ͻÿ�: ");
    while (1) {
        scanf("%s", input);
        if (!strcmp(input,pw1)) {
            break;
        }
        else {
            printf("�߸��� ��й�ȣ�Դϴ�. �ٽ� �Է��Ͻÿ�: ");
            continue;
        }
    }
}

void menu_1() //�޴�1 ����: �й�, ��й�ȣ,�л� �̸�, ���� �Է�
{
    int i;

    printf("�л������� �Է��ϼ���.\n");

    for (i = len; i < len + 1; i++)
    {
        do {
            printf("�й� : ");
            scanf("%s", std[i].id);
            if (checkid(std[i].id) != 1)
            {
                printf("**�̹� �����ϰų�,��ȿ���� ���� �й��Դϴ�. �ٽ� �Է��ϼ���.\n");
            }
        } while (checkid(std[i].id) != 1);

        while (1) {
            printf("��й�ȣ ����(���� 4�ڸ� �Է�): ");
            scanf("%s", std[i].pw);
            if (strlen(std[i].pw) == 4) {
                break;
            }
            else {
                continue;
            }
        }

        do {
            printf("�����ʼ� ���� �Է�(0~100�� �Է�): ");
            scanf("%d", &std[i].majorN);
            if (std[i].majorN < 0 || std[i].majorN > 100)
            {
                printf("�Է� ����!! ������ ���Է��ϼ���.\n");
            }
        } while (std[i].majorN < 0 || std[i].majorN > 100);
        std[i].mn = cal(std[i].majorN);

        do {
            printf("�������� ���� �Է�(0~100�� �Է�): ");
            scanf("%d", &std[i].majorC);
            if (std[i].majorC < 0 || std[i].majorC > 100)
            {
                printf("�Է� ����!! ������ ���Է��ϼ���.\n");
            }
        } while (std[i].majorC < 0 || std[i].majorC> 100);
        std[i].mc = cal(std[i].majorC);

        do {
            printf("�����ʼ� ���� �Է�(0~100�� �Է�): ");
            scanf("%d", &std[i].ectN);
            if (std[i].ectN < 0 || std[i].ectN > 100)
            {
                printf("�Է� ����!! ������ ���Է��ϼ���.\n");
            }
        } while (std[i].ectN < 0 || std[i].ectN > 100);
        std[i].en = cal(std[i].ectN);

        do {
            printf("���缱�� ���� �Է�(0~100�� �Է�): ");
            scanf("%d", &std[i].ectC);
            if (std[i].ectC < 0 || std[i].ectC > 100)
            {
                printf("�Է� ����!! ������ ���Է��ϼ���.\n");
            }
        } while (std[i].ectC < 0 || std[i].ectC > 100);
        std[i].ec = cal(std[i].ectC);
        std[i].average = (std[i].mn + std[i].mc + std[i].en + std[i].ec) / 4;
    }
    len++;
    printf("\n\n");
    printf("�޴� �Է�('q' �Է½� ����): ");
}

double cal(int score)//�������� �������� ��ȯ�ϴ� �Լ�
{
    if (score <= 100 && score >= 97) {
        return 4.5;
    }
    else if (score <= 96 && score >= 94) {
        return 4.3;
    }
    else if (score <= 93 && score >= 90) {
        return 4.0;
    }
    else if (score <= 89 && score >= 87) {
        return 3.5;
    }
    else if (score <= 86 && score >= 84) {
        return 3.3;
    }
    else if (score <= 83 && score >= 80) {
        return 3.0;
    }
    else if (score <= 79 && score >= 77) {
        return 2.5;
    }
    else if (score <= 76 && score >= 74) {
        return 2.3;
    }
    else if (score <= 73 && score >= 70) {
        return 2.0;
    }
    else if (score <= 69 && score >= 67) {
        return 1.5;
    }
    else if (score <= 66 && score >= 64) {
        return 1.3;
    }
    else if (score <= 63 && score >= 60) {
        return 1.0;
    }
    else
        return 0;
}


void menu_2() //2. �̸��� ������ �Է� �޾� �ش� �л��� �ش� ���� �������� ������ ���
{
    char input_id[20];
    char input_pw[20];
    int i, j;
    int success = 0;

    printf("�й� �Է�: ");
    scanf("%s", input_id);
here:
    printf("��й�ȣ �Է�: ");
    scanf("%s", input_pw);
here2:
    for (i = 0; i < len; i++)
    {
        if (!strcmp(input_id, std[i].id)) {
            success = 2;
            if(!strcmp(input_pw,std[i].pw)) {
                printf("[ %s ]�л��� �����Դϴ�. \n", input_id);
                printf("���� �ʼ� ����: %.1lf \n", std[i].mn);
                printf("���� ���� ����: %.1lf \n", std[i].mc);
                printf("���� �ʼ� ����: %.1lf\n", std[i].en);
                printf("���� ���� ����: %.1lf\n", std[i].ec);
                printf("��� ���� : %.1lf\n", std[i].average);
                success = 1;
                break;
            }
        }
    }
    if (success == 0) {
        i = 0;
        printf("�������� �ʴ� �л����Դϴ�. �ٽ��Է����ּ���. : ");
        scanf("%s", input_id);
        goto here;
    }
    else if (success == 2) {
        i = 0;
        printf("�߸��� ��й�ȣ�Դϴ�. �ٽ��Է����ּ���. : ");
        scanf("%s", input_pw);
        goto here2;
    }

    printf("\n\n");
    printf("�޴� �Է�('q' �Է½� ����): ");

}


void menu_3() //3. �й��� �Է� ������ ����,����,����,���� ������ ��������� ���
{
    char input_id[20];
    char input_pw[20];
    int i, j;
    int success = 0;

    printf("�й� �Է�: ");
    scanf("%s", input_id);
here:
    printf("��й�ȣ �Է�: ");
    scanf("%s", input_pw);
here2:
    for (i = 0; i < len; i++)
    {
        if (!strcmp(input_id, std[i].id)) {
            success = 2;
            if (!strcmp(input_pw, std[i].pw)) {
                printf("[ %s ]�л� -> ����:%.1lf  ����:%.1lf  ����:%.1lf ����:%.1lf \n", std[i].id, std[i].mn, std[i].mc, std[i].en, std[i].ec);
                printf("                 -> ��� ����: %.1lf\n", std[i].average);
                success = 1;
                break;
            }
        }
    }
    if (success == 0) {
        i = 0;
        printf("�������� �ʴ� �л����Դϴ�. �ٽ��Է����ּ���. : ");
        scanf("%s", input_id);
        goto here;
    }
    else if (success == 2) {
        i = 0;
        printf("�߸��� ��й�ȣ�Դϴ�. �ٽ��Է����ּ���. : ");
        scanf("%s", input_pw);
        goto here2;
    }
    printf("\n\n");
    printf("�޴� �Է�('q' �Է½� ����): ");
}

void menu_4() //4. ��ü �л��� ��ü ����� ���� ���
{
    int i;
    check1();
    printf("��ü �л� ���� ���\n");
    for (i = 0; i < len; i++)
    {
        printf("[ %d ]�� �л�  �й�:%s  ����:%.1lf  ����:%.1lf  ����:%.1lf  ����:%.1lf  �������:%.1lf\n",
            i + 1, std[i].id, std[i].mn, std[i].mc, std[i].en, std[i].ec, std[i].average);
    }
    printf("\n\n");
    printf("�޴� �Է�('q' �Է½� ����): ");
}

void menu_5() //5. ��ü �л��� ��ü ����� ���� ���������� ���
{
    int i, j;
    check1();
    for (i = 0; i < len; i++)
    {
        std_dest[i] = std[i];
    }

    for (i = 0; i < len; i++)
    {
        for (j = i + 1; j < len; j++)
        {
            if (std[i].average < std[j].average)
            {
                temp = std_dest[j];
                std_dest[j] = std_dest[i];
                std_dest[i] = temp;
            }
        }
    }

    printf("��ü �л� ��� ���\n");
    for (i = 0; i < len; i++)
    {
        printf("[ %d ]�� �й�:%s  ����:%.1lf  ����:%.lf  ����:%.1lf  ����:%.1lf   �������:%.1lf\n",
            i + 1, std_dest[i].id, std_dest[i].mn, std_dest[i].mc, std_dest[i].en, std_dest[i].ec, std_dest[i].average);
    }

    printf("\n\n");
    printf("�޴� �Է�('q' �Է½� ����): ");
}

void menu_6() //6. ����� �л��� �����͸� �����ϴ� ���
{
    char input_id[20];
    char subject[20];
    int k = 0;

    while (1) {
        printf("���� ������ �л� �й� �Է�:");
        scanf("%s", input_id);
        for (int i = 0; i < len; i++)
        {
            if (!strcmp(input_id, std[i].id))
            {
                printf("������ ����(����,����,����,���� �� �Է�):");
                scanf("%s", subject);
                if (!strcmp(subject, "����"))
                {
                    printf("�����ʼ� ����:");
                    scanf("%d", &std[i].majorN);
                    std[i].mn = cal(std[i].majorN);
                }
                else if (!strcmp(subject, "����"))
                {
                    printf("�������� ����:");
                    scanf("%d", &std[i].majorC);
                    std[i].mc = cal(std[i].majorC);
                }
                else if (!strcmp(subject, "����"))
                {
                    printf("�����ʼ� ����:");
                    scanf("%d", &std[i].ectN);
                    std[i].en = cal(std[i].ectN);
                }
                else if (!strcmp(subject, "����"))
                {
                    printf("���缱�� ����:");
                    scanf("%d", &std[i].ectC);
                    std[i].ec = cal(std[i].ectC);
                }
                std[i].average = (double)(std[i].mn + std[i].mc + std[i].en + std[i].ec) / 4; //��� ����
                printf("������ �Ϸ�Ǿ����ϴ�.\n");
                printf("\n\n");
                break;
            }
            else { k++; }
        }
        if (k == len) {
            printf("�������� �ʴ� �й��Դϴ�. �ٽ� �Է��Ͻÿ�.\n");
            k = 0;
        }
        else {
            break;
        }
    }
    printf("�޴� �Է�('q' �Է½� ����): ");
}

void menu_7() //7. ������ �л��� �����ϴ� ���
{
    char input_id[20];
    int i, j, k = 0;
    check1();
    while (1) {
        printf("������ �л� �й� �Է�:");
        scanf("%s", input_id);
        for (i = 0; i < len; i++)
        {
            if (!strcmp(input_id, std[i].id))
            {
                for (j = i; j < len; j++) {
                    std[j] = std[j + 1];
                    
                }
                len--;
                k++;
                break;
            }
            else { ; }
        }
        if (k == 1) { break; }
        else{
            printf("�������� �ʴ� �й��Դϴ�. �ٽ� �Է��Ͻÿ�.\n"); }
     
    }
    printf("������ �Ϸ�Ǿ����ϴ�.\n");
    printf("\n\n");
    printf("�޴� �Է�('q' �Է½� ����): ");
}


void processMenu(char choice)
{
    switch (choice)
    {
    case '1':
        menu_1();
        break;

    case '2':
        menu_2();
        break;

    case '3':
        menu_3();
        break;

    case '4':
        menu_4();
        break;

    case '5':
        menu_5();
        break;

    case '6':
        menu_6();
        break;

    case '7':
        menu_7();
        break;
    }
}
void myflush()
{
    while (getchar() != '\n');
}

int checkid(char* a) 
{
    if (strlen(a) != 8) {
        return -1; //8�ڸ� �ƴѰ� �Ÿ���
    }
    for (int i = 0; i < 8; i++) {
        if (a[i] < '0' || a[i]>'9') return -1;//���ھƴϸ� �Ÿ���
    }
    if (a[0] != '2' || a[1] != '0' || a[2] > '2') return -1; //�� ���ڸ� 20 �ƴϸ� �Ÿ���, 3��° �� 3�̻� �Ÿ���
    else if (a[2] == '2' && a[3] > '2') return -1; //2022�ʰ��� ���� �Ÿ���
    else {
        for (int i = 0; i < len; i++) {
            if (!strcmp(a,std[i].id)){
                return -1;
            }
            else { ; }
        }
        return 1;
    }
}