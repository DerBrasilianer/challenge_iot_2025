# 🔐 Trava Inteligente para Pátio de Motos - Mottu Challenge (IoT)

Protótipo funcional desenvolvido com **ESP32 (via Wokwi)**, **MQTT** e **Node-RED**, criado para demonstrar uma **trava inteligente conectada**, capaz de detectar a presença de uma moto e enviar/receber comandos em tempo real por meio de um dashboard interativo.

---

## 👨‍💻 Integrantes - Grupo LTAKN

- **Enzo Prado Soddano** – RM: 557937  
  [GitHub](https://github.com/DerBrasilianer)

- **Lucas Resende Lima** – RM: 556564  
  [GitHub](https://github.com/lucasresendelima)

- **Vinicius Prates Altafini** – RM: 559183  
  [GitHub](https://github.com/vinicius945)

---

## 📡 Sobre o Projeto

Este protótipo foi desenvolvido para o **Challenge da Mottu**, na disciplina *Disruptive Architectures: IoT, IoB & Generative AI*, com o objetivo de criar uma solução funcional e conectada que possibilite o **controle remoto de travas de motos em um pátio**, aumentando a segurança e o monitoramento em tempo real.

### Funcionalidades

- Simulação de **trava física inteligente** conectada a um sistema de monitoramento via MQTT.
- Detecção da **chegada ou saída da moto** por botão ou comando remoto.
- Dashboard com **indicador visual**, **status em tempo real** e **botão de controle remoto**.
- Envio e recepção de mensagens MQTT com tópicos personalizados.

---

## 🛠️ Tecnologias Utilizadas

- **ESP32 (simulado no Wokwi)**
- **MQTT (broker HiveMQ)**
- **Node-RED + Node-RED Dashboard**
- **Servo motor e LED simulados**
- **Tópicos MQTT:**
  - `LTAKN/publish` (publicações da ESP32)
  - `LTAKN/subscribe` (comandos recebidos pelo ESP32)

---

## 🌐 Estrutura do Repositório

- `ESP32/`: Código da simulação da ESP32 (Arduino/C++)
- `Node-Red/`: Fluxo JSON do Node-RED com o painel
- `Prints do Projeto/`: Prints do circuito e do painel do dashboard
- `Link_do_Video.txt`: Roteiro do pitch e anotações
- `README.md`: Documentação do projeto

---

## 🚀 Como Rodar o Projeto

### 🔧 Simulador (ESP32 + MQTT)

1. Importe os arquivos `ESP32/` ou Acesse o circuito no Wokwi: [🔗 Link para o Wokwi](https://wokwi.com/projects/431856122530881537)
2. Clique em **"Start Simulation"**
3. Observe a troca de mensagens com o broker MQTT nos tópicos definidos

### 📊 Dashboard (Node-RED)

1. Importe o fluxo do arquivo `Node-Red/challenge_iot_2025_node-red_flows.json` para o seu Node-RED local
2. Configure os nodes MQTT com o broker `broker.hivemq.com`
3. Acesse o painel via `/ui`
4. Envie comandos (`chegou` ou `saiu`) por meio do Dashboard Switch para simular o movimento da moto

---

## 🎬 Vídeo Pitch

Assista ao vídeo demonstrando o funcionamento completo do protótipo:

📽️ [Link para o vídeo no YouTube (Não listado)](https://youtube.com/SEU_LINK_AQUI)
