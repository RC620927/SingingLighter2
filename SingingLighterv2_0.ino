#define melodyPin 3
#define harmonyPin 12
//
int harmonyNotes[][2] = {{660, 200000}, {660, 200000}, {660, 2000}, {660, 2000}, {660, 20000}};
int melodyNotes[][2] = {{587, 268}, {587, 134}, {784, 268}, {784, 134}, {1174, 268}, {0, 268}, {988, 134}, {1046, 134}, {1174, 134}, {1046, 134}, {988, 268}, {880, 268}, {880, 268}, {659, 134}, {784, 268}, {740, 670}, {0, 536}, {587, 670}, {587, 134}, {784, 134}, {880, 134}, {988, 268}, {880, 268}, {988, 134}, {1046, 268}, {1174, 804}, {1318, 134}, {1174, 134}, {784, 536}, {880, 670}, {587, 804}, {784, 134}, {880, 134}, {988, 268}, {880, 268}, {988, 134}, {1046, 134}, {1174, 1205}, {294, 268}, {0, 402}, {262, 402}, {587, 670}, {587, 134}, {784, 134}, {880, 134}, {988, 268}, {880, 268}, {988, 134}, {1046, 268}, {1174, 804}, {1318, 134}, {1174, 134}, {784, 536}, {880, 670}, {988, 268}, {988, 134}, {1174, 268}, {1174, 134}, {784, 268}, {0, 804}, {784, 134}, {740, 134}, {659, 268}, {659, 268}, {740, 134}, {740, 268}, {784, 670}, {0, 536}};

int totalMelodyNotes;
int totalHarmonyNotes;

long nextMelodyTime = 0;
long nextHarmonyTime = 0;

int melodyCounter = 0;
int harmonyCounter = 0;

boolean melodyDone = false;
boolean harmonyDone = false;


int currentMelodyNote = 0;
int currentHarmonyNote = 0;

void setup() {
  Serial.begin(9600);
  setupPWMA();

  pinMode(melodyPin, OUTPUT);
  pinMode(harmonyPin, OUTPUT);
  int x = 1;

  totalMelodyNotes = sizeof(melodyNotes) / (2 * sizeof(x));
  totalHarmonyNotes = sizeof(harmonyNotes) / (2 * sizeof(x));
  Serial.println(totalMelodyNotes);

  long currentTime = millis();
  nextMelodyTime = melodyNotes[0][1] + currentTime;
  nextHarmonyTime = harmonyNotes[0][1] + currentTime;
}

void loop() {
  loopPWMS();
  long currentTime = millis();
  loopPWMS();
  //if I am done with previous melody note, start new one
  if (currentTime > nextMelodyTime) {
    loopPWMS();
    melodyCounter++;
    loopPWMS();
    //if I am done playing all melody notes, stop, else set the time this next note will end;
    if (melodyCounter >= totalMelodyNotes || melodyDone) {
      loopPWMS();
      melodyDone = true;
      melodyCounter = 0;
      loopPWMS();
    } else {
      loopPWMS();
      //set next melody time
      nextMelodyTime = melodyNotes[melodyCounter][1] + currentTime;
      loopPWMS();
    }

  }
  loopPWMS();
  //if I am done with previous harmony Note, start new one
  if (currentTime > nextHarmonyTime) {
    harmonyCounter++;
    loopPWMS();
    //if I am done playing all harmony notes, stop, else set the time this next note will end;
    if (harmonyCounter >= totalHarmonyNotes || harmonyDone) {
      loopPWMS();
      harmonyCounter = 0;
      harmonyDone = true;
    } else {
      loopPWMS();
      nextHarmonyTime = harmonyNotes[harmonyCounter][1] + currentTime;
    }
    loopPWMS();
  }
  loopPWMS();
   //if my notes arent done playing, play, else play nothing
//    if(!melodyDone){
//      playNote(melodyPin,  melodyNotes[melodyCounter][0]);
//    }else{
//      playNote(melodyPin,0);
//    }
//   loopPWMS();
//    if(!harmonyDone){
//      playNote(harmonyPin, harmonyNotes[harmonyCounter][0]);
//    }else{
//      playNote(harmonyPin,0);
//    }
    loopPWMS();
  // playNote(melodyPin,740);
  //playNote(harmonyPin,740);
  int potVal = analogRead(A0);
  loopPWMS();
  playNote(melodyPin, potVal);
 // Serial.println(potVal);

  //debug :)
  loopPWMS();
  //writeToDashboard();
}

void loopPWMS(){
  loopPWMA();
  loopPWMB();
}

//debugging statements
void writeToDashboard() {

  Serial.print("MELODYCOUNTER: ");
  Serial.print(melodyCounter);
  Serial.print("     HARMONYCOUNTER: ");
  Serial.print(harmonyCounter);
  Serial.print("MELODY: ");
  Serial.print(currentMelodyNote);
  Serial.print("    HARMONY: ");
  Serial.println(currentHarmonyNote);


}


