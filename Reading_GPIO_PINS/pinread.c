#include<unistd.h>
C:\Users\mapatel>;
FILE *LED = NULL;
char *GPIO_27 = "/sys/class/gpio/gpio27/value";
char *LED_60 = "/sys/class/gpio/gpio60/value";
int read_gpio_27 (){
char val;
   if(GPIO = fopen(GPIO_27,"r")){
       fread(&val,1,1,GPIO);
       fclose(GPIO);
   }
   return val;
}
char uval
int main() {
     int num_reads = 200;
     int gpio;
printf("\nThis Programme provides output for the from any pin you desire");
printf("\n kindly select pin :");
scanf("%d",&gpio);
if(gpio = 27){
for(int i=0;i<=num_reads;i++){
    printf("The output is :%c\n",read_gpio_27());
usleep(2000000);
  }
}
    return 0;
}
