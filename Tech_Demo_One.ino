int SPEAKER = 8; //Output to speaker

void setup()
{
  pinMode(SPEAKER, OUTPUT);
  Serial.begin(9600);
}


void loop()
{
  delay(100); //Delay at the start of every loops keeps the notes distinct and diminishes static
  int x = analogRead(0) - 269; //Reading in the x-value from the accelerometer
  int y = analogRead(1) - 269; //Reading in the x-value from the accelerometer
  int z = analogRead(2) - 269; //Reading in the x-value from the accelerometer

  //Code safety ensures that I can't get a negative note
  if(z < 0){
    z = 0;
  }
  if(y < 0){
    y = 0;
  }
  if(x < 0){
    x = 0;
  }

  int note = 33 + y*11 + x*11 + z*11; //Initializing the note with a scaling factor

  //Ensuring that I don't burn out the speaker and only play notes the speaker can make
  if(note > 4978 || note < 33){
     noTone(SPEAKER);
     Serial.println("Wrong Parameters");
     delay(100000);
  }
  
  tone(SPEAKER, note); //Play the note on the speaker
}
