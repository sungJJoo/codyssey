#include <stdio.h>
#include <stdlib.h>

#define NUM_CANDIDATES 6
#define NUM_ACCEPTED 4

typedef struct {
    int id;
    char name[50];
    char birth_date[11];
    char gender;
    char email[50];
    char nationality[30];
    float bmi;
    char main_skill[30];
    char secondary_skill[30];
    int topik;
    char mbti[5];
    int is_accepted;
} member_info;

typedef struct {
    int id;
    char name[50];
    char nickname[20];
    char education[20];
    float height;
    float weight;
    char blood_type;
    char allergy[30];
    char hobbies[50];
    char sns[50];
    char bmi_category[10];
} milliways_member;

int main() {
    // 미리 정의된 후보자 데이터
    member_info candidates[NUM_CANDIDATES] = {
        {1, "박지연", "2005/03/14", 'F', "jiyeon@example.com", "Korea", 18.2, "Singing", "Dancing", 5, "INTJ", 1},
        {2, "Ethan Smith", "2006/08/21", 'M', "ethan@example.com", "USA", 24.3, "Guitar", "Composing", 4, "ENTP", 1},
        {3, "Helena Silva", "2005/12/10", 'F', "helena@example.com", "Brazil", 22.7, "Drawing", "Singing", 3, "INFJ", 1},
        {4, "Liam Wilson", "2007/02/02", 'M', "liam@example.com", "Canada", 27.1, "Producing", "Dancing", 2, "ISTP", 1},
        {5, "Alex Lee", "2006/06/30", 'M', "alex@example.com", "Korea", 21.3, "Rap", "Dance", 4, "ENTJ", 0},
        {6, "Sara Kim", "2008/01/25", 'F', "sara@example.com", "Korea", 19.5, "Violin", "Piano", 5, "ISFP", 0}
    };
    
    milliways_member milliways_arr[NUM_ACCEPTED];
    int j = 0;
    
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        if (candidates[i].is_accepted) {
            milliways_arr[j].id = candidates[i].id;
            sprintf(milliways_arr[j].name, "%s", candidates[i].name);
            
            // 미리 정의된 데이터는 입력하지 않음
            printf("합격자 %d 정보 입력:\n", j + 1);
            
            // 닉네임 입력
            printf("닉네임: ");
            scanf("%s", milliways_arr[j].nickname);
            
            // 학력 입력
            printf("학력: ");
            scanf("%s", milliways_arr[j].education);
            
            // 키 입력 (센티미터를 미터로 변환하여 입력)
            printf("키(cm): ");
            int height_cm;
            scanf("%d", &height_cm);
            milliways_arr[j].height = height_cm / 100.0f;
            
            // 몸무게 계산 (키와 BMI를 이용하여 계산)
            milliways_arr[j].weight = candidates[i].bmi * milliways_arr[j].height * milliways_arr[j].height;
            
            // 혈액형 입력
            getchar();  // 버퍼에 남아 있는 개행 문자 제거
            printf("혈액형: ");
            scanf("%c", &milliways_arr[j].blood_type);
            
            // 알러지 입력
            getchar();  // 개행 문자 제거
            printf("알러지: ");
            scanf("%[^\n]", milliways_arr[j].allergy);  // 공백 포함 입력받기
            
            // 취미 입력
            getchar();  // 개행 문자 제거
            printf("취미: ");
            scanf("%[^\n]", milliways_arr[j].hobbies);  // 공백 포함 입력받기
            
            // SNS 입력
            getchar();  // 개행 문자 제거
            printf("SNS: ");
            scanf("%[^\n]", milliways_arr[j].sns);  // 공백 포함 입력받기
            
            // BMI 체형 분류
            if (candidates[i].bmi < 18.5) {
                sprintf(milliways_arr[j].bmi_category, "저체중");
            } else if (candidates[i].bmi < 24.9) {
                sprintf(milliways_arr[j].bmi_category, "정상");
            } else if (candidates[i].bmi < 29.9) {
                sprintf(milliways_arr[j].bmi_category, "과체중");
            } else {
                sprintf(milliways_arr[j].bmi_category, "비만");
            }
            
            j++;
        }
    }

    // 합격자 명단 출력
    printf("\n밀리웨이즈 합격자 명단:\n");
    for (int i = 0; i < NUM_ACCEPTED; i++) {
        printf("--------------------------------------------------\n");
        printf("ID: %d, 이름: %s\n", milliways_arr[i].id, milliways_arr[i].name);
        printf("닉네임: %s\n", milliways_arr[i].nickname);
        printf("학력: %s\n", milliways_arr[i].education);
        printf("키: %.2fm, 몸무게: %.1fkg\n", milliways_arr[i].height, milliways_arr[i].weight);
        printf("혈액형: %c, 알러지: %s\n", milliways_arr[i].blood_type, milliways_arr[i].allergy);
        printf("취미: %s\n", milliways_arr[i].hobbies);
        printf("SNS: %s\n", milliways_arr[i].sns);
        printf("BMI 체형: %s\n", milliways_arr[i].bmi_category);
    }

    return 0;
}
