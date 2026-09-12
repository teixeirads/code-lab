# Jogo da Memória

![C++](https://img.shields.io/badge/C%2B%2B-17-00599C?logo=cplusplus&logoColor=white)
![Plataforma](https://img.shields.io/badge/plataforma-Windows-0078D6?logo=windows&logoColor=white)
![Demo](https://img.shields.io/badge/demo%20web-planejada-f0ad4e)

Jogo de memória em C++ para terminal, com suporte a um ou dois jogadores, duas configurações de tabuleiro e acompanhamento de pontuação e jogadas.

## Objetivo

Modelar um jogo baseado em turnos no qual o estado visual precisa permanecer sincronizado com as regras: cartas começam ocultas, duas posições são reveladas por jogada, pares corretos permanecem visíveis e o jogo termina quando todos os pares são encontrados.

## Lógica de estado do jogo

O fluxo coordena seis grupos de estado:

- `tabuleiro`: valor de cada carta.
- `revelado`: visibilidade de cada posição.
- `paresEncontrados`: progresso global da partida.
- `turno`: alternância entre jogadores.
- `pontos`: pares encontrados por jogador.
- `jogadas`: quantidade de tentativas por jogador.

A função `inicializarJogo` cria os pares, embaralha as cartas e define o tamanho do tabuleiro. `lerPosicao` impede coordenadas fora da matriz e cartas já descobertas. `verificarPar` compara a dupla escolhida, enquanto `main` conduz as transições entre revelar, validar, manter ou ocultar.

## Interface e manipulação do tabuleiro

Na implementação atual, `exibirTabuleiro` renderiza a interface no terminal e `limparTela` redesenha a tela entre estados. O projeto usa `windows.h`, `Sleep` e `system("cls")`, por isso a execução atual é específica para Windows.

Não há manipulação de DOM no código atual. Na versão planejada para GitHub Pages, os mesmos estados serão representados em JavaScript e cada transição atualizará os elementos visuais do tabuleiro no DOM.

## Aprendizados demonstrados

- Coordenação de estado mutável entre funções.
- Passagem de parâmetros por referência em C++.
- Validação de coordenadas e prevenção de segunda escolha inválida.
- Construção e embaralhamento de pares.
- Alternância de turnos, pontuação e condição de término.
- Separação inicial entre leitura, regra e apresentação.

## Modos de jogo

| Modo | Tabuleiro | Cartas | Pares | Memorização |
|---|---:|---:|---:|---:|
| Rápido | 3 × 6 | 18 | 9 | 3 segundos |
| Normal | 4 × 6 | 24 | 12 | 5 segundos |

## Como executar

Requisitos: Windows e compilador C++ compatível com C++17.

```powershell
cd jogo-da-memoria
New-Item -ItemType Directory -Force output | Out-Null
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o output/memory_game.exe
.\output\memory_game.exe
```

## 🎮 Jogar agora

[Abrir a URL planejada no GitHub Pages](https://teixeirads.github.io/code-lab/jogo-da-memoria/)

> A demo web ainda não está publicada. O Pages receberá uma implementação estática em HTML, CSS e JavaScript; o binário C++ atual não é executado pelo navegador.

## Limitações conhecidas e evolução

- Validar explicitamente modo de jogo e quantidade de jogadores antes de iniciar a partida.
- Substituir `rand`, `srand` e a troca manual por `<random>` e `std::shuffle`.
- Remover a dependência de `windows.h` com abstrações portáveis para tempo e tela.
- Encapsular o estado em tipos como `Game`, `Board` e `Player`, somente quando os testes exigirem essa separação.
- Criar testes determinísticos com semente controlada.
- Implementar a versão web com eventos, DOM, acessibilidade por teclado e layout responsivo.

