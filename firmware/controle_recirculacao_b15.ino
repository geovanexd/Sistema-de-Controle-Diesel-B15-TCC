// Entradas analógicas
const int sensorBateria = A0;
const int sensorNivel = A1;

// Entradas digitais
const int sensorAgua = 22;
const int botaoManual = 23;

// Saídas digitais
const int bomba = 30;
const int valvula = 31;
const int ledFalha = 34;

// Limites de operação
const float limiteBateria = 12.2;
const int limiteNivel = 20;
const unsigned long tempoRecirculacao = 5000;

void setup() {
  pinMode(sensorAgua, INPUT_PULLUP);
  pinMode(botaoManual, INPUT_PULLUP);

  pinMode(bomba, OUTPUT);
  pinMode(valvula, OUTPUT);
  pinMode(ledFalha, OUTPUT);

  digitalWrite(bomba, LOW);
  digitalWrite(valvula, LOW);
  digitalWrite(ledFalha, LOW);

  Serial.begin(9600);
}

void loop() {
  float tensaoBateria = lerBateria();
  int nivelTanque = lerNivel();

  bool aguaDetectada = digitalRead(sensorAgua) == LOW;
  bool botaoPressionado = digitalRead(botaoManual) == LOW;

  Serial.print("Bateria: ");
  Serial.print(tensaoBateria);
  Serial.print(" V | Nivel: ");
  Serial.print(nivelTanque);
  Serial.print(" % | Agua no filtro: ");
  Serial.print(aguaDetectada ? "SIM" : "NAO");
  Serial.print(" | Botao manual: ");
  Serial.println(botaoPressionado ? "PRESSIONADO" : "SOLTO");

  if (condicoesOK(tensaoBateria, nivelTanque, aguaDetectada)) {
    digitalWrite(ledFalha, LOW);
  } else {
    digitalWrite(ledFalha, HIGH);
  }

  if (botaoPressionado) {
    iniciarCiclo(tensaoBateria, nivelTanque, aguaDetectada);
  }

  delay(300);
}

float lerBateria() {
  int leitura = analogRead(sensorBateria);
  float tensao = leitura * (15.0 / 1023.0);
  return tensao;
}

int lerNivel() {
  int leitura = analogRead(sensorNivel);
  int nivel = map(leitura, 0, 1023, 0, 100);
  return nivel;
}

bool condicoesOK(float tensao, int nivel, bool agua) {
  if (tensao < limiteBateria) {
    return false;
  }

  if (nivel < limiteNivel) {
    return false;
  }

  if (agua == true) {
    return false;
  }

  return true;
}

void iniciarCiclo(float tensao, int nivel, bool agua) {
  if (condicoesOK(tensao, nivel, agua)) {
    Serial.println("CICLO INICIADO: recirculacao ativa.");

    digitalWrite(ledFalha, LOW);

    digitalWrite(valvula, HIGH);
    delay(1000);

    digitalWrite(bomba, HIGH);
    delay(tempoRecirculacao);

    digitalWrite(bomba, LOW);
    digitalWrite(valvula, LOW);

    Serial.println("CICLO FINALIZADO.");
  } else {
    Serial.println("CICLO BLOQUEADO: condicao insegura.");

    digitalWrite(bomba, LOW);
    digitalWrite(valvula, LOW);
    digitalWrite(ledFalha, HIGH);

    delay(1000);
  }
}
