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


#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main() 
{
 
       char  str1[100], str2[100],choice,ch;
        int  con,length=0,i=0,j=0,le=0,count=0,name=0,vowels = 0, consonants = 0,spaces = 0, digits = 0;

    do
	{
		str1[0] = '\0';
		str2[0] = '\0';
		ch ='\0';
		con=0;
		length=0;
		i=0;
		j=0;
		le=0;
		count=0;
		name=0;
		vowels = 0;
		consonants = 0;
		spaces = 0;
	    digits = 0;
		 
		
        printf("\nString Operations Menu:\n");
        printf("1. Reverse a string\n");
        printf("2. Concatenate two strings\n");
        printf("3. Check if a string is a palindrome\n");
        printf("4. Copy a string\n");
        printf("5. Find the length of a string\n");
        printf("6. Find the frequency of a character in a string\n");
        printf("7. Find the number of vowels and consonants in a string\n");
        printf("8. Find the number of blank spaces and digits in a string\n");
        printf("9. Exit\n");

        printf("Enter your choice (1-9): ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter a string to reverse: ");
                scanf(" %[^\n]s", str1);
                
                for(i=0; str1[i]!='\0';i++) 
                {
                	length++;
                }
                printf("\n reverce string :");
                for(i=length;i>=0;i--)
                {
                	printf("%c",str1[i]);
				}
				
                break;
            case '2':
                printf("Enter the first string: ");
                scanf(" %[^\n]s", str1);
                printf("Enter the second string: ");
                scanf(" %[^\n]s", str2);
                strcat(str1,str2);
                printf("\n Concate String Is : %s",&str1);
                break;
            case '3':
             	printf("\n Enter Name :");
	            scanf("%s",&str1);
	while(str1[i]!='\0')	
	{
		le++;
		i++;
	}
	for(i=0;str1[i]!='\0';i++)
	{
		
		str2[i]=str1[le-1];
		le--;	
	}
	for(i=0;str2[i]!='\0';i++)
	{
		printf("%c",str2[i]);
	}
	for(i=0;str1[i]!='\0';i++)
	{
		for(j=0;str2[j]!='\0';j++)
		{
			if(str1[j]!=str2[j])
			{
				count++;
			}
		}
	}
	if(count!=0)
	{
		printf("\n Not Palindrome");
		
	}
	else
	{
		printf("\n palindrome");
	}
	
                break;
            case '4':
                printf("\nEnter a string  1: ");
                scanf(" %[^\n]s", str1);
                printf("\nEnter a string 2: ");
                scanf(" %[^\n]s", str2);
                strcpy(str1,str2);
                printf("\n string 1 %s:",str1);
                
                //code
                break;
            case '5':
                printf("Enter a string to find its length: ");
                scanf(" %[^\n]s", str1);
               // printf("Enter Name : ");
	           // scanf(" %s",&nm);

	for(i=0;str1[i]!='\0';i++)
	{
		
		name++;
	}
	printf("\n length  is : %d",name);
                //code
                break;
            case '6':
                printf("Enter a string: ");
                scanf(" %[^\n]s", str1);
                printf("Enter the character to find its frequency: ");
                scanf(" %c", &ch);
                 for (i = 0; str1[i] != '\0'; i++) 
				 {
        			if (str1[i] == ch)
					 {
           			 length++;
        			}
   				 }

             printf("Frequency of '%c' = %d\n",ch,length);
               //code
                break;
            case '7':
               printf("Enter a string: ");
               scanf(" %[^\n]s", str1);

                for (i = 0; str1[i] != '\0'; i++)
				{
                  char ch = tolower(str1[i]); 
                   if (ch >= 'a' && ch <= 'z') 
				   { 
                   if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') 
				   {
                    vowels++;
                   }    
				   else 
				   {
                     consonants++;
                   }
                   }
                }
                 printf("Number of vowels: %d\n", vowels);
                printf("Number of consonants: %d\n", consonants);
    
                //code
                break;
            case '8':
                printf("Enter a string: ");
                scanf(" %[^\n]s", str1);
                for (i = 0; str1[i] != '\0'; i++) 
				{
       				 if (isspace(str1[i]))
						{
           				 	spaces++;
        				}
					 else if (isdigit(str1[i])) 
						{
            				digits++;
        				}
   				}				

    printf("Number of blank spaces: %d\n", spaces);
    printf("Number of digits: %d\n", digits);

                //code
                break;
            case '9':
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\nDo you want to continue <<press 1 to conytinue>>");
        scanf("%d",&con);
    } while (con==1);
    
}

    
       
                
        
            

