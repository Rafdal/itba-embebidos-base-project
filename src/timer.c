#include <src/config.h>
#include <src/gpio/gpio.h>
#include <src/timer.h>
#include "MK64F12.h"
#include "hardware.h"
#include <stdint.h>
#include <sys/types.h>

#define CORECLK (__CORE_CLOCK__)
#define FREQ 1000U // 1 KHz

#define SETA_ADDRS (0x400FF004u)
#define SETA_PTR ((uint32_t *)SETA_ADDRS)
#define SETA_VAL (1 << 1)

#define CLRA_ADDRS (0x400FF008u)
#define CLRA_PTR ((uint32_t *)CLRA_ADDRS)
#define CLRA_VAL (1 << 1)
#define DEBUG_TP_SET *(SETA_PTR) = SETA_VAL
#define DEBUG_TP_CLR *(CLRA_PTR) = CLRA_VAL

typedef struct
{
    uint8_t state;
    uint32_t curr;
    uint32_t time;
    uint8_t mode;
    void (*callback)(void);
} TIMER_t;

static TIMER_t timer[MAX_TIMERS];

bool initTimer()
{
    bool success = false;

    if (SysTick_Config(CORECLK / FREQ) == 0)
    {
        NVIC_EnableIRQ(SysTick_IRQn);
        success = true;
    }

    return true;
}

uint8_t createTimer(uint32_t time, void (*funcallback)(void), timerModes_t mode)
{

    uint8_t i = 0;
    bool found = false;

    while (i < MAX_TIMERS && !found)
    {
        if (timer[i].state == FREE)
        {
            timer[i].mode = mode;
            timer[i].state = IDLE;
            timer[i].time = time;
            timer[i].callback = funcallback;
            resetTimer(i);
            found = true;
        }
        else
        {
            i++;
        }
    }

    return i;
}

void setTimerCallback(uint8_t id, void (*funcallback)(void))
{
    timer[id].callback = funcallback;
}

void setTimerCurrentTime(uint8_t id, uint32_t time)
{
    timer[id].curr = time;
}

void setTimerTime(uint8_t id, uint32_t time)
{
    timer[id].time = time;
}

void setTimerMode(uint8_t id, uint8_t mode)
{
    timer[id].mode = mode;
}

void destroyTimer(uint8_t id)
{
    timer[id].curr = 0;
    timer[id].time = 0;
    timer[id].state = FREE;
}

void resetTimer(uint8_t id)
{
    timer[id].curr = timer[id].time; // Reload the timer
}

void startTimer(uint8_t id)
{
    resetTimer(id);
    if (timer[id].state != FREE)
        timer[id].state = RUNNING;
}

void stopTimer(uint8_t id)
{
    if (timer[id].state != FREE)
        timer[id].state = IDLE;
    resetTimer(id);
}

uint32_t getTime(uint8_t id)
{
    return timer[id].curr;
}

uint32_t getTimerState(uint8_t id)
{
    return timer[id].state;
}

void SysTick_Handler(void)
{

    DEBUG_TP_SET;

    for (int i = 0; i < MAX_TIMERS; i++)
    {
        if (timer[i].state == RUNNING)
        {
            if (timer[i].curr > 0)
                timer[i].curr--;
            else
            {
                timer[i].callback();
                resetTimer(i);
                if (timer[i].mode == SINGLE)
                {
                    stopTimer(i);
                }
            }
        }
    }

    NVIC_ClearPendingIRQ(SysTick_IRQn);
    DEBUG_TP_CLR;
}
