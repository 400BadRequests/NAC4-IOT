int pin_sensor_temperatura_term = A1; //Entrada termistor
float temperatura_sensor_term = 0;

// Parâmetros do termistor
const double beta = 3600.0;
const double r0 = 10000.0;
const double t0 = 273.0 + 25.0;
const double rx = r0 * exp(-beta/t0);

// Numero de amostras na leitura
const int nAmostras = 2;

// Parâmetros do circuito
const double vcc = 5.0;
const double R = 10000.0;
int contagem_last;
float templast_user, templast_term;

void setup() {
	 pinMode(pin_sensor_temperatura_term, INPUT);
	 Serial.begin(9600);

}

void loop() {
	serial();
	temperatura_sensor_term = temperatura_termistor(pin_sensor_temperatura_term);

}

void serial(){
	Serial.print(" |Temp. Medida: ");
	Serial.print(temperatura_sensor_term);
	Serial.println("");
}

float temperatura_termistor(int sensor){
  // Le o sensor algumas vezes
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