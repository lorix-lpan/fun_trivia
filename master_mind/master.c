#include<stdio.h>
#include<stdlib.h>

void game(int,int);

int main(void){
   char choice,choose;
   int num,max;
   system("clear");
   while(1){
   printf("\t1.Start\n\t2.How to play\n\t3.Quit\n");
   printf("Please choose what to do: ");
   choose=getchar();
   getchar();
   switch(choose){
      case '1':
	      printf("Start the game?(y/n): ");
	      choice=getchar();
	      getchar();
	        if(choice=='y'||choice=='Y'){
	          printf("\nPlease input the number of digits(max9): ");
	          scanf("%d",&num);
	          getchar();
	          printf("\nPlease input the max number will appear: ");
	          scanf("%d",&max);
	          getchar();
	          if(max>=num){
	            game(num,max);
	          } else {
	            printf("Invalid input");
	          }
	        }
	        break;
	    case '2':
	      printf("This game is the same as the game mastermind\n");
	      break;
	    case '3':
	      printf("exiting\n");
	      exit(0);
	      break;
	    default:printf("Invalid argument\n");
   }
   printf("Press enter to continue: ");
   getchar();
   system("clear");
   }
}

void game(int n,int m){
   int randlist[9]={0};
   int user[9]={0};
   int i,j,temp,flag;
   for(i=0;i<n;i++){
      do{
         temp=rand()%(m+1);
	 flag=0;
	 for(j=0;j<=i;j++){
	    if(temp==randlist[j]){
	       flag++;
	    }
	 }
      } while(flag!=0);
      randlist[i]=temp;
   }
   int count=0,test=0;
   do {
      int k,a,b;
      int black=0,white=0;
      for(k=0;k<n;k++){
	 scanf("%d",&user[k]);
      }
      for(a=0;a<n;a++){
	 for(b=0;b<n;b++){
	    if(user[a]==randlist[b]&&a==b){
	       black++;
	    } else if(user[a]==randlist[b]){
	       white++;
	    } else {
	       continue;
	    }
	 }
      }
      count++;
      test=black;
      printf("Black:\t%d\nWhite:\t%d\n",black,white);
   } while(test!=n);
   printf("Good job, it took you only %d times to guess the answer",count);
   int c;
   printf("\nThe correct list is: ");
   for(c=0;c<n;c++){
      printf("%d ",randlist[c]);
   }
   printf("\n");
   getchar();
}
