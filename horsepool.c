#include <stdio.h>
#include <string.h>

#define MAX 256

// Create Shift Table
void shiftTable(char p[], int table[])
{
    int m = strlen(p);

    for(int i = 0; i < MAX; i++)
        table[i] = m;

    for(int j = 0; j < m - 1; j++)
        table[p[j]] = m - 1 - j;
}

// Horspool Function
int horspool(char text[], char pattern[])
{
    int table[MAX];
    int n = strlen(text);
    int m = strlen(pattern);

    shiftTable(pattern, table);

    int i = m - 1;

    while(i < n)
    {
        int k = 0;

        while(k < m && pattern[m - 1 - k] == text[i - k])
            k++;

        if(k == m)
            return i - m + 1;

        i = i + table[text[i]];
    }

    return -1;
}

int main()
{
    char text[100], pattern[100];

    printf("Enter text: ");
    scanf(" %[^\n]", text);

    printf("Enter pattern: ");
    scanf("%s", pattern);

    int pos = horspool(text, pattern);

    if(pos >= 0)
        printf("Pattern found at position: %d", pos);
    else
        printf("Pattern not found");

    return 0;
}