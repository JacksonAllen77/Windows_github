#ifndef _ENCODER_H
#define _ENCODER_H

void Enconder_Init(void);
void EXTI0_IRQHandler(void);
void EXTI1_IRQHandler(void);
int16_t Encoder_Get(void);

#endif
