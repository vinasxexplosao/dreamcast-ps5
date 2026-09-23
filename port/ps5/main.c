/*
 * dreamcast_ps5 — ponto de entrada do payload
 *
 * Regra do projeto: este código NÃO sabe nada sobre exploit,
 * kernel ou offsets. Quem carrega este ELF é a cadeia externa
 * (BD-JB/P2JB -> elfldr). Aqui começa apenas o emulador.
 *
 * Dois pontos de entrada:
 *   - payload_main: usado quando compilado com a toolchain do PS5SDK
 *   - main: usado no build de teste no PC (prova de sanidade)
 */

#include <stdio.h>

int payload_main(int argc, const char **argv)
{
    /* M2 (marco atual): provar que o ELF inicia, escreve log
     * e sai de forma limpa sem travar o console. */

    printf("dreamcast_ps5: payload iniciado\n");
    printf("dreamcast_ps5: marco M2 — ELF minimo\n");

    /* TODO M3: inicializar video (padrao de teste)
     * TODO M4: input (DualSense), audio, filesystem
     * TODO M5: integrar core Flycast
     * TODO M6: frontend listando games/ do HD/SSD */

    printf("dreamcast_ps5: encerrando com exit limpo\n");
    return 0;
}

#ifndef PS5_BUILD
/* Build de teste no PC: o linker exige uma função main.
 * No console, a toolchain do PS5SDK usa payload_main e
 * este bloco nem existe. */
int main(int argc, const char **argv)
{
    return payload_main(argc, argv);
}
#endif
