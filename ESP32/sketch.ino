#include <WiFi.h>
#include <PubSubClient.h>
#include <ESP32Servo.h>

// Credenciais Wi-Fi
// PS: Usei a rede padrão da Wokwi porque por algum motivo
// não consegui conectar na minha
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// Configurações do MQTT
const char* mqttServer = "broker.hivemq.com";
const int mqttPort = 1883;
const char* publishTopic = "LTAKN/publish";
const char* subscribeTopic = "LTAKN/subscribe";

WiFiClient espClient;
PubSubClient client(espClient);

const int led = 5;
const int pinoServo = 13;

Servo travaServo;
bool motoPresente = false;

// Callback para mensagens recebidas
void callback(char* topic, byte* payload, unsigned int length) {

  String mensagem = "";

  for (int i = 0; i < length; i++) {

    mensagem += (char)payload[i];
    
  }

  Serial.print("Mensagem recebida no tópico ");
  Serial.print(topic);
  Serial.print(": ");
  Serial.println(mensagem);

  if (mensagem == "chegou" && !motoPresente) {

    // Ao receber o sinal da moto, a trava se fecha
    digitalWrite(led, HIGH);
    travaServo.write(90);

    // Mensagem de confirmação
    Serial.println("🚩 Moto chegou ao pátio");
    client.publish(publishTopic, "Trava fechada");
    motoPresente = true;

  } else if (mensagem == "saiu" && motoPresente) {

    // Quando a moto sai, a trava se abre
    digitalWrite(led, LOW);
    travaServo.write(0);

    // Mensagem de confirmação
    Serial.println("🏁 Moto saiu do pátio");
    client.publish(publishTopic, "Trava aberta");
    motoPresente = false;

  }

}

void setup() {

  Serial.begin(115200);
  pinMode(led, OUTPUT);

  // Inicializa o servo motor
  travaServo.attach(pinoServo);

  // A posição inicial da trava é aberta
  travaServo.write(0);
  
  // Conecta ao Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {

    delay(500);
    Serial.print(".");

  }
  Serial.println("\nWiFi conectado!");

  // Configura o servidor MQTT e o callback
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);

  // Conecta ao broker do MQTT
  while (!client.connected()) {

    Serial.print("Conectando ao MQTT...");

    if (client.connect("ESP32Client_LTAKN")) {

      Serial.println("Conectado!");
      client.subscribe(subscribeTopic);
      client.publish(publishTopic, "Sistema inicializado");

    } else {

      Serial.print("Falha, rc=");
      Serial.print(client.state());
      delay(2000);

    }

  }

}

void loop() {

  // Mantém a conexão MQTT ativa
  client.loop();

}
