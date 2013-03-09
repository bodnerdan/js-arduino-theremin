/* 
 * Note definitions taken from http://arduino.cc/en/Tutorial/tone.
 */

#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988

/* This code supports 2 octaves*/
int notes[] = {
  NOTE_C4, NOTE_CS4, NOTE_D4, NOTE_DS4, NOTE_E4, NOTE_F4, 
  NOTE_FS4, NOTE_G4, NOTE_GS4, NOTE_A4, NOTE_AS4, NOTE_B4, 
  /**/
  NOTE_C5, NOTE_CS5, NOTE_D5, NOTE_DS5, NOTE_E5, NOTE_F5, 
  NOTE_FS5, NOTE_G5, NOTE_GS5, NOTE_A5, NOTE_AS5, NOTE_B5, 
  };

int notesLen = 12*2;

void setup() {
  Serial.begin(9600);
  pinMode(7, OUTPUT);
}

void loop() {
  /* The light sensor is connected to analog input pin 0*/
  int sensorValue = analogRead(A0);
  
  /* These values are used to calibrate the light sensor. */
  int rangeLow = 207;
  int rangeHigh = 930;
  int notesIndex = map(sensorValue, rangeLow, rangeHigh, 0, notesLen-1);

  /* Make sure we don't access values outside the array's bounds. */  
  if ( notesIndex < 0 )
    notesIndex = 0;
   
  if ( notesIndex > notesLen - 1 )
    notesIndex = notesLen - 1;
  
  int pitchValue = notes[notesIndex];
  
  /* Print some values that are useful for debugging. */
  Serial.print("sensor=");
  Serial.print(sensorValue);
  Serial.print(", notesIndex=");
  Serial.print(notesIndex);
  Serial.print(", pitch=");
  Serial.println(pitchValue);
  
  /* The piezo speaker is connected to digital output pin 2. */
  tone(2, pitchValue, 100);  
  delay(1);
}
