#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main (){
FILE *LED = NULL;
char *LEDPATH1 = "/sys/class/leds/beaglebone:green:usr3/brightness";
for  (int i=0;i<=10;i++)
{
for (int j=0;j<=10;j++){
if(LED =fopen(LEDPATH1,"w")){
fwrite("1",1,1,LED);
fclose(LED);
}
}
sleep(2);
}
return 0;
}
