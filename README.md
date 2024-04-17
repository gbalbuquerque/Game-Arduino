# Game Arduino

Esse jogo apresenta uma proposta de ser um Quiz no microcontrolador Arduino em um display LCD.

![image](https://github.com/gbalbuquerque/Game-Arduino/assets/115583227/652b753e-208b-44e7-a766-46f44adc1f74)

Nesse display serão exibidas 15(quinze) perguntas de nível baixo, médio e difícil, onde o nível será incrementado a cada 5 perguntas contendo uma pergunta final, que se acertada o jogador ganha o jogo.
O jogador terá o direito de pular até 3 perguntas caso não saiba responder e se o tempo da pergunta expirar, uma tentativa de pulo será contabilizada.

Falando Sobre os led's, eles são acessos em 3 hipóteses, quando o jogador acerta uma pergunta o led verde acende, quando o jogador erra uma pergunta o led vermelho acende e quando o tempo está acabando o led vermelho pisca para avisar.

![image](https://github.com/gbalbuquerque/Game-Arduino/assets/115583227/2f3e193e-634c-4e23-a63b-3bce49ab50a4)


Além disso,sons são tocados para as seguintes situações no jogo:

• Ao inciar o jogo;
• Ao acertar uma pergunta;
• Ao errar uma pergunta;
• Ao pular uma pergunta;
• Ao perder o jogo;
• Ao ganhar o jogo.

Os tons do aúdio que o piezo(buzzer) toca estão relacionados com a situação que o jogador estiver passando no jogo.

## **Como Jogar**

Na placa de ensaio, o jogador contará com 6 botões que tem as seguintes funcionalidades, da esquerda para a direita

![image](https://github.com/gbalbuquerque/Game-Arduino/assets/115583227/d779e650-34d0-4207-b1ba-a7de5832aa67)

Botão 1 (botão mais a esquerda) - Tem a função de inciar e reiniciar o jogo

Botão 2 - Tem a função de pular as perguntas

Botão 3 - Tem a função de dizer não para as perguntas

Botão 4 (botão mais a direita) - Tem a função de dizer sim para as perguntas

## Materiais Ultilizados

### Placa de ensaio

![image](https://github.com/gbalbuquerque/Game-Arduino/assets/115583227/7e5f2cc3-25f0-4b51-90da-30e418cd0fdd)

### Display LCD 16x2

![image](https://github.com/gbalbuquerque/Game-Arduino/assets/115583227/a877f356-c189-48a4-8589-a3829a980286)
Fonte: (https://www.usinainfo.com.br/display-arduino/display-lcd-16x2-com-fundo-azul-2304.html)

### Arduino Uno R3
![image](https://github.com/gbalbuquerque/Game-Arduino/assets/115583227/e97b7cc4-6279-4bae-82c8-c094111f1b9c)

### Piezo(Buzzer)

![image](https://github.com/gbalbuquerque/Game-Arduino/assets/115583227/3754bc45-6de6-4383-bcf7-30df9592964a)

### Pontênciometro

![image](https://github.com/gbalbuquerque/Game-Arduino/assets/115583227/90c9183b-f140-4fca-8061-9b602dd663f9)

## Conclusão

  Em conclusão, desenvolver este jogo de quiz no Arduino foi uma oportunidade empolgante para aplicar os conceitos de programação em C em um ambiente prático e interativo. Ao longo do processo, enfrentamos desafios significativos, desde a estruturação das perguntas até a implementação das funcionalidades de interface e lógica do jogo. Para resolver esses problemas, adotamos uma abordagem iterativa, refinando constantemente nosso código e testando sua funcionalidade em cada etapa do desenvolvimento.

  Utilizamos técnicas de depuração e troubleshooting para identificar e corrigir erros, garantindo que o jogo funcionasse conforme o planejado. Além disso, aprofundamos nosso entendimento sobre o funcionamento do Arduino e sua integração com sensores e dispositivos de entrada, o que ampliou nosso conhecimento em eletrônica e programação embarcada.

  Ao final, o resultado foi um jogo de quiz funcional e envolvente, capaz de desafiar os jogadores e proporcionar entretenimento. Este projeto destacou a importância da prática e da perseverança na resolução de problemas de programação, ao mesmo tempo em que demonstrou as infinitas possibilidades criativas que o Arduino oferece para projetos interativos. Estamos entusiasmados com o que aprendemos e motivados a explorar ainda mais as aplicações dessa plataforma versátil em futuros projetos. 

  Algumas questões do código ainda estão em aberto, como a diferença de pontuação que os diversos níveis podem proporcionar ou como o a parte final das perguntas. Mas isso será ajustado em breve. Gostaria de agradecer ao professor Isaac por ter proposto esse desafio.
