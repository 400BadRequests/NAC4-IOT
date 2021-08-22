//Parametros 
float r_Ldr;
double lux_Ldr;
double l_ldr;
int sensor_Ldr_pino = A2;



void setup(){
  Serial.begin(115200);
  pinMode(sensor_Ldr_pino, INPUT);
  //O valor padrão de 1000ms é muito tempo
  Serial.setTimeout(10);
}

void loop(){
     lux_Ldr = luminosidade_ldr(sensor_Ldr_pino);
	Serial.println(lux_Ldr);
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

void sendNodeRed(float valor, String chave){
  //formato de leitura no node-red
  StaticJsonDocument<TAMANHO> json; //cria o objeto Json e aloca um pedaço de bits na memoria 
  json["topic"] = chave; //topico do json
  json["msgpayload"] = valor; //Valor do topico, valor da chave
  serializeJson(json, Serial); //Serializa e envia na serial
  Serial.println();
}