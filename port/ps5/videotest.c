#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int sceVideoOutOpen(int, int, int, const void *);
int sceVideoOutClose(int);
int sceVideoOutSetBufferAttribute2(void *, uint64_t, int, uint32_t, uint32_t, uint32_t, uint32_t, uint64_t);
int sceVideoOutRegisterBuffers2(int, int, int, void **, int, const void *, int, const void *);
int sceVideoOutSubmitFlip(int, int, int, long long);
int sceVideoOutSetFlipRate(int, int);
int sceKernelAllocateMainDirectMemory(size_t, size_t, int, intptr_t *);
int sceKernelMapDirectMemory(void **, size_t, int, int, intptr_t, size_t);
int sceKernelReleaseDirectMemory(intptr_t, size_t);
int sceSystemServiceHideSplashScreen(void);

int main(void) {
    printf("Dreamcast PS5: videotest M3 iniciado\n");
    sceSystemServiceHideSplashScreen();

    int h = sceVideoOutOpen(0xFF, 0, 0, 0);
    if (h < 0) { printf("erro: VideoOutOpen\n"); return 1; }

    const int W = 1920, H = 1080;
    const int TW = 512, TH = 128, TSZ = TW * TH;
    int tw = (W + TW - 1) / TW, th = (H + TH - 1) / TH;
    size_t bppix = (size_t)tw * th * TSZ;
    size_t one = ((bppix * 4 + 0x20000 - 1) / 0x20000) * 0x20000;
    size_t total = one * 2;

    intptr_t pa = 0;
    if (sceKernelAllocateMainDirectMemory(total, 0x20000, 3, &pa)) { printf("erro: alloc mem\n"); return 2; }
    void *va = 0;
    if (sceKernelMapDirectMemory(&va, total, 0x33, 0, pa, 0x20000)) { printf("erro: map mem\n"); return 3; }

    void *bufs[2] = { va, (char *)va + one };
    memset(va, 0, total);

    char attr[256];
    memset(attr, 0, sizeof attr);
    sceVideoOutSetBufferAttribute2(attr, 0x8000000022000000ULL, 0, W, H, 0, 0, 0);
    if (sceVideoOutRegisterBuffers2(h, 0, 0, bufs, 2, attr, 0, 0)) { printf("erro: RegisterBuffers2\n"); return 4; }
    sceVideoOutSetFlipRate(h, 0);

    uint32_t cores[4] = { 0xFF0000FF, 0xFF00FF00, 0xFFFF0000, 0xFFFFFFFF };
    int ativo = 0;
    long long fid = 0;
    for (int rep = 0; rep < 3; rep++) {
        for (int c = 0; c < 4; c++) {
            uint32_t *fb = (uint32_t *)bufs[ativo];
            for (size_t i = 0; i < bppix; i++) fb[i] = cores[c];
            sceVideoOutSubmitFlip(h, ativo, 1, fid++);
            sleep(1);
            ativo ^= 1;
        }
    }

    sceVideoOutClose(h);
    sceKernelReleaseDirectMemory(pa, total);
    printf("Dreamcast PS5: videotest M3 concluido\n");
    return 0;
}
