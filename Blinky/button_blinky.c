#include <stdio.h>    // printf, perror
#include <stdlib.h>   // exit
#include <unistd.h>   // usleep, lseek
#include <fcntl.h>    // open
#include <string.h>   // strlen, snprintf

#define BUTTON_GPIO 72

int main(void) {
    int button_fd;
    char buf[2];
    char path[64];
/*
    // 1) Export the GPIOs by writing their numbers to /sys/class/gpio/export

    int export_fd = open("/sys/class/gpio/export", O_WRONLY);
    if (export_fd < 0) {
        perror("open export");
        return 1;
    }

    // Export button GPIO
    snprintf(buf, sizeof(buf), "%d", BUTTON_GPIO); // convert number to text
    if (write(export_fd, buf, strlen(buf)) < 0) {
        // If this fails, it might already be exported; we just warn
        perror("export button");
    }
    close(export_fd);

    // Wait a bit so the kernel creates the gpio directories
    usleep(100000); // 100 ms

    // 2) Set directions
*/
 // Button as input: write "in" to /sys/class/gpio/gpioX/direction
    snprintf(path, sizeof(path), "/sys/class/gpio/gpio%d/direction", BUTTON_GPIO);
    int dir_fd = open(path, O_WRONLY);
    if (dir_fd < 0) {
        perror("open button direction");
        return 1;
    }
    if (write(dir_fd, "in", 2) < 0) {
        perror("write button direction");
        close(dir_fd);
        return 1;
    }
    close(dir_fd);

    // 3) Open the button "value" file for reading
    snprintf(path, sizeof(path), "/sys/class/gpio/gpio%d/value", BUTTON_GPIO);   
    button_fd = open(path, O_RDONLY);
    if (button_fd < 0) {
    perror("open button value");
        return 1;
    }
// USR 2 LED path ( no export needed)
const char *led_path = "/sys/class/leds/beaglebone:green:usr1/brightness";
    printf("Simple button->LED program running. Press Ctrl+C to stop.\n");

    // 4) Main loop: read button, set LED
    while (1) {
        // Read button value ('0' or '1')
        lseek(button_fd, 0, SEEK_SET); // go to start of file before each read
        if (read(button_fd, buf, 1) < 0) {
            perror("read button");
            close(button_fd);
            return 1;
        }

        // Prepare LED value path

        int led_fd = open(led_path,O_WRONLY);
        if (led_fd < 0) {
            perror("open usr2 brightness");
            close(button_fd);
            return 1;
        }

        if (buf[0] == '1') {
            // Button pressed -> turn LED on
            write(led_fd, "1", 1);
        } else {
            // Button not pressed -> turn LED off
            write(led_fd, "0", 1);
        }

        close(led_fd);

        // Small delay so we don’t read too fast
        usleep(50000); // 50 ms
    }

    close(button_fd);
    return 0;
}
