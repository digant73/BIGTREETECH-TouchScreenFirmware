#include "FanControl.h"
#include "includes.h"

#define FAN_REFRESH_TIME 500  // 1 second is 1000

const char * fanID[MAX_FAN_COUNT]  = FAN_DISPLAY_ID;
const char * fanCmd[MAX_FAN_COUNT] = FAN_CMD;

static uint8_t fanTargetSpeed[MAX_FAN_COUNT] = {0};
static uint8_t fanCurrentSpeed[MAX_FAN_COUNT] = {0};
static uint8_t fanNeedingTargetSpeed = 0;

static bool ctrlFanSendingWaiting = false;

void fanResetSpeed(void)
{
  memset(fanTargetSpeed, 0, sizeof(fanTargetSpeed));
  memset(fanCurrentSpeed, 0, sizeof(fanCurrentSpeed));
  fanNeedingTargetSpeed = 0;
}

bool fanIsValid(const uint8_t index)
{
  if (index >= infoSettings.fan_count && index < MAX_COOLING_FAN_COUNT)  // invalid cooling fan index
    return false;
  else if (!infoSettings.ctrl_fan_en && index >= MAX_COOLING_FAN_COUNT)  // controller cooling fan is disabled
    return false;
  else if (index >= (MAX_COOLING_FAN_COUNT + MAX_CTRL_FAN_COUNT))  // invalid controller cooling fan index (not active/idle)
    return false;
  else
    return true;
}

void fanSetTargetSpeed(const uint8_t i, const uint8_t speed)
{
  SET_BIT_VALUE(fanNeedingTargetSpeed, i, fanGetCurrentSpeed(i) != speed);
  fanTargetSpeed[i] = speed;
}

uint8_t fanGetTargetSpeed(const uint8_t i)
{
  return fanTargetSpeed[i];
}

void fanSetTargetPercent(const uint8_t i, const uint8_t percent)
{
  fanSetTargetSpeed(i, (NOBEYOND(0, percent, 100) * infoSettings.fan_max[i]) / 100);
}

uint8_t fanGetTargetPercent(const uint8_t i)
{
  return (fanTargetSpeed[i] * 100.0f) / infoSettings.fan_max[i] + 0.5f;
}

void fanSetCurrentSpeed(const uint8_t i, const uint8_t speed)
{
  fanCurrentSpeed[i] = speed;
}

uint8_t fanGetCurrentSpeed(const uint8_t i)
{
  return fanCurrentSpeed[i];
}

void fanSetCurrentPercent(const uint8_t i, const uint8_t percent)
{
  fanCurrentSpeed[i] = (NOBEYOND(0, percent, 100) * infoSettings.fan_max[i]) / 100;
}

uint8_t fanGetCurrentPercent(const uint8_t i)
{
  return (fanCurrentSpeed[i] * 100.0f) / infoSettings.fan_max[i] + 0.5f;
}

void loopCheckFan(void)
{
  static uint32_t nextUpdateTime = 0;

  if (OS_GetTimeMs() < nextUpdateTime)  // avoid rapid fire, clogging the queue
    return;

  nextUpdateTime = OS_GetTimeMs() + FAN_REFRESH_TIME;  // extend next check time

  for (uint8_t i = 0; i < MAX_FAN_COUNT; i++)
  {
    if (GET_BIT(fanNeedingTargetSpeed, i))
    {
      if (storeCmd(fanCmd[i], fanTargetSpeed[i]))
        SET_BIT_OFF(fanNeedingTargetSpeed, i);
    }
  }
}

void ctrlFanQueryClearSendingWaiting(void)
{
  ctrlFanSendingWaiting = false;
}

void ctrlFanQuery(void)
{ // following conditions ordered by importance
  if (infoSettings.ctrl_fan_en && !ctrlFanSendingWaiting && infoHost.tx_slots != 0 && infoHost.connected)
    ctrlFanSendingWaiting = storeCmd("M710\n");
}
