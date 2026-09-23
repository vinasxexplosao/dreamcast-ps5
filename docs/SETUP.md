# Setup do Console de Teste — PS5

> Última atualização: 22/09/2026

## Consoles do projeto

| Console | Firmware | Papel | Cadeia atual |
|---|---|---|---|
| PS5 #1 | 7.61 | **Desenvolvimento principal** (mais rápido, comunidade maior) | BD-JB (TheFloW) + kernel + elfldr |
| PS5 #2 | 11.20 | **Laboratório de compatibilidade** | P2JB / BD-JB5 (cobertura estendida até ~12.70) |

### Regras de segurança (invioláveis)
- **NUNCA atualizar** nenhum dos dois consoles.
- **NUNCA logar na PSN** — sem conta conectada, sem internet nos testes.
- 13.60 está no privado (não confirmado publicamente) — **não planejar com base nisso**.
- 12.70 é o limite atual do P2JB publicamente conhecido.

## Filosofia de compatibilidade entre firmwares
1. O emulador (`dreamcast_ps5.elf`) deve ser **um único binário para todos os firmwares**.
2. O emulador **não sabe nada sobre exploit, kernel ou offsets** — quem ganha privilégios é a cadeia externa.
3. **Proibido** no código: `if (firmware == 7.61)`. Usar detecção em tempo de execução (função existe? caminho acessível?).
4. A cadeia muda por firmware;
