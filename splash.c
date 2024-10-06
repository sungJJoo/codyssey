#include <stdio.h>
#include <stdlib.h> // system 함수 사용

void clear_screen() {
    #ifdef _WIN32
        system("cls"); 
    #endif
}

void print_splash_screen(char *name, char *date) {
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        if (i == 1) printf("                         [마그라테아 ver 0.1]                               ");
        if (i == 2) printf("**   풀 한 포기 없는 황무지에서 반짝이는 행성을 만들내는 곳 마그라테아,            ");
        if (i == 3) printf("***   사람들이 보지 못하는 잠재력을 찾고 전문가의 손길을 더해 보석을 빗는 곳,       ");
        if (i == 4) printf("****    마그라테아에 오신걸 환영합니다.\"                                         ");
        if (i == 5) printf("*****                                                                          ");
        for (int j = 5; j >= i; j--) {
            printf("*");
        }
        printf("\n");
    }
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("[사용자]: %s                                   [실행 시간]: %s\n", name, date);
    printf("================================================================================\n");
}

void delay_3_seconds() {
    #ifdef _WIN32
        system("timeout /t 3 >nul");  // 3초 대기
    #endif
}

int main() {
    char name[50];
    char date[11]; // yyyy-mm-dd 형식에 맞추기 위해 11자리 문자열 배열
    
    // 사용자로부터 이름과 날짜를 입력받음
    printf("[현재 날짜를 \"yyyy-mm-dd\" 형식으로 입력하세요]: ");
    scanf("%s", date);
    printf("[당신의 이름을 입력하세요]: ");
    scanf("%s", name);
    
    printf("**입력이 정상적으로 처리되었습니다.**\n");

    delay_3_seconds(); // 3초 대기
    clear_screen(); // 화면 지우기

    print_splash_screen(name, date); // 스플래시 화면 출력
    
    return 0;
}
