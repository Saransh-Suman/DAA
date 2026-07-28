#include <stdio.h>
#include <string.h>
#define MAX 256
// Shift table function
void shiftTable(char pattern[], int table[])
{
    int m = strlen(pattern);
    // Initialize all values with pattern length
    for (int i = 0; i < MAX; i++)
        table[i] = m;
    // Fill actual shift values
    for (int j = 0; j <= m - 2; j++)
        table[(unsigned char)pattern[j]] = m - 1 - j;
}
// Horspool function
int horspool(char text[], char pattern[])
{
    int table[MAX];
    int n = strlen(text);
    int m = strlen(pattern);
    shiftTable(pattern, table);
    int i = m - 1;
    while (i <= n - 1)
    {
        int k = 0;
        // Match from right to left
        while (k <= m - 1 && pattern[m - 1 - k] == text[i - k])
            k++;
        if (k == m)
            return i - m + 1; // Match found
        i += table[(unsigned char)text[i]];
    }
    return -1; // No match
}
// Main function
int main()
{
    char text[100], pattern[100];
    printf("Enter text: ");
    scanf("%[^\n]", text);
    printf("Enter pattern: ");
    scanf("%s", pattern);
    int pos = horspool(text, pattern);
    if (pos >= 0)
        printf("Pattern found at position: %d\n", pos);
    else
        printf("Pattern not found\n");
    return 0;
}