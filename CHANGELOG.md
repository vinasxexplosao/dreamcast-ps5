# Changelog

Todas as mudanças notáveis deste projeto serão documentadas aqui.

O formato é baseado em [Keep a Changelog](https://keepachangelog.com/pt-BR/1.1.0/).

## [Unreleased]
### Added
- Estrutura inicial do repositório
- Documentação de setup dos consoles 7.61 e 11.20
- CHANGELOG e .gitignore de proteção de conteúdo
- Stub do payload_main com build de teste no PC compilando (M2 — prova de sanidade)
- Configuração CMake inicial e primeira execução do binário de teste
- Toolchain PS5 configurada: ELF nativo gerado com ps5-payload-dev SDK (M2 completo)

## Marcos planejados
- [ ] M1 — Build do Flycast no PC (referência)
- [ ] M2 — ELF mínimo rodando no 7.61
- [ ] M2b — Mesmo ELF validado no 11.20
- [ ] M3 — Vídeo com frame pacing
- [ ] M4 — Input (DualSense) + áudio + filesystem
- [ ] M5 — Core rodando homebrew Dreamcast
- [ ] M6 — Frontend v0 listando games/ do HD/SSD
- [ ] M7 — Upscaling 2×–6× + saves/VMU
- [ ] M8 — Experimentos: clock unlock e 120 fps
- [ ] M9 — Matriz de compatibilidade pública + v1.0
