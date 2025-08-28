#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE *f1, *f2;
    char line1[100], line2[100];

    f1 = fopen("mydetails.txt", "w");
    if (f1 == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    fprintf(f1, "Name: Rahul Kandwal\n");
    fprintf(f1, "Age: 21\n");
    fprintf(f1, "City: Dehradun\n");
    fclose(f1);
    f2 = fopen("frienddetails.txt", "w");
    if (f2 == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    fprintf(f2, "Name: XYZ\n");
    fprintf(f2, "Age: 21\n");
    fprintf(f2, "City: Dehradun\n");
    fclose(f2);
    f1 = fopen("mydetails.txt", "r");
    f2 = fopen("frienddetails.txt", "r");

    if (f1 == NULL || f2 == NULL)
    {
        printf("Error opening file for reading\n");
        exit(1);
    }
    printf("\nMatching lines in both files:\n");
    while (fgets(line1, sizeof(line1), f1) != NULL)
    {
        rewind(f2);
        while (fgets(line2, sizeof(line2), f2) != NULL)
        {
            if (strcmp(line1, line2) == 0)
            {
                printf("%s", line1);
            }
        }
    }
    fclose(f1);
    fclose(f2);
    return 0;
}
