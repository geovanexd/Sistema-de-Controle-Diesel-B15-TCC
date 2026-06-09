# Sistema de Controle Diesel B15 - TCC

Repositório desenvolvido para o Trabalho de Conclusão de Curso em Engenharia Mecânica.

O projeto consiste em um sistema eletrônico de controle para recirculação de combustível diesel B15 em tanque automotivo. A proposta busca auxiliar na redução de contaminantes, água acumulada e formação de depósitos no sistema de combustível.

## Objetivo

Controlar o acionamento de uma bomba e de uma válvula de recirculação, verificando previamente as condições mínimas de operação do sistema.

As condições avaliadas são:

- Tensão da bateria;
- Nível do tanque;
- Presença de água no filtro;
- Acionamento manual do sistema.

Caso alguma condição esteja fora do limite definido, o ciclo de recirculação é bloqueado e o LED de falha é acionado.

## Funcionamento

O sistema realiza a leitura dos sensores e verifica se as condições de operação estão adequadas.

Quando o botão manual é pressionado, o controle avalia os parâmetros definidos. Se todos estiverem dentro dos limites, a válvula é acionada e, em seguida, a bomba inicia o ciclo de recirculação.

Caso exista alguma condição de falha, a bomba e a válvula permanecem desligadas.

## Componentes Utilizados

| Componente | Função |
|---|---|
| Arduino Mega | Controle do sistema |
| Sensor de tensão | Monitoramento da bateria |
| Sensor de nível | Verificação do nível do tanque |
| Sensor de água | Detecção de água no filtro |
| Botão manual | Acionamento do ciclo |
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

## Sequência de Operação

1. Leitura da tensão da bateria;
2. Leitura do nível do tanque;
3. Verificação da presença de água no filtro;
4. Verificação do botão manual;
5. Análise das condições de operação;
6. Acionamento da válvula;
7. Acionamento da bomba;
8. Finalização do ciclo de recirculação.

## Lógica de Controle

```text
Início
  ↓
Ler tensão da bateria
  ↓
Ler nível do tanque
  ↓
Verificar sensor de água
  ↓
Verificar botão manual
  ↓
Botão pressionado?
  ↓
Não → Continua monitorando
  ↓
Sim
  ↓
Condições adequadas?
  ↓
Sim → Aciona válvula → Aciona bomba → Finaliza ciclo
  ↓
Não → Bloqueia sistema → Aciona LED de falha
```

## Estrutura do Repositório

```text
Sistema-de-Controle-Diesel-B15-TCC/
│
├── firmware/
│   └── controle_recirculacao_b15.ino
│
└── README.md
```

## Código-Fonte

O código-fonte do sistema está localizado em:

```text
firmware/controle_recirculacao_b15.ino
```

O arquivo contém a lógica de leitura dos sensores, verificação das condições de operação, acionamento da bomba, acionamento da válvula e indicação de falha.

## Observações

O sistema foi desenvolvido em escala de bancada para fins acadêmicos.

Para aplicação em veículo real, são necessários testes complementares, dimensionamento elétrico adequado, proteção dos circuitos e validação dos componentes em ambiente automotivo.

## Autores

- Geovane Ferretti Caldeirão Prado
- Victor Augusto Oliveira da Silva
- Igor Neves Santos

## Instituição

Centro Universitário FEI  
Engenharia Mecânica  
Trabalho de Conclusão de Curso
