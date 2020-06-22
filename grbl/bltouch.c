#include "bltouch.h"

void bltouch_init()
{
  BLTOUCH_DDR |= (1 << BLTOUCH_BIT); // Configure as output pin

  // If we got here from reset the probe might be in an error condition
  bltouch_alarm_off_up();
  delay_ms(200);

  bltouch_send(BLT_CONTROLLER_SHUTDOWN);
  // wait for 200ms so it can check for wiring problems before we start PWM
  delay_ms(200);
  
  bltouch_send(BLT_CONTROLLER_STARTUP);

  delay_ms(100);

}

void bltouch_deploy() 
{
    bltouch_send(BLT_DEPLOY);
}

void bltouch_stow() 
{
    bltouch_send(BLT_STOW);
}

void bltouch_self_test() 
{
    bltouch_send(BLT_SELF_TEST);
}

void bltouch_alarm_off_up() 
{
    bltouch_send(BLT_ALARM_OFF_UP);
}

void bltouch_send(uint8_t data)
{
    // High 10ms. Low 10ms.
    // {
    //    High 8ms == 1 ; High 2ms == 0
    //    Low 5ms
    //  } x 8
    // High
    BLTOUCH_PORT |= (1 << BLTOUCH_BIT);
    delay_us(10000);
    for(int i=7; i>=0; i--) {
    
        BLTOUCH_PORT &= ~(1 << BLTOUCH_BIT);
        delay_us(5000);
        BLTOUCH_PORT |= (1 << BLTOUCH_BIT);
    
        if(data & (1 << i)) {
            delay_us(5000);
        } else {
            delay_us(2000);
        }
        BLTOUCH_PORT &= ~(1 << BLTOUCH_BIT);
    }
}