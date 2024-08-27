#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *increment(const char *num, int length)
{
    char *result = (char *)malloc((length + 2) * sizeof(char)); 
    int carry = 1;
    for (int i = length - 1; i >= 0; --i)
    {
        int value = (num[i] - '0') + carry;
        if (value == 10)
        {
            result[i + 1] = '0';
            carry = 1;
        }
        else
        {
            result[i + 1] = (char)(value + '0');
            carry = 0;
        }
    }
    if (carry)
    {
        result[0] = '1';
        result[length + 1] = '\0'; 
    }
    else
    {
        memcpy(result, result + 1, length + 1); 
    }
    return result;
}

int main()
{
    int N;
    scanf("%d", &N);

    char *digits = (char *)malloc((N + 1) * sizeof(char)); 
    for (int i = 0; i < N; ++i)
    {
        scanf(" %c", &digits[i]); 
    }
    digits[N] = '\0'; 

    for (int len = 1; len <= N; ++len)
    {
        char *A = (char *)malloc((len + 1) * sizeof(char));
        strncpy(A, digits, len);
        A[len] = '\0'; 

        int valid = 1;
        int pos = len;
        char *num = A;
        while (pos < N && valid)
        {
            char *next_num = increment(num, strlen(num));
            for (int i = 0; i < strlen(next_num); ++i)
            {
                if (pos + i >= N || digits[pos + i] != next_num[i])
                {
                    valid = 0;
                    break;
                }
            }
            if (num != A)
            { 
                free(num);
            }
            num = next_num;
            pos += strlen(num);
        }

        if (valid)
        {
            printf("%s\n", A); 
            free(A);
            break;
        }

        free(A);
    }

    free(digits);
    return 0;
}
