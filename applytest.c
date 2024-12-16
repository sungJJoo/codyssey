#include <stdio.h>
#include <math.h>

#define FIELD_COUNT 9
#define MIN_DAYS 30
#define MAX_DAYS 100
#define ROOM_COUNT 10

// Function declarations
int calculate_date_difference(int start_date, int exam_date);
void print_exam_results(int exam_dates[], const char training_fields[][20], int total_fields);
int select_random_room();

int main(void) {
    // Initialize training fields
    const char training_fields[FIELD_COUNT][20] = {
        "체력", "지식", "자기관리", "팀워크",
        "한국어", "보컬", "댄스", "비주얼", "연기"
    };

    int exam_dates[FIELD_COUNT] = {0}; // Store exam dates for each field
    int prerequisites_met[FIELD_COUNT] = {0}; // Track prerequisite completion

    int start_date;

    // Input training start date
    printf("훈련 시작 날짜를 입력하세요 (YYYYMMDD): ");
    scanf("%d", &start_date);

    int choice;
    do {
        printf("\n인증 시험 관리 시스템\n");
        printf("1. 시험 예약\n");
        printf("2. 시험 결과 보기\n");
        printf("3. 종료\n");
        printf("선택을 입력하세요: ");
        scanf("%d", &choice);

        if (choice == 1) {
            // Schedule exam
            printf("\n예약 가능한 분야:\n");
            for (int i = 0; i < FIELD_COUNT; i++) {
                printf("%d. %s\n", i + 1, training_fields[i]);
            }

            int field_choice, exam_date;
            printf("분야를 선택하세요 (1-%d): ", FIELD_COUNT);
            scanf("%d", &field_choice);
            field_choice -= 1; // Adjust to 0-based index

            if (field_choice < 0 || field_choice >= FIELD_COUNT) {
                printf("잘못된 분야 선택입니다.\n");
                continue;
            }

            if ((field_choice == 2 || field_choice == 3) &&
                (!prerequisites_met[0] || !prerequisites_met[1])) {
                printf("체력과 지식을 통과한 후에 이 분야를 예약할 수 있습니다.\n");
                continue;
            }

            printf("시험 날짜를 입력하세요 (YYYYMMDD): ");
            scanf("%d", &exam_date);

            int day_difference = calculate_date_difference(start_date, exam_date);
            if (day_difference < MIN_DAYS || day_difference > MAX_DAYS) {
                printf("시험 날짜는 훈련 시작 후 %d일 이상, %d일 이내여야 합니다.\n",
                       MIN_DAYS, MAX_DAYS);
                continue;
            }

            exam_dates[field_choice] = exam_date;
            prerequisites_met[field_choice] = 1; // Mark field as completed
            printf("%s 분야 시험이 %d로 예약되었습니다.\n", training_fields[field_choice], exam_date);

        } else if (choice == 2) {
            // View exam results
            print_exam_results(exam_dates, training_fields, FIELD_COUNT);
        } else if (choice != 3) {
            printf("잘못된 선택입니다. 다시 시도하세요.\n");
        }

    } while (choice != 3);

    printf("프로그램을 종료합니다. 안녕히 가세요!\n");
    return 0;
}

// Calculate the difference in days between two dates
int calculate_date_difference(int start_date, int exam_date) {
    int start_year = start_date / 10000;
    int start_month = (start_date / 100) % 100;
    int start_day = start_date % 100;

    int exam_year = exam_date / 10000;
    int exam_month = (exam_date / 100) % 100;
    int exam_day = exam_date % 100;

    int start_total_days = start_year * 365 + start_month * 30 + start_day;
    int exam_total_days = exam_year * 365 + exam_month * 30 + exam_day;

    return exam_total_days - start_total_days;
}

// Print exam results
void print_exam_results(int exam_dates[], const char training_fields[][20], int total_fields) {
    printf("\n시험 결과:\n");
    for (int i = 0; i < total_fields; i++) {
        if (exam_dates[i] != 0) {
            printf("%s: %d에 예약됨\n", training_fields[i], exam_dates[i]);
        } else {
            printf("%s: 예약되지 않음\n", training_fields[i]);
        }
    }
}

// Select a random room
int select_random_room() {
    return (rand() % ROOM_COUNT) + 1;
}
