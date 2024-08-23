#include<stdio.h>
#include<string.h>
#include<ctype.h>

void main()
{
printf("LEXEMES\tTOKENS");
  char token[50],c,fs[5],c_op=0,c_key=0,c_id=0,c_spc=0,c_num=0,k;
  int i=0;
  FILE *fp=fopen("input.c","r");
  c=fgetc(fp);
  while(c!=EOF){
   if(c=='/'){
   c=getc(fp);
   if(c=='/')
   {
    do{
     c=getc(fp);
    }while(c!='\n' && c!=EOF);
   }
 else{
  printf("\n/\tOPERATOR");
  c_op++;
  }
}

if(c=='"')
{
   int k=0;
   c=getc(fp);
   if(c=='%')
   {
       fs[k++]=c;
       c=getc(fp);
       if(c=='d' || c=='f' || c=='s')
       {
           fs[k++]=c;
           printf("\n%s\tFORMAT SPECIFIER",fs);
           c=getc(fp);
         }
     }
 }
 
 else if(isalpha(c) && c!=' ' && c!='\n')
 {
  i=0;
  while(isalpha(c) && c!=' ' && c!='\n')
  {
  token[i++]=c;
  c=fgetc(fp);
  }
  token[i]='\0';
  if(strcmp(token,"void")==0 || strcmp(token,"int")==0 || strcmp(token,"char")==0 || strcmp(token,"float")==0 || strcmp(token,"main")==0 || strcmp(token,"printf")==0 || strcmp(token,"scanf")==0 ) 
  {
   printf("\n%s\tKEYWORD",token);
   c_key++;
  }
 else{
   printf("\n%s\tIDENTIFIER",token);
   c_id++;
   }
 }
else if(c=='=' || c=='+' || c=='-' || c=='*'){
  printf("\n%c\tOPERATOR",c);
  c_op++;
  c=fgetc(fp);
}
else if(c=='(' || c==')' || c=='{' || c=='}' || c==';'){
  printf("\n%c\tSPECIAL CHARACTER",c);
  c_spc++;
  c=fgetc(fp);
}
else if(isdigit(c)&& c!=' ' && c!='\n'){
  i=0;
  while(isdigit(c) && c!=' ' && c!='\n')
{
 token[i++]=c;
 c=fgetc(fp);
}
 token[i]='\0';
 printf("\n%s\tNUMBER",token);
 c_num++;
}
else
{
 c=fgetc(fp);
}
}
fclose(fp);


printf("\n");
printf("OPERATOR COUNT-->%d",c_op);
printf("\nKEYWORD COUNT-->%d",c_key);
printf("\nIDENTIFIERS COUNT-->%d",c_id);
printf("\nSPECIAL CHARACTERS COUNT-->%d",c_spc);
printf("\nNUMBER COUNT-->%d",c_num);
printf("\n");

}





