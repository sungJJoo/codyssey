#include <stdio.h>
#include <stdlib.h>

#define NUM_CANDIDATES 6 // 후보자 수 
#define NUM_FIELDS 5 // 점수 필드 수 
#define MAX_SCORE 100 // 점수 최대값
#define MIN_SCORE 10 // 점수 최소값 

int main() {
    // 후보자 정보
    char candidate_names[NUM_CANDIDATES][30] = { 
        "박지연", "Ethan Smith", 
        "Helena Silva", "Liam Wilson", 
        "Jin Park", "Alice Chen"
    };
    int candidate_ids[NUM_CANDIDATES] = {1,2,3,4,5,6}; //순서대로 박지연,Ethan Smith 

    // 후보자의 점수를 저장하는 배열 (ID, 5개의 점수, 총점)
    int scoring_sheet[NUM_CANDIDATES][NUM_FIELDS + 2] = {0}; // 모든 배열의 요소를 0으로 초기화

    char judge_name[30]; //심사자 이름
    char expertise[20]; //전문 분야

    printf("####################################\n"); //젤 처음에 나오는 출력문
    printf("#       오디션 심사 결과 입력       #\n");
    printf("####################################\n");
    
    printf("> 심사자 이름: ");
    fgets(judge_name, sizeof(judge_name), stdin); 

    printf("> 전문 분야: ");
    fgets(expertise, sizeof(expertise), stdin);

    // 전문 분야에서 개행 문자 '\n' 제거
    int len = 0; //while 문 반복 제어변수
    while (expertise[len] != '\0') { // 문자열 끝 즉 null 찾을때까지 len 증가 이러면 expertise의 길이를 알 수 있음  
        len++;
    }
    if (expertise[len - 1] == '\n') { // 구한 expertise의 길이 -1하는 이유는 ex) 음악\n 은 len 길이가 4가됨 음 1 악 2 \n 3 \0 4라서 이걸 없애주는거임
        expertise[len - 1] = '\0'; //개행 문자를 null로 처리해서 음악 으로 수정
    }

    // 전문 분야에 따른 처리: 문자열 비교
    int field_index = -1; //잘못된 전문 분야 입력 예외 처리 
    char *fields[] = {"", "음악", "댄스", "보컬", "비주얼", "전달력"};

    for (int i = 1; i <= NUM_FIELDS; i++) {
        int j = 0;
        while (fields[i][j] != '\0' && expertise[j] != '\0' && fields[i][j] == expertise[j]) {
            j++;
        }
        if (fields[i][j] == '\0' && expertise[j] == '\0') {
            field_index = i; // 여기서 for문돌면서 전문 분야 입력 받기 
            break;
        }
    }

    if (field_index == -1) { // 아무런 입력도 받지 않으면 예외 처리 
        printf("잘못된 전문 분야입니다.\n");
        return 1;  // 프로그램 종료
    }

    // 후보자에 대한 점수 입력
    for (int i = 0; i < NUM_CANDIDATES; i++) { //후보자의 수만큼 반복 
        int score;
        printf("후보자: %s\n", candidate_names[i]); //후보자 이름 배열에 들어있는걸 i 인덱스 순서대로 출력 
        do { //do-while문 사용해서 if문안에 조건은 잘못된 값일 때 경고 메시지 출력 while 조건이 같은 이유는 유효할때까지 계속 반복할려고 
            printf("%s 소양 점수 (10~100): ", expertise); //전문분야 변수 
            scanf("%d", &score); // 사용자에게 점수 입력 받기 
            if (score < MIN_SCORE || score > MAX_SCORE) {  //최소가 10점 ~ 100점이므로 and 연산자 사용해서 조건확인
                printf("잘못된 값입니다. 다시 입력하세요.\n");
            }
        } while (score < MIN_SCORE || score > MAX_SCORE); //이 조건이 true 이면 유효한 점수가 입력될때까지 무한 반복 
        scoring_sheet[i][0] = candidate_ids[i];  // ID 저장 설정되어있는 ID를 후보자에게 
        scoring_sheet[i][field_index] = score;  // 해당 분야 점수 저장 점수 필드에 점수 저장
    }

    // 총점 계산
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        int total = 0; //총점
        for (int j = 1; j <= NUM_FIELDS; j++) {
            total += scoring_sheet[i][j];  // 각 분야 점수 합산
        }
        scoring_sheet[i][NUM_FIELDS + 1] = total;  // 총점 저장
    }

    // 입력 완료 후 점수 출력
    printf("입력을 모두 완료했습니다.\n입력하신 내용을 검토하세요!\n");
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("%s: %d\n", candidate_names[i], scoring_sheet[i][field_index]);  // 해당 분야 점수 출력
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
                if (scoring_sheet[i][0] == modify_id) {
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
            scoring_sheet[candidate_index][field_index] = new_score;
            // 총점 재계산
            int total = 0;
            for (int j = 1; j <= NUM_FIELDS; j++) {
                total += scoring_sheet[candidate_index][j];
            }
            scoring_sheet[candidate_index][NUM_FIELDS + 1] = total;

        } while (1);  // '0'을 입력할 때까지 계속 반복
    }

    // 최종 후보 선발 (총점을 기준으로 상위 4명을 출력)
    printf("=======================================\n");
    printf("후보 선발 결과 집계 중 ...\n");
    printf("=======================================\n");

    // 총점을 기준으로 후보자 정렬
    for (int i = 0; i < NUM_CANDIDATES - 1; i++) {
        for (int j = 0; j < NUM_CANDIDATES - 1 - i; j++) {
            if (scoring_sheet[j][NUM_FIELDS + 1] < scoring_sheet[j + 1][NUM_FIELDS + 1]) {
                // 점수 교환
                for (int k = 0; k < NUM_FIELDS + 2; k++) {
                    int temp = scoring_sheet[j][k];
                    scoring_sheet[j][k] = scoring_sheet[j + 1][k];
                    scoring_sheet[j + 1][k] = temp;
                }
                // 이름도 교환
                char temp_name[30];
                int l = 0;
                while (candidate_names[j][l] != '\0') {
                    temp_name[l] = candidate_names[j][l];
                    l++;
                }
                temp_name[l] = '\0'; // 널 종료
                l = 0;
                while (candidate_names[j + 1][l] != '\0') {
                    candidate_names[j][l] = candidate_names[j + 1][l];
                    l++;
                }
                candidate_names[j][l] = '\0'; // 널 종료
                l = 0;
                while (temp_name[l] != '\0') {
                    candidate_names[j + 1][l] = temp_name[l];
                    l++;
                }
                candidate_names[j + 1][l] = '\0'; // 널 종료
            }
        }
    }

    // 상위 4명 출력
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, candidate_names[i]);  // 상위 후보자 출력
    }

    printf("#######################################\n");
    printf("# 밀리웨이즈의 멤버가 된 걸축하합니다!  #\n");
    printf("#######################################\n");

    return 0;
}
