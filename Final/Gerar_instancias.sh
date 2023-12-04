#!/bin/bash

# Diretório onde os arquivos serão salvos
mkdir -p INSTANCIAS

# Gerar instâncias
for N in $(seq 400 400 2000); do
    for M in $(seq 400 400 2000); do
        # Verificar se N é maior ou igual a M
        if [ $N -ge $M ]; then
            for P in $(seq 250 250 1000); do
                echo "Gerando instância com N=$N, M=$M, P=$P"
                ./gen_supermarble $N $M $P > INSTANCIAS/instancia_${N}_${M}_${P}.txt
            done
        fi
    done
done
