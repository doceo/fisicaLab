

#define DIST 200

#define MIN_DIST 3

#define TRIG A5
#define ECHO A4
#define BUZZER 9

#define NOISE A0

int noiseValue;
int cmconv =49;
double sonar[10];
long int mic[10];
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

    while(!noiseLevel()){
      
      if(noiseLevel()){ start=true;
      
      }
    }
    
    beep(500);
    delay(1000);
}

void loop() {

  for(int i=5; i>=0; i--){
    Serial.println(i);
  }
  Serial.print("via!");


  for(int i =0; i<10;i++){

  sonar[i]=temp();
  delay(100);
  beep(200);  
  }

  for(int i =0; i<10;){

  timeAvg = timeAvg + sonar[i];

  }

  Serial.print("Il tempo medio su dieci lanci e': ");
  Serial.print(timeAvg);
  Serial.println(" (millisecondi) ");   
  Serial.println();
  
  double vel = 2*(DIST)/(double(timeAvg)/1000);
  Serial.print("vel in m/s: ");
  Serial.println(vel);

  start=false;
  
     while(!noiseLevel()){
      
      if(noiseLevel()){ start=true;
      
      }
    }
}
  
 
