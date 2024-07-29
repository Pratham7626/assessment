/*Over Here, take string input from user and perform string operations listed below :
. reverse a string
. Concatenation
. Palindrome
. Copy a string
. Length of the string
. Frequency of character in s string
. Find number of vowels and consonants
. Find number of blank spaces and digits
As given above perform the operation as per user’s choice
If user will not select any of the above then it should not perform any operation and
give an appropriate user friendly message
After performing the operation ask the user if the user wants to continue or not ?*/



#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
void reverseString(char str[]);
void concatenateStrings(char str1[], char str2[], char result[]);
int isPalindrome(char str[]);
void copyString(char src[], char dest[]);
int stringLength(char str[]);
void charFrequency(char str[]);
void countVowelsConsonants(char str[], int *vowels, int *consonants);
void countBlanksDigits(char str[], int *blanks, int *digits);

int main() {
    char str[100], str2[100], result[200];
    int choice, continueChoice;
    int vowels, consonants, blanks, digits;

    do {
        // Input string from user
        printf("Enter a string: ");
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0'; // Remove newline character

        // Display operation choices
        printf("\nChoose an operation:\n");
        printf("1. Reverse a string\n");
        printf("2. Concatenate two strings\n");
        printf("3. Check if a string is a palindrome\n");
        printf("4. Copy a string\n");
        printf("5. Length of the string\n");
        printf("6. Frequency of characters in the string\n");
        printf("7. Find number of vowels and consonants\n");
        printf("8. Find number of blank spaces and digits\n");
        printf("9. Exit\n");

        // Get user choice
        printf("Enter your choice (1-9): ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character left by scanf

        switch (choice) {
            case 1:
                reverseString(str);
                printf("Reversed string: %s\n", str);
                break;

            case 2:
                printf("Enter another string to concatenate: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = '\0'; // Remove newline character
                concatenateStrings(str, str2, result);
                printf("Concatenated string: %s\n", result);
                break;

            case 3:
                if (isPalindrome(str)) {
                    printf("The string is a palindrome.\n");
                } else {
                    printf("The string is not a palindrome.\n");
                }
                break;

            case 4:
                copyString(str, result);
                printf("Copied string: %s\n", result);
                break;

            case 5:
                printf("Length of the string: %d\n", stringLength(str));
                break;

            case 6:
                charFrequency(str);
                break;

            case 7:
                countVowelsConsonants(str, &vowels, &consonants);
                printf("Number of vowels: %d\n", vowels);
                printf("Number of consonants: %d\n", consonants);
                break;

            case 8:
                countBlanksDigits(str, &blanks, &digits);
                printf("Number of blank spaces: %d\n", blanks);
                printf("Number of digits: %d\n", digits);
                break;

            case 9:
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice. Please select a number between 1 and 9.\n");
                break;
        }

        // Ask user if they want to continue
        printf("\nDo you want to perform another operation? (1 for yes, 0 for no): ");
        scanf("%d", &continueChoice);
        getchar(); // To consume the newline character left by scanf

    } while (continueChoice == 1);

    printf("Exiting the program.\n");
    return 0;
}

// Function definitions
void reverseString(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void concatenateStrings(char str1[], char str2[], char result[]) {
    strcpy(result, str1);
    strcat(result, str2);
}

int isPalindrome(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

void copyString(char src[], char dest[]) {
    strcpy(dest, src);
}

int stringLength(char str[]) {
    return strlen(str);
}

void charFrequency(char str[]) {
    int freq[256] = {0};
    for (int i = 0; str[i]; i++) {
        freq[(unsigned char)str[i]]++;
    }

    printf("Character frequency:\n");
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            printf("'%c': %d\n", i, freq[i]);
        }
    }
}

void countVowelsConsonants(char str[], int *vowels, int *consonants) {
    *vowels = 0;
    *consonants = 0;
    for (int i = 0; str[i]; i++) {
        if (isalpha(str[i])) {
            char ch = tolower(str[i]);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                (*vowels)++;
            } else {
                (*consonants)++;
            }
        }
    }
}

void countBlanksDigits(char str[], int *blanks, int *digits) {
    *blanks = 0;
    *digits = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ') {
            (*blanks)++;
        } else if (isdigit(str[i])) {
            (*digits)++;
        }
    }
}

