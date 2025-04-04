# Trabalho de aquecimento | Skip Game

![Skip Game](img/resized_skip_game.png)

## 🐰 Sobre o Trabalho

**O trabalho de Aquecimento** foi desenvolvido em c++, ultilisando o paradigma Procedural, onde o tabuleiro é uma matriz de inteiros e cada elemento é representado por um numero diferente onde:
  - 0 → Área vazia (não queima)
  - 1 → Árvore saudável
  - 2 → Árvore em chamas
  - 3 → Árvore queimada (não propaga mais fogo, árvore totalmente queimada)
  - 4 → Presença de água
  - 9 → Representa o animal
    
<p>&nbsp;&nbsp;&nbsp;&nbsp;Ultilizando esses principios, optei por desenvolver ultilisando o procedimento procedural, no intuido de consumir menos memoria e deixar o progama mais leve, a partir disso, eu implementei algumas funçoes nas quais cada uma tem uma funcionalidade diferente fundamental para o funcionamneto do programa, para a propagação do fogo a função criada foi: <b>propagateFire</b>, para a movimentação do animal pela floresta(Matriz) foi criado a função <b>runAnimal</b>, e para a execução do programa foi criado a função <b>executeProgram</b> a qual sera chamada na main.</p>

---

## 🎮 Como Jogar

- Use as setas do teclado para mover o personagem.
- Evite as áreas pegando fogo.
- Alcance a zona segura antes que as chamas se espalhem.

---

## 🧱 Tecnologias Usadas

- C++ (Lógica do jogo)
- SDL2 (Gráficos e som)
- Git e GitHub (Controle de versão)
- Imagens 2D customizadas (como a capa acima)

---

## 🚀 Como Executar

```bash
git clone https://github.com/seu-usuario/skip-game.git
cd skip-game
make
./skip-game
