# Code Lab | Engenharia aplicada em pequenos sistemas

![Status](https://img.shields.io/badge/status-em_evolu%C3%A7%C3%A3o-2ea44f)
![Python](https://img.shields.io/badge/Python-3.x-3776AB?logo=python&logoColor=white)
![C++](https://img.shields.io/badge/C%2B%2B-17-00599C?logo=cplusplus&logoColor=white)
![Foco](https://img.shields.io/badge/foco-l%C3%B3gica%20%7C%20estado%20%7C%20regras%20de%20neg%C3%B3cio-6f42c1)

O **Code Lab** é um laboratório de projetos pequenos e deliberados, criado para transformar fundamentos de programação em evidências verificáveis de engenharia. Cada projeto isola um tipo de problema — cálculo, controle de estado ou regras de negócio — e documenta decisões, limitações e próximos passos.

Mais do que reunir exercícios, este repositório mostra como uma solução evolui: do primeiro fluxo funcional para código testável, portátil e demonstrável.

## Projetos

| Projeto | Descrição | Stack | Código | Demo / execução |
|---|---|---|---|---|
| [Calculadora](./calculadora/) | Calculadora de terminal com quatro operações, tratamento de entradas inválidas e proteção contra divisão por zero. | Python 3 | [Ver código](./calculadora/calculadora.py) | [URL prevista no GitHub Pages](https://teixeirads.github.io/code-lab/calculadora/) · em implementação |
| [Jogo da Memória](./jogo-da-memoria/) | Jogo de terminal para um ou dois jogadores, com embaralhamento, turnos, pontuação e dois tamanhos de tabuleiro. | C++ · Windows API | [Ver código](./jogo-da-memoria/main.cpp) | [URL prevista no GitHub Pages](https://teixeirads.github.io/code-lab/jogo-da-memoria/) · em implementação |
| [Sistema de Pedidos e Comissões](./sistema-de-pedidos-e-comissoes/) | Processamento de vendas para quatro representantes, com faixas de comissão, agregações e rankings. | C++ 17 | [Ver código](./sistema-de-pedidos-e-comissoes/main.cpp) | [Importar e testar no Replit](https://replit.com/github.com/teixeirads/code-lab) |

> **Transparência técnica:** as versões atuais da Calculadora e do Jogo da Memória executam no terminal. As URLs do GitHub Pages são os destinos planejados para versões web estáticas; elas só serão ativadas depois do port para HTML, CSS e JavaScript.

## Competências demonstradas

| Competência | Evidência no laboratório |
|---|---|
| Decomposição de problemas | Operações da calculadora separadas em funções pequenas e reutilizáveis. |
| Validação e fluxos de erro | Entradas numéricas inválidas, opção inexistente e divisão por zero tratadas no fluxo da calculadora. |
| Gestão de estado | Tabuleiro, cartas reveladas, turnos, tentativas e pontuação coordenados no Jogo da Memória. |
| Modelagem de regras de negócio | Faixas progressivas de comissão e consolidação por representante no Sistema de Pedidos. |
| Comunicação técnica | Cada projeto registra objetivo, decisões, execução, limitações e estratégia de demonstração. |

## Stack tecnológica

![Python](https://img.shields.io/badge/Python-CLI-3776AB?logo=python&logoColor=white)
![C++](https://img.shields.io/badge/C%2B%2B-console-00599C?logo=cplusplus&logoColor=white)
![Git](https://img.shields.io/badge/Git-versionamento-F05032?logo=git&logoColor=white)
![GitHub Pages](https://img.shields.io/badge/GitHub%20Pages-demos%20web-222222?logo=githubpages&logoColor=white)
![Replit](https://img.shields.io/badge/Replit-demo%20interativa-F26207?logo=replit&logoColor=white)

- **Python 3:** funções, controle de fluxo, exceções e interface de terminal.
- **C++:** arrays, referências, estruturas de repetição, estado em memória e regras de domínio.
- **Git e GitHub:** histórico, revisão e documentação orientada a portfólio.
- **GitHub Pages e Replit:** estratégia de entrega para demos estáticas e aplicações de terminal.

## Como explorar este laboratório

1. Comece pela tabela de projetos e escolha a competência que deseja avaliar.
2. Leia o README individual para entender o problema e as decisões antes de abrir o código.
3. Execute o projeto com os comandos documentados e teste os cenários de erro.
4. Consulte a seção de limitações para distinguir a implementação atual da evolução planejada.
5. Veja o [plano de evolução do portfólio](./docs/PORTFOLIO_PLAN.md) para a arquitetura-alvo, critérios de qualidade e publicação das demos.

## Execução rápida

```bash
# Calculadora (Windows com Python Launcher)
py -3 calculadora/calculadora.py

# Jogo da Memória — Windows com g++
g++ -std=c++17 jogo-da-memoria/main.cpp -o jogo-da-memoria/output/memory_game.exe

# Sistema de Pedidos e Comissões (Linux/Replit)
g++ -std=c++17 sistema-de-pedidos-e-comissoes/main.cpp -o sistema-de-pedidos-e-comissoes/orders_commission
```

## Evolução do laboratório

O próximo ciclo prioriza testes automatizados, builds reproduzíveis, portabilidade do C++ e duas interfaces web para GitHub Pages. O plano completo está em [docs/PORTFOLIO_PLAN.md](./docs/PORTFOLIO_PLAN.md).
