#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
    long long credit_number;

    printf("Enter the credit card number: ");

    scanf("%lld", &credit_number);

    int nums[16] = {0}, count = 0;

    char card_type[20];

    while (credit_number > 0)
    {
        nums[count] = credit_number % 10;
        credit_number /= 10;
        count++;
    }

    if(nums[count - 1] == 4 && (count == 13 || count == 16))
    {
        strcpy(card_type, "VISA");
    }
    else if (nums[count - 1] == 5 && (nums[count - 2] == 1 || nums[count - 2] == 2 || nums[count - 2] == 3 || nums[count - 2] == 4 || nums[count - 2] == 5  ) && (count == 16))
    {
        strcpy(card_type, "MASTERCARD");
    }
    else if(nums[count - 1] == 3 && (nums[count - 2] == 4 || nums[count - 2] == 7) && (count == 15))
    {
        strcpy(card_type, "AMEX");
    }
    else
    {
        strcpy(card_type, "INVALID");
    }

    for (int i = 0; i < count; i++)
    {
        if(i % 2 == 1)
        {
            nums[i] *= 2;
            if (nums[i] > 9)
            {
                nums[i] = nums[i] % 10 + nums[i] / 10;
            }
        }
    }

    int sum = 0;

    for (int i = 0; i < count; i++)
    {
        sum += nums[i];
    }

    if (sum % 10 == 0)
    {
        printf("%s\n", card_type);

        getch();
    }
    else
    {
        printf("INVALID\n");

        getch();
    }

    return 0;
}