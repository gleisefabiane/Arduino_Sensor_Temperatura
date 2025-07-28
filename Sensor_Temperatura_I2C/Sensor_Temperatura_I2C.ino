
//Sensor de temperatura usando o LM35 e I2C

#include <LiquidCrystal_I2C.h> // comunicação com display
#include <Wire.h> // comunicação I2C

// display

#define col 16 // Define o numero de colunas do display utilizado
#define lin  2 // Define o numero de linhas do display utilizado
#define ende  0x27 // Define o endereço do display.. vide site blog robótica

LiquidCrystal_I2C lcd(ende,col,lin); // Chamada da funcação LiquidCrystal para ser usada com o I2C

// sensor de temperatura

const int LM35 = A0; // Define o pino que lera a saída do LM35
float temperatura; // Variável que armazenará a temperatura medida
 

void setup() {

// LCD
  lcd.init(); // Serve para iniciar a comunicação com o display já conectado
  lcd.backlight(); // Serve para ligar a luz do display
  lcd.clear(); // Serve para limpar a tela do display  
  
  Serial.begin(9600); // inicializa a comunicação serial
}
 
//Função que será executada continuamente
void loop() {

temperatura = (float(analogRead(LM35))*5/(1023))/0.01-4;
  Serial.print("Temperatura: ");
  Serial.println(temperatura);

  lcd.setCursor(1,0); // Coloca o cursor do display na coluna 1 e linha 1
  lcd.print("TEMPERATURA:"); // Comando de saída com a mensagem que deve aparecer na coluna 2 e linha 1.
  lcd.setCursor(1, 1); //Coloca o cursor do display na coluna 1 e linha 2
  lcd.print(temperatura);  // Comando de saida com a mensagem que deve aparecer na coluna 2 e linha 2

  delay(1000);

  lcd.clear(); // Limpa o display até o loop ser reiniciado
}