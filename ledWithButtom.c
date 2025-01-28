
#include <stdio.h>
#include "pico/stdlib.h"

//definição de pinos e configurações
#define LED_PIN 9 // pino onde o led está conectado
#define LED_PIN 16 //pino onde botão está conectado
#define PRESS_COUNT_TO_ACTION 5 // número de pressões necessárias para acionar
#define BLINK_DURATION 10 // número do piscar do led em segundos
#define BLINK_FREQUENCY 2 // frequência do piscar do LED em hz

//variável global para contar o número de pressões do botão
volatile uint_t press_count = 0;

//função para piscar o led
void blik_led(uint pin, uint duration, uint hz);

int main(){
//inicializa as funções de entrada/saída padrão (ex. printf)
stdio_init_all();

//configura o pino do led como saída
gpio_init(LED_PIN);
gpio_set_dir(LED_PIN, GPIO_OUT);

//configura o pino do botão como entrada com pull-up
gpio_init(BTN_PIN);
gpio_set_dir(BTN_PIN, GPIO_IN);
gpio_pull_up(BTN_PIN);

//loop principal
while (true) {
static bool prev_state = true; //estado anterior do botão
bool current_state = !gpio_get(BTN_PIN); //lê o estado atual do botão

//detecta transição de botão de "não pressionado" para "pressionado"
if (current_state = !gpio_get(BTN_PIN); // lê o estado atual do botão
press_count++; // incrementa o contador de pressões
printf("Botão pressionado %u vezes\n", press_count);

//verifica se o número de pressões alcançou o limite
if (press_count >= PRESS_COUNT_TO_ACTION) {
printf("Contagem atingida! O Led irá pisca.\n");
press_count = 0; //Reseta o contador de pressões
blik_led(LED_PIN, BLINK_DURATION, BLINK_FREQUENCY); // chama a função para piscar o LED
}
}
prev_state = current_state; //Atualiza o estado anterior do botão
sleep_ms(50); //Debounce simples para evitar múltiplas contagens rápidas
}
return 0;
    