# Sistema de Pedidos e Comissões

![C++](https://img.shields.io/badge/C%2B%2B-17-00599C?logo=cplusplus&logoColor=white)
![Interface](https://img.shields.io/badge/interface-terminal-4c566a)
![Demo](https://img.shields.io/badge/demo-Replit-F26207?logo=replit&logoColor=white)

Aplicação de terminal que registra vendas, calcula comissões progressivas e consolida indicadores de quatro representantes comerciais.

## Objetivo

Traduzir regras de comissão em um fluxo operacional simples e auditável: cada venda atualiza quantidade de itens, faturamento e comissão do representante; os relatórios agregam os valores e identificam extremos de desempenho.

## Regras de negócio

| Quantidade de itens na venda | Taxa de comissão |
|---:|---:|
| Menos de 20 | 10% |
| De 20 a 49 | 15% |
| De 50 a 74 | 20% |
| 75 ou mais | 25% |

O sistema aceita códigos de representante entre `1` e `4` e mantém acumuladores independentes para itens vendidos, valor total de vendas e comissão total.

## Gestão de comissões

A comissão é calculada no momento do registro da venda e adicionada ao total do representante. O menu permite consultar:

- valor total de vendas processadas;
- comissão acumulada por representante;
- comissão total paga pela empresa;
- representante com maior valor vendido;
- representante com menor quantidade de itens vendidos.

## Lógica de domínio

O projeto concentra regras semelhantes às de uma camada de backend — validação do representante, classificação por faixa, agregação e ranking — mas a versão atual é uma aplicação monolítica em memória. Ela ainda não oferece API, persistência, autenticação ou banco de dados.

Essa distinção torna o valor técnico verificável: o código demonstra lógica de domínio e processamento, não uma infraestrutura que ainda não foi construída.

## Execução simulada

```text
$ g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o orders_commission
$ ./orders_commission

==== MENU - SISTEMA DE COMISSOES ====
1 - Registrar nova venda
2 - Exibir total de vendas processadas
3 - Exibir total de comissoes por representante
4 - Exibir total de comissoes pagas pela empresa
5 - Vendedor com o maior valor de vendas
6 - Vendedor com a menor quantidade de itens vendidos
7 - Sair
Digite uma das opcoes acima: 1
Informe o codigo do representante (1-4): 2
Informe a quantidade de itens da venda: 25
Informe o valor total da venda: R$ 2000
Comissao desta venda: R$ 300.00
Venda registrada com sucesso!
Deseja informar mais uma venda? (S/N): N
```

## Como executar localmente

Requisito: compilador C++ compatível com C++17.

```bash
cd sistema-de-pedidos-e-comissoes
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o orders_commission
./orders_commission
```

No Windows, execute o binário com `./orders_commission.exe` ou `.\orders_commission.exe`.

## 💻 Testar interativamente

[Importar o repositório público no Replit](https://replit.com/github.com/teixeirads/code-lab)

Depois da importação, abra o Shell e execute:

```bash
cd sistema-de-pedidos-e-comissoes
clang++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o app
./app
```

Se a detecção automática não configurar o botão **Run**, use este comando único em um arquivo `.replit` na raiz do repositório:

```toml
run = "cd sistema-de-pedidos-e-comissoes && clang++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o app && ./app"
```

## Demonstração em GIF

> 🎬 **Placeholder:** grave a execução e salve o arquivo como `docs/assets/sistema-pedidos.gif`. Depois, substitua este bloco pela imagem abaixo.

```markdown
![Demonstração do Sistema de Pedidos e Comissões](./docs/assets/sistema-pedidos.gif)
```

## Próximos passos

- Extrair o cálculo de comissão para uma função pura e testável.
- Substituir arrays indexados de `1` a `4` por uma coleção de estruturas `Representative`.
- Validar quantidade e valor da venda, incluindo falhas de leitura do `cin`.
- Definir comportamento explícito para empates nos rankings.
- Adicionar testes para os limites `19/20`, `49/50` e `74/75` itens.
- Separar regras de domínio da interface de terminal antes de introduzir persistência ou API.

