const int noteCount= 25;
int melody[noteCount] = {523,523,587,523,698,659,523,523,587,523};
int duration[noteCount] = {375,375,123,500,500,500,1000,375,125,500};
//----------------------------------------
#define melodyPin 11
short beat = 400;
void setup() {
}

void loop() {
for(int i = 0; i < noteCount; i++){
tone(melodyPin, melody[i], duration[i]);
delay (beat);
noTone(melodyPin);
}
}
