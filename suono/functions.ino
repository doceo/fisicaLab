/***************************************************************
 * DOMANDA()
 * questa funzione stampa semplicemente al monitor la scelta 
 * possibile
 **************************************************************/

void domanda(){
  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.println("Come vuoi rilevare la velocita' del suono?");
  Serial.println("premi '1' per gli ultrasuoni");
  Serial.println("premi '2' per le frequenze udibili"); 
  Serial.println("");

}
 /**************************************************************
  * ULTRASUONI()
  * peremtte il calcolo della velocità a partire da 5 rilevazioni
  * effettuate con il sensore ad ultrasuoni
  **************************************************************/
  
void ultrasuoni(){
  
  Serial.println("verifica che il sensore sia a 2 metri da un ostacolo e poi premi un tasto qualsiasi");
  
  //attendo al pressione di un tasto qualsiasi

  
  for(int i=5; i>=0; i--){
      Serial.println(i);
  }
  Serial.println("via! Eseguiamo 5 rilevazioni...");
  Serial.println("");

//eseguo 5 rilevazioni e popolo il vettore temp()
  
  for(int i =0; i<5;i++){

        tempo[i]=temp();
        Serial.print("tempo[");
        Serial.print(i);
        Serial.print("]=");
        Serial.println(tempo[i]);
        Serial.println("");
        delay(100);
        Serial.println("");
        beep(200);
  }

//calcolo la media delle rilevazioni
  for(int i =0; i<5; i++){

  timeAvg = (i*timeAvg + tempo[i])/(i+1);
  }
  
//restituisco in output i valori trovati e il calcolo finale
  
  Serial.print("Il tempo medio su cinque lanci e': ");
  Serial.print(timeAvg);
  Serial.println(" (millisecondi) ");   
  Serial.println();
  
  double vel = 2*(DIST/100)/(double(timeAvg)/1000);
  Serial.print("la velocita' in m/s: ");
  Serial.println(vel);

  domanda();
}

/*************************************************************
 * MICROFONO()
 * Utilizzando due sensore di tipo acustico, che integrano un 
 * trasduttore rileviamo 5 volte il tempo T0 e T1, relativo
 * al mic1 ed al mic2 posti alla distanza di due metri l'uno 
 * dall'altro
 ************************************************************/
 
void microfono(){

  //variaibili necessarie alla rilevazione con sensore acustico
  unsigned long tZero, tUno;
  bool inizio = true;
  bool fine = true;
  double deltaT;
  
  Serial.println("verifica che i sensori sono posti a 2 metri di distanza");
  
  //attendo al pressione di un tasto qualsiasi
  
  Serial.println("");

//eseguo un ciclo di 5 rilevazioni
          
/*
 * eseguo un ciclo in attesa di un suono rilevato dal
 * microfono e reso pari ad un segnale "alto" dal 
 * trasduttore, quindi leggibie da arduino.
 * Per il ciclo si usano variabili booleane, commutate
 * a rilevazione avvenuta.
 * i cicli sono due in funzione dell'ordine con cui sono
 * posizionati i sensori
*/
  Serial.println("Batti le mani in prossimità del primo sensore.");
        while(inizio){
        
            if(digitalRead(NOISE_1)){
                tZero = micros();
                inizio = false;
                Serial.println(tZero);
            }
        }
        while(fine){
        
          if(digitalRead(NOISE_2)){
            tUno = micros();
            fine = false;
          }
        }
/*
 * rilevati i due tempi procedo al calcolo del tempo medio
 * ed alla costruzione del vettore TEMPO, poi rendo TRUE le variabili
 * utili ai cicli
 */
        deltaT = (tUno - tZero)/1000;
        Serial.print("t0 = ");
        Serial.println(tZero);
        Serial.print("t1 = ");
        Serial.println(tUno);
        inizio = true;
        fine = true;
        delay(200);        


  Serial.print("Il tempo e': ");
  Serial.print(deltaT);
  Serial.println(" (millisecondi) ");   
  Serial.println("");
  
  double vel = (DIST/100)/(double(deltaT)/1000);
  Serial.print("la velocita' in m/s: ");
  Serial.println(vel);
  Serial.print("Il tempo intercorso tra la prima rilevazione e la seconda è: ");
  Serial.println(deltaT);
  Serial.println();
  
  Serial.println("");

domanda();
 
}
/**************************************************************
 * TEMP() 
 * è il nodo centrale dell'esperimento perchè attraverso
 * questa funzione troviamo il tempo trascorso dall'emissione
 * del segnale alla sua ricezione
 *************************************************************/

double temp(){

  double tempo;
  digitalWrite (TRIG, HIGH);                                        // attraverso il trigger inizia a emettere onde
  delayMicroseconds(10);                                                   // per dieci microsecondi
  digitalWrite(TRIG,LOW);                                           // e si ferma

  long duration =pulseIn(ECHO, HIGH);                                  //attraverso la funzione pulseIn acquisiamo il segnale tramite il sensore
//  Serial.print("duration: ");
//  Serial.println(duration);
//  Serial.print("durata (millisecondi): ");                                 //stampiamo sul monitor seriale la durata del segnale
  double durationInMillis = (float)duration/1000;

//Serial.println(durationInMillis);   
  
  if (duration >500000) { 
          tempo = -1;
          Serial.println("fuori portata");                      //segnaliamo se la distanza è fuori dalla portata dello strumento
  
  }else if(duration == 0){
          
          tempo = -2;
          Serial.println("qualcosa è andato storto");           //segnaliamo se la distanza è fuori dalla portata dello strumento

    
  }else{ 
       // Serial.print("distanza:");  
        tempo = durationInMillis;
          
    }
         
return tempo;  

}


  
/**************************************************** 
 *BUZZER
 *il Buzzer ci permette di iniziare l'esercizio
 ****************************************************/

 void beep(int sec){
      
    digitalWrite (BUZZER, HIGH); 
    delay(sec);
    digitalWrite (BUZZER, LOW); 

 }

 /**************************************************** 
 *SENSORE A ULTRASUONI
 *rileva la distanza attraverso il sensore ad ultrasuoni 
 *a partire dalla conoscenza della velocità
 ****************************************************/

double distanza(){
 
  double distanza;
  
  digitalWrite (TRIG, HIGH);                                        // attraverso il trigger inizia a emettere onde
  delayMicroseconds(10);                                                   // per dieci microsecondi
  digitalWrite(TRIG,LOW);                                           // e si ferma

  long duration =pulseIn(ECHO, HIGH);                                  //attraverso la funzione pulseIn acquisiamo il segnale tramite il sensore
  Serial.print("duration: ");
  Serial.println(duration);
  Serial.print("durata (millisecondi): ");                                 //stampiamo sul monitor seriale la durata del segnale
  double durationInMillis = (float)duration/1000;

  Serial.println(durationInMillis);

  
  if (duration >500000) { 
          Serial.println("fuori portata");                                 //segnaliamo se la distanza è fuori dalla portata dello strumento
  
  }else if(duration == 0){
    
   duration == 1000;
    
  }else{ 
       // Serial.print("distanza:"); 
        distanza = microsecondsToCentimeters(duration);
       // Serial.print(distanza);
       // Serial.println ("cm");
    }
Serial.println();
return distanza;  

}

/*********************************************************
 * questa funzione è necessaria al calcolo della distanza
 * conoscendo la velocità del suono. Utilzza il fattore di 
 * conversione cmconv
 *********************************************************/
double microsecondsToCentimeters(double microseconds){
   return microseconds / cmconv;
  }
 
