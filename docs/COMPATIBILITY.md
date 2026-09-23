# Matriz de Compatibilidade

> Registro oficial de testes do `dreamcast_ps5.elf` nos consoles do projeto.
> Cada linha é um teste real executado. Sem linha, sem promessa.

## Legendas

**Resultado:** ✅ Jogável | ⚠️ Com falhas (descrever) | ❌ Não roda

## Testes — Firmware 7.61 (console #1)

| Jogo | Formato | Res. interna | FPS | Loader | Resultado | Observações |
|---|---|---|---|---|---|---|
| *(nenhum teste ainda)* | — | — | — | — | — | — |

## Testes — Firmware 11.20 (console #2)

| Jogo | Formato | Res. interna | FPS | Loader | Resultado | Observações |
|---|---|---|---|---|---|---|
| *(nenhum teste ainda)* | — | — | — | — | — | — |

## Testes sem jogo — validação técnica

| Marco | FW 7.61 | FW 11.20 | Data | Observações |
|---|---|---|---|---|
| M2 — ELF mínimo abre e sai limpo | ⬜ | ⬜ | — | — |
| M3 — Padrão gráfico com frame pacing | ⬜ | ⬜ | — | — |
| M4 — Controle detectado | ⬜ | ⬜ | — | — |
| M4 — Áudio reproduzido | ⬜ | ⬜ | — | — |
| M4 — Leitura de arquivo no HD/SSD | ⬜ | ⬜ | — | — |
| M5 — Homebrew Dreamcast chega ao menu | ⬜ | ⬜ | — | — |
| M6 — Frontend lista `games/` e inicia | ⬜ | ⬜ | — | — |
| M7 — Save/VMU persiste após reinício | ⬜ | ⬜ | — | — |
| M8 — Upscaling 2× | ⬜ | ⬜ | — | — |
| M8 — Upscaling 4× | ⬜ | ⬜ | — | — |
| M8 — Clock unlock (experimental) | ⬜ | ⬜ | — | — |

**Legendas dos marcos:** ✅ passou | ⚠️ parcial | ❌ falhou | ⬜ não testado

## Regras deste documento

1. Só entra nesta tabela o que foi **testado de verdade** no console — nada de "deve funcionar".
2. Todo teste de jogo deve informar **resolução interna e fps medido** (não estimado).
3. Um jogo só é ✅ se rodar estável por **no mínimo 15 minutos**.
4. Toda nova versão do ELF deve re-testar os jogos já ✅ — se quebrar, o resultado é atualizado e o CHANGELOG registra o problema.
5. Formato dos jogos: sempre `.chd` (padrão do projeto).
