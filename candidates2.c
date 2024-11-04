#include <stdio.h>
#include <stdlib.h>

// 후보자의 정보를 담는 구조체 정의
typedef struct {
    char name[50];          // 성명
    char birth_date[11];     // 생년월일 (YYYY/MM/DD 형식)
    char gender;             // 성별 (F 또는 M)
    char email[50];          // 이메일 주소
    char nationality[30];    // 국적
    float bmi;               // BMI
    char main_skill[30];     // 주 스킬
    char secondary_skill[30];// 보조 스킬
    int topik;               // 한국어 등급 (TOPIK)
    char mbti[5];            // MBTI
    char introduction[256];  // 자기소개
} member_info;

// 함수 선언
int calculate_age(char birth_date[]);
void remove_newline(char* str);
void input_candidate_data(member_info *candidate, int number);
void display_candidate_data(member_info *candidate);

int main() {
    // 메인 프로그램 실행
    char audition_group_name[50];
    
    printf("오디션 그룹명을 입력하세요: ");
    fgets(audition_group_name, 50, stdin);
    remove_newline(audition_group_name);

    printf("####################################\n");
    printf("[%s] 오디션 후보자 데이터 입력\n", audition_group_name);
    printf("####################################\n");

    member_info candidate01, candidate02, candidate03, candidate04, candidate05, candidate06;
    member_info* candidates[6] = {&candidate01, &candidate02, &candidate03, &candidate04, &candidate05, &candidate06};
    
    int i = 0;
    while (i < 6) {
        input_candidate_data(candidates[i], i + 1);
        i++;
    }

    printf("####################################\n");
    printf("[%s] 오디션 후보자 데이터 조회\n", audition_group_name);
    printf("####################################\n");
    
    for (i = 0; i < 6; i++) {
        display_candidate_data(candidates[i]);
    }

    return 0;
}

// 생년월일을 기반으로 나이 계산하는 함수
int calculate_age(char birth_date[]) {
    int year, month, day;
    sscanf(birth_date, "%d/%d/%d", &year, &month, &day);
    int current_year = 2024;
    int age = current_year - year;
    return age;
}

// 개행 문자 제거 함수
void remove_newline(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }
}

// 후보자 정보를 입력받는 함수
void input_candidate_data(member_info *candidate, int number) {
    printf("후보자 %d의 정보를 입력합니다.\n---------------------------------\n", number);

    printf("1. 성명: ");
    fgets(candidate->name, 50, stdin);
    remove_newline(candidate->name);

    printf("2. 생년월일(YYYY/MM/DD 형식): ");
    fgets(candidate->birth_date, 11, stdin);
    remove_newline(candidate->birth_date);

    printf("3. 성별(여성이면 F 남성이면 M): ");
    scanf(" %c", &candidate->gender);
    getchar();

    printf("4. 메일 주소: ");
    fgets(candidate->email, 50, stdin);
    remove_newline(candidate->email);

    printf("5. 국적: ");
    fgets(candidate->nationality, 30, stdin);
    remove_newline(candidate->nationality);

    printf("6. BMI: ");
    scanf("%f", &candidate->bmi);
    getchar();

    printf("7. 주 스킬: ");
    fgets(candidate->main_skill, 30, stdin);
    remove_newline(candidate->main_skill);

    printf("8. 보조 스킬: ");
    fgets(candidate->secondary_skill, 30, stdin);
    remove_newline(candidate->secondary_skill);

    printf("9. 한국어 등급(TOPIK): ");
    scanf("%d", &candidate->topik);
    getchar();

    printf("10. MBTI: ");
    fgets(candidate->mbti, 5, stdin);
    remove_newline(candidate->mbti);

    printf("11. 소개: ");
    fgets(candidate->introduction, 256, stdin);
    remove_newline(candidate->introduction);
}

// 후보자 정보를 출력하는 함수
void display_candidate_data(member_info *candidate) {
    int age = calculate_age(candidate->birth_date);

    printf("=============================================================================================\n");
    printf("성   명 | 생   일 | 성별 | 메   일            | 국적 | BMI | 주스킬 | 보조스킬 | TOPIK | MBTI | \n");
    printf("=============================================================================================\n");
    printf("%-7s | %-8s | %c   | %-19s | %-5s | %.1f | %-7s | %-7s | %-5d | %-4s |\n",
        candidate->name, candidate->birth_date, candidate->gender, candidate->email,
        candidate->nationality, candidate->bmi, candidate->main_skill, candidate->secondary_skill,
        candidate->topik, candidate->mbti);

    printf("---------------------------------------------------------------------------------------------\n");
    printf("%s\n", candidate->introduction);
    printf("---------------------------------------------------------------------------------------------\n");
}
