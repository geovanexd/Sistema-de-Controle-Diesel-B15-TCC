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

## Funcionamento Geral

O Arduino realiza continuamente a leitura dos sensores conectados ao sistema. A partir dessas leituras, o programa verifica se as condições mínimas de funcionamento foram atendidas.

O ciclo de recirculação só é iniciado quando o botão manual é pressionado e todas as condições de segurança estão adequadas.

Se as condições forem atendidas, o sistema aciona a válvula, aguarda um intervalo de segurança, liga a bomba por um tempo determinado e, ao final do ciclo, desliga novamente a bomba e a válvula.

Se alguma condição não for atendida, o sistema bloqueia o funcionamento da bomba e da válvula, acionando o LED de falha.

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

## Lógica de Funcionamento

O sistema foi desenvolvido para controlar a recirculação de combustível diesel B15 de forma segura, utilizando uma lógica simples de verificação de condições antes do acionamento da bomba e da válvula.

O Arduino realiza continuamente a leitura dos sensores conectados ao sistema. As entradas utilizadas são:

- Sensor de bateria, ligado ao pino A0;
- Sensor de nível do tanque, ligado ao pino A1;
- Sensor de água no filtro, ligado ao pino digital 22;
- Botão manual de acionamento, ligado ao pino digital 23.

As saídas controladas pelo Arduino são:

- Bomba de recirculação, ligada ao pino digital 30;
- Válvula de direcionamento do fluxo, ligada ao pino digital 31;
- LED de falha, ligado ao pino digital 34.

## Etapas de Operação

### 1. Leitura dos sensores

O sistema inicia realizando a leitura da tensão da bateria e do nível do tanque.

A tensão da bateria é calculada a partir da leitura analógica do pino A0, sendo convertida para uma escala de até 15 V.

O nível do tanque é lido pelo pino A1 e convertido para uma escala percentual de 0 a 100%.

Além disso, o sistema verifica se há presença de água no filtro e se o botão manual foi pressionado.

### 2. Verificação das condições de segurança

Antes de iniciar a recirculação, o sistema verifica três condições principais:

| Condição | Limite adotado |
|---|---|
| Tensão da bateria | Igual ou maior que 12,2 V |
| Nível do tanque | Igual ou maior que 20% |
| Presença de água | Não pode haver água detectada |

Se qualquer uma dessas condições não for atendida, o sistema considera que há uma condição insegura de operação.

### 3. Indicação de falha

Quando alguma condição de segurança não é atendida, o LED de falha é acionado.

Isso indica que o sistema não está autorizado a iniciar o ciclo de recirculação.

As possíveis causas de falha são:

- Bateria com tensão abaixo do limite definido;
- Nível de combustível abaixo de 20%;
- Presença de água detectada no filtro.

### 4. Acionamento manual

O ciclo de recirculação só é iniciado quando o botão manual é pressionado.

Ao pressionar o botão, o sistema verifica novamente todas as condições de segurança.

Se estiver tudo correto, o ciclo é liberado.

Se houver falha, o ciclo é bloqueado.

### 5. Ciclo de recirculação

Quando as condições estão adequadas, o sistema executa a seguinte sequência:

1. O LED de falha permanece desligado;
2. A válvula é acionada;
3. O sistema aguarda 1 segundo;
4. A bomba é acionada;
5. A recirculação permanece ativa por 5 segundos;
6. A bomba é desligada;
7. A válvula é desligada;
8. O ciclo é finalizado.

Essa lógica evita que a bomba funcione em condições inadequadas, como baixa tensão, baixo nível de combustível ou presença de água no filtro.

### 6. Bloqueio do ciclo

Caso alguma condição esteja fora dos limites definidos, o sistema bloqueia o ciclo.

Nesse caso:

- A bomba permanece desligada;
- A válvula permanece desligada;
- O LED de falha é acionado;
- Uma mensagem de bloqueio é exibida no Monitor Serial.

## Resumo da Lógica

```text
Início
  ↓
Leitura da bateria
  ↓
Leitura do nível do tanque
  ↓
Verificação do sensor de água
  ↓
Verificação do botão manual
  ↓
Botão pressionado?
  ↓
Não → Continua monitorando
  ↓
Sim
  ↓
Bateria ≥ 12,2 V?
  ↓
Nível ≥ 20%?
  ↓
Água detectada?
  ↓
Se as condições estiverem corretas:
    Aciona válvula
    Aguarda 1 segundo
    Aciona bomba
    Mantém recirculação por 5 segundos
    Desliga bomba e válvula
  ↓
Se houver falha:
    Bloqueia bomba
    Bloqueia válvula
    Liga LED de falha
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

O código-fonte do sistema está localizado na pasta:

```text
firmware/controle_recirculacao_b15.ino
```

Esse arquivo contém a lógica de leitura dos sensores, verificação das condições de operação, acionamento da válvula, acionamento da bomba e indicação de falha.

## Finalidade da Lógica de Controle

A lógica desenvolvida tem como finalidade representar, em escala de bancada, um sistema de controle aplicado à recirculação de combustível em tanque automotivo.

O controle busca impedir o funcionamento da bomba em condições inadequadas, contribuindo para maior segurança operacional e melhor proteção dos componentes do sistema.

## Observações

Este sistema foi desenvolvido em escala de bancada para fins acadêmicos.

Para aplicação em veículo real, são necessários testes adicionais, dimensionamento elétrico adequado, proteção dos circuitos, validação dos sensores e adequação dos componentes ao ambiente automotivo.

## Autores

- Geovane Ferretti Caldeirão Prado
- Victor Augusto Oliveira da Silva
- Igor Neves Santos

## Instituição

Centro Universitário FEI  
Engenharia Mecânica  
Trabalho de Conclusão de Curso
