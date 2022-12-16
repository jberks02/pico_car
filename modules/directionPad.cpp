#include "../main.h"

uint F = 0;
uint R = 0;
uint L = 0;
uint B = 0;
int presses[4] = {0, 0, 0, 0};

void buttonPressed(uint gpio, uint32_t events) {
    if(gpio == F) presses[0]++;
    else if(gpio == R) presses[1]++;
    else if(gpio == L) presses[2]++;
    else if(gpio == B) presses[3]++;
    else {
        printf("bad button press location unknown");
    }
};

void setup_gpio_in(uint pin) {
        gpio_init(pin);
        gpio_set_dir(pin, GPIO_IN);
        gpio_pull_down(pin);
};
    
void init_directionPad(uint forward, uint right, uint left, uint back) {
    F = forward;
    R = right;
    L = left;
    B = back;
    setup_gpio_in(F);
    setup_gpio_in(R);
    setup_gpio_in(L);
    setup_gpio_in(B);
    
    gpio_set_irq_enabled_with_callback(F, GPIO_IRQ_EDGE_FALL, true, &buttonPressed);
    gpio_set_irq_enabled(R, GPIO_IRQ_EDGE_FALL, true);
    gpio_set_irq_enabled(L, GPIO_IRQ_EDGE_FALL, true);
    gpio_set_irq_enabled(B, GPIO_IRQ_EDGE_FALL, true);
} 