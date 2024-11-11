#include <stdio.h>
#include <stdlib.h>

#define NUM_CANDIDATES 6
#define NUM_ACCEPTED 4

// 후보자 기본 정보 구조체
typedef struct {
    int id;                  // 고유 ID
    char name[50];           // 이름
    char birth_date[11];     // 생년월일
    char gender;             // 성별
    char email[50];          // 이메일
    char nationality[30];    // 국적
    float bmi;               // BMI
    char main_skill[30];     // 주 스킬
    char secondary_skill[30];// 보조 스킬
    int topik;               // TOPIK 등급
    char mbti[5];            // MBTI
    int is_accepted;         // 합격 여부
} member_info;

// 합격자 추가 정보 구조체
typedef struct {
    int id;
    char name[50];
    char nickname[20];
    char education[20];
    float height;            // 키 (미터)
    float weight;            // 몸무게
    char blood_type;
    char allergy[30];
    char hobbies[50];
    char sns[50];
    char bmi_category[10];   // 체형 분류
} milliways_member;

int main() {
    member_info candidates[NUM_CANDIDATES] = {
        {1, "박지연", "2005/03/14", 'F', "jiyeon@example.com", "Korea", 18.2, "Singing", "Dancing", 5, "INTJ", 1},
        {2, "Ethan Smith", "2006/08/21", 'M', "ethan@example.com", "USA", 24.3, "Guitar", "Composing", 4, "ENTP", 1},
        {3, "Helena Silva", "2005/12/10", 'F', "helena@example.com", "Brazil", 22.7, "Drawing", "Singing", 3, "INFJ", 1},
        {4, "Liam Wilson", "2007/02/02", 'M', "liam@example.com", "Canada", 27.1, "Producing", "Dancing", 2, "ISTP", 1},
        {5, "Alex Lee", "2006/06/30", 'M', "alex@example.com", "Korea", 21.3, "Rap", "Dance", 4, "ENTJ", 0},
        {6, "Sara Kim", "2008/01/25", 'F', "sara@example.com", "Korea", 19.5, "Violin", "Piano", 5, "ISFP", 0}
    };
    
    milliways_member milliways_arr[NUM_ACCEPTED];

    // 합격자 복사 및 인터뷰 정보 수집
    int j = 0;
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        if (candidates[i].is_accepted) {
            milliways_arr[j].id = candidates[i].id;
            sprintf(milliways_arr[j].name, "%s", candidates[i].name);
            printf("합격자 %d 정보 입력:\n", j + 1);

            printf("닉네임: ");
            fgets(milliways_arr[j].nickname, 20, stdin);
            printf("학력: ");
            fgets(milliways_arr[j].education, 20, stdin);
            printf("키(m): ");
            scanf("%f", &milliways_arr[j].height);
            milliways_arr[j].weight = candidates[i].bmi * milliways_arr[j].height * milliways_arr[j].height;
            getchar(); // 개행문자 제거

            printf("혈액형: ");
            scanf(" %c", &milliways_arr[j].blood_type);
            getchar();

            printf("알러지: ");
            fgets(milliways_arr[j].allergy, 30, stdin);
            printf("취미: ");
            fgets(milliways_arr[j].hobbies, 50, stdin);
            printf("SNS: ");
            fgets(milliways_arr[j].sns, 50, stdin);

            // BMI 체형 분류
            if (candidates[i].bmi < 18.5) {
                sprintf(milliways_arr[j].bmi_category, "Underweight");
            } else if (candidates[i].bmi < 24.9) {
                sprintf(milliways_arr[j].bmi_category, "Normal");
            } else if (candidates[i].bmi < 29.9) {
                sprintf(milliways_arr[j].bmi_category, "Overweight");
            } else {
                sprintf(milliways_arr[j].bmi_category, "Obese");
            }

            j++;
        }
    }

    // 합격자 데이터 출력
    printf("\n밀리웨이즈 합격자 명단:\n");
    for (int i = 0; i < NUM_ACCEPTED; i++) {
        printf("--------------------------------------------------\n");
        printf("ID: %d, 이름: %s\n", milliways_arr[i].id, milliways_arr[i].name);
        printf("닉네임: %s", milliways_arr[i].nickname);
        printf("학력: %s", milliways_arr[i].education);
        printf("키: %.2fm, 몸무게: %.1fkg\n", milliways_arr[i].height, milliways_arr[i].weight);
        printf("혈액형: %c, 알러지: %s", milliways_arr[i].blood_type, milliways_arr[i].allergy);
        printf("취미: %s", milliways_arr[i].hobbies);
        printf("SNS: %s", milliways_arr[i].sns);
        printf("BMI 체형: %s\n", milliways_arr[i].bmi_category);
    }
    return 0;
}
