#ifndef _TIMER_H_
#define _TIMER_H_

#include <stdbool.h>
#include <stdint.h>

#define MAX_TIMERS (20)

typedef enum timerModes {
  SINGLE,
  PERIODIC
} timerModes_t;

enum states {
  FREE,
  IDLE,
  RUNNING
};

bool initTimer(void);
uint8_t createTimer(uint32_t time, void (*funcallback)(void), timerModes_t mode);
void setTimerCallback(uint8_t id, void (*funcallback)(void));
void setTimerCurrentTime(uint8_t id, uint32_t time);
void setTimerTime(uint8_t id, uint32_t time);
void setTimerMode(uint8_t id, uint8_t mode);
void destroyTimer(uint8_t id);
void resetTimer(uint8_t id);
void startTimer(uint8_t id);
void stopTimer(uint8_t id);
uint32_t getTime(uint8_t id);
uint32_t getTimerState(uint8_t id);

#endif // _TIMER_H_
