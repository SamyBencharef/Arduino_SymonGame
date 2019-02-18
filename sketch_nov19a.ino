const int led[4] = {7,6,5,4};
const int button[4] = {12,11,10,9};
const int buzzer = 2;
const int sound[4] = {256, 325, 387, 518};

int i = 0,lights[99], compt=1, score=0, j=0;
boolean game = false;

void setup() {
  for(i=0;i<4;i++){
    pinMode(led[i],OUTPUT);
    pinMode(button[i],INPUT);
  }
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  randomSeed(analogRead(0));
}


void loop() 
{
  if( game==false ){
    startSong();
  }
  
  game=true;
  
  Serial.print("Round : ");
  Serial.println(compt);
  
  lights[compt-1]=random(4);
  for(i=0;i<compt;i++){
    digitalWrite(led[lights[i]], HIGH);
    tone(buzzer, sound[lights[i]]);
    delay(333);
    digitalWrite(led[lights[i]], LOW);
    noTone(buzzer);
    delay(333);
      }
 
 i=0;
 while( i<compt && game==true){
  for(j=0;j<4;j++){
    if(digitalRead(button[j]) == HIGH){
        digitalWrite(led[j], HIGH);
        tone(buzzer, sound[j]);
        delay(333);
        digitalWrite(led[j], LOW);
        noTone(buzzer);
        delay(333);
        if(j==lights[i]){
          i = i + 1 ;
        }else{
          score = 0;
          compt = 0;
          game = false;
          looseSong();
          Serial.println("You loose!");
        }
      }
    }
  }
  if ( game == true ) {
    score = score + 1;
    winSong();
    Serial.print("Score : ");
    Serial.println(score);
  }
  compt = compt + 1;
}


void startSong() 
{
  for(i=0;i<4;i++){
    digitalWrite(led[i], HIGH);
  }
  for(i=0;i<4;i++){
    tone(buzzer, sound[i]);
    delay(250);
  }
  for(i=0;i<4;i++){
    digitalWrite(led[i], LOW);
  }
  noTone(buzzer);
  delay(1500);
}

void winSong() 
{
  for(i=0;i<4;i++){
    digitalWrite(led[i], HIGH);
  }
  for(i=0;i<4;i++){
    tone(buzzer, sound[i]);
    delay(150);
  }
  for(i=0;i<4;i++){
    digitalWrite(led[i], LOW);
  }
  noTone(buzzer);
  delay(1500);
}

void looseSong()
{
  for(i=0;i<4;i++){
    digitalWrite(led[i], HIGH);
  }
  tone(buzzer, sound[3]);
  delay(150);
  for(i=0;i<4;i++){
    digitalWrite(led[i], LOW);
  }
  delay(150);
  for(i=0;i<4;i++){
    digitalWrite(led[i], HIGH);
  }
  tone(buzzer, sound[2]);
  delay(150);
  for(i=0;i<4;i++){
    digitalWrite(led[i], LOW);
  }
  tone(buzzer, sound[1]);
  delay(150);
  for(i=0;i<4;i++){
    digitalWrite(led[i], HIGH);
  }
  tone(buzzer, sound[0]);
  delay(150);
   for(i=0;i<4;i++){
    digitalWrite(led[i], LOW);
  }
  delay(500);
  noTone(buzzer);
  delay(1500);
}
