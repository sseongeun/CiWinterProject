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
    int majorN, majorC, ectN, ectC;//전필, 전선, 교필, 교선
    double mn, mc, en, ec; //(학점)전필, 전선, 교필, 교선
    double average; // (학점)평균

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
        printf("성적 관리자 비밀번호를 설정하시오(4자리 숫자):");
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
        if (ch == 'q') { break; }// 추가코드**
        else {
            processMenu(ch);
        }
    }

    printf("프로그램 종료\n");
    return 0;
}





void choice_menu() //메뉴
{
    printf("          성적관리 프로그램 \n\n");
    printf("---------------M E N U---------------\n\n");
    printf("1.학생 정보 입력 \n\n");
    printf("2.학생 본인의 해당 과목 점수 열람 \n\n");
    printf("3.학생 본인의 평균 열람 \n\n");
    printf("4.전체 학생의 정보 출력 (관리자 권한 필요) \n\n");
    printf("5.전체 학생의 성적순 출력 (관리자 권한 필요) \n\n");
    printf("6.학생 본인의 데이터 수정 \n\n");
    printf("7.학생 정보 삭제 (관리자 권한 필요)\n\n");
    printf("메뉴를 입력하세요('q' 입력시 종료): ");
}



void check1()
{
    char input[20];
    printf("성적 관리자 비밀번호를 입력하시오: ");
    while (1) {
        scanf("%s", input);
        if (!strcmp(input,pw1)) {
            break;
        }
        else {
            printf("잘못된 비밀번호입니다. 다시 입력하시오: ");
            continue;
        }
    }
}

void menu_1() //메뉴1 정보: 학번, 비밀번호,학생 이름, 성적 입력
{
    int i;

    printf("학생정보를 입력하세요.\n");

    for (i = len; i < len + 1; i++)
    {
        do {
            printf("학번 : ");
            scanf("%s", std[i].id);
            if (checkid(std[i].id) != 1)
            {
                printf("**이미 존재하거나,유효하지 않은 학번입니다. 다시 입력하세요.\n");
            }
        } while (checkid(std[i].id) != 1);

        while (1) {
            printf("비밀번호 설정(숫자 4자리 입력): ");
            scanf("%s", std[i].pw);
            if (strlen(std[i].pw) == 4) {
                break;
            }
            else {
                continue;
            }
        }

        do {
            printf("전공필수 성적 입력(0~100점 입력): ");
            scanf("%d", &std[i].majorN);
            if (std[i].majorN < 0 || std[i].majorN > 100)
            {
                printf("입력 오류!! 성적을 재입력하세요.\n");
            }
        } while (std[i].majorN < 0 || std[i].majorN > 100);
        std[i].mn = cal(std[i].majorN);

        do {
            printf("전공선택 성적 입력(0~100점 입력): ");
            scanf("%d", &std[i].majorC);
            if (std[i].majorC < 0 || std[i].majorC > 100)
            {
                printf("입력 오류!! 성적을 재입력하세요.\n");
            }
        } while (std[i].majorC < 0 || std[i].majorC> 100);
        std[i].mc = cal(std[i].majorC);

        do {
            printf("교양필수 성적 입력(0~100점 입력): ");
            scanf("%d", &std[i].ectN);
            if (std[i].ectN < 0 || std[i].ectN > 100)
            {
                printf("입력 오류!! 성적을 재입력하세요.\n");
            }
        } while (std[i].ectN < 0 || std[i].ectN > 100);
        std[i].en = cal(std[i].ectN);

        do {
            printf("교양선택 성적 입력(0~100점 입력): ");
            scanf("%d", &std[i].ectC);
            if (std[i].ectC < 0 || std[i].ectC > 100)
            {
                printf("입력 오류!! 성적을 재입력하세요.\n");
            }
        } while (std[i].ectC < 0 || std[i].ectC > 100);
        std[i].ec = cal(std[i].ectC);
        std[i].average = (std[i].mn + std[i].mc + std[i].en + std[i].ec) / 4;
    }
    len++;
    printf("\n\n");
    printf("메뉴 입력('q' 입력시 종료): ");
}

double cal(int score)//원점수를 학점으로 변환하는 함수
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


void menu_2() //2. 이름과 과목을 입력 받아 해당 학생의 해당 과목 원점수와 학점을 출력
{
    char input_id[20];
    char input_pw[20];
    int i, j;
    int success = 0;

    printf("학번 입력: ");
    scanf("%s", input_id);
here:
    printf("비밀번호 입력: ");
    scanf("%s", input_pw);
here2:
    for (i = 0; i < len; i++)
    {
        if (!strcmp(input_id, std[i].id)) {
            success = 2;
            if(!strcmp(input_pw,std[i].pw)) {
                printf("[ %s ]학생의 성적입니다. \n", input_id);
                printf("전공 필수 학점: %.1lf \n", std[i].mn);
                printf("전공 선택 학점: %.1lf \n", std[i].mc);
                printf("교양 필수 학점: %.1lf\n", std[i].en);
                printf("교양 선택 학점: %.1lf\n", std[i].ec);
                printf("평균 점수 : %.1lf\n", std[i].average);
                success = 1;
                break;
            }
        }
    }
    if (success == 0) {
        i = 0;
        printf("존재하지 않는 학생명입니다. 다시입력해주세요. : ");
        scanf("%s", input_id);
        goto here;
    }
    else if (success == 2) {
        i = 0;
        printf("잘못된 비밀번호입니다. 다시입력해주세요. : ");
        scanf("%s", input_pw);
        goto here2;
    }

    printf("\n\n");
    printf("메뉴 입력('q' 입력시 종료): ");

}


void menu_3() //3. 학번을 입력 받으면 전필,전선,교필,교선 성적과 학점평균을 출력
{
    char input_id[20];
    char input_pw[20];
    int i, j;
    int success = 0;

    printf("학번 입력: ");
    scanf("%s", input_id);
here:
    printf("비밀번호 입력: ");
    scanf("%s", input_pw);
here2:
    for (i = 0; i < len; i++)
    {
        if (!strcmp(input_id, std[i].id)) {
            success = 2;
            if (!strcmp(input_pw, std[i].pw)) {
                printf("[ %s ]학생 -> 전필:%.1lf  전선:%.1lf  교필:%.1lf 교선:%.1lf \n", std[i].id, std[i].mn, std[i].mc, std[i].en, std[i].ec);
                printf("                 -> 평균 학점: %.1lf\n", std[i].average);
                success = 1;
                break;
            }
        }
    }
    if (success == 0) {
        i = 0;
        printf("존재하지 않는 학생명입니다. 다시입력해주세요. : ");
        scanf("%s", input_id);
        goto here;
    }
    else if (success == 2) {
        i = 0;
        printf("잘못된 비밀번호입니다. 다시입력해주세요. : ");
        scanf("%s", input_pw);
        goto here2;
    }
    printf("\n\n");
    printf("메뉴 입력('q' 입력시 종료): ");
}

void menu_4() //4. 전체 학생의 전체 저장된 값을 출력
{
    int i;
    check1();
    printf("전체 학생 정보 출력\n");
    for (i = 0; i < len; i++)
    {
        printf("[ %d ]번 학생  학번:%s  전필:%.1lf  전선:%.1lf  교필:%.1lf  교선:%.1lf  평균학점:%.1lf\n",
            i + 1, std[i].id, std[i].mn, std[i].mc, std[i].en, std[i].ec, std[i].average);
    }
    printf("\n\n");
    printf("메뉴 입력('q' 입력시 종료): ");
}

void menu_5() //5. 전체 학생의 전체 저장된 값을 성적순으로 출력
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

    printf("전체 학생 등수 출력\n");
    for (i = 0; i < len; i++)
    {
        printf("[ %d ]등 학번:%s  전필:%.1lf  전선:%.lf  교필:%.1lf  교선:%.1lf   평균학점:%.1lf\n",
            i + 1, std_dest[i].id, std_dest[i].mn, std_dest[i].mc, std_dest[i].en, std_dest[i].ec, std_dest[i].average);
    }

    printf("\n\n");
    printf("메뉴 입력('q' 입력시 종료): ");
}

void menu_6() //6. 저장된 학생의 데이터를 수정하는 기능
{
    char input_id[20];
    char subject[20];
    int k = 0;

    while (1) {
        printf("성적 수정할 학생 학번 입력:");
        scanf("%s", input_id);
        for (int i = 0; i < len; i++)
        {
            if (!strcmp(input_id, std[i].id))
            {
                printf("수정할 과목(전필,전선,교필,교선 중 입력):");
                scanf("%s", subject);
                if (!strcmp(subject, "전필"))
                {
                    printf("전공필수 성적:");
                    scanf("%d", &std[i].majorN);
                    std[i].mn = cal(std[i].majorN);
                }
                else if (!strcmp(subject, "전선"))
                {
                    printf("전공선택 성적:");
                    scanf("%d", &std[i].majorC);
                    std[i].mc = cal(std[i].majorC);
                }
                else if (!strcmp(subject, "교필"))
                {
                    printf("교양필수 성적:");
                    scanf("%d", &std[i].ectN);
                    std[i].en = cal(std[i].ectN);
                }
                else if (!strcmp(subject, "교선"))
                {
                    printf("교양선택 성적:");
                    scanf("%d", &std[i].ectC);
                    std[i].ec = cal(std[i].ectC);
                }
                std[i].average = (double)(std[i].mn + std[i].mc + std[i].en + std[i].ec) / 4; //평균 변경
                printf("변경이 완료되었습니다.\n");
                printf("\n\n");
                break;
            }
            else { k++; }
        }
        if (k == len) {
            printf("존재하지 않는 학번입니다. 다시 입력하시오.\n");
            k = 0;
        }
        else {
            break;
        }
    }
    printf("메뉴 입력('q' 입력시 종료): ");
}

void menu_7() //7. 선택한 학생을 삭제하는 기능
{
    char input_id[20];
    int i, j, k = 0;
    check1();
    while (1) {
        printf("삭제할 학생 학번 입력:");
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
            printf("존재하지 않는 학번입니다. 다시 입력하시오.\n"); }
     
    }
    printf("삭제가 완료되었습니다.\n");
    printf("\n\n");
    printf("메뉴 입력('q' 입력시 종료): ");
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
        return -1; //8자리 아닌거 거르기
    }
    for (int i = 0; i < 8; i++) {
        if (a[i] < '0' || a[i]>'9') return -1;//숫자아니면 거르기
    }
    if (a[0] != '2' || a[1] != '0' || a[2] > '2') return -1; //앞 두자리 20 아니면 거르기, 3번째 수 3이상 거르기
    else if (a[2] == '2' && a[3] > '2') return -1; //2022초과한 숫자 거르기
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