
/*
 * rilevazione della velocità del suono in due modalità:
 * sensore ad ultrasioni
 * sensore acustico
 */

//distanza fissa in centimetri
#define DIST 200

//parametri relativi ai pin a cui corrispondono i sensori
#define TRIG A5
#define ECHO A4
#define BUZZER 9
#define NOISE_1 6
#define NOISE_2 7

// valore di conversione per il calcolo della distanza
int cmconv = 49;

//vettore in cui salvare i valori rilevati
double tempo[5];

//variabili utili al calcolo finale
double timeAvg = 0;
double vel;
bool start=false;



void setup() {
    //inizializzo il monitor seriale
    Serial.begin(9600);
  
    //definisco il tipo di pin: output e input
      
    pinMode(NOISE_1, INPUT);
    pinMode(NOISE_2, INPUT);
    
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);

    pinMode(BUZZER, OUTPUT);
    digitalWrite(BUZZER, LOW);

    domanda();

}

void loop() {

       if (Serial.read() == '1'){
          ultrasuoni();
       
       }else if(Serial.read() == '2'){
          microfono(); 
       }
}
