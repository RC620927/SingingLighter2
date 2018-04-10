#define DPWMB 12

int frequencyB = 500;
int dutyCycleB = 50;
bool pinONB = false;

// variables for software PWM
unsigned long currentMicrosB = micros();
unsigned long previousMicrosB = 0;
// this is the frequency of the sw PWM
// frequency = 1/(2 * microInterval)
unsigned long microIntervalB = 0.5 * (1000000 / frequencyB);

void setupPWMB() {
  pinMode(DPWMB, OUTPUT);
}

void setFrequencyPWMB(int freq) {
  frequencyB = freq;
  microIntervalB = 0.5 * (((1000000.0/1.008)) / frequencyB);
}

void loopPWMB() {
  currentMicrosB = micros();
  // check to see if we need to increment our PWM counters yet
  if (frequencyB == 0) {
    digitalWrite(DPWMB, LOW);
  } else {


    if (currentMicrosB - previousMicrosB >= microIntervalB) {
      if (pinONB) {
        digitalWrite(DPWMB, LOW);
        pinONB = false;
      } else {
        digitalWrite(DPWMB, HIGH);
        pinONB = true;
      }
      previousMicrosB = currentMicrosB;
    }
  }
}

