/*
 * car Raspberry Pi Pico
 *
 * @version     1.0.0
 * @author     Justin Berkshire
 * @copyright   2022
 * @licence     MIT
 *
 */
#include "main.h"
using namespace std;


motor motor_left(5, 2);
motor motor_right(3, 4);

void motorActByPress(int pressed) {
    if(pressed == 0) {
        motor_left.forward();
        motor_right.forward();
    } else if (pressed == 1) {
        motor_right.reverse();
        motor_left.forward();
    } else if (pressed == 2) {
        motor_right.forward();
        motor_left.reverse();
    } else if (pressed == 3) {
        motor_right.reverse();
        motor_left.reverse();
    } else {
        printf("That wasn't a valid press");
    }
};

void stahp() {
    motor_left.off();
    motor_right.off();
};

int main()
{

    const uint LED = PICO_DEFAULT_LED_PIN;

    gpio_init(LED);

    gpio_set_dir(LED, GPIO_OUT);

    gpio_put(LED, 1);

    init_directionPad(11, 13, 10, 12);

    while (true)
    {
        for(int i = 0; i < 4; i++) {
            if(presses[i] > 0) {
                motorActByPress(i);
                sleep_ms(1500);
                stahp();
                presses[i]--;
            }
        }
    }

    return 0;
}
