#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main (){
FILE *LED = NULL; /*Defining the name of the file as LED and defining it as NULL.*/
char *LEDPATH1 = "/sys/class/leds/beaglebone:green:usr3/brightness";
for  (int i=0;i<=10;i++)
{
for (int j=0;j<=10;j++){
if(LED =fopen(LEDPATH1,"w")){
fwrite("1",1,1,LED);/*fwrite( const void *ptr, size_t size, size_t nmemb, FILE *stream ); Write 1 element of 1 byte from the memory starting at "1" into the file LED.*/
fclose(LED);
}
}
sleep(2);
}
return 0;
}
