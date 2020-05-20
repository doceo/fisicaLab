


// defines pins numbers
const int TRIG = A5;
const int ECHO = A4;

// defines variables
long duration;
int distance;
long tempo;
int pausa;  //definisco una pausa tra una rilevazione e l'altra. 

void setup() {
pinMode(TRIG, OUTPUT); // Sets the trigPin as an Output
pinMode(ECHO, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
}

void loop() {
// Clears the trigPin
digitalWrite(TRIG, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(TRIG, HIGH);
delayMicroseconds(10);
digitalWrite(TRIG, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(ECHO, HIGH);
tempo = millis();

/*
 * utilizzo la funzione millis() che genera un valore numerico associato al tempo,
 * in millisecondi, trascorso dall'accensione di Arduino. In questo modo posso
 * "fotografare" l'istante associato all'aquisizione della posizione rilevata
 * da pulseIn().
 * Salvare nella variabile "tempo" il valore temporale, subito dopo aver ricavato la
 * posizione riduce l'errore di rilevazione del tempo associato al tempo di esecuzione
 * delle istruzioni da parte del microcontrollore.
 */


// Calculating the distance
distance = duration*0.034/2;
  
//restituisco in output la coppia di valori che associa tempo e distanza  
Serial.print(tempo);
Serial.print(",");
Serial.println(distance);  

delay(pausa);
  
  
  
}
