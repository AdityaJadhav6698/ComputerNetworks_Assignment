#include <stdio.h>
#include <string.h>

int main()
{
    char data[100], stuffed[200];
    int i, j = 0, count = 0;

    printf("Enter binary data: ");
    scanf("%s", data);

    // Add starting flag
    strcpy(stuffed, "01111110");
    j = strlen(stuffed);

    for(i = 0; data[i] != '\0'; i++)
    {
        stuffed[j++] = data[i];

        if(data[i] == '1')
            count++;
        else
            count = 0;

        if(count == 5)
        {
            stuffed[j++] = '0';
            count = 0;
        }
    }

    // Add ending flag
    strcpy(&stuffed[j], "01111110");

    printf("\nStuffed Data: %s", stuffed);

    return 0;
}
