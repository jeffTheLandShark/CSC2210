#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[] = "CSC2210";
    char *ptr = name;

    printf("address of name is %x\n", ptr);

    char anotherName[] = {'a', 'b', 'c', '\0'};
    // char anotherName[] = {'a', 'b', 'c'};
    char *ptr2 = anotherName;

    printf("name %s \n", name);
    printf("anotherName %s \n", anotherName);

    char nameCopy[7];
    char *ptr3 = nameCopy;
    printf("address of nameCopy %x\n", ptr3);

    int lengthName = strlen(name);
    int lengthNameCopy = strlen(nameCopy);
    printf("lengthNameCopy %d \n", lengthNameCopy);

    strcpy(nameCopy, "CSC2210");
    printf("lengthName %d \n", lengthName);
    lengthNameCopy = strlen(nameCopy);
    printf("lengthNameCopy %d \n", lengthNameCopy);

    int same = strcmp(nameCopy, "CSC2210");
    printf("same %d \n", same);

    printf("anotherName %s \n", anotherName);

}
