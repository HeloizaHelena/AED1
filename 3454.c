#include <stdio.h>
#include <string.h>

int main() {
    char s[5];
    scanf("%s", s);

    int x = 0, o = 0;
    for (int i = 0; i < 3; i++) {
        if (s[i] == 'X') x++;
        else if (s[i] == 'O') o++;
        else { printf("?\n"); return 0; }
    }

    if (!(x == o || x == o + 1)) {
        printf("?\n");
        return 0;
    }

    int winX = (s[0]=='X' && s[1]=='X') || (s[1]=='X' && s[2]=='X');
    int winO = (s[0]=='O' && s[1]=='O') || (s[1]=='O' && s[2]=='O');

    if (winX && winO) {
        printf("?\n");
        return 0;
    }

    if (winX) {
        if (x != o + 1) {
            printf("?\n");
            return 0;
        }
        printf("Alice\n");
        return 0;
    }

    if (winO) {
        if (x != o) {
            printf("?\n");
            return 0;
        }
        printf("Bob\n");
        return 0;
    }

    printf("*\n");
    return 0;
}
