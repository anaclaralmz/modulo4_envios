//---------codigo para interface web---------
#include "WiFi.h"
#include "ESPAsyncWebServer.h"

// Rede de wi-fi que será utilizada
const char *ssid = "SHARE-RESIDENTE";

// senha da rede wi-fi utilizada
const char *password = "Share@residente";

AsyncWebServer server(80);
//---------codigo para interface web---------


//definição das portas de entrada

#define button0 4  //botão do vermelho
#define button1 5  //botão do azul
#define button2 6  //botão do amarelo

//definição das portas de saída

#define LED0 1     //LED vermelho
#define LED1 2     //LED azul
#define LED2 42    //LED amarelo
#define LED3 7     //LED verde - serve para avisar quando devo clicar nos botoes
#define buzzer 41  //buzzer


//criação de variaveis para armazenar algumas informações uteis

int Led[3] = { LED0, LED1, LED2 };
int Button[3] = { button0, button1, button2 };
int Sequencia[100];    // sequencia de até 100 numeros, que representa os LEDs que vão ser acesos
int Round = 0;         //contador de rounds
int BotaoPressionado;  //armazena qual botão foi pressionado
bool Flag = true;     
String status = "O jogo começou!"; 


//definição de funções que serão chamadas no loop

//função que adiciona uma nova cor - com uma função random - a cada round
void gerarRodada() {
  Sequencia[Round] = random(0, 3);
  acenderSequencia();  //acende e apaga o LED que foi indicado na random()
  Round++;             //adiciona +1 ao contador declarado no inicio
}

//função utilizada a cima para acender e apagar o LED
void acenderSequencia() {
  for (int h = 0; h <= Round; h++) {
    digitalWrite(Led[Sequencia[h]], HIGH);
    delay(500);
    digitalWrite(Led[Sequencia[h]], LOW);
    delay(500);
  }
  delay(3000);
}

// verifica se o botão pressionado é igual ao botão que foi aceso
void checarInput() {
  for (int j = 0; j < Round; j++) {
    Flag = true;
    while (Flag) {
      if (digitalRead(button0) == LOW) {
        BotaoPressionado = 0;
        Serial.println("vermelho");
        Flag = false;
      } else if (digitalRead(button1) == LOW) {
        BotaoPressionado = 1;
        Serial.println("azul");
        Flag = false;
      } else if (digitalRead(button2) == LOW) {
        BotaoPressionado = 2;
        Serial.println("amarelo");
        Flag = false;
      }
    }
    delay(200);  // evita efeito de bouncing do botão

    Serial.println("botao press:");
    Serial.println(BotaoPressionado);
    Serial.println("sequencia:");
    Serial.println(Sequencia[j]);

    //se o botão pressionado for o correto
    if (BotaoPressionado == Sequencia[j]) {
      //print na tela
      Serial.println("Acertou!");
      status = "Acertou!";
      //som de acerto
      tone(buzzer, 9000, 1000);

    }

    //se o botão pressionado for o errado
    else {
      //print na tela
      Serial.println("Errou :(");
      status = "Você errou! O jogo será reiniciado :(";
      //som de erro
      tone(buzzer, 7000, 1000);

      Round = 0;
    }
    delay(1000);
  }
}


//------------codigo para a interface web----------------
// essa função será responsavel pelo html que aparecerá na interface web
String html() {
  String html = "";
  html += "<meta name=\"viewport\" content=\"width=device-width, "
          "initial-scale=1\">";
  html += "<title>Relatorio</title>";
  html += "<style>html { display: inline-block; "
          "margin: 0px auto; text-align: center;}";
  html += "@media screen and (max-width: 480px){";
  html += ".content{width: 94%;}";
  html += ".rTable thead{display: none;}";
  html += ".rTable tbody td{";
  html += "    display: flex;";
  html += "    flex-direction: column;";
  html += "}";
  html += " .rTable tbody td{";
  html += "    display: flex;";
  html += "    flex-direction: column;";
  html += "}";
  html += "}";
  html += "@media screen and (min-width: 1200px){";
  html += "    .content{width: 100%;}";
  html += "    .rTable th , rTable td{padding: 7px 0;}";
  html += "    .rTable tbody tr td:nth-child(1){width:10%}";
  html += "    .rTable tbody tr td:nth-child(2){width:10%}";
  html += "    .rTable tbody tr td:nth-child(3){width:10%}";
  html += "    .rTable tbody tr td:nth-child(4){width:10%}";
  html += "}";
  html += "*{";
  html += "margin: 0;";
  html += "padding: 0;";
  html += "box-sizing: border-box;";
  html += "align-items: center;";
  html += "}";
  html += ".content{";
  html += "    display: flex;";
  html += "    margin: auto;";
  html += "}";
  html += ".rTable{";
  html += "    width: 100%;";
  html += "    text-align: center;";
  html += "    font-size: 20px;";
  html += "}";
  html += "h1{";
  html += "    font-size: 30px;";
  html += "    padding-bottom: 20px;";
  html += "    text-align: center;";
  html += "    font-weight: bold;";
  html += "    text-color: pink;";
  html += "}";
  html += "</style>";
  html += "</head>";

  html += "<body>";
  html += "<div class=\"container\">";
  html += "  <table class=\"table\">";
  html += " <thead>";
  html += "   <tr>";
  html += "     <th id=\"main\">ID</th>";
  html += "      </tr>";
  html += "    </tbody>";
  html += "  </table>";
  html += "</div>";
  html += "<script>setTimeout(() => (window.location.href = '/'), 1000)</script>"; //responsavel por atualizar a pagina a cada 1s
  html += "</body>";

  html += "<h1>Jogo da Clarinha</h1>";
  html += "</br>";
  html += "<h2>Como jogar</h2>";
  html += "<p>1. O jogo se inicia com o primeiro apito </p>";
  html += "<p>2. Aperte o botão assim que o LED verde acender </p>";
  html += "</br>";
  html += "</br>";
  html += "<h2>Rodada:</h2>";
  html += "<h3>" + String(Round) + "</h3> ";
  html += "</br>";
  html += "<h2>" + String(status) + "</h2> ";
  html += "</div>";
  return html;
}
//------------codigo para a interface web----------------

//função de setup que rodará no inicio do programa
void setup() {
  Serial.begin(9600);

  pinMode(buzzer, OUTPUT);
  pinMode(LED3, OUTPUT);

  for (int i = 0; i < 3; i++) {
    pinMode(Button[i], INPUT_PULLUP);
    pinMode(Led[i], OUTPUT);
  }

  //a função abaixo serve para que a geração de sequências seja praticamente aleatória
  //conta o numero em milisegundos desde que o programa iniciou
  randomSeed(millis());

  //-----------codigo para a interface web----------------
  Serial.println("Conectando ao wifi...");
  while (WiFi.status() != WL_CONNECTED) {
    WiFi.begin(ssid, password);
    delay(800);
    Serial.print(".");
  }

  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *req) {
    req->send(200, "text/html; charset=UTF-8", html());
  });

  server.begin();
}

//função que rodará repetidamente durante o programa, e chama as funções definidas anteriormente
void loop() {
  digitalWrite(LED3, LOW);
  delay(2000);
  //apita pra avisar que começou
  tone(buzzer, 9000, 1000);

  delay(1000); 
  gerarRodada();
  digitalWrite(LED3, HIGH);  //avisa quando posso clicar

  checarInput();
}