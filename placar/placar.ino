
int p [] = {13,12,10,9,8,7,6,5};
int tam = 8;
bool on = true;

void setup()
{
  for(int i = 0; i<tam; i++)
  { 
    pinMode (p[i], OUTPUT);
    digitalWrite (p[i], on);
  }
  
}

void loop()
{
  //for(int i = 0; i<tam; i++)
  
    digitalWrite(13, !on);
    digitalWrite(12, !on);
    digitalWrite(6, !on);
    digitalWrite(10, !on);
    digitalWrite(8, !on);
    digitalWrite(9, !on);
//    delay(1000);
  
}
