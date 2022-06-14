#include <stdint.h>

#define SRAM_START 0x20000000U  /* Inicio da SRAM CORTEX-M */
#define SRAM_SIZE (64U * 1024U) /* Tam. SRAM STM32F401 64K */
#define SRAM_END ((SRAM_START) + (SRAM_SIZE)) /* Final da SRAM STM32F411 */
#define STACK_START SRAM_END /* Inicio da Stack */

int main(void);

void reset_handler(void);
void nmi_handler          (void) __attribute__ ((alias("default_handler")));
void hardfault_handler    (void) __attribute__ ((weak, alias("default_handler")));
void memmanage_handler    (void) __attribute__ ((weak, alias("default_handler")));
void busfault_handler     (void) __attribute__ ((weak, alias("default_handler")));
void usagefault_handler   (void) __attribute__ ((weak, alias("default_handler")));
void svc_handler          (void) __attribute__ ((weak, alias("default_handler")));
void debugmon_handler     (void) __attribute__ ((weak, alias("default_handler")));
void pendsv_handler       (void) __attribute__ ((weak, alias("default_handler")));
void systick_handler      (void) __attribute__ ((weak, alias("default_handler")));
void wwdg_handler         (void) __attribute__ ((weak, alias("default_handler")));
void exti16_handler       (void) __attribute__ ((weak, alias("default_handler")));
void exti21_handler       (void) __attribute__ ((weak, alias("default_handler")));
void exti22_handler       (void) __attribute__ ((weak, alias("default_handler")));
void flash_handler        (void) __attribute__ ((weak, alias("default_handler")));
void rcc_handler          (void) __attribute__ ((weak, alias("default_handler")));
void exti0_handler        (void) __attribute__ ((weak, alias("default_handler")));
void exti1_handler        (void) __attribute__ ((weak, alias("default_handler")));
void exti2_handler        (void) __attribute__ ((weak, alias("default_handler")));
void exti3_handler        (void) __attribute__ ((weak, alias("default_handler")));
void exti4_handler        (void) __attribute__ ((weak, alias("default_handler")));
void dma1strm0_handler    (void) __attribute__ ((weak, alias("default_handler")));
void dma1strm1_handler    (void) __attribute__ ((weak, alias("default_handler")));
void dma1strm2_handler    (void) __attribute__ ((weak, alias("default_handler")));
void dma1strm3_handler    (void) __attribute__ ((weak, alias("default_handler")));
void dma1strm4_handler    (void) __attribute__ ((weak, alias("default_handler")));
void dma1strm5_handler    (void) __attribute__ ((weak, alias("default_handler")));
void dma1strm6_handler    (void) __attribute__ ((weak, alias("default_handler")));
void adc_handler          (void) __attribute__ ((weak, alias("default_handler")));
void exti95_handler       (void) __attribute__ ((weak, alias("default_handler")));
void tim1brk9_handler     (void) __attribute__ ((weak, alias("default_handler")));
void tim1up10_handler     (void) __attribute__ ((weak, alias("default_handler")));
void tim1trgcom11_handler (void) __attribute__ ((weak, alias("default_handler")));
void tim1cc_handler       (void) __attribute__ ((weak, alias("default_handler")));
void tim2_handler         (void) __attribute__ ((weak, alias("default_handler")));
void tim3_handler         (void) __attribute__ ((weak, alias("default_handler")));
void tim4_handler         (void) __attribute__ ((weak, alias("default_handler")));
void i2c1ev_handler       (void) __attribute__ ((weak, alias("default_handler")));
void i2c1er_handler       (void) __attribute__ ((weak, alias("default_handler")));
void i2c2ev_handler       (void) __attribute__ ((weak, alias("default_handler")));
void i2c2er_handler       (void) __attribute__ ((weak, alias("default_handler")));
void spi1_handler         (void) __attribute__ ((weak, alias("default_handler")));
void spi2_handler         (void) __attribute__ ((weak, alias("default_handler")));
void usart1_handler       (void) __attribute__ ((weak, alias("default_handler")));
void usart2_handler       (void) __attribute__ ((weak, alias("default_handler")));
void exti510_handler      (void) __attribute__ ((weak, alias("default_handler")));
void exti17_handler       (void) __attribute__ ((weak, alias("default_handler")));
void exti18_handler       (void) __attribute__ ((weak, alias("default_handler")));
void dma1strm7_handler    (void) __attribute__ ((weak, alias("default_handler")));
void stdio_handler        (void) __attribute__ ((weak, alias("default_handler")));
void tim5_handler         (void) __attribute__ ((weak, alias("default_handler")));
void spi3_handler         (void) __attribute__ ((weak, alias("default_handler")));
void dma2strm0_handler    (void) __attribute__ ((weak, alias("default_handler")));
void dma2strm1_handler    (void) __attribute__ ((weak, alias("default_handler")));
void dma2strm2_handler    (void) __attribute__ ((weak, alias("default_handler")));
void dma2strm3_handler    (void) __attribute__ ((weak, alias("default_handler")));
void dma2strm4_handler    (void) __attribute__ ((weak, alias("default_handler")));
void otgfs_handler        (void) __attribute__ ((weak, alias("default_handler")));
void dma2strm5_handler    (void) __attribute__ ((weak, alias("default_handler")));
void dma2strm6_handler    (void) __attribute__ ((weak, alias("default_handler")));
void dma2strm7_handler    (void) __attribute__ ((weak, alias("default_handler")));
void usart6_handler       (void) __attribute__ ((weak, alias("default_handler")));
void i2c3ev_handler       (void) __attribute__ ((weak, alias("default_handler")));
void i2c3er_handler       (void) __attribute__ ((weak, alias("default_handler")));
void fpu                  (void) __attribute__ ((weak, alias("default_handler")));
void spi4                 (void) __attribute__ ((weak, alias("default_handler")));

/* Variaveis exportadas pelo linker script */

extern uint32_t _sdata;     //Início da seção .data
extern uint32_t _edata;     //Fim da seção .data
extern uint32_t _la_data;   //Endereço de carga na RAM da seção .data
extern uint32_t _etext;     //Fim da seção .text
extern uint32_t _sbss;      //Início da seção .bss
extern uint32_t _ebss;      //Fim da seção .bss


uint32_t vectors[] __attribute__((section(".isr_vectors"))) =
{
    STACK_START,                          /* 0x0000 0000 */
    (uint32_t)reset_handler,              /* 0x0000 0004 */
    (uint32_t)nmi_handler,                /* 0x0000 0008 */
    (uint32_t)hardfault_handler,          /* 0x0000 000c */
    (uint32_t)memmanage_handler,          /* 0x0000 0010 */
    (uint32_t)busfault_handler,           /* 0x0000 0014 */
    (uint32_t)usagefault_handler,         /* 0x0000 0018 */
    0,                                    /* 0x0000 001c */
    0,                                    /* 0x0000 0020 */
    0,                                    /* 0x0000 0024 */
    0,                                    /* 0x0000 0028 */
    (uint32_t)svc_handler,                /* 0x0000 002c */
    (uint32_t)debugmon_handler,           /* 0x0000 0030 */
    0,                                    /* 0x0000 0034 */
    (uint32_t)pendsv_handler,             /* 0x0000 0038 */
    (uint32_t)systick_handler,            /* 0x0000 003c */
    (uint32_t) wwdg_handler,              /* 0x0000 0040 */
    (uint32_t) exti16_handler,            /* 0x0000 0044 */
    (uint32_t) exti21_handler,            /* 0x0000 0048 */
    (uint32_t) exti22_handler,            /* 0x0000 004c */
    (uint32_t) flash_handler,             /* 0x0000 0050 */
    (uint32_t) rcc_handler,               /* 0x0000 0054 */
    (uint32_t) exti0_handler,             /* 0x0000 0058 */
    (uint32_t) exti1_handler,             /* 0x0000 005c */
    (uint32_t) exti2_handler,             /* 0x0000 0060 */
    (uint32_t) exti3_handler,             /* 0x0000 0064 */
    (uint32_t) exti4_handler,             /* 0x0000 0068 */
    (uint32_t) dma1strm0_handler,         /* 0x0000 006c */
    (uint32_t) dma1strm1_handler,         /* 0x0000 0070 */
    (uint32_t) dma1strm2_handler,         /* 0x0000 0074 */
    (uint32_t) dma1strm3_handler,         /* 0x0000 0078 */
    (uint32_t) dma1strm4_handler,         /* 0x0000 007c */
    (uint32_t) dma1strm5_handler,         /* 0x0000 0080 */
    (uint32_t) dma1strm6_handler,         /* 0x0000 0084 */
    (uint32_t) adc_handler,               /* 0x0000 0088 */
    (uint32_t) exti95_handler,            /* 0x0000 009c */
    (uint32_t) tim1brk9_handler,          /* 0x0000 00a0 */
    (uint32_t) tim1up10_handler,          /* 0x0000 00a4 */
    (uint32_t) tim1trgcom11_handler,      /* 0x0000 00a8 */
    (uint32_t) tim1cc_handler,            /* 0x0000 00ac */
    (uint32_t) tim2_handler,              /* 0x0000 00b0 */
    (uint32_t) tim3_handler,              /* 0x0000 00b4 */
    (uint32_t) tim4_handler,              /* 0x0000 00b8 */
    (uint32_t) i2c1ev_handler,            /* 0x0000 00bc */
    (uint32_t) i2c1er_handler,            /* 0x0000 00c0 */
    (uint32_t) i2c2ev_handler,            /* 0x0000 00c4 */
    (uint32_t) i2c2er_handler,            /* 0x0000 00c8 */
    (uint32_t) spi1_handler,              /* 0x0000 00cc */
    (uint32_t) spi2_handler,              /* 0x0000 00d0 */
    (uint32_t) usart1_handler,            /* 0x0000 00d4 */
    (uint32_t) usart2_handler,            /* 0x0000 00d8 */
    (uint32_t) exti510_handler,           /* 0x0000 00e0 */
    (uint32_t) exti17_handler,            /* 0x0000 00e4 */
    (uint32_t) exti18_handler,            /* 0x0000 00e8 */
    (uint32_t) dma1strm7_handler,         /* 0x0000 00fc */
    (uint32_t) stdio_handler,             /* 0x0000 0104 */
    (uint32_t) tim5_handler,              /* 0x0000 0108 */
    (uint32_t) spi3_handler,              /* 0x0000 010c */
    (uint32_t) dma2strm0_handler,         /* 0x0000 0120 */
    (uint32_t) dma2strm1_handler,         /* 0x0000 0124 */
    (uint32_t) dma2strm2_handler,         /* 0x0000 0128 */
    (uint32_t) dma2strm3_handler,         /* 0x0000 012c */
    (uint32_t) dma2strm4_handler,         /* 0x0000 0130 */
    (uint32_t) otgfs_handler,             /* 0x0000 014c */
    (uint32_t) dma2strm5_handler,         /* 0x0000 0150 */
    (uint32_t) dma2strm6_handler,         /* 0x0000 0154 */
    (uint32_t) dma2strm7_handler,         /* 0x0000 0158 */
    (uint32_t) usart6_handler,            /* 0x0000 015c */
    (uint32_t) i2c3ev_handler,            /* 0x0000 0160 */
    (uint32_t) i2c3er_handler,            /* 0x0000 0164 */
    (uint32_t) fpu,                       /* 0x0000 0184 */
    (uint32_t) spi4,                      /* 0x0000 0190 */
};

void reset_handler(void)
{
uint32_t i;
/* Copia a secao .data para a RAM */
uint32_t size = (uint32_t)&_edata - (uint32_t)&_sdata;
uint8_t *pDst = (uint8_t*)&_sdata; /* SRAM */
uint8_t *pSrc = (uint8_t*)&_etext; /* FLASH */
for(i = 0; i < size; i++)
{
*pDst++ = *pSrc++;
}
/* Preenche a secao .bss com zero */

size = (uint32_t)&_ebss - (uint32_t)&_sbss;
pDst = (uint8_t*)&_sbss;
for(i = 0 ; i < size; i++)
{
*pDst++ = 0;
}
/* Chama a funcao main() */
main();
}

void default_handler(void)
{
while(1){};
}