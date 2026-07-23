#include<stdio.h>
#include<unistd.h>
FILE *EXPO = NULL;
char *PWM_P9 = "/sys/class/pwm/pwmchip3"
char *PWM_P8 = "/sys/class/pwm/pwmchip6"
char *PWM_P9_14 = "/sys/class/pwm/pwmchip3/pwm0"
char *PWM_P9_16 = "/sys/class/pwm/pwmchip3/pwm1"
char *PWM_P8_13 = "/sys/class/pwm/pwmchip6/pwm1"
char *PWM_P8_19 = "/sys/class/pwm/pwmchip6/pwm0"

int pin_export_P9(void){
EXPO = fopen(PWM_P9,"w");
if(EXPO == NULL)
{
perror("Failed to export the pin");
return -1;
}
fwrite("echo 0 | sudo tee export",1,100,EXPO);
fclose(EXPO);
return 0 ;
}

int pin_export_P8(void){
EXPO = fopen(PWM_P8,"w");
if(EXPO == NULL)
{
perror("Failed to export the pin");
return -1;
}
fwrite("echo 0 | sudo tee export",1,100,EXPO);
fclose(EXPO);
return 0 ;
}
