
int portas[] = {13,12,11,10,9,8};
int leds_pedestre[] = {5, 7, 4, 6};
int botoes_ped[] = {3, 2};
int vermelho = 0;
int verde = 2;
int amarelo = 1;
/* CORES DO SEMAFORO NAS PORTAS DO ARDUINO
 sinaleiro 1
13 - vermelho 
12 - amarelo 
11 - verde 

 sinaleiro 2
10 - vermelho 
9 - amarelo 
8 - verde 
*/
int potenciometro = A5; // potenciometro e o fluxo de carros no sinaleiro 1
void setup()
{
  for(int i = 0; i < sizeof(portas)/sizeof(int) ; i++) {
    pinMode(portas[i],OUTPUT);
  }
  pinMode(potenciometro, INPUT);
  Serial.begin(9600);
  ligarLedSin(1, 1);
  ligarLedSin(2, 3);
  ligarLedPed(2,1);
  attachInterrupt(digitalPinToInterrupt(botoes_ped[0]), interromperSinal1, FALLING);
  attachInterrupt(digitalPinToInterrupt(botoes_ped[1]), interromperSinal2, FALLING);
}

float DelayTotalEntreSinais = 30000; // esse e so o delay TOTAL da troca de sinais, mas ainda ele mapea de acordo com o potenciometro entao nunca vai ser exatamente isso
int delayPadrao = 5000; // esse e o valor do delay na hora de ir de um led para o outro
int delayped1 = 0; // valor adicional do delay quando o pedestre aperta o botao
int delayped2 = 0;

void loop()
{
  float d1 = pegarEntreMudanca();
  float d2 = DelayTotalEntreSinais - d1;
  Serial.print("DELAY PARA OS PEDESTRES DO SINALEIRO 1 PASSAR: ");
  Serial.println(d2 + delayped1);
  pisca_led_ped(1, d2+ delayped1); // essa funcao serve como o delay() e pra pisca o led, o primeiro valor e o sinaleiro pra liga e o segundo a duracao do delay
  delayped1 = 0;
  SinalVerde(1);
  Serial.print("DELAY PARA OS PEDESTRES DO SINALEIRO 2 PASSAR: ");
  Serial.println(d1 + delayped2);
  pisca_led_ped(2, d1+ delayped2); 
  delayped2 = 0;
  SinalVerde(2);
}

float pegarEntreMudanca(){
  float entreMudanca;
  if(analogRead(potenciometro) > 342){
    entreMudanca = map(analogRead(potenciometro), 342, 1023, 500, 667); 
  } else{
    entreMudanca = map(analogRead(potenciometro), 0, 341, 250, 500); 
  }
  entreMudanca = DelayTotalEntreSinais * (entreMudanca/1000);
  return entreMudanca;
  //Serial.println(entreMudanca);
  //Serial.println(analogRead(potenciometro));
}

void interromperSinal1(){
  delayped1 = 8000;
  Serial.println("BOTAO 1 PRECIONADO");
}
void interromperSinal2(){
  delayped2 = 10000;
  Serial.println("BOTAO 2 PRECIONADO");
}

void ligarLedSin(int sinaleiro, int nLed){ // 1 - vermelho, 2 - amarelo, 3 - verde
  int a = 0;
  if(sinaleiro == 2){a = 3;}
  switch(nLed){
    case 3:
      digitalWrite(portas[vermelho + a], LOW);
      digitalWrite(portas[amarelo + a], LOW);
      digitalWrite(portas[verde + a], HIGH);
    break;
    case 2:
      digitalWrite(portas[vermelho + a], LOW);
      digitalWrite(portas[amarelo + a], HIGH);
      digitalWrite(portas[verde + a], LOW);
    break;
    case 1:
      digitalWrite(portas[vermelho + a], HIGH);
      digitalWrite(portas[amarelo + a], LOW);
      digitalWrite(portas[verde + a], LOW);
    break;
  }
}
void ligarLedPed(int sinaleiro, int led){
  if(sinaleiro == 2){sinaleiro = 3;}
  digitalWrite(leds_pedestre[sinaleiro-1+(led - 1)], HIGH);
}
void desligarLedPed(int sinaleiro, int led){
  if(sinaleiro == 2){sinaleiro = 3;}
  digitalWrite(leds_pedestre[sinaleiro-1+(led - 1)], LOW);
}

void pisca_led_ped(int sinaleiro, int tempo){ // inclui o delay()
  long temp_comeco = millis();
  int intervalo;
  while(millis() - temp_comeco <= tempo){
    intervalo = map(millis() - temp_comeco, 0, tempo, 500, 50);
    ligarLedPed(sinaleiro, 2); // 2 pra verde
    delay(intervalo);
    if(millis() - temp_comeco >= tempo*0.4){
      desligarLedPed(sinaleiro, 2);
      delay(intervalo);
    }
  }
  desligarLedPed(sinaleiro, 2);
}

void SinalVerde(int sinaleiro){
  switch(sinaleiro){
    case 1:
      ligarLedSin(2, 2);
      ligarLedPed(1, 1);
      delay(delayPadrao);
      ligarLedSin(2, 1);
      delay(delayPadrao);
      ligarLedSin(1, 3);
      desligarLedPed(2, 1);
    break;
    case 2:
      ligarLedSin(1, 2);
      ligarLedPed(2, 1);
      delay(delayPadrao);
      ligarLedSin(1, 1);
      delay(delayPadrao);
      ligarLedSin(2, 3);
      desligarLedPed(1, 1);
    break;
  }
}