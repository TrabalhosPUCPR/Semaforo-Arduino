# Semaforo-Arduino
Sistema de semaforo feito com arduino


[![video](https://img.youtube.com/vi/Lbi7a-hn3zs/0.jpg)](https://www.youtube.com/watch?v=Lbi7a-hn3zs)

(no video nao tem o sinal vermelho no sinaleiro do pedestre)<br>
<img src="https://github.com/TrabalhosPUCPR/Semaforo-Arduino/blob/main/circuito_semaforo.png">

### QUESTAO PROPOSTA:

- Extensão do protótipo do sistema de semáforos com a inclusão de dois 
botões para travessia de pedestres 
- O circuito deve incluir um par de LEDs (um vermelho e outro verde) para 
representar o semáforo de pedestre da via principal e outro par de LEDs 
para representar o semáforo de pedestre da via secundária. 
- O circuito deve incluir dois botões para solicitação de travessia de 
pedestres, uma para cada via. 
- O acionamento de qualquer um dos botões deverá causar o respectivo 
tratamento, fazendo com que os dois semáforos de veículos fiquem no 
vermelho, enquanto os dois semáforos de pedestres fiquem no verde a 
fim de permitir a travessia. 
- O acionamento de um botão de pedestre não causa o fechamento 
imediado para os veículos; é preciso aguardar, ao menos,  o fim do ciclo 
corrente dos semáforos dos veículos para, então, fazer o tratamento 
efetivo do acionamento do botão. 
- Como regra, o tratamento efetivo do acionamento de um botão de 
pedestres deve ocorrer, no máximo, a cada dois ciclos dos semáforos de 
veículos para que não prejudicar demais o fluxo de veículos. 
- Quando um dos dois botões for acionado, ambos deverão ficar inativos até 
seja feito o devido tratamento. 
- O tempo de verde para um semáforo de pedestre é fixo, definido no 
código por uma constante, digamos, TVP (tempo de verde para pedestre). 
- O semáforo de pedestres deve indicar quando está prestes a fechar, de 
maneira a alertar os pedestres para que acelerem o passo caso estejam 
atravessando a via, ou nem comecem a atravessar caso não tenham 
iniciado. Por exemplo, com TVP igual a 10 segundos, o semáforo de 
pedestres pode ficar verde por 6 segundos e, então, piscar por mais 4 
segundos. Sejam criativos! 
