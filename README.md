# sistema-controle-tanque-biodiesel-b15
Sistema eletrônico de controle para recirculação de combustível biodiesel B15 em tanque automotivo.

# Sistema de Controle de Tanque de Combustível a Biodiesel B15

Repositório desenvolvido como parte do Trabalho de Conclusão de Curso em Engenharia Mecânica.

O projeto propõe um sistema eletrônico de controle para auxiliar a recirculação de combustível biodiesel B15 em tanques automotivos, com o objetivo de reduzir a permanência de contaminantes em regiões de baixa circulação e auxiliar na remoção de água acumulada por meio de filtro com dreno.

## Objetivo do Sistema

O firmware desenvolvido em Arduino tem como objetivo controlar, em escala de bancada, a lógica de acionamento de uma bomba de recirculação e de uma válvula, considerando condições mínimas de segurança antes do funcionamento.

O sistema verifica:

- Tensão da bateria;
- Nível do tanque;
- Presença de água no filtro;
- Acionamento manual pelo operador.

Caso alguma condição esteja fora do limite definido, o ciclo de recirculação é bloqueado e o LED de falha é acionado.

## Funcionamento Geral

O sistema realiza leituras contínuas dos sensores e exibe os dados no monitor serial. Quando o botão manual é pressionado, o Arduino verifica se as condições de operação são seguras.

Se as condições forem atendidas:

1. A válvula é acionada;
2. Após 1 segundo, a bomba é ligada;
3. A recirculação permanece ativa por 5 segundos;
4. A bomba e a válvula são desligadas.

Se alguma condição não for atendida, o ciclo é bloqueado e o LED de falha permanece aceso.

## Componentes Utilizados

| Componente | Função |
|---|---|
| Arduino Mega | Unidade de controle |
| Sensor de tensão | Monitoramento da bateria |
| Sensor de nível | Verificação do nível do tanque |
| Sensor de água | Detecção de água no filtro |
| Botão manual | Acionamento do ciclo |
| Relé ou módulo de acionamento | Controle da bomba |
| Bomba automotiva | Recirculação do combustível |
| Válvula | Direcionamento do fluxo |
| LED | Indicação de falha |

## Pinagem

| Função | Pino Arduino |
|---|---|
| Sensor de bateria | A0 |
| Sensor de nível | A1 |
| Sensor de água | 22 |
| Botão manual | 23 |
| Bomba | 30 |
| Válvula | 31 |
| LED de falha | 34 |

## Limites de Operação

| Parâmetro | Valor definido |
|---|---|
| Tensão mínima da bateria | 12,2 V |
| Nível mínimo do tanque | 20% |
| Tempo de recirculação | 5 segundos |

## Lógica de Segurança

O ciclo de recirculação só é iniciado quando todas as condições abaixo são atendidas:

- Tensão da bateria maior ou igual a 12,2 V;
- Nível do tanque maior ou igual a 20%;
- Ausência de água detectada no filtro.

Caso uma dessas condições não seja atendida, o sistema bloqueia a bomba e a válvula, mantendo o LED de falha aceso.

## Estrutura do Repositório

```text
sistema-controle-tanque-biodiesel-b15/
│
├── firmware/
│   └── controle_recirculacao_b15.ino
│
├── docs/
│   ├── fluxograma_logica.png
│   └── esquema_eletronico.png
│
├── imagens/
│   ├── prototipo_bancada.jpg
│   └── montagem_arduino.jpg
│
├── README.md
└── LICENSE
