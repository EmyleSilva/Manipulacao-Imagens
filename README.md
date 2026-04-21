# Pixel Wizard – Processador de Imagens PGM (P2)

O **Pixel Wizard** é um programa em C para manipulação de imagens no formato **PGM (Portable GrayMap)**, versão texto (P2). Através de um menu interativo, o usuário pode aplicar uma série de transformações geométricas e ajustes de intensidade, incluindo rotações, espelhamentos, negativo, controle de brilho e correção de ruídos por média dos vizinhos.

## 📋 Funcionalidades

| Opção | Comando                     | Descrição                                                                 |
|-------|-----------------------------|---------------------------------------------------------------------------|
| 1     | Rotação de 90°              | Gira a imagem 90° no sentido horário                                       |
| 2     | Rotação de -90°             | Gira a imagem 90° no sentido anti‑horário                                  |
| 3     | Inversão horizontal         | Espelha a imagem no eixo vertical (flip horizontal)                        |
| 4     | Inversão vertical           | Espelha a imagem no eixo horizontal (flip vertical)                        |
| 5     | Negativo                    | Inverte os níveis de cinza (255 – valor do pixel)                          |
| 6     | Aumento de brilho           | Soma um valor constante (0‑255) a cada pixel, limitando ao máximo (255)    |
| 7     | Diminuição de brilho        | Subtrai um valor constante (0‑255) de cada pixel, limitando ao mínimo (0)  |
| 8     | Detecção e correção de ruídos | Substitui pixels cuja diferença para a média dos vizinhos exceda um limiar |

## 📁 Estrutura do Projeto

```
Manipulacao-imagens/
├── projeto.c # Código principal
├── projeto.h # Cabeçalho com declarações e variáveis globais (imagem, dimensões, etc.)
└── README.md # Este arquivo
```

## ⚙️ Pré‑requisitos

- Compilador C com suporte ao padrão C99 ou superior.
- Sistema operacional que reconheça os comandos `clear` (Linux/macOS) ou `cls` (Windows). 

## 🔧 Compilação e Execução

Compile todos os arquivos fonte juntos. Exemplo com GCC:

```bash
gcc -o pixelwizard projeto.c 
```

Para Executar:

```bash
./pixelwizard # Linux/macOS
pixelwizard.exe # Windows
```

Ao iniciar, o programa exibirá o menu principal. O usuário deve digitar o número da operação desejada e pressionar Enter.

## 🖼️ Formato da Imagem Suportado

O programa trabalha exclusivamente com imagens PGM no formato P2 (texto). A estrutura esperada do arquivo é:

```text
P2
# Comentário opcional
largura altura
255
valor1 valor2 valor3 ...
```

- A primeira linha deve conter P2.
- Linhas iniciadas com # são comentários (ignorados).
- A largura e altura são números inteiros positivos.
- O valor máximo de cinza (quant_nivel_cinza) geralmente é 255.
- Os pixels são representados por inteiros (0 a 255) separados por espaços ou quebras de linha.

> Atenção: As funções abrir_imagem() e fechar_imagem() (definidas em projeto.h) devem implementar corretamente a leitura e escrita neste formato. O programa não realiza validação aprofundada de formato de arquivo – presume-se que o usuário forneça um PGM válido.

## 📌 Observações

- A limpeza de tela (system("clear || cls")) é usada para melhorar a experiência do usuário, mas pode não funcionar em todos os ambientes. Em caso de falha, mensagens serão apenas sobrepostas.

- O programa utiliza a variável global quant_nivel_cinza (geralmente 255) como valor máximo de intensidade.

- A função mensagem_final() aguarda um ENTER para que o usuário visualize o resultado antes de retornar ao menu.

---

Desenvolvido como parte de um projeto acadêmico da disciplina Linguagem de Programação I para fixação dos conceitos aprendidos sobre Linguagem C.