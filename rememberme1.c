#include <stdio.h>

#define MAX_CANDIDATES 5
#define MAX_MESSAGE_LENGTH 100
#define MAX_NAME_LENGTH 50

int main(void)
{
    /* 1차원 배열로 불합격 후보자 데이터 정의 */
    const char memorial01_arr[] =
        "Alice,alice@example.com;Bob,bob@example.com;"
        "Charlie,charlie@example.com;Diana,diana@example.com;"
        "Eve,eve@example.com";

    /* 1차원 배열로 롤링페이퍼 데이터 저장 */
    char rollingpp01_arr[MAX_CANDIDATES][MAX_MESSAGE_LENGTH] = {""};

    /* 합격 여부 저장 (0: 불합격, 1: 합격) */
    int accepted_candidates[MAX_CANDIDATES] = {0};

    int choice;

    while (1)
    {
        printf("\n=== 기억하기 시스템 ===\n");
        printf("1. 합격 여부 입력\n");
        printf("2. 롤링페이퍼 작성\n");
        printf("3. 롤링페이퍼 보기\n");
        printf("4. 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            /* 합격 여부 입력 */
            printf("\n=== 합격 여부 입력 ===\n");
            for (int i = 0; i < MAX_CANDIDATES; i++)
            {
                printf("후보자 %d를 합격 처리하려면 1을, 불합격 처리하려면 0을 입력하세요: ", i + 1);
                scanf("%d", &accepted_candidates[i]);
                if (accepted_candidates[i] != 0 && accepted_candidates[i] != 1)
                {
                    printf("잘못된 입력입니다. 다시 시도하세요.\n");
                    i--; /* 다시 입력 */
                }
            }
        }
        else if (choice == 2)
        {
            /* 롤링페이퍼 작성 */
            int candidate_index;
            char message[MAX_MESSAGE_LENGTH];
            char name[MAX_NAME_LENGTH] = {0};
            int i = 0, count = 0;
            const char *start = memorial01_arr;

            printf("\n=== 롤링페이퍼 작성 ===\n");
            printf("메시지를 작성할 후보자 번호를 입력하세요 (1-%d, 종료: 0): ", MAX_CANDIDATES);
            scanf("%d", &candidate_index);

            if (candidate_index == 0)
            {
                continue; /* 종료 */
            }

            if (candidate_index < 1 || candidate_index > MAX_CANDIDATES)
            {
                printf("잘못된 번호입니다.\n");
                continue;
            }

            if (accepted_candidates[candidate_index - 1] == 1)
            {
                printf("해당 후보자는 합격자로 메시지를 작성할 수 없습니다.\n");
                continue;
            }

            /* 이름 추출 */
            while (*start)
            {
                if (*start == ';')
                {
                    if (count == candidate_index - 1)
                    {
                        strncpy(name, memorial01_arr + i, start - (memorial01_arr + i));
                        name[start - (memorial01_arr + i)] = '\0'; /* 문자열 끝 */
                        break;
                    }
                    count++;
                    i = start - memorial01_arr + 1;
                }
                start++;
            }

            printf("메시지를 입력하세요: ");
            getchar(); /* 입력 버퍼 비우기 */
            fgets(message, MAX_MESSAGE_LENGTH, stdin);

            /* 메시지 저장 */
            snprintf(rollingpp01_arr[candidate_index - 1], MAX_MESSAGE_LENGTH, "[%s]: %s", name, message);
            printf("메시지가 저장되었습니다.\n");
        }
        else if (choice == 3)
        {
            /* 롤링페이퍼 보기 */
            int candidate_index;
            char name[MAX_NAME_LENGTH] = {0};
            int i = 0, count = 0;
            const char *start = memorial01_arr;

            printf("\n=== 롤링페이퍼 보기 ===\n");
            printf("후보자 번호를 입력하세요 (1-%d): ", MAX_CANDIDATES);
            scanf("%d", &candidate_index);

            if (candidate_index < 1 || candidate_index > MAX_CANDIDATES)
            {
                printf("잘못된 번호입니다.\n");
                continue;
            }

            /* 이름 추출 */
            while (*start)
            {
                if (*start == ';')
                {
                    if (count == candidate_index - 1)
                    {
                        strncpy(name, memorial01_arr + i, start - (memorial01_arr + i));
                        name[start - (memorial01_arr + i)] = '\0'; /* 문자열 끝 */
                        break;
                    }
                    count++;
                    i = start - memorial01_arr + 1;
                }
                start++;
            }

            printf("후보자 %s에 대한 메시지:\n%s\n", name,
                   rollingpp01_arr[candidate_index - 1][0] ? rollingpp01_arr[candidate_index - 1] : "메시지가 없습니다.");
        }
        else if (choice == 4)
        {
            /* 종료 */
            break;
        }
        else
        {
            printf("잘못된 입력입니다. 다시 시도하세요.\n");
        }
    }

    return 0;
}
