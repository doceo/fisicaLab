#define DIST 200

#define MIN_DIST 3

#define TRIG A5
#define ECHO A4
#define BUZZER 9

#define NOISE_1 6
#define NOISE_2 6

unsigned long tZero, tUno;

bool inizio = true;
bool fine = true;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(NOISE_1, INPUT);
    pinMode(NOISE_2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

while(inizio){

  if(digitalRead(NOISE_1)){
    tZero = micros();
    inizio = false;
  }
}
while(fine){

  if(digitalRead(NOISE_1)){
    tUno = micros();
    fine = false;
  }

unsigned long deltaT = tUno - tZero;

Serial.print("Il tempo intercorso tra la prima rilevazione e la seconda è: ");
Serial.println(deltaT);
Serial.println();
if (!inizio && !fine){
  Serial.print("vuoi ripetere l'esperimento? (s/n)");
    while (Serial.available() > 0) {

       if (Serial.read() == 's'){
        inizio = true;
        fine = true;
       
       }else if(Serial.read() == 'n'){
        break;
       
       }else{
        Serial.println("scrivi s per SI e n per NO");
       }
    }
}

}

delay(200);
}
