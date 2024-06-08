# Projeto de Monitoramento de pH, Temperatura e TDS

-- Mateus dos Santos RM: 558436
-- Lucas Imparato RM: 554896

## Descrição do Projeto

Este projeto consiste em simular três sensores: pH, Temperatura e TDS (Total Dissolved Solids) usando um microcontrolador Arduino. O sensor de pH e temperatura são representados por um único circuito, enquanto o sensor de TDS é simulado separadamente.

## Instruções de Uso

1. **Montagem do Circuito:**
   - Conecte os componentes de acordo com o esquemático fornecido.
   - Certifique-se de conectar corretamente os sensores aos pinos do Arduino.

2. **Upload do Código:**
   - Abra o código fornecido no Arduino IDE.
   - Conecte a placa Arduino ao computador via USB.
   - Faça o upload do código para a placa Arduino.

3. **Monitoramento:**
   - Abra o monitor serial no Arduino IDE para visualizar os dados em tempo real.
   - Os valores de pH, temperatura e TDS serão exibidos no monitor serial.
   - Os resultados também serão exibidos em dois displays LCDs conectados ao Arduino.

## Requisitos e Dependências

- Arduino IDE instalado no computador.
- Componentes eletrônicos necessários para montagem do circuito:
  - Sensores de pH, temperatura e TDS.
  - Resistores e fios para conexão.
  - Displays LCDs compatíveis com o Arduino.
  - Placa Arduino (compatível com o código fornecido).

## Informações Adicionais

- O código fornecido utiliza a biblioteca LiquidCrystal para controle dos displays LCDs.
- Os sensores de pH e temperatura são simulados por meio de leituras analógicas.
- O sensor de TDS é simulado com base na relação entre resistências elétricas.
- As leituras de pH são convertidas para valores de pH utilizando uma fórmula específica.
- A temperatura é calculada a partir de uma leitura analógica e convertida para graus Celsius.

## Contribuições e Melhorias

Este projeto pode ser expandido e aprimorado de várias maneiras, incluindo:

- Implementação de calibração para os sensores de pH e TDS.
- Integração com um sistema de controle para ajuste automático de parâmetros.
- Adição de alarmes ou notificações para valores fora dos limites aceitáveis.
- Melhoria da interface do usuário para exibição de gráficos ou históricos de dados.
