# Setup do Console de Teste — PS5

## Console
- Firmware: 7.61
- REGRAS: NUNCA atualizar o console. Sem login na PSN. Sem conectar na internet.

## Segundo console (backup)
- Firmware: 11.20 — não mexer por enquanto, aguardar exploit de kernel.

## Cadeia de execução (como o emulador roda no PS5)
1. BD-JB — exploit que entra pelo Blu-ray do console
2. Kernel exploit — ganha privilégios no sistema
3. elfldr — programa que carrega nosso arquivo ELF
4. dreamcast_ps5.elf — nosso emulador de Dreamcast

## HD/SSD externo (estrutura de pastas)
dreamcast/
├── bios/       → arquivo dc_boot.bin (BIOS do Dreamcast, fornecido pelo usuário)
├── games/      → jogos convertidos em .chd
├── saves/      → saves e VMU
└── states/     → save states

## Links úteis
- Flycast (emulador base): https://github.com/flyinghead/flycast
- PS5SDK: https://github.com/PS5Dev/PS5SDK
- Payload loader: https://github.com/cy33hc/ps5-payload-loader

## Problemas encontrados
- (anotar aqui tudo que der errado no console e como resolveu)
