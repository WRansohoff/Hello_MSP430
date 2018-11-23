#include <msp430.h>

// Short delay method, until I figure out timers.
void delay (unsigned long int d) {
  unsigned long int i;
  for (i = 0; i < d; ++i) { asm("nop"); }
}

int main() {
  // Stop the watchdog timer.
  WDTCTL  =  (WDTPW + WDTHOLD);
  // Set P1.0 and P1.6 to output mode.
  P1DIR  |=  (BIT0 | BIT6);
  // Set initial LED states.
  P1OUT  |=  (BIT0);
  P1OUT  &= ~(BIT6);

  while (1) {
    // Toggle the LEDs, and delay a bit.
    P1OUT ^= (BIT0 | BIT6);
    delay(100000);
  }

  return 0;
}
