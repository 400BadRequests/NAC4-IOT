//Comunicação Serial
#include <ArduinoJson.h> //Biblioteca json do arduino
const int TAMANHO = 600;//Setando o espaço de memoria em bits da comunicação Serial
float termistor_json;
float luminosidade_json;

//Termistor
float temperatura_sensor_term = 0;
int pin_sensor_temperatura_term = A0; //Entrada termistor
// Parâmetros do termistor
const double beta = 3600.0;
const double r0 = 10000.0;
const double t0 = 273.0 + 25.0;
const double rx = r0 * exp(-beta/t0);
const int nAmostras = 10; // Numero de amostras na leitura
// Parâmetros do circuito
const double vcc = 5.0;
const double R = 10000.0;

//Botão
int btn_change = 4;
int change = 0;
bool start = false;

//Parametros LDR
float r_Ldr;
double lux_Ldr;
double l_ldr;
int sensor_Ldr_pino = A2;

//Secao gerador de funcao
int pin_gerador_pulso = 2; // Gerador de Pulso
float velocidade_sensor_freq = 0;
// Parâmetros 
const float r = 2.0;
const float pi = 3.14;
// Numero de amostras na leitura
const int nAmostras_wind = 2;

void setup(){
  Serial.begin(115200);
  pinMode(btn_change, INPUT_PULLUP);
  pinMode(sensor_Ldr_pino, INPUT);
  pinMode(pin_sensor_temperatura_term, INPUT);
  //O valor padrão de 1000ms é muito tempo
  Serial.setTimeout(10);
  pinMode(pin_gerador_pulso, INPUT);
}

void loop(){
    temperatura_sensor_term = temperatura_termistor(pin_sensor_temperatura_term);
    lux_Ldr = luminosidade_ldr(sensor_Ldr_pino);
    velocidade_sensor_freq = velocidade_vento(pin_gerador_pulso);
    sendNodeRed();
}

float temperatura_termistor(int sensor){
    int soma = 0;
    for (int i = 0; i < nAmostras; i++) {
        soma += analogRead(sensor);
        delay (10);
    }
    // Determina a resistência do termistor
   double v = (vcc*soma)/(nAmostras*1024.0);
   double rt = (vcc*R)/v - R;
   
   // Calcula a temperatura
   double t = beta / log(rt/rx);
   return t-273.0;
}

float luminosidade_ldr(int sensor){
	 float leitura_Ldr =  analogRead(sensor);
	 float r1_Ldr = 10000;
	 float vcc_Ldr = 1023;
	 float rDark_Ldr = 127410;
	 float alpha = 1 / 0.858;
	 r_Ldr = r1_Ldr / ((vcc_Ldr / leitura_Ldr) - 1); 
	 float res_Ldr = rDark_Ldr/r_Ldr;
	 l_ldr = pow(res_Ldr, alpha);
     return l_ldr;
}

float velocidade_vento(int sensor){
  // Le o sensor algumas vezes
  	float freq = 0;
	for (int i = 0; i < nAmostras_wind; i++) {
    		freq += digitalRead(sensor);
    		delay (10);
  	}
  	// Determina a velocidade angular
	float w = 0.0;
	w = (2 * pi) * freq;

	// Determina a velocidade tangencial 
	float v = w * r;

	// Converte o resultado de m/s para km/h	 
	float v_km = v * 3.6;
	
	return v_km;
}

void sendNodeRed(){
  //formato de leitura no node-red
  StaticJsonDocument<TAMANHO> json; //cria o objeto Json e aloca um pedaço de bits na memoria 
  json["topic_ldr"] = "Luminosidade"; //topico do json
  json["msgpayload_ldr"] = lux_Ldr; //Valor do topico, valor da chave
  json["topic_term"] = "Temperatura"; //topico do json
  json["msgpayload_term"] = temperatura_sensor_term; //Valor do topico, valor da chave
  json["topic_wind"] = "Valocidade do vento"; //topico do json valocidade do vento
  json["msgpayload_wind"] = velocidade_sensor_freq; //Valor do topico, valor da chave
  serializeJson(json, Serial); //Serializa e envia na serial
  Serial.println();
}