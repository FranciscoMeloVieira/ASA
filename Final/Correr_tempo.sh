#!/bin/bash

# Diretório onde os arquivos de instância estão salvos
INSTANCIAS_DIR="INSTANCIAS"

# Arquivo para salvar os tempos de execução
TEMPOS_FILE="tempos_execucao.txt"

# Limpar ou criar o arquivo de tempos
> $TEMPOS_FILE

# Executar o programa em cada arquivo de instância e medir o tempo
for file in $(find $INSTANCIAS_DIR -name 'instancia_*.txt' | sort -V); do
    nome_arquivo=$(basename $file)
    
    # Extrair as informações de tamanho e número de placas do nome do arquivo
    IFS='_' read -r -a parametros <<< "$nome_arquivo"
    tamanho="${parametros[1]} x ${parametros[2]}"
    placas="${parametros[3]%.txt}"

    # Executar o programa e capturar o tempo
    tempo=$( (time ./a.out < $file) 2>&1 | grep 'real' | awk '{print $2}' )

    # Escrever no arquivo de tempos
    echo -e "tamanho: $tamanho\tplacas: $placas\ttempo: $tempo" >> $TEMPOS_FILE
done

echo "Tempos de execução salvos em $TEMPOS_FILE."