 
  
/**************************************************** 
 *SENSORE A ULTRASUONI
 *deve avviare la sequenza di rilevazioni e poi   
 *fissare la distanza delloo SLAVE
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

/*
 * questa funzione è necessaria al calcolo della distanza
 * conoscendo la velocità del suono. Utilzza il fattore di 
 * conversione cmconv
 */
double microsecondsToCentimeters(double microseconds){
   return microseconds / cmconv;
  }

/*
 * temp() è il nodo centrale dell'esperimento perchè attraverso
 * questa funzione troviamo il tempo trascorso dall'emissione
 * del segnale alla sua ricezione
 */

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

  Serial.println(durationInMillis);   
  
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
 
 
