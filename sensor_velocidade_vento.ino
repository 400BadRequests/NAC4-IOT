int pin_gerador_pulso = 2; // Gerador de Pulso
float velocidade_sensor_freq = 0;

// Parâmetros 
const float r = 2.0;
const float pi = 3.14;


// Numero de amostras na leitura
const int nAmostras = 2;

void setup() {
	 pinMode(pin_gerador_pulso, INPUT);
	 Serial.begin(9600);

}

void loop() {
	velocidade_sensor_freq = velocidade_vento(pin_gerador_pulso);
	serial();

}

void serial(){
	Serial.print(" |Freq. Medida: ");
	Serial.print(velocidade_sensor_freq);
	Serial.println("");
}

float velocidade_vento(int sensor){
  // Le o sensor algumas vezes
  	float freq = 0;
	for (int i = 0; i < nAmostras; i++) {
    		freq += digitalRead(sensor);
    		delay (10);
  	}
  	// Determina a velocidade angular
	float w = 0.0;
	w = (2 * pi) * (freq/2);

	// Determina a velocidade tangencial 
	float v = w * r;

	// Converte o resultado de m/s para km/h	 
	float v_km = v * 3.6;
	
	return v_km;
}