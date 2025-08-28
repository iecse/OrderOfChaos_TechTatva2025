#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100005


int numStack[MAX_LEN], numTop = -1;

char *strStack[MAX_LEN];
int strTop = -1;


void pushNum(int val) {
    numStack[++numTop] = val;
}

int popNum() {
    return numStack[numTop--];
}


void pushStr(char *s) {
    strStack[++strTop] = s;
}


char* popStr() {
    return strStack[strTop--];
}


char* decodeScroll(char *s) {
    char *currStr = (char*)calloc(MAX_LEN, sizeof(char));
    int currNum = 0;
    int i = 0;

    while (s[i]) {
        if (isdigit(s[i])) {
            currNum = currNum * 10 + (s[i] - '0'); // build number
        } else if (s[i] == '[') {
            pushNum(currNum);
            currNum = 0;
            pushStr(currStr);
            currStr = (char*)calloc(MAX_LEN, sizeof(char));
        } else if (s[i] == ']') {
            int repeat = popNum();
            char *prevStr = popStr();
            char *newStr = (char*)calloc(MAX_LEN, sizeof(char));
            strcpy(newStr, prevStr);
            for (int j = 0; j < repeat; j++) {
                strcat(newStr, currStr);
            }
            free(currStr);
            currStr = newStr;
            free(prevStr);
        } else {
            int len = strlen(currStr);
            currStr[len] = s[i];
            currStr[len + 1] = '\0';

        }
        i++;
    }
    return currStr;
}

int main() {
    char s[MAX_LEN];
    printf("Enter the magical scroll: ");
    scanf("%s", s);

    char *decoded = decodeScroll(s);
    printf("Decoded spell: %s \n", decoded);

    free(decoded);
    return 0;
}

