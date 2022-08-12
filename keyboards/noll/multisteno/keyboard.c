#include <ch.h>
#include <hal.h>
#include "util.h"
#include "quantum.h"

#ifdef BOARD_STM32_F103_STM32DUINO

// this is fairly unnecessary
#define RED_LED_OFF()    do { palClearPad(GPIOA, 0) ;} while (0) // GPIOA1 is right green LED
#define RED_LED_ON()   do { palSetPad(GPIOA, 0); } while (0)
#define RED_LED_TGL()   do { palTogglePad(GPIOA, 0); } while (0)

#define GREEN_LED_OFF()    do { palClearPad(GPIOA, 1) ;} while (0) // GPIOA1 is right green LED
#define GREEN_LED_ON()   do { palSetPad(GPIOA, 1); } while (0)
#define GREEN_LED_TGL()   do { palTogglePad(GPIOA, 1); } while (0)

#else
#define LED_ON()
#define LED_OFF()
#define LED_TGL()
#endif

void keyboard_pre_init_user(void){
    
    // Initialize LED pins to correct setting
    palSetPadMode(GPIOA, 0, PAL_MODE_OUTPUT_PUSHPULL); // 6U correct
    palSetPadMode(GPIOA, 1, PAL_MODE_OUTPUT_PUSHPULL); // 6U correct

}

void matrix_init_kb(void){

    RED_LED_ON();
    GREEN_LED_ON();
    wait_ms(500);
    RED_LED_OFF();
    //GREEN_LED_OFF();

}
