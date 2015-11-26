#include<stdio.h>

void string_cat(char* arr1,char* arr2);

void print_string(char* arr);

int main(void){
  char string1[20]={"Hello"};
  char* string2={" World"};
  string_cat(string1,string2);
  print_string(string1);
  return 0;
}

void string_cat(char* arr1,char* arr2){
  while(*arr1!='\0'){
    arr1++;
  }
  while(*arr2!='\0'){
    *arr1=*arr2;
    arr1++;
    arr2++;
  }
  *arr1='\0';
}

void print_string(char* arr){
  printf("%s\n",arr);
}
