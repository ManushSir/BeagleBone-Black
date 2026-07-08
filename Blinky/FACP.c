/*This program turns On LED in standard UL fire alarm fashion*/
#include <stdio.h>
#include<unistd.h>
int main (){
int a;
printf("\nThis Programme runs LED's as per your command\n");
printf("\nPlease Enter \n 1 for Temporal \n 2 for California Code\n");
scanf("%d",&a);
if( a == 1){
FILE *GPIO = NULL;
char *GPIO_60 = "/sys/class/gpio/gpio60/value";
printf("\nGPIO60 plays temporal code\n");
for (int i=0;i<10;i++){
for (int i=0;i<3;i++){
if(GPIO = fopen(GPIO_60,"w")){
fwrite("1",1,1,GPIO);
fclose(GPIO);
usleep(500000);
}
if(GPIO = fopen(GPIO_60,"w")){
fwrite("0",1,1,GPIO);
fclose(GPIO);
usleep(500000);
}
}
usleep(1500000);
}
}
else if(a==2){
printf("\nThe system is playing California Code\n");
FILE *GPIO = NULL;
char *GPIO_60 = "/sys/class/gpio/gpio60/value";
for (int i=0;i<10;i++){
if(GPIO = fopen(GPIO_60,"w")){
fwrite("1",1,1,GPIO);
fclose(GPIO);
usleep(5000000);
}
if(GPIO = fopen(GPIO_60,"w")){
fwrite("0",1,1,GPIO);
fclose(GPIO);
usleep(10000000);
}
}
}
else {(printf("\nSorry Wrong Input"));}
return 0;
}
