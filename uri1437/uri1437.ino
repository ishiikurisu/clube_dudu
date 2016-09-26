int readInt() {
  int result;
  char junk;

  while (Serial.available() == 0);
  result = Serial.parseInt();
  while (Serial.available() > 0)
    junk = Serial.read();
  
  return result;
}

String analize(long result)
{
  long bacon = abs(result % 4);
  String dir = "N";
  
  switch (bacon) {
    case 1:
      dir = "L"; break;
    case 2:
      dir = "S"; break;
    case 3:
      dir = "O"; break;
  }
  
  return dir;
}

String func(String arg) {
  long result = 0;
  
  for (long i = 0; i < arg.length(); ++i)
    if (arg.charAt(i) == 'D')
      ++result;
    else
      --result;
  
  return analize(result);
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  int instructions = readInt();
  Serial.println(func(Serial.readString()));
}
