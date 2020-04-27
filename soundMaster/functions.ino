 
  
/**************************************************** 
 *SENSORE A ULTRASUONI
 *deve avviare la sequenza di rilevazioni e poi   
 *fissare la distanza delloo SLAVE
 ****************************************************/

double dist(){
 
  double distanza;
  
  digitalWrite (TRIG, HIGH);                                        // attraverso il trigger inizia a emettere onde
  delayMicroseconds(10);                                                   // per dieci microsecondi
  digitalWrite(TRIG,LOW);                                           // e si ferma

  long duration =pulseIn(ECHO, HIGH);                                  //attraverso la funzione pulseIn acquisiamo il segnale tramite il sensore
  
  Serial.print("durata (millisecondi): ");                                 //stampiamo sul monitor seriale la durata del segnale
  double durationInMillis = (float)duration/1000;

  Serial.println(durationInMillis);

  
  if (duration >38000) { 
          Serial.println("fuori portata");                                 //segnaliamo se la distanza è fuori dalla portata dello strumento
  
  }else if(duration == 0){
    
   duration == 1000;
    
  }else{ 
       // Serial.print("distanza:"); 
        distanza = microsecondsToCentimeters(duration);
       // Serial.print(distanza);
       // Serial.println ("cm");
    }
         
return distanza;  

}

double microsecondsToCentimeters(double microseconds)
  {
   return microseconds / cmconv;
  }
  

  
/**************************************************** 
 *SENSORE DI RUMORE
 *se il microfono percepisce un rumore compie 
 *un giro completo
 ****************************************************/

void noiseLevel(){


   noiseValue = analogRead(NOISE);
 //     Serial.println (noiseValue, DEC);
 
}

  
/**************************************************** 
 *BUZZER
 *il Buzzer ci permette di iniziare l'esercizio
 ****************************************************/

 void beep(){
      
    digitalWrite (BUZZER, HIGH); 
    delay(100);
    digitalWrite (BUZZER, LOW); 

 }
 
 