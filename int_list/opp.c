#include<stdio.h>

void stack(int *n){
   if(*n){
      stack(n+1);
      printf("%d ",*n);
   }
}

int expo(int n,int exp){
        if(exp==0){
                return n;
        } else {
                return 10*expo(n,exp-1);
        }
}

int main(void){
        char list[100];
        int counter=0;
        char temp;
        do{
                scanf("%c",&temp);
                if(temp=='\n'){
	                       break;
                }
                if(temp==' '){
	                        list[counter]='-';
	                        counter++;
	                        continue;
                }
	list[counter]=temp;
	counter++;
        }while(1);
        int intlist[100]={0};
        char revlist[100];
        int i;
        for(i=0;i<counter;i++){
                revlist[i]=list[counter-1-i];
        }
        revlist[counter]='*';
        int tet=0,sum,exp,cot=0,temp1;
        do{
                exp=0;
                sum=0;
                while(revlist[tet]!='-'){
	                       if(revlist[tet]=='*'){
	                                      break;
	                        }
	 temp1=revlist[tet]-'0';
	 sum+=expo(temp1,exp);
	 exp++;
	 tet++;
      }
      intlist[cot]=sum;
      cot++;
      if(revlist[tet]=='-'){
	 tet++;
	 continue;
      }
   }while(revlist[tet]!='*');
   printf("Your list: ");
   stack(intlist);
   printf("\n");
   int sum2=0;
   for(i=0;i<100;i++){
      sum2+=intlist[i];
   }
   printf("The sum of the integers is: %d\n",sum2);
   return 0;
}
