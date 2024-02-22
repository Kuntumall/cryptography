#include <stdio.h>
#include <string.h>
#include<conio.h>
#include <ctype.h>

int main()
{
char plain[10], cipher[10];
int key,i,length;
int result;

printf("\n Enter the plain text:");
scanf("%s", plain);
printf("\n Enter the key value:");
scanf("%d", &key);
printf("\n \n \t PLAIN TEXt: %s",plain);
printf("\n \n \t ENCRYPTED TEXT: ");
for(i = 0, length = strlen(plain); i < length; i++)
{
cipher[i]=plain[i] + key;
printf("%c", cipher[i]);
}
printf("\n \n AFTER DECRYPTION :%c ",plain[i]);
}
