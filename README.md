---
# 📄 TABALHO AEDI - Simulação de Propagação de Incêndios

<div align="center">
    <img src="img/resized_skip_game.png" width="200" height="200">
</div>

<div align="center">

##  🖤 Simulação de Propagação de Incêndios

</div>

## ☕ Introdução

Este trabalho de Aquecimento foi desenvolvido em C++, adotando o paradigma procedural para garantir um programa mais leve e com menor consumo de memória. O tabuleiro é representado por uma matriz de inteiros, na qual cada número indica um tipo de elemento da floresta:

- **0** → Área vazia (não queima)  
- **1** → Árvore saudável  
- **2** → Árvore em chamas  
- **3** → Árvore queimada (não propaga mais fogo)  
- **4** → Presença de água  
- **9** → Animal  

O código foi organizado em funções específicas para cada responsabilidade do sistema:

- **`propagateFire`**: Responsável pela propagação do fogo na floresta.  
- **`runAnimal`**: Gerencia a movimentação do animal pela matriz.  
- **`executeProgram`**: Controla a execução geral do programa e é chamada na função **`main`**.

O progrma é responsavel por execultar dois algoritimos de movimentação pela matriz, o algoritimo do fogo e o do animal, o intuito do programa é desenvolver uma matriz de NxM de numeros aleatorios segunido a seguint ordem dada a cima, 
a partir da leitura do arquivo input.dat o programa recebe essa matriz que a principio, informa ao programa duas informaçoes fundamentais, as dimenções da matriz e onde sera o primeiro foco do incendio, a partir disso, o programa faz uma varredura 
verificando onde esta o '0' mais proximo para alocar o animal, assim temos os dois principais membros do programa ja posicionados na matriz.

A partir desse ponto, se inicia outra parte do programa, as partes principais que serão avaliadas, no qual se trata da propagação 
do fogo e a movimentação do animal, a propagação do fogo se da a partir de um arquivo config.hpp em que o usuario pode definir algumas informações, uma delas é a direção do vento, sao existentes 14 direçoes possiveis as quais são: 
Direções possíveis de propagação do fogo:

| Nº | Descrição                   | Movimento                          |
|----|----------------------------|-----------------------------------|
| 1  | Direita e baixo            | ➡️⬇️ `{{1, 0}, {0, 1}}` |
| 2  | Esquerda e baixo           | ⬅️⬇️ `{{-1, 0}, {0, 1}}` |
| 3  | Direita e cima             | ➡️⬆️ `{{1, 0}, {0, -1}}` |
| 4  | Esquerda e cima            | ⬅️⬆️ `{{-1, 0}, {0, -1}}` |
| 5  | Cima e baixo               | ⬆️⬇️ `{{-1, 0}, {1, 0}}` |
| 6  | Esquerda e direita         | ⬅️➡️ `{{0, -1}, {0, 1}}` |
| 7  | Direita, esquerda e cima   | ➡️⬅️⬆️ `{{1, 0}, {0, -1}, {0, 1}}` |
| 8  | Direita, esquerda e baixo  | ➡️⬅️⬇️ `{{1, 0}, {0, -1}, {0, 1}}` |
| 9  | Direita, cima e baixo      | ➡️⬆️⬇️ `{{1, 0}, {0, -1}, {0, 1}}` |
| 10 | Esquerda, cima e baixo     | ⬅️⬆️⬇️ `{{-1, 0}, {0, -1}, {1, 0}}` |
| 11 | Direita                    | ➡️ `{{0, 1}}` |
| 12 | Esquerda                   | ⬅️ `{{0, -1}}` |
| 13 | Cima                       | ⬆️ `{{-1, 0}}` |
| 14 | Baixo                      | ⬇️ `{{1, 0}}` |

Assim o usuario pode escoler qualquer dirção para a propagação do fogo e a possição '0' representa a padrão onde o fogo se propaga ppara todas as direções.

O animal ja se movimenta de forma independente, visando sempre uma lista de prioridade, onde temos que a prioridade um é casas onde tem o numeral 4, que representa a presença de agua, a segunda prioridade é onde possui o numeral 0,
que são casas que não pode pegar fogo, e a terceira e ultima são as casas de numeral 1, onde tem arvores e se caso o animal estiver presente antes de pegar fogo ele perdera sua vida, a partir disso, todas as posições em que o animal vizitar entrara para uma lisa
e ele não podera mais voltar aquela posição.


## 🎯 Objetivos do Trabalho

- Proporcionar uma experiência prática na implementação de algoritmos utilizando vetores e matrizes.
- Estimular a reflexão sobre a eficiência computacional.
- Oferecer a oportunidade de revisar e consolidar os conhecimentos adquiridos até o momento.
- Reforçar os conceitos já abordados durante o curso.
- Aprimorar habilidades de pensamento crítico e desenvolvimento de soluções.
- Aplicar padrões de projeto na construção do programa.
- Incentivar a documentação adequada das ações realizadas na resolução de problemas computacionais emergentes.

## 🖥️ Ambiente de Criação

Foi ultilizado para implementação do programa, a linguagem: C++, no sistema operacional linux Ubuntu 24.04.2 LTS, Notebook Sansung Book3
a ferramenta para codigo foi o VSCode, para execução foi utilizado o compilador g++ no linux e o comando make file, o arquivo makefile ultilizado
esta presente no repositorio para qualquer duvidas.

## 📂 Organização dos Arquivos

A organização de arquivos ficou da seguinte forma: 

```plaintext
📦 projeto/                 # Raiz do repositório
├── 📂 .vscode/            # Configurações do VSCode
├── 📂 build/              # Arquivos de compilação (gerados)
├── 📂 img/                # Assets visuais (imagens, ícones)
├── 📂 src/                # Código-fonte principal
│   ├── 📂 include/        # Cabeçalhos (.hpp)
│   │   ├── algoritmics.hpp  # Algoritmos principais
│   │   ├── arquivos.hpp     # Manipulação de arquivos
│   │   ├── config.hpp       # Configurações globais
│   │   └── programa.hpp     # Estrutura do programa
│   │
│   ├── algoritmics.cpp   # Implementação dos algoritmos
│   ├── arquivos.cpp      # Lógica de arquivos
│   ├── config.cpp        # Configurações
│   ├── programa.cpp      # Fluxo do programa
│   └── main.cpp          # Ponto de entrada
│
├── input.dat            # Dados de entrada (exemplo)
├── output.dat           # Dados de saída (gerado)
│
├── 📄 Makefile          # Automação de compilação
└── 📄 README.md         # Documentação
```

Seguindo as diretrizes organizacionais, visando em deixar separado os arquivos .hpp dos arquivos .cpp para mais segurança e legibilidade.

## 💡 Implementação
### Funções
- `bool limit(int x, int y, int rows, int cols);`  
  Função ultilizada para verificar se a posição esta dentro dos limites da matriz, ela foi elaborada para evitar erros de segmentação.

- `void propagateFire(vector<vector<int>>& matrix, int rows, int cols);`
  Essa função é a responsavel pela propagação do fogo da seguinte forma: 
      Para o funcionamento correto dessa cunção eu criei uma variavel global static para armazenar todas as posiçoes anteriores em que o fogo propagou, isso sera ultil para que nas proximas iteração ela sejam atualizadas para 3, seguindo dentro da função, criei uma lisata para armazenar os lugres em que estão os focos de incendio, a qual tem o nome firePos, em seguida temos um for que percorre toda a matriz porcurando onde tem o fogo, e vai adicionando as cordenadas de cada foco na lista firePos, em seguida temos o while responsavel para a atualização das posiçoes onde estava queimamdo na iteração anterior, ele sera executado ate a lista estiver vazia, cada iteração dele é responsavel por pegar um para da lista cirada para armazenar as posiçoes anteriores, chamada newFirePositions, removendo cada posição da lista ele verifica se esta posição esta dentro dos limites apos a verificação troca o a arvore em chamas (2) para arvore queimada (3).
      Apos isso temos outro while, que é responsavel pela propagação do fogo. Ele sera execultado ate a lista firePosition estiver vazia, ele segue os mesmos criterios do ultimo while, pega cada posição e remove ela da lista, apos isso faz uma verificÇõ se esta dentro dos limists, se caso estiver ela é adicionada na lista estatica newFirePositions, apos isso entramos em um for que a partir ads cordenadas solicitadas no arquivo config, ele entratr em um for que executara o comando para todas elas, onde dentro do for crio duas variaves de cordenaasas dirreçãoX e direçaoY que recebe a posição de dentro da lista sobado ao par das cordenadas de propagação, chamada directions fire,apos isso faço a verificação para saber se esta dentro dos limites e verifico se o animal esta nesa posição, se caso ele estiver, ele sera quemado e a variavel global responsavel por verificar se o animal esta vivo ou morte muda para false, e assim perdemos o animal, apos isso temos um else if que verifica se caso a verificação anterior for falsa ele verifica esta dentro dos limites e verirfica se é uma arvore saldavel(1), se caso for verdade, ele incendeia a arvore e assim termina o loop, ele fara isso para todas as direçes.

- `bool isFireExtinguished(const vector<vector<int>>& matrix)`
  Essa função é responsavel por verificar se a floresta ja foi toda incendiada. Ela sera fundamental para dizer se a execução cehgou ao fim.

- `bool runAnimal(vector<vector<int>>& matrix, int rows, int cols, pair<int, int> &animalPos)`
  A função runAnimal é responsável por movimentar o animal na matriz da floresta da seguinte forma:
    Ela começa verificando se o animal ainda está vivo através da variável global animalAlive. Caso o animal já tenha sido queimado, a função retorna false imediatamente. Em seguida, ela define uma ordem de prioridade para os terrenos que o animal deve tentar se mover, dando preferência para áreas com água (4), depois espaços vazios (0), e por fim, florestas comuns (1). Essa prioridade existe para aumentar as chances de sobrevivência do animal, tentando sempre fugir do fogo e buscar áreas mais seguras.

  Dentro da função, para cada prioridade, ela percorre todas as direções possíveis ao redor da posição atual do animal, calculando novas posições e verificando se elas estão dentro dos limites da matriz e se correspondem ao tipo de terreno que estamos buscando naquele momento. Se a posição for válida e o animal ainda não tiver passado por ela (usando a variável global lastPositionsAnimal para evitar que o animal volte para posições antigas), ele prossegue para o movimento. Caso a nova posição seja uma área de água, a função também reforça a proteção ao redor dela, percorrendo novamente as direções ao redor para transformar as células próximas em áreas seguras.

  Por fim, a função atualiza a matriz: marca a posição antiga do animal como floresta comum (1), a nova posição como a do animal (9), e atualiza também a posição atual do animal na variável animalPos, além de adicionar essa nova posição no histórico de locais visitados pelo animal. Com isso, a função retorna true, indicando que o animal conseguiu se mover para uma nova célula da matriz com sucesso.

- `vector<vector<int>> getMatrix(ifstream &file, int& rows, int& cols, int& fireX, int& fireY)`
   A função getMatrix é responsável por montar e retornar a matriz inicial do seu cenário de simulação, lendo as informações de um arquivo. Ela recebe como parâmetro uma referência para um objeto ifstream, por onde lê as entradas do arquivo de configuração. Logo no início, ela captura as dimensões da matriz (rows e cols) e também as coordenadas iniciais do foco de incêndio (fireX e fireY). Com esses dados, a função cria uma matriz de inteiros (matrix) com o tamanho informado e inicializa todas as posições de acordo com os valores lidos do arquivo.

    Depois de preencher a matriz, a função faz uma varredura completa para encontrar o primeiro espaço vazio da matriz, que é representado pelo valor 0. Esse espaço vazio será a posição inicial do animal na simulação. Para garantir que o animal seja posicionado corretamente, a função usa uma variável booleana verify, que começa como false e muda para true assim que encontra a primeira posição livre. Quando isso acontece, o valor da célula na matriz é alterado de 0 para 9, que representa o animal na simulação, e o laço de busca é interrompido imediatamente com o comando break.

    Após posicionar o animal, a função finaliza configurando o foco inicial do incêndio na matriz, marcando a célula nas coordenadas fireX e fireY com o valor 2, que indica fogo ativo. Por fim, ela retorna a matriz completamente inicializada para que o restante do programa possa utilizá-la. Vale comentar que existe um cout no final da função, mas ele está após o return, então nunca será executado. Se for necessário exibir alguma mensagem, ele deveria estar antes do return.

- `printMatrix(const vector<vector<int>>& matrix)`
    É a responsavel por printar a matriz.

- `pair<int, int> getRowsAndCols(ifstream &file)`
    É responsavel por apartir do documento retornar o numero de linha e colunas da matriz.

- `pair<int, int> getAnimalPosition(const vector<vector<int>>& matrix, int rows, int cols)`
    Essa função é responsavel por dizer onde o animal se encontra dentro da matriz.

- `vector<vector<int>> createMatrix()`
    Essa função é responsavel por criar a matriz a partir do documento de entrada

- `void executeProgram() `
    E por ultimo e não menos importate essa função é a responsavel por excultar o programa de modo:
  funcionando como o fluxo principal que gerencia as etapas da simulação do incêndio na floresta. Logo no início, ela abre o arquivo de entrada chamado input.dat, de onde serão lidas as informações iniciais necessárias para o programa. Em seguida, a função obtém as dimensões da matriz (número de linhas e colunas) através da função getRowsAndCols, inicializa a contagem de iterações em 1, cria a matriz da floresta utilizando a função createMatrix, e localiza a posição inicial do animal com a getAnimalPosition, que armazena essas coordenadas em animalPos.

    Na sequência, a função redireciona a saída padrão do programa para um arquivo de saída chamado output.dat, utilizando o freopen, garantindo que todas as impressões feitas com cout dentro do laço sejam gravadas no arquivo especificado. Com isso preparado, a função entra em um laço while que continuará executando enquanto houver fogo ativo na floresta e a contagem de iterações não ultrapassar o limite máximo estabelecido por numberOfIterations. Dentro do laço, primeiro ela imprime o estado atual da matriz da floresta, junto com o número da iteração atual, depois chama a função runAnimal para movimentar o animal conforme a lógica definida, e logo em seguida executa a propagação do fogo chamando a função propagateFire. Esse ciclo se repete a cada iteração, atualizando constantemente o estado da floresta e do animal.

    Assim que o laço while termina, seja porque o fogo acabou ou porque o número máximo de iterações foi atingido, a função imprime a mensagem final avisando que não há mais árvores para queimar. Por fim, ela fecha a saída padrão que foi redirecionada para o arquivo com o comando fclose(stdout), encerrando a escrita no arquivo de saída e finalizando assim a execução do programa de forma organizada. Esse fluxo garante que a simulação ocorra de maneira sequencial, respeitando a ordem das ações e permitindo que o usuário possa acompanhar o resultado da execução consultando o arquivo output.dat.
  
## 📜 Arquivos Adicionais
- `matrix.py`:
     Este algoritmo em Python gera uma matriz de dimensões definidas pelo usuário, preenchendo cada célula com valores aleatórios entre 0, 1 e 4, onde o número 1 tem maior probabilidade de ser escolhido. Após receber as entradas de linhas e colunas, o programa cria a matriz utilizando pesos para controlar a frequência dos números e, em seguida, exibe a matriz formatada no terminal. Foi ultilizado para ciração de todas as matrizes de testes.
- `Makefile`:
      O Makefile é um arquivo de automação usado para simplificar e automatizar a compilação e execução de projetos, principalmente em linguagens como C ou C++. Ele define um conjunto de regras que descrevem como construir o projeto, especificando os arquivos-fonte, os comandos de compilação e as dependências necessárias. Com ele, basta executar o comando make no terminal para que todas as etapas definidas sejam realizadas automaticamente, evitando que o programador precise compilar manualmente cada arquivo ou lembrar de comandos complexos, além de otimizar o processo ao compilar apenas os arquivos que foram modificados. Sera ultilizado para correção, verificação e testes do algoritimo.

## 🧪 Casos de Teste
- `Entrada`:  
    Na entrada ultilizamos um arquivo input.dat que o seu conteude é uma matriz da seguint maneira:  
    6 6 0 0  
    1 0 1 0 1 1  
    1 1 0 1 4 4  
    1 1 1 1 4 4  
    1 0 1 1 0 1  
    1 1 1 1 1 1  
    1 4 4 1 4 1  

     Onde os dois primeiros numeros representa as dimenções da matriz, e os outros dois representa o inicio do foco de incendio, apos isso ser lido pela função getMatrix ela nos retornara nossa Florestas no seguinte formato:
    2 9 1 0 1 1  
    1 1 0 1 4 4  
    1 1 1 1 4 4  
    1 0 1 1 0 1  
    1 1 1 1 1 1  
    1 4 4 1 4 1  

     Ja com o animal posicionado e o fogo tambem!

  - `Saida:`
       Na saida temos uma arquivo output.dat que mostar todas as iterações, da seguinte maneira:  
  
    Matriz atual:  
    2 9 1 0 1 1  
    1 1 0 1 4 4  
    1 1 1 1 4 4  
    1 0 1 1 0 1  
    1 1 1 1 1 1  
    1 4 4 1 4 1  

    Iteracao: 1 de 10

    Matriz atual:  
    2 2 1 0 1 1  
    2 9 0 1 4 4  
    1 1 1 1 4 4  
    1 0 1 1 0 1  
    1 1 1 1 1 1  
    1 4 4 1 4 1  

    Iteracao: 2 de 10  

     O programa emitirar um aviso caso o anima tenha sido atingido pelo fogo da seguinte forma:

    Matriz atual:  
    3 3 3 0 1 1  
    3 3 3 2 4 4  
    3 3 2 1 4 4  
    3 9 1 1 0 1  
    2 2 1 1 1 1  
    2 4 4 1 4 1  
    Animal atingido pelo fogo! Vida restante: 0

     Se caso o animal for atingido novamente pelo fogo emitirar o segundo aviso:  
    Matriz atual:    
    3 3 3 0 1 1  
    3 3 3 2 4 4  
    3 3 2 2 4 4  
    8 2 2 1 0 1  
    2 2 1 1 1 1  
    2 4 4 1 4 1  
    Animal atingido pelo fogo! Animal morreu!

     A partir disso onde o animal morreu se transforma em 8 e o animal para de se movimentar.
     Apos ter termidadno o numero de iterações ou o fogo ter sido extinguido o progrma mostra o relatorio:  
    ______________________________________  
    Relatorio de execucao:  
    Iteracoes: 10  
    Fogo extinto: Não  
  
    Informacoes do animal:  
    Animal vivo: Nao  
    Vidas Animal : 0  
    Passos:6  
    Posicoes:  
    [1, 1]  
    [1, 2]  
    [2, 0]  
    [2, 2]  
    [3, 1]  
    [3, 2]  
    ______________________________________  

     E assim finaliza a saida e as entradas do programa.
        

## 🤔 Curiosidades / Observações
 - `Observações`  
       O fogo se propaga em uma velocidade exponencial, que é bem mais rapido que a movimentação do animal, reduzindo assim as possiblidades de deixar o animal vivo por muito tempo, o animal não consegue pular o fogo, se caso ele estiver sercado pelo fogo ele sempre morrera queimado, na ordem de prioridade do animal os locais que estão com 3 o animal considera como ultima opção em uma situação de pior caso, mas em verios casos de testes eu nunca consegui colocar ele em cima do 3 pois ele sempres fiacava sercado pelo fogo e acabava morrendo, o fogo quando esta se propagando em uma direção, ele se estingue mais rapido do que quando se propaga nas quatro direçõe,  se caso o fogo estiver sercado por aguas e o animal entra em uma casa com agua ele abrira caminho para que o fogo consiga sair da região isolada.

 - `Ideias de Melhorias`  
        Algumas ideias para melhora o progrma são: a implementação de uma area segura para o animal como se fosse uma base florestal, la o fogo não podear atingir o animal, e o animal podear se mover em loop nessas areas pois ele ja esta salvo, e o fogo não tera terminado de propagar. Outra melhoria, a implementação de um destino para o animal, pois ele ainda esta circulando pelo mapa sem direções. Melhorias no codigo, para a movimentação do animal uma melhoria seria salvar o numero dele com um conjunto pair<int, int> ,onde o primeiro inte seria o numero do animal(9), e o segundo seria a posição anterior que o animal estava, podendo ser atribuida uma verificação para se caso o animal estiver em <9, 3> ou em <9, 0>, o fogo não podera atingilo naquela posição 

## 👨🏻‍🔬 Ambiente de Teste
- **Sistema Operacional:** Ubuntu Ubuntu 24.04.2 LTS
- **Compilador:** gcc (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0
- **Hardware:** Processador i5 e 8GB RAM

## 👨🏻‍💻 Compilação e Execução
- `Compilação`  
      Para a compilação foi ultilizado o Makefile seguindo os seguintes comandos:  
        - make clean: limpar os executaves antigos  
        - make: para criar os arquivos executaveis  
        - make run: para executar  
        - meke r: para executar todos de uma vez so
- `Comandos para clonar o Repositorio:`  
      git clone https://github.com/hugnarok/Trabalho-AEDI-Fogueira.git  

## 🔚 Conclusão  
Este projeto foi uma simulação bem estruturada de propagação de incêndio em uma floresta, com o adicional do desafio dinâmico de movimentação de um animal tentando escapar das chamas. Desde o início, o desenvolvimento foi pensado para integrar de forma fluida a leitura de dados, a manipulação da matriz que representa o ambiente, e a interação entre os elementos — fogo e animal — permitindo observar como o fogo avança e como o animal reage, tudo isso controlado por iterações claramente contadas e registradas em um arquivo de saída. A implementação das funções como propagateFire e runAnimal trouxe uma dinâmica interessante, permitindo não apenas visualizar a destruição causada pelo fogo, mas também acompanhar a tentativa do animal de sobreviver em meio ao caos.  

Além disso, o projeto foi uma ótima oportunidade para aprofundar conhecimentos em algoritmos de simulação, uso de estruturas de dados como vetores e pares, além do manuseio de arquivos para entrada e saída de dados. Você também aplicou conceitos importantes como o controle de fluxo, condições de parada eficientes, e uso de variáveis globais e locais para manter o estado da simulação de maneira consistente. Mais do que um simples trabalho técnico, ele se tornou um exercício de lógica e planejamento, mostrando como as escolhas de implementação impactam diretamente no comportamento do sistema.  

Finalizando, este projeto não só cumpriu com sucesso os objetivos propostos, mas também serviu como um excelente exercício de raciocínio algorítmico e de organização do código. Agora, com a base sólida que foi construída, você tem total liberdade para expandir ainda mais, seja adicionando novos elementos como obstáculos, melhorias visuais na saída do programa, ou até uma inteligência mais avançada para o movimento do animal. O importante é que a estrutura central está muito bem montada, e você fechou esse ciclo com um resultado consistente e funcional!  

## 📪 Contato
- Email: hugohmarques4@gmail.com(mailto:hugohmarques4@gmail.com)
- LinkedIn: [Hugo H. Marques](www.linkedin.com/in/hugo-h-marques-980629216)
- GitHub: [@hugnarok](https://github.com/hugnarok)
