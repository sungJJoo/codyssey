#include <stdio.h>
#include <stdlib.h>

#define NUM_CANDIDATES 6
#define NUM_FIELDS 5
#define MAX_SCORE 100
#define MIN_SCORE 10

int main() {
    // 후보자 정보
    char candidate_names[NUM_CANDIDATES][30] = {
        "박지연", "Ethan Smith", 
        "Helena Silva", "Liam Wilson", 
        "Jin Park", "Alice Chen"
    };
    int candidate_ids[NUM_CANDIDATES] = {123456, 234567, 345678, 456789, 567890, 678901};

    // 후보자의 점수를 저장하는 배열 (ID, 5개의 점수, 총점)
    int scores[NUM_CANDIDATES][NUM_FIELDS + 2] = {0}; 

    char judge_name[30];
    char expertise[20];

    printf("####################################\n");
    printf("#       오디션 심사 결과 입력       #\n");
    printf("####################################\n");
    
    printf("> 심사자 이름: ");
    fgets(judge_name, sizeof(judge_name), stdin);

    printf("> 전문 분야: ");
    fgets(expertise, sizeof(expertise), stdin);

    // fgets로 입력받은 전문 분야에서 개행 문자 '\n'을 제거
    if (expertise[strlen(expertise) - 1] == '\n') {
        expertise[strlen(expertise) - 1] = '\0';
    }

    // 전문 분야에 따른 처리: 문자열 비교
    int field_index = -1;

    // '음악' 문자열과 비교
    if (strcmp(expertise, "음악") == 0) {
        field_index = 1;
    }

    if (field_index == -1) {
        printf("잘못된 전문 분야입니다.\n");
        return 1;  // 프로그램 종료
    }

    // 후보자에 대한 점수 입력
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        int score;
        printf("후보자: %s\n", candidate_names[i]);
        do {
            printf("%s 소양 점수 (10~100): ", expertise);
            scanf("%d", &score);
            if (score < MIN_SCORE || score > MAX_SCORE) {
                printf("잘못된 값입니다. 다시 입력하세요.\n");
            }
        } while (score < MIN_SCORE || score > MAX_SCORE);
        scores[i][0] = candidate_ids[i];  // ID 저장
        scores[i][field_index] = score;  // 해당 분야 점수 저장
    }

    // 총점 계산
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        int total = 0;
        for (int j = 1; j <= NUM_FIELDS; j++) {
            total += scores[i][j];  // 각 분야 점수 합산
        }
        scores[i][NUM_FIELDS + 1] = total;  // 총점 저장
    }

    // 입력 완료 후 점수 출력
    printf("입력을 모두 완료했습니다.\n입력하신 내용을 검토하세요!\n");
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("%s: %d\n", candidate_names[i], scores[i][field_index]);  // 해당 분야 점수 출력
    }

    // 제출 여부 확인
    char submit;
    printf("제출하시겠습니까? (Y/N): ");
    getchar();  // 이전 입력 버퍼 비우기
    submit = getchar();

    if (submit == 'Y' || submit == 'y') {
        printf("***최종 제출을 완료했습니다.***\n");
    } else if (submit == 'N' || submit == 'n') {
        // 점수 수정 루프
        int modify_id, new_score;
        do {
            printf("수정할 후보자의 ID를 입력하세요 (종료하려면 0 입력): ");
            scanf("%d", &modify_id);

            if (modify_id == 0) {
                break;
            }

            int candidate_index = -1;
            for (int i = 0; i < NUM_CANDIDATES; i++) {
                if (scores[i][0] == modify_id) {
                    candidate_index = i;
                    break;
                }
            }

            if (candidate_index == -1) {
                printf("잘못된 ID입니다.\n");
                continue;
            }

            // 새로운 점수 입력
            do {
                printf("%s 소양 새로운 점수 (10~100): ", expertise);
                scanf("%d", &new_score);
                if (new_score < MIN_SCORE || new_score > MAX_SCORE) {
                    printf("잘못된 값입니다. 다시 입력하세요.\n");
                }
            } while (new_score < MIN_SCORE || new_score > MAX_SCORE);

            // 점수 업데이트
            scores[candidate_index][field_index] = new_score;
            // 총점 재계산
            int total = 0;
            for (int j = 1; j <= NUM_FIELDS; j++) {
                total += scores[candidate_index][j];
            }
            scores[candidate_index][NUM_FIELDS + 1] = total;

        } while (1);  // '0'을 입력할 때까지 계속 반복
    }

    // 최종 후보 선발 (총점을 기준으로 상위 4명을 출력)
    printf("=======================================\n");
    printf("후보 선발 결과 집계 중 ...\n");
    printf("=======================================\n");

    // 정렬 및 출력 부분은 따로 구현 가능
    printf("#######################################\n");
    printf("# 밀리웨이즈의 멤버가 된 걸축하합니다!  #\n");
    printf("#######################################\n");

    return 0;
}
