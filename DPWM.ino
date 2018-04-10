#define DPWMA 3

int frequencyA = 500;
int dutyCycleA = 50;
bool pinONA = false;

// variables for software PWM
unsigned long currentMicrosA = micros();
unsigned long previousMicrosA = 0;
// this is the frequency of the sw PWM
// frequency = 1/(2 * microInterval)
unsigned long microIntervalA= 0.5 * (1000000 / frequencyA);

void setupPWMA() {
  pinMode(DPWMA, OUTPUT);
}

void setFrequencyPWMA(int freq) {
  frequencyA = freq;
  microIntervalA = 0.5 * ((1000000.0/1.04) / frequencyA) ;
}

void loopPWMA() {
  currentMicrosA = micros();
  // check to see if we need to increment our PWM counters yet
  if (frequencyA == 0) {
    digitalWrite(DPWMA, LOW);
  } else {


    if (currentMicrosA - previousMicrosA >= microIntervalA) {
      if (pinONA) {
        digitalWrite(DPWMA, LOW);
        pinONA = false;
      } else {
        digitalWrite(DPWMA, HIGH);
        pinONA = true;
      }
      previousMicrosA = currentMicrosA;
    }
  }
}

