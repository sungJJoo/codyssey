#include <stdio.h>
#include <stdlib.h>

#define MAX_JUDGES 10
#define MAX_INFO_LEN 200

int main() {
    char judges_array[MAX_JUDGES][MAX_INFO_LEN]; //2차원 배열 최대 10명, 200자까지 허용 
    int judge_count = 0, member_count;//데이터를 담을 변수

    printf("####################################\n");
    printf("#       심사자 풀 데이터 입력       #\n");
    printf("####################################\n");

    char project_name[50];
    
    // 프로젝트 이름 입력
    printf("> 참여 프로젝트: ");
    fgets(project_name, sizeof(project_name), stdin);

    // 심사 풀 인원과 선발 멤버 수 입력
    printf("> 심사 풀 인원: ");
    scanf("%d", &judge_count);
    getchar();  // 입력 버퍼 비우기

    printf("> 선발 멤버 수: ");
    scanf("%d", &member_count);
    getchar();  // 입력 버퍼 비우기

    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("%d명의 심사자 정보 입력을 시작합니다.\n", judge_count);
    printf("++++++++++++++++++++++++++++++++++++\n");

    // 심사자 정보 입력
    for (int i = 0; i < judge_count; i++) {
        printf("* 심사자 %d 정보 입력 (형식: 이름,성별,소속,직함,전문분야,메일,전화):\n", i + 1);
        fgets(judges_array[i], MAX_INFO_LEN, stdin);
        
        // 개행 문자 제거
        int len = 0;
        while (judges_array[i][len] != '\0') {
            if (judges_array[i][len] == '\n') {
                judges_array[i][len] = '\0';
                break;
            }
            len++;
        }
    }

    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("심사자 풀 입력이 끝났습니다.\n");
    printf("++++++++++++++++++++++++++++++++++++\n");

    // 심사자 풀 확인 여부
    char confirm;
    printf("심사자 풀을 확인할까요? (Y/N): ");
    scanf(" %c", &confirm);

    if (confirm == 'Y') {
        printf("####################################\n");
        printf("#       심사자 풀 데이터 출력       #\n");
        printf("####################################\n");

        for (int i = 0; i < judge_count; i++) {
            char name[50], gender[10], organization[50], title[50], expertise[30], email[50], phone[20];
            
            // 심사자 데이터를 분리하는 과정 (parse_judge_info 함수의 내용)
            int idx = 0, j = 0;
            char *fields[] = {name, gender, organization, title, expertise, email, phone};

            for (int f = 0; f < 7; f++) {
                while (judges_array[i][idx] != ',' && judges_array[i][idx] != '\0') {
                    fields[f][j++] = judges_array[i][idx++];
                }
                fields[f][j] = '\0';  // 각 필드 문자열 끝에 NULL 추가
                idx++;  // ',' 건너뜀
                j = 0;  // 다음 필드를 위해 인덱스 초기화
            }

            // 심사자 정보를 출력 (print_judge_info 함수의 내용)
            printf("[심사자 %d]\n", i + 1);
            printf("이름: %s\n", name);
            printf("성별: %s\n", gender);
            printf("소속: %s\n", organization);
            printf("직함: %s\n", title);
            printf("전문분야: %s\n", expertise);
            printf("메일: %s\n", email);
            printf("전화: %s\n", phone);
            printf("-----------------------------------\n");
        }
    } else {
        printf("프로그램을 종료합니다.\n");
    }

    return 0;
}
