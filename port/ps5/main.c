/*
 * dreamcast_ps5 — ponto de entrada do payload
 *
 * Regra do projeto: este código NÃO sabe nada sobre exploit,
 * kernel ou offsets. Quem carrega este ELF é a cadeia externa
 * (BD-JB/P2JB -> elfldr). Aqui começa apenas o emulador.
 *
 * Entrypoint: main() — padrão do ps5-payload-dev/sdk.
 * No build de teste no PC, a notificação nem existe (só log).
 */
#include <stdio.h>

#ifdef PS5_BUILD
#include <string.h>
#include <stdbool.h>

#define SCE_NOTIFICATION_LOCAL_USER_ID_SYSTEM 0xFE

int sceNotificationSend(int userId, bool isLogged, const char* payload);

static const char toast_tmpl[] =
  "{\n"
  "  \"rawData\": {\n"
  "    \"viewTemplateType\": \"InteractiveToastTemplateB\",\n"
  "    \"channelType\": \"Downloads\",\n"
  "    \"useCaseId\": \"IDC\",\n"
  "    \"toastOverwriteType\": \"No\",\n"
  "    \"isImmediate\": true,\n"
  "    \"priority\": 100,\n"
  "    \"viewData\": {\n"
  "      \"icon\": {\n"
  "        \"type\": \"Predefined\",\n"
  "        \"parameters\": {\n"
  "          \"icon\": \"download\"\n"
  "        }\n"
  "      },\n"
  "      \"message\": {\n"
  "        \"body\": \"Dreamcast PS5: payload rodando!\"\n"
  "      },\n"
  "      \"subMessage\": {\n"
  "        \"body\": \"M2b validado no console real\"\n"
  "      }\n"
  "    }\n"
  "  },\n"
  "  \"createdDateTime\": \"2026-09-23T00:00:00.000Z\",\n"
  "  \"localNotificationId\": \"588193127\"\n"
  "}";
#endif /* PS5_BUILD */

int main(int argc, const char **argv)
{
    /* M2/M2b (marco atual): provar que o ELF inicia, dá feedback
     * visível na tela e sai de forma limpa sem travar o console. */
    printf("dreamcast_ps5: payload iniciado\n");
    printf("dreamcast_ps5: marco M2 — ELF minimo\n");

#ifdef PS5_BUILD
    printf("dreamcast_ps5: enviando notificacao na tela\n");
    sceNotificationSend(SCE_NOTIFICATION_LOCAL_USER_ID_SYSTEM,
                        true, toast_tmpl);
#endif

    /* TODO M3: inicializar video (padrao de teste)
     * TODO M4: input (DualSense), audio, filesystem
     * TODO M5: integrar core Flycast
     * TODO M6: frontend listando games/ do HD/SSD */

    printf("dreamcast_ps5:
