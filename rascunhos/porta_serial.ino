#define NUM_BUTS 3
#define TAM_SEQ 5
int but[NUM_BUTS] = {2, 3, 4};
int led[2] = {5, 6}; // 5 - vermelho; 6 - verde
int* sequencia;

void setup() {
  int i;
  Serial.begin(9600);
  Serial.flush();

  for (i = 0; i < NUM_BUTS; ++i)
  { pinMode(but[i], INPUT); }

  for (i = 0; i < 2; ++i)
  { pinMode(led[i], OUTPUT); }
  pinMode(14, INPUT);
}



int* gerar_sequencia()
{
  int* nova_sequencia = (int*) malloc(sizeof(int)*TAM_SEQ);
  int numeroAleatorio;

  Serial.print("# ");
  srand(analogRead(14));
  for (int i = 0; i < TAM_SEQ; ++i)
  {
    numeroAleatorio = rand() % NUM_BUTS + 1;
    Serial.print(numeroAleatorio);
    Serial.print(" ");
    nova_sequencia[i] = numeroAleatorio;
  }

  Serial.println();
  return nova_sequencia;
}

void fechar_porta()
{
  digitalWrite(led[0], HIGH);
  digitalWrite(led[1], LOW);
  Serial.println("XXX");
  sequencia = gerar_sequencia();
  delay(500);
}

void abrir_porta()
{
  digitalWrite(led[0], LOW);
  digitalWrite(led[1], HIGH);
  Serial.println("$$$");
  delay(1000);
}

int ler_botao()
{
  int porta;

  do
  {
    porta = Serial.parseInt();
  }
  while (porta == 0);

  return porta;
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
  int nova_sequencia[TAM_SEQ];
  int numero;

  while (!flag)
  {
    Serial.print("  + ");
    for (int i = 0; i < TAM_SEQ; ++i)
    {
      numero = ler_botao();
      Serial.print(numero);
      Serial.print(" ");
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
