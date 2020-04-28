

#define DIST 200

#define MIN_DIST 3

#define TRIG A5
#define ECHO A4
#define BUZZER 9

#define NOISE A0

int noiseValue;
int cmconv =49;
long int sonar[10];
long int mic[10];

void setup() {
  // put your setup code here, to run once:

    
    Serial.begin(9600);
    Serial.println("Posiziona il sonar a 2 metri da una parete e batti le mani in prossimità di arduino");
    Serial.println(); 
    
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);

    pinMode(BUZZER, OUTPUT);

    pinMode(NOISE, INPUT);

    while(noiseLevel());
    beep();
    delay(1000);
}

void loop() {

  for(int i=5; i>=0; i--){
    Serial.println(i);
  }
  Serial.print(via!);


  for(int i =0; i<10;){
    
  }
  
  Serial.print("durata (millisecondi): ");                                 //stampiamo sul monitor seriale la durata del segnale
 
}
  
 
