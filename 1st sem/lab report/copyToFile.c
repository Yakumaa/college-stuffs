// 39.WAP that opens a file and copies all its content to another file.Your program should read source and destinationpath from the user.
#include<stdio.h>
#include<stdlib.h>

int main()
{
 FILE *source, *destination;
 char ch;
 source = fopen("source.txt","r");

 if(source==NULL)
 {
  printf("File error!");
  exit(1);
 }

 destination = fopen("destination.txt","w");
 if(source==NULL)
 {
  printf("File error!");
  exit(1);
 }

 do
 {
  ch = fgetc(source);
  fputc(ch, destination);
 }while(ch!=EOF);

 fclose(source);                          
 fclose(destination);

 printf("Program completed open destination.txt to view copied content.");
 return 0;
}
