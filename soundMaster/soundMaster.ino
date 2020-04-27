


#define MIN_DIST 3

#define TRIG A5
#define ECHO A4
#define BUZZER 9

#define NOISE A0

int cmconv = 59; 
int noiseValue;


void setup() {
  // put your setup code here, to run once:
   pinMode(TRIG, OUTPUT);
   pinMode(ECHO, INPUT);

  pinMode(BUZZER, OUTPUT);

   pinMode(NOISE, INPUT);

  noiseLevel();
  
  while(dist() > 10){
  }
   
   
}

void loop() {

  beep();
  // put your main code here, to run repeatedly:

  if(noiseValue>100){
    
  beep();
}
