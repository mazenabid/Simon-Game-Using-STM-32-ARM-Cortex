/*
Name: Mazen Abid
SID: 200464618
University: UofR
Class: ENSE 352
Professor: Trevor Douglas
*/

#include "main.h"
#include <stdbool.h>
#include <stdlib.h>

void GPIO_Configurations(
    void); // Initialize GPIO configurations for input and output pins
unsigned int CylonEyeScanner(
    void); // Start the Simon game and return the generated first random number
unsigned int
randomSpitter(unsigned int); // Generate a random number based on the input seed
unsigned int simonTurns(unsigned int); // Control the turning on and off of
                                       // specific LEDs based on the input value
unsigned int conceptCheck(
    unsigned int); // Check if the player pressed the correct button within a
                   // limited time, return a value for the next step in the game
void loss(void);   // Handle the behavior of the game when the player loses
void win(void);    // Handle the behavior of the game when the player wins
void score(unsigned int); // Display the level reached by the player represented
                          // in binary using 4 LEDs
void timeDelay(
    unsigned int); // Create a time delay for the specified time value

// main and declairing intigers and variables... note that the 'unsigned int'
// part signifies that these variables can only store *positive* whole numbers!!

int main(void) {
  unsigned int rands = 0; // his variable will be used to store a random number
                          // generated during the game.

  unsigned int correctButtonPressedLv1, correctButtonPressedLv2,
      correctButtonPressedLv3, correctButtonPressedLv4, correctButtonPressedLv5,
      correctButtonPressedLv6, correctButtonPressedLv7, correctButtonPressedLv8,
      correctButtonPressedLv9,
      correctButtonPressedLv10; // this creates several pos integer variables
                                // meant to store the values representing the
                                // correct button presses for each level of the
                                // game.. latre on, it will compare the logic of
                                // what the LED created to what the user pressed

  unsigned int userStat = 0; // is used to check the player's status, if the
                             // player has won or lost in the given time???

  unsigned int ledNum1, ledNum2, ledNum3, ledNum4, ledNum5, ledNum6, ledNum7,
      ledNum8, ledNum9, ledNum10; // stores each of the random numbers generated
                                  // for each level of the game

  unsigned int scores =
      0; // this variable is used to keep track of the player's score in the
         // game (on the board it's shown in binary).

  // set the configurations
  GPIO_Configurations();

  // begin the game
  rands = CylonEyeScanner();

  /*|------------------------------------------------------------------------|
    |                                 ROUND 1                                |
    |------------------------------------------------------------------------|*/

  /*
  - Initialize GPIO configurations for input and output pins
  - Begin the Simon game and generate the first random number
  - Control the turning on and off of specific LEDs based on the input value
  - Check if the player pressed the correct button within a limited time
  - Handle the behavior of the game when the player loses
  - Display the level reached by the player represented in binary using 4 LEDs
  */

  ledNum1 = randomSpitter(
      rands); // calling a function and passing the variable "rands" as an
              // argument. The functionrandomspitter is responsible for
              // generating a random number and assigning it to the variable
              // "ledNum1." teh purpose of this function is to create a random
              // sequence of LEDs in the gane.

  correctButtonPressedLv1 = simonTurns(ledNum1);
  userStat = conceptCheck(
      correctButtonPressedLv1); // call the simonTurns function to control the
                                // turning on and off of specific LEDs based on
                                // the input value received from the variable
                                // ledNum1

  if (userStat == 0) // if the user's status is 0, indicating a loss...
  {
    loss();        // vall the loss function to handle the loss behavior
    score(scores); // display the current score using the score function (in
                   // Binary)
    return 0;
  }

  /*|------------------------------------------------------------------------|
    |                                 ROUND 2                                |
    |------------------------------------------------------------------------|*/

  scores += 1;     // if user achievs this, the score gets stored, hence, the
                   // increment by 1...
  timeDelay(1500); // It pauses the execution of the program for 1.5 seconds,
                   // from now on.. every delay is in millisecond just in case i
                   // don't comment each one..

  simonTurns(ledNum1); // call simonTurns function passing ledNum1 as argument

  ledNum2 = randomSpitter(userStat); // generate a random number using userStat
                                     // as a seed and assign it to ledNum2

  correctButtonPressedLv2 = simonTurns(
      ledNum2); // csll simonTurns function passing ledNum2 as argument and
                // assign the result to correctButtonPressedLv2

  userStat = conceptCheck(
      correctButtonPressedLv1); // update userStat by calling conceptCheck
                                // function passing correctButtonPressedLv1 as
                                // argument

  timeDelay(1000); // 1 second

  // perform loss behavior and update and display the score in case of userStat
  // being 0
  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  userStat = conceptCheck(
      correctButtonPressedLv2); // check userStat again, perform loss behavior
                                // and update the score if necessary. This line
                                // is important cuz the function conceptCheck is
                                // being called with the argument
                                // correctButtonPressedLv2. The function then is
                                // responsible for checking if the user pressed
                                // the correct button within a limited time. The
                                // result of this check is then stored in the
                                // variable userStat!

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  /*|------------------------------------------------------------------------|
    |                                 ROUND 3                                |
    |------------------------------------------------------------------------|*/

  scores += 1; // if user passes, increment by one and so on for the rest of the
               // rounds... a repition of what's  above

  timeDelay(1500);
  simonTurns(ledNum1);
  simonTurns(ledNum2);

  ledNum3 = randomSpitter(userStat);

  correctButtonPressedLv3 = simonTurns(ledNum3);

  userStat = conceptCheck(correctButtonPressedLv1);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  userStat = conceptCheck(correctButtonPressedLv2);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  userStat = conceptCheck(correctButtonPressedLv3);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  /*|------------------------------------------------------------------------|
    |                                 ROUND 4                                |
    |------------------------------------------------------------------------|*/

  scores += 1;
  timeDelay(1500);
  simonTurns(ledNum1);
  simonTurns(ledNum2);
  simonTurns(ledNum3); // notice how we keep adding simonturns as arguments in a
                       // quantity that's 1 less than the round... this is
                       // because we don't know if the user will win win or lose
                       // in that round given the rest of the code.

  ledNum4 = randomSpitter(userStat);

  correctButtonPressedLv4 = simonTurns(ledNum4);

  userStat = conceptCheck(correctButtonPressedLv1);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  userStat = conceptCheck(correctButtonPressedLv2);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  userStat = conceptCheck(correctButtonPressedLv3);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  userStat = conceptCheck(correctButtonPressedLv4);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }
  /*|------------------------------------------------------------------------|
    |                                 ROUND 5                                |
    |------------------------------------------------------------------------|*/
  scores += 1;
  timeDelay(1500);
  simonTurns(ledNum1);
  simonTurns(ledNum2);
  simonTurns(ledNum3);
  simonTurns(ledNum4);

  ledNum5 = randomSpitter(userStat);

  correctButtonPressedLv5 = simonTurns(ledNum5);

  userStat = conceptCheck(correctButtonPressedLv1);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  userStat = conceptCheck(correctButtonPressedLv2);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  userStat = conceptCheck(correctButtonPressedLv3);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  userStat = conceptCheck(correctButtonPressedLv4);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  userStat = conceptCheck(correctButtonPressedLv5);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }
  /*|------------------------------------------------------------------------|
    |                                 ROUND 6                                |
    |------------------------------------------------------------------------|*/
  scores += 1;
  timeDelay(1500);
  simonTurns(ledNum1);
  simonTurns(ledNum2);
  simonTurns(ledNum3);
  simonTurns(ledNum4);
  simonTurns(ledNum5);

  ledNum6 = randomSpitter(userStat);

  correctButtonPressedLv6 = simonTurns(ledNum6);

  userStat = conceptCheck(correctButtonPressedLv1);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  userStat = conceptCheck(correctButtonPressedLv2);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  userStat = conceptCheck(correctButtonPressedLv3);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  userStat = conceptCheck(correctButtonPressedLv4);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  userStat = conceptCheck(correctButtonPressedLv5);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  userStat = conceptCheck(correctButtonPressedLv6);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }
  /*|------------------------------------------------------------------------|
    |                                 ROUND 7                                |
    |------------------------------------------------------------------------|*/
  scores += 1;
  timeDelay(1500);
  simonTurns(ledNum1);
  simonTurns(ledNum2);
  simonTurns(ledNum3);
  simonTurns(ledNum4);
  simonTurns(ledNum5);
  simonTurns(ledNum6);

  ledNum7 = randomSpitter(userStat);

  correctButtonPressedLv7 = simonTurns(ledNum7);

  userStat = conceptCheck(correctButtonPressedLv1);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  userStat = conceptCheck(correctButtonPressedLv2);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }
  userStat = conceptCheck(correctButtonPressedLv3);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }
  userStat = conceptCheck(correctButtonPressedLv4);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  userStat = conceptCheck(correctButtonPressedLv5);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  userStat = conceptCheck(correctButtonPressedLv6);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  userStat = conceptCheck(correctButtonPressedLv7);
  if (userStat == 0)

  {
    loss();
    score(scores);
    return 0;
  }
  /*|------------------------------------------------------------------------|
    |                                 ROUND 8                                |
    |------------------------------------------------------------------------|*/

  scores += 1;
  timeDelay(1500);
  simonTurns(ledNum1);
  simonTurns(ledNum2);
  simonTurns(ledNum3);
  simonTurns(ledNum4);
  simonTurns(ledNum5);
  simonTurns(ledNum6);
  simonTurns(ledNum7);

  ledNum8 = randomSpitter(userStat);

  correctButtonPressedLv8 = simonTurns(ledNum8);

  userStat = conceptCheck(correctButtonPressedLv1);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  userStat = conceptCheck(correctButtonPressedLv2);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  userStat = conceptCheck(correctButtonPressedLv3);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  userStat = conceptCheck(correctButtonPressedLv4);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  userStat = conceptCheck(correctButtonPressedLv5);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  userStat = conceptCheck(correctButtonPressedLv6);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  userStat = conceptCheck(correctButtonPressedLv7);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  userStat = conceptCheck(correctButtonPressedLv8);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }
  /*|------------------------------------------------------------------------|
    |                                 ROUND 9                                |
    |------------------------------------------------------------------------|*/
  scores += 1;
  timeDelay(1500);
  simonTurns(ledNum1);
  simonTurns(ledNum2);
  simonTurns(ledNum3);
  simonTurns(ledNum4);
  simonTurns(ledNum5);
  simonTurns(ledNum6);
  simonTurns(ledNum7);
  simonTurns(ledNum8);

  ledNum9 = randomSpitter(userStat);

  correctButtonPressedLv9 = simonTurns(ledNum9);

  userStat = conceptCheck(correctButtonPressedLv1);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  userStat = conceptCheck(correctButtonPressedLv2);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  userStat = conceptCheck(correctButtonPressedLv3);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  userStat = conceptCheck(correctButtonPressedLv4);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  userStat = conceptCheck(correctButtonPressedLv5);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  userStat = conceptCheck(correctButtonPressedLv6);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  userStat = conceptCheck(correctButtonPressedLv7);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  userStat = conceptCheck(correctButtonPressedLv8);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  userStat = conceptCheck(correctButtonPressedLv9);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }
  /*|------------------------------------------------------------------------|
    |                                 ROUND 10                               |
    |------------------------------------------------------------------------|*/
  scores += 1;
  timeDelay(1500);
  simonTurns(ledNum1);
  simonTurns(ledNum2);
  simonTurns(ledNum3);
  simonTurns(ledNum4);
  simonTurns(ledNum5);
  simonTurns(ledNum6);
  simonTurns(ledNum7);
  simonTurns(ledNum8);
  simonTurns(ledNum9);

  ledNum10 = randomSpitter(userStat);

  correctButtonPressedLv10 = simonTurns(ledNum10);

  userStat = conceptCheck(correctButtonPressedLv1);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }
  userStat = conceptCheck(correctButtonPressedLv2);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  userStat = conceptCheck(correctButtonPressedLv3);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  userStat = conceptCheck(correctButtonPressedLv4);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  userStat = conceptCheck(correctButtonPressedLv5);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  userStat = conceptCheck(correctButtonPressedLv6);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  userStat = conceptCheck(correctButtonPressedLv7);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  userStat = conceptCheck(correctButtonPressedLv8);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  userStat = conceptCheck(correctButtonPressedLv9);
  timeDelay(1000);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }

  userStat = conceptCheck(correctButtonPressedLv10);

  if (userStat == 0) {
    loss();
    score(scores);
    return 0;
  }
  scores += 1; // now score equals 10!!! this is where the game breaks and the
               // only instance where the win function is called.

  win();
  return 0;
}

/*|------------------------------|
  | GPIO_Configurations FUNCTION |
  |------------------------------|*/

void GPIO_Configurations(void) {
  // if we forgot about the STM for asecond and thought of it as intigers...
  // these will define masks to clear specific ranges of bits within a 32-bit
  // integer. they are responsible for turning on the red LEDs as well as
  // configuring the clock and pins on the STM32F103RB

  uint32_t clear0to3Bits = 0xFFFFFFF0;   // mask to clear bits 0-3
  uint32_t clear4to7Bits = 0xFFFFFF0F;   // mask to clear bits 4-7
  uint32_t clear16to19Bits = 0xFFF0FFFF; // mask to clear bits 16-19
  uint32_t clear20to23Bits = 0xFF0FFFFF; // mask to clear bits 20-23
  uint32_t clear24to27Bits = 0xF0FFFFFF; // mask to clear bits 24-27

  // clocks for A, B, C (2,3,4) respectively
  RCC->APB2ENR |= ((1 << 2) | (1 << 3) | (1 << 4));

  // PA0
  GPIOA->CRL &= clear0to3Bits;
  GPIOA->CRL |= 0x3;

  // PA1
  GPIOA->CRL &= clear4to7Bits;
  GPIOA->CRL |= (0x3 << 4);

  // PA4
  GPIOA->CRL &= clear16to19Bits;
  GPIOA->CRL |= (0x3 << 16);

  // PB0
  GPIOB->CRL &= clear0to3Bits;
  GPIOB->CRL |= 0x3;

  // PA5
  GPIOA->CRL &= clear20to23Bits;
  GPIOA->CRL |= (3 << 20);

  // PA6
  GPIOA->CRL &= clear24to27Bits;
  GPIOA->CRL |= (3 << 24);

  // Setting bit 5 for the very last LED on the right to stay on (it will be
  // displayed when you lose)
  GPIOA->ODR |= (1 << 5);
}

/*|--------------------------|
  | CylonEyeScanner FUNCTION |
  |--------------------------|*/

unsigned int CylonEyeScanner(void) {

  // masks to clear specific ranges of bits within a 32-bit integer, made for
  // the initial sequence that mimics the cylon eye movement

  uint32_t clearbitA0 = 0xFFFFFFFE; // Mask to clear bit 0
  uint32_t clearbitA1 = 0xFFFFFFFD; // Mask to clear bit 1
  uint32_t clearbitA4 = 0xFFFFFFEF; // Mask to clear bit 4
  uint32_t clearbitB0 = 0xFFFFFFFE; // Mask to clear bit 0

  //------------//

  unsigned int count = 0; // the count produced by this function will be
                          // utilized to generate the initial random number.

  //------------//

  // this while loop  will never stop until the user presses the blue button on
  // the STM32F103
  while (1) {
    GPIOA->ODR |=
        (1
         << 0); // set the corresponding bit in the ODR register of port A to 1

    // check if the bit corresponding to pin 13 of port C in the IDR register is
    // 0
    if ((GPIOC->IDR & (1 << 13)) == 0)
      break; // If the condition is met, exit the loop

    timeDelay(900); // 0.9 seconds

    // check if the bit corresponding to pin 13 of port C in the IDR register is
    // 0
    if ((GPIOC->IDR & (1 << 13)) == 0)
      break; // If the condition is met... againn, exit the loop

    // clear the corresponding bit in the ODR register of port A
    GPIOA->ODR &= clearbitA0;

    // check if the bit corresponding to pin 13 of port C in the IDR register is
    // 0
    if ((GPIOC->IDR & (1 << 13)) == 0)
      break; // If the condition is met..., exit the loop

    count = count + 1; // increment count to store it later when a user wins or
                       // display it when the user loses.

    //------------//

    // turn on the corresponding bit in the ODR register of port A to illuminate
    // the LED connected to pin 1
    GPIOA->ODR |= (1 << 1);

    // check if the bit corresponding to pin 13 of port C in the IDR register is
    // 0, indicating a button press
    if ((GPIOC->IDR & (1 << 13)) == 0)
      break;

    // delay for 900 millisec or 0.9 sec
    timeDelay(900);

    // check if the bit corresponding to pin 13 of port C in the IDR register is
    // 0, indicating a button press
    if ((GPIOC->IDR & (1 << 13)) == 0)
      break;

    // turn off the corresponding bit in the ODR register of port A to turn off
    // the LED connected to pin 1
    GPIOA->ODR &= clearbitA1;

    // check if the bit corresponding to pin 13 of port C in the IDR register is
    // 0, indicating a button press
    if ((GPIOC->IDR & (1 << 13)) == 0)
      break;

    count = count + 1;

    //------------//

    // set the corresponding bit in the ODR register of port A to illuminate the
    // LED connected to pin 4
    GPIOA->ODR |= (1 << 4);

    // check if the bit corresponding to pin 13 of port C in the IDR register is
    // 0, indicating a button press
    if ((GPIOC->IDR & (1 << 13)) == 0)
      break;

    // delay
    timeDelay(900);

    // check if the bit corresponding to pin 13 of port C in the IDR register is
    // 0, indicating a button press
    if ((GPIOC->IDR & (1 << 13)) == 0)
      break;

    // turn off the corresponding bit in the ODR register of port A to turn off
    // the LED connected to pin 4
    GPIOA->ODR &= clearbitA4;

    // check if the bit corresponding to pin 13 of port C in the IDR register is
    // 0, indicating a button press
    if ((GPIOC->IDR & (1 << 13)) == 0)
      break;

    count = count + 1; // increment count to store it later when a user wins or
                       // display it when the user loses

    //-----AND SO ON-------//

    GPIOB->ODR |= (1 << 0);
    if ((GPIOC->IDR & (1 << 13)) == 0)
      break;
    timeDelay(900);
    if ((GPIOC->IDR & (1 << 13)) == 0)
      break;
    GPIOB->ODR &= clearbitB0;
    if ((GPIOC->IDR & (1 << 13)) == 0)
      break;

    count = count + 1;

    GPIOA->ODR |= (1 << 4);
    if ((GPIOC->IDR & (1 << 13)) == 0)
      break;
    timeDelay(900);
    if ((GPIOC->IDR & (1 << 13)) == 0)
      break;
    GPIOA->ODR &= clearbitA4;
    if ((GPIOC->IDR & (1 << 13)) == 0)
      break;

    count = count + 1;

    GPIOA->ODR |= (1 << 1);
    if ((GPIOC->IDR & (1 << 13)) == 0)
      break;
    timeDelay(900);
    if ((GPIOC->IDR & (1 << 13)) == 0)
      break;
    GPIOA->ODR &= clearbitA1;
    if ((GPIOC->IDR & (1 << 13)) == 0)
      break;

    count = count + 1;
  }

  // Manually creating a "random" blinking pattern
// First cycle
GPIOA->ODR |= (1 << 0);  // Turn on A0
GPIOA->ODR &= clearbitA1; // Turn off A1
GPIOA->ODR |= (1 << 4);  // Turn on A4
GPIOB->ODR &= clearbitB0; // Turn off B0
timeDelay(300);          // Short delay

// Second cycle
GPIOA->ODR &= clearbitA0; // Turn off A0
GPIOA->ODR |= (1 << 1);  // Turn on A1
GPIOA->ODR &= clearbitA4; // Turn off A4
GPIOB->ODR |= (1 << 0);  // Turn on B0
timeDelay(500);          // Short delay

// Repeat similar cycles as needed to create the effect of randomness

// Steady light phase
GPIOA->ODR |= (1 << 0); // Turn on A0
GPIOA->ODR |= (1 << 1); // Turn on A1
GPIOA->ODR |= (1 << 4); // Turn on A4
GPIOB->ODR |= (1 << 0); // Turn on B0
timeDelay(1500);        // Hold steady

// Turn off all LEDs
GPIOA->ODR &= clearbitA0;
GPIOA->ODR &= clearbitA1;
GPIOA->ODR &= clearbitA4;
GPIOB->ODR &= clearbitB0;
  return count;
}

/*|--------------------------|
  |  RANDOMSPITTER FUNCTION  |
  |--------------------------|*/

// This function will generate a random number
unsigned int randomSpitter(unsigned int rands) {
  unsigned int randomNumber = 0; // between 0 and 3
  unsigned int LIGHTMASK = 0x00000003;
  srand(rands); // seed the random number generator

  randomNumber = rand();

  randomNumber =
      randomNumber >> 29; // sgift the random number to the right by 29 bits

  randomNumber &= LIGHTMASK; // mask the random number to get any betwern 0 and
                             // 3

  return randomNumber;
}

/*|----------------------|
  |  SIMONTURNS FUNCTION |
  |----------------------|*/

// This function will turn an LED on, off and it's already determained by the
// 'randomSpitter' function and 'win'
unsigned int simonTurns(unsigned int rands) {
  uint32_t clearbitA0 = 0xFFFFFFFE; // clear bit A0
  uint32_t clearbitA1 = 0xFFFFFFFD; // clear bit A1
  uint32_t clearbitA4 = 0xFFFFFFEF; // clear Bit A4
  uint32_t clearbitB0 = 0xFFFFFFFE; // clear bit B0

  // switch statement based on the value of 'rands'
  switch (rands) {

  case 0:                   // case 0: Handling for when 'rands' is 0
    GPIOA->ODR |= (1 << 0); // set bit 0 of GPIOA's Output Data Register (ODR)
    timeDelay(1000);        // wait for 1sec
    GPIOA->ODR &=
        clearbitA0;  // clear bit 0 of GPIOA's ODR using 'clearbitA0' mask
    timeDelay(1000); // wait for another sec
    break;

  case 1:                   // case 1: Handling for when 'rands' is 1
    GPIOA->ODR |= (1 << 1); // set bit 1 of GPIOA's ODR
    timeDelay(1000);        // wait for 1s
    GPIOA->ODR &=
        clearbitA1;  // clear bit 1 of GPIOA's ODR using 'clearbitA1' mask
    timeDelay(1000); // wait for another 1sec
    break;

  case 2: // case 2: Handling for when 'rands' is 2... and so on
    GPIOA->ODR |= (1 << 4);
    timeDelay(1000);
    GPIOA->ODR &= clearbitA4;
    timeDelay(1000);
    break;

  case 3:
    GPIOB->ODR |= (1 << 0);
    timeDelay(1000);
    GPIOB->ODR &= clearbitB0;
    timeDelay(1000);
    break;
  }

  return rands;
}

/*|------------------------|
  |  CONCEPTCHECK FUNCTION |
  |------------------------|*/

// this checks if the player or user pressed the correct button in the given
// time, and if they did, it will return 1 and if they didn't, it will return 0.
// if loss is 0 the you lose and if rand is anything but 0 then you move on to
// the next round..
unsigned int conceptCheck(unsigned int check) {

  unsigned int start_time = 0;
  unsigned int current_time = 0;
  bool button_pressed = false;

  unsigned int rands = 0;

  start_time = current_time; // initialize start_time with the current time

  // loop for a duration of 800000 time units

  while (current_time - start_time < 800000) {
    rands += 10;        // increment 'rands' by 10 in each iteration
    timeDelay(12);      //  introduce a very short delay of 12 time units
    current_time += 10; // then manually increment current time by 10

    // Check if any of the specified GPIOB pins (bit 4, 6, 8, or 9) is pressed,
    // depending on 'check' value defined earlier in the beginning of the
    // function
    if (((check == 0) && ((GPIOB->IDR & (1 << 4)) == 0)) ||
        ((check == 1) && ((GPIOB->IDR & (1 << 6)) == 0)) ||
        ((check == 2) && ((GPIOB->IDR & (1 << 8)) == 0)) ||
        ((check == 3) && ((GPIOB->IDR & (1 << 9)) == 0))) {
      button_pressed = true; // set flag if the correct button is pressed
      break;                 // exit the loop if the correct button is pressed

      // check if any wrong button is pressed for the current 'check' value
    } else if ((((check == 0) && ((GPIOB->IDR & (1 << 6)) == 0)) ||
                ((check == 0) && ((GPIOB->IDR & (1 << 8)) == 0)) ||
                ((check == 0) && ((GPIOB->IDR & (1 << 9)) == 0))) ||
               (((check == 1) && ((GPIOB->IDR & (1 << 4)) == 0)) ||
                ((check == 1) && ((GPIOB->IDR & (1 << 8)) == 0)) ||
                ((check == 1) && ((GPIOB->IDR & (1 << 9)) == 0))) ||
               (((check == 2) && ((GPIOB->IDR & (1 << 4)) == 0)) ||
                ((check == 2) && ((GPIOB->IDR & (1 << 6)) == 0)) ||
                ((check == 2) && ((GPIOB->IDR & (1 << 9)) == 0))) ||
               (((check == 3) && ((GPIOB->IDR & (1 << 6)) == 0)) ||
                ((check == 3) && ((GPIOB->IDR & (1 << 8)) == 0)) ||
                ((check == 3) && ((GPIOB->IDR & (1 << 4)) == 0)))) {
      break; // exit the loop if any wrong button is pressed
    }
  }
  if (!button_pressed) {
    return 0;
  } else {
    return rands;
  }
}
/*|----------------|
  |  LOSS FUNCTION |
  |----------------|*/

// Ithis function is made if the player losss at any level, one red LEDs will be
// blinking for 3 seconds

void loss(void) {
  uint32_t clearbitA6 = 0xFFFFFFBF; // a mask to clear bit A6 in (ODR)
  unsigned int start_time = 0;      // declare and initialize start time
  unsigned int current_time = 0;    // declare and initialize current time
  start_time = current_time; // set start time to current time (initially 0)

  // Loop for a duration of 150 time units
  while (current_time - start_time < 150) {
    current_time += 10; // increment current time by 10 in each iteration

    GPIOA->ODR |= (1 << 6); // set bit 6 of GPIOA's ODR
    timeDelay(500);         // wait for 500 milliseconds

    GPIOA->ODR &=
        clearbitA6; // clear bit 0 of GPIOA's ODR using the clearbitA0 mask
    timeDelay(500); // wait for 500 milliseconds
  }
}

/*|---------------|
  |  WIN FUNCTION |
  |---------------|*/
// only initiated if you win all 10 levels... then the 4 LEDs will blink nonstop
void win(void) {
  uint32_t clearbitA0 = 0xFFFFFFFE; // a mask to clear bit 0 in (ODR)
  uint32_t clearbitA1 = 0xFFFFFFFD; // a mask to clear bit 1 in (ODR)
  uint32_t clearbitA4 = 0xFFFFFFEF; // a mask to clear bit 4in (ODR)
  uint32_t clearbitB0 = 0xFFFFFFFE; // a mask to clear bit 16 in (ODR)

  while (1) {
    GPIOA->ODR |= (1 << 0);
    GPIOA->ODR |= (1 << 1);
    GPIOA->ODR |= (1 << 4);
    GPIOB->ODR |= (1 << 0);
    timeDelay(1000);
    GPIOA->ODR &= clearbitA0;
    GPIOA->ODR &= clearbitA1;
    GPIOA->ODR &= clearbitA4;
    GPIOB->ODR &= clearbitB0;
    timeDelay(1000);
  }
}

/*|------------------|
  |  SCORE FUNCTION  |
  |------------------|*/
// weather the player loses or wins, the score will be displayed in binary
/*
    1 in binary is 0001. (Displayed such that LEDs show OFF OFF OFF ON states to
   determine your level) 2 in binary is 0010. 3 in binary is 0011. 4 in binary
   is 0100. 5 in binary is 0101. 6 in binary is 0110. 7 in binary is 0111. 8 in
   binary is 1000. 9 in binary is 1001. 10 in binary is 1010.
  */

void score(unsigned int scores) {

  uint32_t clearbitA0 = 0xFFFFFFFE; // a mask to clear bit 0 in (ODR)
  uint32_t clearbitA1 = 0xFFFFFFFD; // a mask to clear bit 1 in (ODR)
  uint32_t clearbitA4 = 0xFFFFFFEF; // a mask to clear bit 4in (ODR)
  uint32_t clearbitB0 = 0xFFFFFFFE; // a mask to clear bit 16 in (ODR)

  switch (scores) {
  case 0: // 0 -> 0000: All lights off, OFF OFF OFF OFF
    break;

  case 1: // 1 -> 0001: Set GPIOB bit 0, OFF OFF OFF ON
    GPIOB->ODR |= (1 << 0);
    break;

  case 2: // 2 -> 0010: Set GPIOA bit 4, OFF OFF ON OFF
    GPIOA->ODR |= (1 << 4);
    break;

  case 3: // 3 -> 0011: Set GPIOB bit 0 and GPIOA bit 4, OFF OFF ON ON...
    GPIOB->ODR |= (1 << 0);
    GPIOA->ODR |= (1 << 4);
    break;

  case 4: // 4 -> 0100: Set GPIOA bit 1
    GPIOA->ODR |= (1 << 1);
    break;

  case 5: // 5 -> 0101: Set GPIOA bit 1 and GPIOB bit 0
    GPIOA->ODR |= (1 << 1);
    GPIOB->ODR |= (1 << 0);
    break;

  case 6: // 6 -> 0110: Set GPIOA bits 1 and 4
    GPIOA->ODR |= (1 << 1) | (1 << 4);
    break;

  case 7: // 7 -> 0111: Set GPIOA bits 1 and 4, and GPIOB bit 0
    GPIOA->ODR |= (1 << 1) | (1 << 4);
    GPIOB->ODR |= (1 << 0);
    break;

  case 8: // 8 -> 1000: Set GPIOA bit 0
    GPIOA->ODR |= (1 << 0);
    break;

  case 9: // 9 -> 1001: Set GPIOA bit 0 and GPIOB bit 0
    GPIOA->ODR |= (1 << 0);
    GPIOB->ODR |= (1 << 0);
    break;

  case 10: // 10 -> 1010: Set GPIOA bits 0 and 4
    GPIOA->ODR |= (1 << 0) | (1 << 4);
    break;
  }
}
/*|----------------------|
  |  TIMEDELAY FUNCTION  |
  |----------------------|*/
// Finally, this function uses nested loops to create a delay. The outer loop
// runs for the number of times specified by value. For each iteration of the
// outer loop, the inner loop runs until y equals delayDuration, effectively
// creating a nested loop delay mechanism.

void timeDelay(unsigned int value) {
  unsigned int i = 0; // initialize counter 'i' for the outer loop
  unsigned int y = 0; // initialize counter 'y' fr the inmner loop
  unsigned int delayDuration =
      0; // variable to hold the value of delay internally

  delayDuration =
      value; // set the internal delay value to the passed argument 'value'

  // outer loop: runs 'value' however many times
  while (i < value) {

    // inner loop: increments 'y' until it equals 'delayDuration'
    while (y < delayDuration) {
      ++y; // increment 'y'
    }

    y = 0; // reset 'y' to 0 for the next iteration of the outer loop
    ++i;   // increment 'i'
  }
}