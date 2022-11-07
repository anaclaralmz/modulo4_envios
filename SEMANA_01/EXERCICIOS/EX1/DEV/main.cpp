#include <iostream>
#include <string>

using namespace std;
using std::string;

// // 1 -  Faça uma função que recebe uma certa medida e ajusta ela percentualmente
// // entre dois valores mínimo e máximo e retorna esse valor

float converteSensor(int medida, int min, int max){
  	float med = medida - min;
	float intervalo = max - min;
	float resultado = (med/intervalo)*100;

  return resultado;
}

// // testa o exercício 1
// int main(){
//   cout << "Teste Ex 1" << endl;
// 	cout << converteSensor(100,100,400) << endl;
// 	cout << converteSensor(400,100,400) << endl;
// 	cout << converteSensor(250,100,400) << endl;
// }

// // 2 - Faça uma função que simule a leitura de um sensor lendo o
// // valor do teclado. ao final a função retorna este valor

int leComando()
{
	int valor;
	cin >> valor;

	// if (valor== 0  || valor==1){
	return valor;
	// }
		// else{
		
		// cout << "voce precisa inserir apenas 0 ou 1";
		// }
}

// // testa o exercício 2
// int main()
// {
// 	cout << "Digite o Comando (0 ou 1):";
// 	int cmd = leComando();
// 	cout << "Comando Recebido: " << cmd << endl;
// }

// // 3 - Faça uma função que armazena uma medida inteira qualquer
// // em um vetor fornecido. Note que como C não possui vetores
// // nativos da linguagem, lembre-se que você precisa passar o
// // valor máximo do vetor assim como a última posição preenchida
// // Evite também que, por acidente, um valor seja escrito em
// // uma área de memória fora do vetor

int insereVetor(int elemento, int valorMax, int lastPos, int* Vetor){
	if (lastPos < valorMax-1){
		int *vet = Vetor;
		vet[lastPos] = elemento;
		return (lastPos + 1);
	}
 //caso o valor seja escrito em uma área de memória fora do vetor
	else{
		cout<< "Erro: valorMax: 10, lastPos + 1 (indice): 10" << endl;
	}
}

// //testa o exercício 3
// int main(){
//   int valorMax = 10;
//   int lastPos = -1;
//   int Numbers[valorMax];
//   insereVetor(9, valorMax, lastPos, Numbers);
//   lastPos = lastPos + 1;
//   insereVetor(8, valorMax, lastPos, Numbers);
//   lastPos = lastPos + 1;
//   insereVetor(7, valorMax, lastPos, Numbers);
//   lastPos = lastPos + 1;
//   insereVetor(6, valorMax, lastPos, Numbers);
//   lastPos = lastPos + 1;
//   insereVetor(5, valorMax, lastPos, Numbers);
//   lastPos = lastPos + 1;
//   insereVetor(4, valorMax, lastPos, Numbers);
//   lastPos = lastPos + 1;
//   insereVetor(3, valorMax, lastPos, Numbers);
//   lastPos = lastPos + 1;
//   insereVetor(2, valorMax, lastPos, Numbers);
//   lastPos = lastPos + 1;
//   insereVetor(1, valorMax, lastPos, Numbers);
//   lastPos = lastPos + 1;
//   insereVetor(0, valorMax, lastPos, Numbers);
//    lastPos = lastPos + 1;
//    insereVetor(100, valorMax, lastPos, Numbers);
//   cout << "vetor: ";
//   cout << Numbers[0] << "; "; // valor esperado: 9
//   cout << Numbers[1] << "; "; // valor esperado: 8
//   cout << Numbers[2] << "; "; // valor esperado: 7
//   cout << Numbers[3] << "; "; // valor esperado: 6
//   cout << Numbers[4] << "; "; // valor esperado: 5
//   cout << Numbers[5] << "; "; // valor esperado: 4
//   cout << Numbers[6] << "; "; // valor esperado: 3
//   cout << Numbers[7] << "; "; // valor esperado: 2
//   cout << Numbers[8] << "; "; // valor esperado: 1
//   cout << Numbers[9]; // valor esperado: 0
  
// }

// 4 - Faça uma função que recebe um vetor com 4 posições que contém
// o valor da distância de um pequeno robô até cada um dos seus 4 lados.
// A função deve retornar duas informações: A primeira é a direção
// de maior distância ("Direita", "Esquerda", "Frente", "Tras") e a
// segunda é esta maior distância.

char* dirMaiorDist(int* Vetor, int *maiordis){
//   int *maiordis = Vetor[0];
  char *dirmaior[20];
  
  for (int i=0; i<4; i++){
    if (Vetor[i] > *maiordis){
      *maiordis = Vetor[i];
    }
  }

  if (*maiordis == Vetor[0]){
    *dirmaior = "Direita";
  }
    else if (*maiordis == Vetor[1]){
      *dirmaior = "Esquerda";
    }
      else if (*maiordis == Vetor[2]){
        *dirmaior = "Frente";
      }
        else if (*maiordis == Vetor[3]){
          *dirmaior = "Tras";
        }
  return *dirmaior;
}

// int maiorDist(int* Vetor, int* maiordis){
//     int* maiordis = Vetor[0];
//     for (int i=0; i<4; i++){
//       if (Vetor[i] > *maiordis){
//         *maiordis = Vetor[i];
//       }
//     }
//     return *maiordis;
// }

//testa o exercício 4
// int main(){
//   //Considere que os valores sempre serão distintos
//   //Considere valores de distância inteiros entre 0 e 100
//   // "Direita", "Esquerda", "Frente", "Tras"
//   int posicoes [4] = {0, 20, 100, 50};
//   cout << dirMaiorDist(posicoes) << endl;
//   //valor esperado: Frente
//   cout << maiorDist(posicoes) << endl;
//   //valor esperado: 100
//   // "Direita", "Esquerda", "Frente", "Tras"
//   int posicoes2 [4] = {95, 70, 80, 50};
//   cout << dirMaiorDist(posicoes2) << endl;
//   //valor esperado: Direita
//   cout << maiorDist(posicoes2) << endl;
//   //valor esperado: 95
//   // "Direita", "Esquerda", "Frente", "Tras"
//   int posicoes3 [4] = {10, 0, 50, 60};
//   cout << dirMaiorDist(posicoes3) << endl;
//   //valor esperado: Tras
//   cout << maiorDist(posicoes3) << endl;
//   //valor esperado: 60
//   // "Direita", "Esquerda", "Frente", "Tras"
//   int posicoes4 [4] = {54, 55, 30, 0};
//   cout << dirMaiorDist(posicoes4) << endl;
//   //valor esperado: Esquerda
//   cout << maiorDist(posicoes4) << endl;
//   //valor esperado: 55
// }


// 5 - Faça uma função 	 pergunta ao usuário se ele deseja continuar o mapeamento e
// retorna verdadeiro ou falso

int continuar(){
	int parar=1;
	cout << "Digite 0 para parar o mapeamento!" << endl;
  cin >> parar;
	if (parar==0){
    return 0;
  }
  else{
    return 1;
  }
  
}

// // testa o exercício 5

// int main(){
//   int parar = 0;
//   while (parar == 0){
//     parar = continuar();6
//   }
//   //A função deve perguntar: "Digite 1 para parar o mapeamento!"
//   //Se o usuário digitar 1, deve sair do loop while declarado acima
//   // Em caso contrário, continua no loop acima e pergunta novamente
//   return 1;
// }


// 6 - A função abaixo (que está incompleta) vai "dirigindo" virtualmente um robô
// e através de 4 sensores em cada um dos 4 pontos do robo ("Direita", "Esquerda",
// "Frente", "Tras").
//      A cada passo, ele verifica as distâncias aos objetos e vai mapeando o terreno
// para uma movimentação futura.
//      Ele vai armazenando estas distancias em um vetor fornecido como parâmetro
// e retorna a ultima posicao preenchida do vetor.
//      Esta função deve ir lendo os 4 sensores até que um comando de pare seja enviado
//
//      Para simular os sensores e os comandos de pare, use as funções já construídas
// nos ítens anteriores e em um looping contínuo até que um pedido de parada seja
// enviado pelo usuário.
//
//      Complete a função com a chamada das funções já criadas
int dirige(int *v,int maxv){
	int maxVetor = maxv;
	int *vetorMov = v;
	int posAtualVetor = 0;
	int dirigindo = 1;
	while(dirigindo){
		for(int i=0; i<4; i++){
			int medida = leComando();/// .. Chame a função de de leitura da medida para a "Direita"
			medida = converteSensor(medida,0,830);
			posAtualVetor = insereVetor(medida, maxVetor, posAtualVetor, vetorMov);// Chame a função para armazenar a medida no vetor
        
		}
		///////////////////////////////////////////////////////////////////////////
    
		// Repita as chamadas acima para a "Esquerda", "Frente", "Tras"
		// ................
		///////////////////////////////////////////////////////////////////////////
		dirigindo = continuar();
	}
	return posAtualVetor;
}

// O trecho abaixo irá utilizar as funções acima para ler os sensores e o movimento
// do robô e no final percorrer o vetor e mostrar o movimento a cada direção baseado
// na maior distância a cada movimento
void percorre(int *v,int tamPercorrido){
	int *vetorMov = v;
	int maiorDir = 0;

	for(int i = 0; i< tamPercorrido; i+=4){
		char *direcao = dirMaiorDist(&(vetorMov[i]), &maiorDir);
		printf("Movimentando para %s distancia = %i\n",direcao,maiorDir);
	}
}

int main(int argc, char** argv) {
	int maxVetor = 100;
	int vetorMov[maxVetor*4];
	int posAtualVet = 0;

	posAtualVet = dirige(vetorMov,maxVetor);
	percorre(vetorMov,posAtualVet);

	return 0;
}