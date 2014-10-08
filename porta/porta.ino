#define NUM_BUTS 3
int but[NUM_BUTS] = {2, 3, 4};
int led[2] = {5, 6}; // 5 - vermelho; 6 - verde
int* sequencia;

void setup() {
  int i;
  Serial.begin(9600);
  
  for (i = 0; i < NUM_BUTS; ++i)
  { pinMode(but[i], INPUT); }
  
  for (i = 0; i < 2; ++i)
  { pinMode(led[i], OUTPUT); }
  pinMode(14, INPUT);
}



int* gerar_sequencia()
{
  int* nova_sequencia = (int*) malloc(sizeof(int)*NUM_BUTS);
  int numeroAleatorio;
  
  Serial.print("# ");
  srand(analogRead(14));
  for (int i = 0; i < NUM_BUTS; ++i)
  { 
    numeroAleatorio = rand() % NUM_BUTS;
    Serial.print(numeroAleatorio);
    nova_sequencia[i] = numeroAleatorio;
  }
  
  Serial.println();
  return nova_sequencia;
}

void fechar_porta()
{
  digitalWrite(led[0], HIGH);
  digitalWrite(led[1], LOW);
  sequencia = gerar_sequencia();
  delay(500);
}

void abrir_porta()
{
  digitalWrite(led[0], LOW);
  digitalWrite(led[1], HIGH);
  delay(1000);
}

int ler_botao()
{
  boolean flag = true;
  int porta = 0;
  
  while (flag)
  {
    if (porta == NUM_BUTS) 
    {
      porta = 0;
      delay(2);
    }
    
    while (digitalRead(but[porta]) == HIGH)
    {
      flag = false;
      delay(5);
    }
    porta++;
    delay(2);
  }
 
  
  return porta - 1;
}

int comparar_sequencias(int* nova_sequencia)
{
  int i;
  int flag;
  
  flag = 1;
  
  for(i=0; i<NUM_BUTS; i++)
  {  
    if (nova_sequencia[i]!= sequencia[i])
     flag = 0; 
  }
  return flag;
}
  
void ler_sequencia()
{
  boolean flag = false;
  int nova_sequencia[NUM_BUTS];
  int numero; 
  
  while (!flag)
  {
    Serial.print("  + ");
    for (int i = 0; i < NUM_BUTS; ++i)
    {
      numero = ler_botao();
      Serial.print(numero);
      nova_sequencia[i] = numero;
    }
    Serial.println();
    
    flag = comparar_sequencias(nova_sequencia);
    
  }
}

void loop() {
  fechar_porta();
  ler_sequencia();
  abrir_porta();
}
