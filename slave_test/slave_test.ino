
#define NOISE 6

unsigned long tInit, tFinal;
bool start=true;

void setup() {
  // put your setup code here, to run once:

pinMode(NOISE, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

if(digitalRead(NOISE)){
tInit = micros();



}
