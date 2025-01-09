#include <ESP8266WiFi.h>

// Configuración de tu red WiFi
const char* ssid = "Gordillo";
const char* password = "chanchitos";

// Configuración del servidor backend
const char* host = "192.168.1.59"; // Reemplaza con la IP de tu servidor Node.js
const int httpPort = 3000;

void setup() {
  Serial.begin(115200);
  delay(10);

  // Conectar a WiFi
  Serial.println();
  Serial.print("Conectando a ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Aquí pondrías la lógica para enviar datos a tu backend
  // Por ejemplo, cada 5 segundos podríamos enviar datos (simulados en este caso)
  delay(5000);

  // Usa la librería WiFiClient para conectar y enviar datos
  WiFiClient client;
  
  if (!client.connect(host, httpPort)) {
    Serial.println("Conexión fallida");
    return;
  }

  // Aquí preparamos los datos a enviar. En un caso real, estos datos vendrían de sensores.
  String datos = "{\"temperature\":25.5,\"humidity\":60,\"light\":800}";
  
  // Enviamos los datos al servidor
  String url = "/sendData";
  String postData = "data=" + datos;
  
  client.print(String("POST ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Content-Type: application/x-www-form-urlencoded\r\n" +
               "Content-Length: " + postData.length() + "\r\n" +
               "Connection: close\r\n\r\n" +
               postData + "\r\n");

  // Esperamos la respuesta del servidor
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Cliente Timeout !");
      client.stop();
      return;
    }
  }

  // Lee la respuesta del servidor
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  
  Serial.println();
  Serial.println("Cerrando conexión");
}