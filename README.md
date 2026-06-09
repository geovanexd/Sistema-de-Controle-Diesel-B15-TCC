# Sistema de Controle Diesel B15 - TCC

Repositório desenvolvido como parte do Trabalho de Conclusão de Curso em Engenharia Mecânica.

O projeto apresenta o firmware de controle eletrônico para um sistema de recirculação de combustível diesel B15 em tanque automotivo, com o objetivo de auxiliar na redução de contaminantes, água acumulada e formação de depósitos no sistema de combustível.

## Objetivo do Projeto

O sistema tem como objetivo controlar o acionamento de uma bomba e de uma válvula de recirculação, verificando previamente condições mínimas de segurança para operação.

As condições verificadas são:

- Tensão da bateria;
- Nível do tanque;
- Presença de água no filtro;
- Acionamento manual pelo operador.

Caso alguma condição esteja fora do limite estabelecido, o ciclo de recirculação é bloqueado e o LED de falha é acionado.

## Funcionamento do Sistema

O Arduino realiza a leitura contínua dos sensores e exibe os dados no Monitor Serial.

Quando o botão manual é pressionado, o sistema verifica se todas as condições de operação estão adequadas.

Se as condições forem atendidas:

1. A válvula é acionada;
2. Após 1 segundo, a bomba é ligada;
3. A recirculação permanece ativa por 5 segundos;
4. A bomba e a válvula são desligadas.

Se alguma condição não for atendida, o sistema bloqueia o ciclo e aciona o LED de falha.

## Componentes Utilizados

| Componente | Função |
|---|---|
| Arduino Mega | Unidade de controle do sistema |
| Sensor de tensão | Monitoramento da bateria |
| Sensor de nível | Verificação do nível do tanque |
| Sensor de água | Detecção de água no filtro |
| Botão manual | Acionamento do ciclo de recirculação |
| Bomba | Recirculação do combustível |
| Válvula | Direcionamento do fluxo |
| LED | Indicação de falha |

## Pinagem

| Função | Pino |
|---|---|
| Sensor de bateria | A0 |
| Sensor de nível | A1 |
| Sensor de água | 22 |
| Botão manual | 23 |
| Bomba | 30 |
| Válvula | 31 |
| LED de falha | 34 |

## Limites de Operação

| Parâmetro | Valor |
|---|---|
| Tensão mínima da bateria | 12,2 V |
| Nível mínimo do tanque | 20% |
| Tempo de recirculação | 5 segundos |

## Estrutura do Repositório

```text
Sistema-de-Controle-Diesel-B15-TCC/
│
├── firmware/
│   └── controle_recirculacao_b15.ino
│
└── README.md
