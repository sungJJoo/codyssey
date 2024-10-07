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

// 생년월일을 기반으로 나이 계산하는 함수
int calculate_age(char birth_date[]) {
    int year, month, day;
    sscanf(birth_date, "%d/%d/%d", &year, &month, &day); //sscanf %d 공백으로 구분된 문자열 정수로 읽기
    int current_year = 2024; //현재 년도를 2024년도로 설정 
    int age = current_year - year; // 나이는 현재 년도 - 출생 연도 
    return age;
}

// 개행 문자 제거 함수
void remove_newline(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '\0'; // 개행 문자를 NULL로 변경 사용 이유? fgets로 입력받은 문자열에서 \n 발견하면 null로 제거 
            break;
        }
    }
}

// 후보자 정보를 입력받는 함수
void input_candidate_data(member_info *candidate, int number) {
    printf("후보자 %d의 정보를 입력합니다.\n---------------------------------\n", number);

    // 이름 입력
    printf("1. 성명: ");
    fgets(candidate->name, 50, stdin); //fgets로 입력 버퍼 크기 50 stdin << 키보드 입력 표준 스트림 
    remove_newline(candidate->name);  // 개행 문자 제거
    
    // 생년월일 입력
    printf("2. 생년월일(YYYY/MM/DD 형식): ");
    fgets(candidate->birth_date, 11, stdin);
    remove_newline(candidate->birth_date); // 개행 문자 제거
    
    // 성별 입력
    printf("3. 성별(여성이면 F 남성이면 M): ");
    scanf(" %c", &candidate->gender);
    getchar();  // 남은 개행 문자 제거
    
    // 이메일 주소 입력
    printf("4. 메일 주소: ");
    fgets(candidate->email, 50, stdin);
    remove_newline(candidate->email); // 개행 문자 제거
    
    // 국적 입력
    printf("5. 국적: ");
    fgets(candidate->nationality, 30, stdin);
    remove_newline(candidate->nationality); // 개행 문자 제거
    
    // BMI 입력
    printf("6. BMI: ");
    scanf("%f", &candidate->bmi);
    getchar();  // 남은 개행 문자 제거
    
    // 주 스킬 입력
    printf("7. 주 스킬: ");
    fgets(candidate->main_skill, 30, stdin);
    remove_newline(candidate->main_skill); // 개행 문자 제거
    
    // 보조 스킬 입력
    printf("8. 보조 스킬: ");
    fgets(candidate->secondary_skill, 30, stdin);
    remove_newline(candidate->secondary_skill); // 개행 문자 제거
    
    // TOPIK (한국어 등급) 입력
    printf("9. 한국어 등급(TOPIK): ");
    scanf("%d", &candidate->topik);
    getchar();  // 남은 개행 문자 제거
    
    // MBTI 입력
    printf("10. MBTI: ");
    fgets(candidate->mbti, 5, stdin);
    remove_newline(candidate->mbti); // 개행 문자 제거
    
    // 자기소개 입력
    printf("11. 소개: ");
    fgets(candidate->introduction, 256, stdin);
    remove_newline(candidate->introduction); // 개행 문자 제거
}

// 후보자 정보를 출력하는 함수 
void display_candidate_data(member_info *candidate) {
    int age = calculate_age(candidate->birth_date);

    // 후보자 정보 테이블 형식으로 출력
    printf("=============================================================================================\n");
    printf("성   명 | 생   일 | 성별 | 메   일            | 국적 | BMI | 주스킬 | 보조스킬 | TOPIK | MBTI | \n");
    printf("=============================================================================================\n");
    printf("%-7s | %-8s | %c   | %-19s | %-5s | %.1f | %-7s | %-7s | %-5d | %-4s |\n", //7칸의 문자열(작으면 공백추가),8칸의 문자열,문자 출력,왼쪽 정렬 19문자,5공간 문자열,실수 한자리 
        candidate->name, candidate->birth_date, candidate->gender, candidate->email,
        candidate->nationality, candidate->bmi, candidate->main_skill, candidate->secondary_skill,
        candidate->topik, candidate->mbti);

    // 자기소개 출력
    printf("---------------------------------------------------------------------------------------------\n");
    printf("%s\n", candidate->introduction);
    printf("---------------------------------------------------------------------------------------------\n");
}

// 메인 함수
int main() {
    char audition_group_name[50]; //오디션 그룹이름이 들어갈 배열 선언
    
    // 오디션 그룹명 입력
    printf("오디션 그룹명을 입력하세요: ");
    fgets(audition_group_name, 50, stdin);//오디션 그룹명 입력 
    remove_newline(audition_group_name); // 개행 문자 제거
    
    // 입력 화면 출력
    printf("####################################\n");
    printf("[%s] 오디션 후보자 데이터 입력\n", audition_group_name);
    printf("####################################\n");

    // 6명의 후보자를 6개의 1차원 배열로 관리
    member_info candidate01, candidate02, candidate03, candidate04, candidate05, candidate06;
    
    // 후보자 입력을 위한 배열
    member_info* candidates[6] = {&candidate01, &candidate02, &candidate03, &candidate04, &candidate05, &candidate06};
    
    // 후보자 정보 입력 (while 반복문 사용)
    int i = 0;
    while (i < 6) {
        input_candidate_data(candidates[i], i + 1);
        i++;
    }

    // 출력 화면 출력
    printf("####################################\n");
    printf("[%s] 오디션 후보자 데이터 조회\n", audition_group_name);
    printf("####################################\n");
    
    // 후보자 정보 출력 (for 반복문 사용)
    for (i = 0; i < 6; i++) {
        display_candidate_data(candidates[i]);
    }

    return 0;
}
