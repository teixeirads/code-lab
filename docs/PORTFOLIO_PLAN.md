# Plano de evolução do Code Lab

![Plano](https://img.shields.io/badge/plano-GSD-6f42c1)
![Status](https://img.shields.io/badge/status-pronto%20para%20execu%C3%A7%C3%A3o-2ea44f)

Este documento transforma o repositório de uma coleção de exercícios em uma vitrine de competências. O plano segue **SPEC → PLAN → EXECUTE**, com entregas pequenas, verificáveis e sem alegar capacidades que o código ainda não possui.

## 0. Diagnóstico e especificação

### Estado atual verificado

| Projeto | Implementação real | Principal evidência | Lacuna para a demo desejada |
|---|---|---|---|
| Calculadora | Python de terminal | Funções aritméticas e tratamento de entrada | GitHub Pages exige uma versão estática para navegador. |
| Jogo da Memória | C++ de terminal para Windows | Estado do tabuleiro, turnos, pontos e tentativas | Não há DOM; é necessário um port para HTML/CSS/JavaScript. |
| Pedidos e Comissões | C++ de terminal | Faixas de comissão, agregações e rankings | Replit pode executar o código, mas falta configuração reproduzível e GIF. |

### Escopo desta reorganização

- Preservar o histórico e o funcionamento dos três programas.
- Remover artefatos compilados do versionamento.
- Padronizar estrutura, nomes, documentação, execução e testes.
- Publicar demos somente quando forem reproduzíveis.
- Evidenciar decisões e limites técnicos em linguagem compreensível para recrutadores.

### Configurações permitidas e fontes

- GitHub Pages por branch aceita `/(root)` ou `/docs`; para este monorepo, usar `main` + `/docs`. Consulte [Configuring a publishing source](https://docs.github.com/en/pages/getting-started-with-github-pages/configuring-a-publishing-source-for-your-github-pages-site).
- O Pages publica arquivos estáticos; não executa Python, C++ ou `.exe`. Consulte [What is GitHub Pages?](https://docs.github.com/en/pages/getting-started-with-github-pages/what-is-github-pages).
- O Replit permite importação guiada ou importação rápida de repositórios públicos. Consulte [Import from a provider](https://docs.replit.com/build/import-from-providers).
- O comando `run` pode ser definido em `.replit` quando a detecção automática não bastar. Consulte [Replit App Configuration](https://docs.replit.com/features/project-setup/configuration).
- O VHS gera demos de terminal reproduzíveis a partir de arquivos `.tape`. Consulte o [repositório oficial do VHS](https://github.com/charmbracelet/vhs).

### Guardas contra anti-padrões

- Não chamar a aplicação C++ de “backend” sem qualificar que ela contém apenas lógica de domínio em memória.
- Não citar DOM, parser de expressões, persistência, testes ou responsividade como concluídos antes de existirem.
- Não versionar binários, caches, pastas de IDE ou segredos.
- Não criar abstrações (`GameEngine`, repositórios, serviços) sem um teste ou segundo consumidor que justifique a separação.

## 1. Arquitetura-alvo

```text
code-lab/
├── README.md
├── .gitignore
├── LICENSE                         # definir licença antes de criar
├── docs/                           # raiz futura do GitHub Pages
│   ├── .nojekyll
│   ├── index.html                  # landing page das demos
│   ├── PORTFOLIO_PLAN.md
│   ├── calculadora/
│   │   ├── index.html
│   │   ├── styles.css
│   │   ├── app.js
│   │   └── assets/
│   └── jogo-da-memoria/
│       ├── index.html
│       ├── styles.css
│       ├── app.js
│       └── assets/
├── calculadora/
│   ├── README.md
│   ├── src/calculator.py
│   └── tests/test_calculator.py
├── jogo-da-memoria/
│   ├── README.md
│   ├── CMakeLists.txt
│   ├── src/main.cpp
│   └── tests/
└── sistema-de-pedidos-e-comissoes/
    ├── README.md
    ├── CMakeLists.txt
    ├── src/main.cpp
    ├── demo.tape
    ├── docs/assets/sistema-pedidos.gif
    └── tests/
```

### Decisões de arquitetura

- Manter nomes de diretório em `kebab-case` porque também serão slugs públicos.
- Usar `src/` e `tests/` dentro de cada projeto para tornar código e verificação imediatamente localizáveis.
- Usar `build/` apenas como saída local e nunca versioná-la.
- Reservar `docs/` da raiz para o único site GitHub Pages do repositório; os dois projetos web serão subdiretórios do mesmo site.
- Não criar uma camada compartilhada entre projetos: eles ainda não possuem código comum que justifique acoplamento.

## 2. Padronização de nomes

### Python — `snake_case` e nomes orientados ao domínio

| Atual | Sugerido | Motivo |
|---|---|---|
| `calculadora.py` | `src/calculator.py` | Nome de módulo explícito e estrutura convencional. |
| `soma` | `add` | Verbo curto e consistente com os demais operadores. |
| `subtrai` | `subtract` | Padronização em inglês para alcance internacional. |
| `multiplica` | `multiply` | Mesmo vocabulário do domínio. |
| `num1` / `num2` | `first_number` / `second_number` | Remove abreviações e comunica o papel. |
| `opcao` | `selected_option` | Expõe intenção, não apenas tipo. |
| `resultado` | `result` | Consistência de idioma no módulo. |

### C++ — `camelCase` consistente

| Atual | Sugerido | Motivo |
|---|---|---|
| `limparTela` | `clearScreen` | Consistência de idioma e verbo de ação. |
| `exibirTabuleiro` | `renderBoard` | Descreve responsabilidade de apresentação. |
| `verificarPar` | `isMatchingPair` | Nome booleano que expressa uma pergunta. |
| `lerPosicao` | `readValidPosition` | Torna a validação parte do contrato. |
| `lerDadosIniciais` | `readGameSetup` | Expõe o objetivo dos dados lidos. |
| `numJog` | `playerCount` | Remove abreviação. |
| `j_atual` | `currentPlayerIndex` | Explica conteúdo e uso como índice. |
| `itensvendidos` | `itemsSold` | Corrige separação e padroniza camelCase. |
| `cod_repres` | `representativeId` | Remove abreviação e explicita identificador. |
| `itens_venda` | `itemCount` | Nome curto e sem mistura de convenções. |
| `valor_venda` | `saleAmount` | Vocabulário de domínio. |
| `novavenda` | `registerAnotherSale` | Expressa a decisão booleana do fluxo. |
| `taxa` | `commissionRate` | Evita nome genérico. |
| `comissaoVenda` | `saleCommission` | Consistência de idioma. |
| `piorVendedor` | `lowestVolumeRepresentative` | Evita julgamento e descreve a métrica real. |

`main.cpp` é um nome convencional para o ponto de entrada e pode ser mantido depois da migração para `src/`. Renomeá-lo não agrega valor se houver um `CMakeLists.txt` claro.

## 3. Fases de implementação

### Fase 1 — Higiene e estrutura

**Implementar**

1. Remover os dois `output/main.exe` do índice Git.
2. Manter `.gitignore` cobrindo Python, C++, IDEs, sistema operacional, web tooling e análises locais.
3. Mover fontes para `src/` em commits separados por projeto.
4. Adicionar `CMakeLists.txt` mínimo a cada projeto C++.

**Referências internas**

- Estrutura-alvo e tabela de nomes deste documento.
- Comandos atuais nos READMEs individuais.

**Verificação**

- `git ls-files "*.exe"` não retorna arquivos.
- `git status --ignored --short` confirma que `output/`, `build/` e caches são ignorados.
- Os três projetos continuam executando após cada movimento.

Comando copy-ready para retirar os binários do índice sem apagar as cópias locais:

```bash
git rm --cached jogo-da-memoria/output/main.exe
git rm --cached sistema-de-pedidos-e-comissoes/output/main.exe
```

**Guardas**

- Não apagar binários locais antes de confirmar que são reproduzíveis.
- Não misturar renomeação estrutural com alteração de regras de negócio no mesmo commit.

### Fase 2 — Testes e separação mínima de responsabilidades

**Implementar**

1. Calculadora: testar as quatro operações, divisão por zero e entradas inválidas.
2. Jogo da Memória: extrair criação/embaralhamento do tabuleiro e comparação de pares para unidades determinísticas.
3. Pedidos: extrair `calculateCommission(itemCount, saleAmount)` e testar os limites de todas as faixas.
4. Adicionar validação para modo, jogadores, falhas de `cin`, quantidade e valor de venda.

**Verificação**

- Cobrir os limites `19/20`, `49/50` e `74/75` do cálculo de comissão.
- Executar testes em uma máquina limpa ou CI.
- Compilar C++ com `-Wall -Wextra -pedantic` sem novos avisos.

**Guardas**

- Não introduzir frameworks de teste ou abstrações pesadas sem comparar o custo com asserts/CMake/CTest simples.
- Não alterar percentuais, tamanhos de tabuleiro ou fluxo de turnos sem um requisito explícito.

### Fase 3 — Demos web no GitHub Pages

**Implementar**

1. Criar `docs/index.html` como índice das demos e `docs/.nojekyll`.
2. Portar a Calculadora para `docs/calculadora/`, preservando os mesmos casos de erro.
3. Portar o Jogo da Memória para `docs/jogo-da-memoria/`, com estado JavaScript, eventos e atualização do DOM.
4. Usar caminhos relativos (`./styles.css`, `./app.js`) para respeitar a base `/code-lab/`.
5. Configurar `Settings → Pages → Deploy from a branch → main → /docs`.

**Verificação**

- Abrir localmente os dois `index.html` e concluir os fluxos principais.
- Validar navegação por teclado e layout em viewport móvel.
- Confirmar HTTP 200 em:
  - `https://teixeirads.github.io/code-lab/calculadora/`
  - `https://teixeirads.github.io/code-lab/jogo-da-memoria/`
- Só então trocar badges de “planejada” para “online”.

**Guardas**

- Não copiar o código de terminal para o Pages esperando execução automática.
- Não usar caminhos absolutos iniciados por `/` para assets do site de projeto.
- Não duplicar a regra da calculadora ou do jogo sem testes de paridade entre os comportamentos.

### Fase 4 — Replit e GIF do Sistema de Pedidos

**Implementar**

1. Importar por `https://replit.com/github.com/teixeirads/code-lab`.
2. Testar primeiro a configuração detectada pelo Replit.
3. Se necessário, versionar um `.replit` com comando único de compilação e execução.
4. Criar `demo.tape` com VHS e gerar `docs/assets/sistema-pedidos.gif`.
5. Substituir o placeholder do README pela imagem final e pelo link permanente do Repl.

**Guia rápido para gravar o terminal**

O **VHS** é a opção recomendada porque transforma a demonstração em um roteiro versionável e reproduzível. No Windows:

```powershell
winget install charmbracelet.vhs
```

Garanta também `ttyd` e `ffmpeg` no `PATH`. Para capturar uma sessão inicial e convertê-la em tape editável:

```bash
vhs record > sistema-de-pedidos-e-comissoes/demo.tape
vhs sistema-de-pedidos-e-comissoes/demo.tape
```

Um roteiro mínimo pode começar assim:

```text
Output sistema-de-pedidos-e-comissoes/docs/assets/sistema-pedidos.gif

Set Shell "bash"
Set Theme "Catppuccin Frappe"
Set Width 1200
Set Height 700
Set FontSize 22
Set TypingSpeed 40ms

Hide
Type "cd sistema-de-pedidos-e-comissoes && clang++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o app"
Enter
Wait
Show

Type "./app"
Enter
Wait+Screen /Digite uma das opcoes acima:/
```

Use `Wait` ou `Wait+Screen` para sincronizar a gravação com a saída real, em vez de depender apenas de tempos fixos. Como alternativa, `asciinema` + `agg` funciona bem em Linux/macOS para gravar uma sessão humana; mantenha Terminalizer apenas como contingência por ter manutenção menos recente.

**Verificação**

- O botão **Run** aceita entrada interativa no Console.
- A gravação mostra ao menos duas faixas de comissão e um relatório agregado.
- O GIF é legível, tem duração curta e não contém caminhos pessoais ou credenciais.

**Guardas**

- Não publicar secrets no repositório ou na gravação.
- Não confundir um link de importação com um Repl já configurado; atualizar o texto quando houver URL permanente.
- Não usar gravação de tela longa quando um tape determinístico do VHS reproduz a evidência.

### Fase 5 — Automação e acabamento de recrutamento

**Implementar**

1. Adicionar CI para testes Python e builds C++.
2. Incluir screenshots/GIFs comprimidos e textos alternativos descritivos.
3. Adicionar licença após escolher explicitamente o modelo adequado.
4. Aplicar tópicos no GitHub: `python`, `cpp`, `algorithms`, `portfolio`, `github-pages`.
5. Criar releases apenas quando houver uma demo reproduzível ou marco funcional claro.

**Verificação final**

- Todos os links do README respondem ou estão marcados explicitamente como planejados.
- Não há binários, caches, segredos nem arquivos pessoais rastreados.
- Cada afirmação de competência aponta para código, teste ou demo observável.
- Uma pessoa nova executa cada projeto usando somente o README.
- A primeira tela do repositório comunica problema, stack, evidência e acesso à demo em menos de um minuto.

## 4. Sequência de commits recomendada

```text
docs: add portfolio readmes and implementation roadmap
chore: ignore generated files and remove tracked binaries
refactor(calculator): organize source and standardize names
test(calculator): cover operations and invalid input
refactor(memory-game): isolate deterministic game rules
test(memory-game): cover board and matching rules
refactor(orders): extract commission domain rules
test(orders): cover commission boundaries
feat(pages): add calculator web demo
feat(pages): add memory game web demo
docs(orders): add Replit link and terminal demo gif
ci: verify Python tests and C++ builds
```

Essa ordem mantém cada mudança revisável, reduz o risco de regressão e produz evolução visível no histórico — um sinal tão importante para recrutamento quanto o estado final do código.
