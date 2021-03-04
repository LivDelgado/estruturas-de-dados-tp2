# estruturas-de-dados-tp2
Segundo Trabalho Prático da disciplina de Estruturas de Dados, do curso de Sistemas de Informação da UFMG (2020/2)

## Como executar a ordenação do arquivo?

```bash
make

./bin/run.out caminho_arquivo_entrada.txt numero_linhas_a_ordenar
```

É necessário que o número de linhas seja maior que 7!
O arquivo será ordenado de forma **decrescente**, utilizando o Hybrid Quick Sort.
Exemplos de arquivo podem ser encontrados na pasta *exemplos*.
## Como executar o medidor de performance?
```bash
make

./bin/run.out caminho_arquivo_entrada.txt 1 1

```
Deste modo, ele ordenará as linhas (em 50, 100, 1k, 5k, 10k, 50k, 100k e 200k) utilizando 5 algoritmos de ordenação diferentes:
- Insertion Sort
- Merge Sort
- Quick Sort
- Hybrid Quick Sort (com o Comb Sort)
- Comb Sort

## Como limpar os arquivos executáveis e de compilação gerados?
```bash
make clean

```