# Atividade de Programação Paralela em C

Este projeto explora conceitos essenciais de **programação paralela** e **distribuída** utilizando a linguagem **C** com a biblioteca `pthread`. São abordados temas como **Leitores e Escritores, Barreiras, Sinais e Deadlocks**, com implementações práticas para ilustrar o funcionamento de cada conceito em sistemas **multi-threaded**.

## Objetivos

- Compreender e implementar conceitos fundamentais de sincronização e coordenação de threads.
- Identificar e solucionar problemas de condições de corrida e deadlocks.
- Implementar soluções eficientes para controle de acesso a recursos compartilhados.
- Aprender técnicas de controle de concorrência, como Leitores e Escritores, Barreiras, Sinais e Deadlocks.

## Estrutura do Projeto

1. **Leitores e Escritores**
   - **Conceito**: Threads leitoras podem acessar simultaneamente um recurso compartilhado, enquanto threads escritoras exigem exclusividade.
   - **Implementação**: Exemplo prático em C usando semáforos para gerenciar o acesso ao recurso compartilhado.

2. **Barreiras**
   - **Conceito**: Sincronização de threads em pontos específicos do código, permitindo que todas completem uma etapa antes de prosseguir.
   - **Implementação**: Exemplo em C usando `pthread_barrier_t` para alinhar as threads em fases de execução.

3. **Sinais**
   - **Conceito**: Permite comunicação e sincronização entre threads, informando sobre a ocorrência de eventos específicos.
   - **Implementação**: Utilização de variáveis de condição e mutexes (`pthread_cond_t` e `pthread_mutex_t`) para enviar sinais entre threads.

4. **Deadlocks**
   - **Conceito**: Situação onde threads ficam presas aguardando recursos bloqueados por outras threads, criando um ciclo de dependência.
   - **Implementação**: Exemplo prático para demonstrar deadlock e como evitá-lo através de uma ordem consistente de bloqueio de mutexes.

## Instruções de Uso

1. Clone o repositório:
   ```bash
   git clone https://github.com/MatheusTaveira/AtividadeProgramacaoParalela.git
   ```
2. Compile os exemplos com gcc:
   ```bash
   gcc -pthread <arquivo.c> -o <nome_executavel>
   ```
3. Execute cada exemplo para observar o funcionamento dos conceitos:
   ```bash
   ./<nome_executavel>
   ```
