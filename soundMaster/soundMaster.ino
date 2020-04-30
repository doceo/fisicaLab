

#define DIST 200

#define MIN_DIST 3

#define TRIG A5
#define ECHO A4
#define BUZZER 9

#define NOISE 6

int noiseValue;
int cmconv =49;
double sonar[5];
long int mic[5];
double timeAvg = 0;
double vel;
bool start=false;


void setup() {
  // put your setup code here, to run once:

    
    Serial.begin(9600);
    Serial.println("Posiziona il sonar a 2 metri da una parete e batti le mani in prossimità di arduino");
    Serial.println(); 
    
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);

    pinMode(BUZZER, OUTPUT);

    pinMode(NOISE, INPUT);

    while(!start){
      if(digitalRead(NOISE)) start=true;
//      Serial.println(digitalRead(NOISE));
//      Serial.println(distanza());
     }
    beep(500);
    delay(1000);
}

void loop() {

  for(int i=5; i>=0; i--){
    Serial.println(i);
  }
  Serial.println("via!");
  Serial.println("");

  for(int i =0; i<5;i++){

  sonar[i]=temp();
  Serial.print("tempo[");
  Serial.print(sonar[i]);
  Serial.println("]");
  delay(100);
  Serial.println("");
  beep(200);
  }

  for(int i =0; i<5; i++){

  timeAvg = timeAvg + sonar[i];
  timeAvg = timeAvg/2;

  }

  Serial.print("Il tempo medio su cinque lanci e': ");
  Serial.print(timeAvg);
  Serial.println(" (millisecondi) ");   
  Serial.println();
  
  double vel = 2*(DIST/100)/(double(timeAvg)/1000);
  Serial.print("la velocita' in m/s: ");
  Serial.println(vel);

  start=false;
  
  while(!start){
    if(digitalRead(NOISE)) start=true;
    }
  }
  
 
