#include <stdio.h>
#include <windows.h>

#define MAX_LENGTH 1000

int main() {

    FILE *fin;

    fin = fopen("..\\file.txt", "r");

    if (fin == NULL) {
        printf("Error occurred while opening file");
        return -1;
    }

    int maxWordLen;
    printf("Set max word length:\n");
    scanf("%d", &maxWordLen);

    char word[MAX_LENGTH];
    char c;
    int i = 0;
    int count = 0;
    while((c=getc(fin)) != EOF) {
        if (c != ' ') {
            word[i] = c;
            i++;
        } else {
            if (i < maxWordLen) {
                printf("%s\n", word);
                count++;
            }
            i = 0;
            memset(word, 0, sizeof(word));
        }
    }
    printf("Total count of words: %d", count);
    fclose(fin);
    return 0;
}
