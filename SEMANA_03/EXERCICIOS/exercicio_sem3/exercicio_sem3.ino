#define LDR 4
#define LED1 20
#define LED2 48
#define LED3 36
#define LED4 40
#define buzzer 16
#define button1 1
#define button2 2

//vetor que armazena o numero binario
int vBinario[4];

//vetor que irá armazenar os 4 valores anteriores
int vetor2[4];

//contador inicial para o vetor2
int cont = 0;

//funções para o botao1
  // transformar valor do LDR entre intervalo 0-15
int valorLDR(float lux, int min, int max){
  float luxprop = lux - min;
	float intervalo = max - min;
	float quase = (luxprop/intervalo);
  int resultado = (quase * 16);

  return resultado;
}
// transformar valor anterior em binario,  e armazenar em vetor (cada algarismo em uma posição)
void valorBinario(int luxNovo, int* Vetor){
  int *vet = Vetor;
  int posicao = 0;
  while (luxNovo != 1){
    if(luxNovo%2==0){
      vet[posicao]= 0;
      luxNovo = luxNovo/2;
      posicao += 1;
    }
      else{
        vet[posicao]= 1;
        luxNovo = (luxNovo-1)/2;
        posicao += 1;
      }
  
  }
}

void saidasLED(int Vetor[]){
  if (Vetor[0]== 1){
    digitalWrite(LED1, HIGH);
    Serial.println("led1 acesso");
  }
  if (Vetor[1]== 1){
    digitalWrite(LED2, HIGH);
    Serial.println("led2 acesso");
  }
  if (Vetor[2]== 1){
    digitalWrite(LED3, HIGH);
    Serial.println("led3 acesso");
  }
  if (Vetor[3]== 1){
    digitalWrite(LED4, HIGH);
    Serial.println("led3 acesso");
  }
  delay(1000);
  Serial.println("ressetou");
    //resetar LEDs
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
}

//o buzzer sempre vai apitar um som, diferente para cada combinação
void saidaBuzzer(int valueLDR){
  if (valueLDR==0){
    tone(buzzer, (600*20), 1000);
  }
  else{
  tone(buzzer, (600*valueLDR), 1000);
  }
}


void setup() {
  Serial.begin(9600);

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(LDR, INPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {

  float lux = analogRead(LDR);
  // Serial.println("lux");
  // Serial.println(lux);
  delay(1000);

  int minimo = 0;
  int maximo = 4095;

  //chamada de funções para o botão 1
  if (digitalRead(button1)==0){
    int novoLux = valorLDR(lux,minimo, maximo);
    // Serial.println("novo lux");
    // Serial.println(novoLux);
    valorBinario(novoLux, vBinario);
    // for (int i=0;i<4;i++){
    //   Serial.print(vBinario[i]);
    // }
    saidaBuzzer(novoLux);
    saidasLED(vBinario);
    
    //adiciona o lux no vetor2
    vetor2[cont] = lux;
    cont += 1;
  }
  delay(1000);

  // //chamada de funções para o botão 2
  if (digitalRead(button2)==0){
    for (int i=0; i<4; i++){
      int novoLux = valorLDR(vetor2[i],minimo, maximo);
      valorBinario(novoLux, vBinario);
      saidaBuzzer(novoLux);
      saidasLED(vBinario);
      delay(1000);
    }

    //esvazia o vetor2
    for (int j = cont; j <= 0; j--){
      vetor2[j] = 0;
      
    }
    cont=0;
  }
  delay(1000);
}