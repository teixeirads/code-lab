# Calculadora em Python

![Python](https://img.shields.io/badge/Python-3.x-3776AB?logo=python&logoColor=white)
![Interface](https://img.shields.io/badge/interface-terminal-4c566a)
![Demo](https://img.shields.io/badge/demo%20web-planejada-f0ad4e)

Calculadora de terminal construída para exercitar decomposição em funções, controle de fluxo e tratamento explícito de erros de entrada.

## Objetivo

Oferecer as quatro operações aritméticas básicas em um fluxo interativo simples, mantendo a regra de cada operação isolada e protegendo o usuário contra entradas inválidas e divisão por zero.

## Funcionalidades

- Soma, subtração, multiplicação e divisão.
- Menu persistente até a escolha de saída.
- Conversão de entradas para números de ponto flutuante.
- Tratamento de `ValueError` para entradas não numéricas.
- Mensagem específica para tentativa de divisão por zero.

## Desafios técnicos

### Separação entre regra e interface

As funções `soma`, `subtrai`, `multiplica` e `divide` concentram as regras aritméticas, enquanto `menu` e `main` coordenam a interação. Essa separação cria um ponto de partida claro para testes unitários e para uma futura interface web.

### Validação de entrada

A conversão com `float` fica protegida por `try/except`, impedindo que uma entrada textual encerre o programa. A divisão possui uma regra adicional para denominador igual a zero.

### Precedência de operações

A versão atual executa **uma operação por vez**, escolhida pelo menu; portanto, ainda não contém parser de expressões nem lógica própria de precedência. Na versão web, há duas opções honestas de evolução:

1. manter o modelo de operação única, tornando a precedência desnecessária; ou
2. aceitar expressões completas e implementar tokenização, validação e precedência explicitamente, com testes.

## Estrutura atual

```text
calculadora/
├── calculadora.py
└── README.md
```

## Como executar

Requisito: Python 3 instalado.

```bash
cd calculadora
python calculadora.py
```

No Windows, se `python` apontar apenas para a Microsoft Store, use `py -3 calculadora.py`.

Exemplo:

```text
--- Calculadora Python ---
1. Soma
2. Subtração
3. Multiplicação
4. Divisão
5. Sair
Escolha uma opção: 4
Digite o primeiro número: 10
Digite o segundo número: 2
Resultado: 10.0 / 2.0 = 5.0
```

## 🚀 Ver demo ao vivo

[Abrir a URL planejada no GitHub Pages](https://teixeirads.github.io/code-lab/calculadora/)

> A demo web ainda não está publicada. O GitHub Pages não executa Python; antes de ativar o link será criada uma versão estática em HTML, CSS e JavaScript que preserve as mesmas regras e cenários de erro.

## Próximos passos

- Adicionar testes unitários para as quatro operações e os casos de erro.
- Renomear os identificadores segundo PEP 8 (`add`, `subtract`, `multiply`, `divide`, `first_number`, `second_number`).
- Separar regra, entrada e apresentação em módulos pequenos.
- Criar a interface web responsiva e validar teclado, estados de erro e acessibilidade.
- Publicar os artefatos estáticos em `docs/calculadora/`.
