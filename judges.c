#include <stdio.h>
#include <stdlib.h>

#define MAX_JUDGES 10
#define MAX_INFO_LEN 200

// 심사자 데이터를 분리하는 함수 문자 파싱하는 함수 , 쉼표로 구분
void parse_judge_info(char *judge_data, char *name, char *gender, char *organization, char *title, char *expertise, char *email, char *phone) {
    int i = 0, j = 0;//필드랑 인덱스 추적 변수
    char *fields[] = {name, gender, organization, title, expertise, email, phone};
    //이름 성별 소속 등등 포인터 배열
    for (int f = 0; f < 7; f++) { //위에 파싱한 변수들만큼 반복
        while (judge_data[i] != ',' && judge_data[i] != '\0') { //, 쉼표나 문자열 끝 \0을 만날때까지 해당 문자를 
            fields[f][j++] = judge_data[i++]; // fields[f]에게 복사 
        }
        fields[f][j] = '\0';  // 문자열 끝에 NULL 추가
        i++;  // 다음 필드로 넘어가기 위해 ',' 건너뜀
        j = 0;  // 다음 필드 시작
    }
}

// 심사자 정보를 출력하는 함수
void print_judge_info(char *judge_data, int judge_num) {
    char name[50], gender[10], organization[50], title[50], expertise[30], email[50], phone[20];
    
    // 데이터를 파싱
    parse_judge_info(judge_data, name, gender, organization, title, expertise, email, phone);
    
    // 출력
    printf("[심사자 %d]\n", judge_num);
    printf("이름: %s\n", name);
    printf("성별: %s\n", gender);
    printf("소속: %s\n", organization);
    printf("직함: %s\n", title);
    printf("전문분야: %s\n", expertise);
    printf("메일: %s\n", email);
    printf("전화: %s\n", phone);
    printf("-----------------------------------\n");
}

int main() {
    char judges_array[MAX_JUDGES][MAX_INFO_LEN];
    int judge_count = 0, member_count;

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
    for (int i = 0; i < judge_count; i++) { //judge_count 수에 입력된 만큼 반복해서 입력받음
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
    printf("심사자 풀을 확인할까요? (Y/N): "); //출력 여부
    scanf(" %c", &confirm);

    if (confirm == 'Y') { //Y를 입력할시 
        printf("####################################\n");
        printf("#       심사자 풀 데이터 출력       #\n");
        printf("####################################\n");

        for (int i = 0; i < judge_count; i++) {
            print_judge_info(judges_array[i], i + 1);
        }
    } else {
        printf("프로그램을 종료합니다.\n");
    }

    return 0;
}
