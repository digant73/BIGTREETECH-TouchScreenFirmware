#ifndef _MAINBOARD_CMD_HANDLER_H_
#define _MAINBOARD_CMD_HANDLER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>
#include "SerialConnection.h"

#define CMD_QUEUE_SIZE 20
#define CMD_MAX_SIZE   100  // including ending character '\0'

#define handleCmd(...)               _handleCmd(__VA_ARGS__, PORT_1)
#define _handleCmd(a, b, ...)        handleCmd(a, b)
#define sendEmergencyCmd(...)        _sendEmergencyCmd(__VA_ARGS__, PORT_1)
#define _sendEmergencyCmd(a, b, ...) sendEmergencyCmd(a, b)

typedef char CMD[CMD_MAX_SIZE];

bool isPendingCmd(void);         // if no pending gcode
bool isIdleCmd(void);            // if no pending gcode and empty command queue
uint8_t getQueueCount(void);     // used by Monitoring menu (available only if DEBUG_MONITORING is enabled in Configuration.h)
bool isFullCmdQueue(void);
bool isNotEmptyCmdQueue(void);   // if not empty command queue or no available gcode tx slot
bool isEnqueued(const CMD cmd);  // if gcode is already enqueued on command queue
bool isWritingMode(void);

bool storeCmd(const char * format, ...);
void mustStoreCmd(const char * format, ...);
void mustStoreScript(const char * format, ...);
bool storeCmdFromUART(const CMD cmd, const SERIAL_PORT_INDEX portIndex);
void clearCmdQueue(void);
void handleCmdLineNumberMismatch(const uint32_t lineNumber);
void handleCmd(CMD cmd, const SERIAL_PORT_INDEX portIndex);
void sendEmergencyCmd(const CMD emergencyCmd, const SERIAL_PORT_INDEX portIndex);
void sendQueueCmd(void);

#ifdef __cplusplus
}
#endif

#endif
