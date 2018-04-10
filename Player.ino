#define melodyPin 3
#define harmonyPin 12

#define timer1PinA  3
#define timer3PinA  12

#define DUTYCYCLE 70

#define cpuFreq 16000000


void playNote(int pin, int frequency) {
if(pin == 3){
  setFrequencyPWMA(frequency);
}
if(pin==12){
  setFrequencyPWMB(frequency);
}
  //setting frequency
//  if (pin == melodyPin) {
//    currentMelodyNote = frequency;
//  } else if (pin == harmonyPin) {
//    currentHarmonyNote = frequency;
//  }

//  int aOut = 10000 / frequency;
//  aOut *= DUTYCYCLE;
//
//
//  int upperTimerLimit = (16000000 / 16) / (frequency);
//
//  if (aOut > upperTimerLimit) {
//    aOut = upperTimerLimit - 1;
//  }
//  if (aOut < 0 || frequency == 0) {
//    aOut = 0;
//  }
//  if (upperTimerLimit <= 0 || frequency == 0) {
//    upperTimerLimit = 1;
//  }
//
//  Serial.print("   UPPER:   ");
//  Serial.print(upperTimerLimit);
//  Serial.print(" aOUT:");
//  Serial.print(aOut);
//
//  if (pin == timer3PinA) {
//    TCCR3A = 0x09;      // sets timer control bits to PWM Phase and Frequency Correct mode
//    TCCR3B = 0x12;      // sets timer control bits to Prescaler N = 8
//    OCR3A = upperTimerLimit;
//    if (aOut == 0) {
//      digitalWrite(pin, LOW);
//    } else {
//
//      analogWrite(pin, aOut);
//    }
//  }
//
//  if (pin == timer1PinA) {
//    TCCR1A = 0x09;      // sets timer control bits to PWM Phase and Frequency Correct mode
//    TCCR1B = 0x12;      // sets timer control bits to Prescaler N = 8
//    // ICR1 = 0x0FA0;      // Upper Timer Limit = 4000 (in hex) equals 4ms => 1/5 of servo frequency
//    OCR1A = upperTimerLimit;
//    if (frequency == 0) {
// 
//      digitalWrite(pin, LOW);
//    } else {
//      analogWrite(pin, aOut);
//    }
//  }






}


