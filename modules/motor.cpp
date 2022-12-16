#include "../main.h"

class motor {
    uint forwardLine;
    uint reverseLine;
    public: motor(uint lineOne, uint lineTwo) {
        
        forwardLine = lineOne;
        reverseLine = lineTwo;
        gpio_init(forwardLine);
        gpio_init(reverseLine);
        gpio_set_dir(forwardLine, GPIO_OUT);
        gpio_set_dir(reverseLine, GPIO_OUT);
        gpio_put(forwardLine, 0);
        gpio_put(reverseLine, 0);

    }
    public: void forward() {
        gpio_put(forwardLine, 1);
        gpio_put(reverseLine, 0);
    }
    public: void reverse() {
        gpio_put(reverseLine, 1);
        gpio_put(forwardLine, 0);
    }
    public: void off() {
        gpio_put(forwardLine, 0);
        gpio_put(reverseLine, 0);
    }
};