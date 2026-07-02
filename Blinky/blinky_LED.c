#include <stdio.h>
int main (void)
{
FILE *LED = NULL;
char *LED_PATH1 = "/sys/class/leds/beaglebone:green:usr3/brightness";
char *LED_PATH2 = "/sys/class/leds/beaglebone:green:usr2/brightness";
char *LED_PATH3 = "/sys/class/leds/beaglebone:green:usr1/brightness";
for (int i=0 ; i<=5 ;i++){

if(LED =fopen(LED_PATH1,"r+")){
fwrite("1",1,1,LED);
fclose(LED);

}
sleep(5);
}
for (int i=5 ;i<=10;i++){
if(LED =fopen(LED_PATH2,"r+")){
fwrite("1",1,1,LED);
fclose(LED);}
sleep(5);
}
return 0;
}
