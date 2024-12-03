#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

int main(void)
{
    printf("Enter some words\n");
    fflush(stdout);

    Queue queue;
    initQueue(&queue);

    char word[WORDLENGTH];

    while (fgets(word, WORDLENGTH, stdin) != NULL) {
        offer(&queue, word);
    }

    char * outWord = poll(&queue);
    while (outWord != NULL) {
        printf("%s\n", outWord);
        free(outWord);
        outWord = poll(&queue);
    }

    clearQueue(&queue);

    return 0;
}
