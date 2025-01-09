# Arduino ESP8266 WiFi Connection and Data Sending to Node.js Backend

Este repositorio contiene un proyecto de Arduino que utiliza un ESP8266 para conectarse a una red WiFi y enviar datos a un servidor backend en Node.js.

## Descripción

El código aquí presente permite que un ESP8266:

- Se conecte a una red WiFi.
- Envíe datos simulados (temperatura, humedad y luz) a un servidor Node.js cada 5 segundos.

## Requisitos

- **Hardware**:
  - Arduino compatible con ESP8266 (como NodeMCU)
- **Software**:
  - Arduino IDE con el soporte para ESP8266 instalado.
  - Un servidor Node.js (no incluido en este repositorio, pero se asume que tienes uno configurado).

## Configuración

1. **WiFi Configuration**:
   - Modifica las variables `ssid` y `password` en el código con los detalles de tu red WiFi.

   ```cpp
   const char* ssid = "TU RED";
   const char* password = "TU CONTRASEÑA";