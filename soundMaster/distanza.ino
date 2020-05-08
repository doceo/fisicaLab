
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

 /********************************************************
  * attraverso questa funzione calcoliamo un codice di 
  * onversione che ci permette di calcolare la distanza 
  * a partire dalla velocità del suono nota
  *******************************************************/

  void conv(double vel){
    
    cmconv = vel/1000;
 
  }
