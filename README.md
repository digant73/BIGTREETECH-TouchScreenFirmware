# Artillery Sidewinder X1 / X2 / Genius TFT FW + Marlin FW (for X1) + M600 support + Marlin mode (optional)

A porting of BIGTREETECH TFT firmware on MKS TFT28 used on Artillery Sidewinder X1, X2 and Genius printers.
This porting is based on lastest release of BIGTREETECH TFT firmware found on https://github.com/bigtreetech/BIGTREETECH-TouchScreenFirmware/tree/master.
It was arranged according to Artillery Sidewinder X1 / X2 / Genius hardware.
Furthermore, bug fixes, rearrangement of menus, improvements and additions were applied.
If you like it or if you want to contribute to further improvements on that firmware, please consider the possibility to donate to:

**paypal.me: adigant**

Thanks!

**NOTE:** Any addition and change in this code is regularly submitted to official BTT repo for integration in the official BTT firmware.

## Table of Contents

1. [Useful Links for Printer Calibration and Tuning](#Useful-Links-for-Printer-Calibration-and-Tuning)
2. [Firmware Variants](#Firmware-Variants)
   - [TFT Firmware Variants](#TFT-Firmware-Variants)
     - [TFT Firmware Source Code Links](#TFT-Firmware-Source-Code-Links)
   - [Marlin Firmware Variants](#Marlin-Firmware-Variants)
     - [Marlin Firmware Source Code Links](#Marlin-Firmware-Source-Code-Links)
     - [BLTouch Support and Probe Offset Setup](#BLTouch-Support-and-Probe-Offset-Setup)
3. [Firmware Compatibility](#Firmware-Compatibility)
   - [TFT Firmware Compatibility](#TFT-Firmware-Compatibility)
     - [TFT Firmware for Genius](#TFT-Firmware-for-Genius)
     - [Marlin Firmware Dependencies](#Marlin-Firmware-Dependencies)
   - [Marlin Firmware Compatibility](#Marlin-Firmware-Compatibility)
     - [Marlin Firmware for Genius](#Marlin-Firmware-for-Genius)
4. [Integration with OctoPrint](#Integration-with-OctoPrint)
   - [Printing from Remote Host](#Printing-from-Remote-Host)
5. [Firmware Update](#Firmware-Update)
   - [TFT Firmware Update](#TFT-Firmware-Update)
     - [TFT Firmware Installation](#TFT-Firmware-Installation)
     - [TFT Firmware Configuration](#TFT-Firmware-Configuration)
     - [TFT Firmware Reset - Recalibration](#TFT-Firmware-Reset---Recalibration)
     - [TFT Firmware Not Attached](#TFT-Firmware-Not-Attached)
     - [TFT Firmware Rollback](#TFT-Firmware-Rollback)
   - [Marlin Firmware Update](#Marlin-Firmware-Update)
     - [Marlin Firmware Installation](#Marlin-Firmware-Installation)
     - [Marlin Firmware Configuration](#Marlin-Firmware-Configuration)
6. [History of Changes](#History-of-Changes)
   - [TFT Firmware Changes](#TFT-Firmware-Changes)
   - [Marlin Firmware Changes](#Marlin-Firmware-Changes)
7. [List of Main Features](#List-of-Main-Features)
   - [TFT Firmware Main Features](#TFT-Firmware-Main-Features)
   - [Marlin Firmware Main Features](#Marlin-Firmware-Main-Features)
   - [Simplify3D Profile Features](#Simplify3D-Profile-Features)

<a name="Useful-Links-for-Printer-Calibration-and-Tuning"></a>

### Useful Links for Printer Calibration and Tuning

- https://3dprintbeginner.com/artillery-sidewinder-x1-calibration-guide/
- https://3dprintbeginner.com/sidewinder-x1-firmware/
- https://3dprintbeginner.com/sidewinder-x1-auto-bed-leveling-stock-sensor/

<a name="Firmware-Variants"></a>

## Firmware Variants

<a name="TFT-Firmware-Variants"></a>

### TFT Firmware Variants

<a name="TFT-Firmware-Source-Code-Links"></a>

#### TFT Firmware Source Code Links

- https://github.com/digant73/BIGTREETECH-TouchScreenFirmware/releases

<a name="Marlin-Firmware-Variants"></a>

### Marlin Firmware Variants

Four different Marlin fw variants are available:

- **Standard**: Standard version (no BLTouch, no bed leveling support)
- **MBL**: Standard version + MBL suppport (Manual Mesh Bed Leveling)
- **BLTouch Waggster Mod**: It supports BLTouch connected to LED cable (Waggster method). LED on printer is no more available
- **BLTouch Standard**: It supports BLTouch connected to Marlin mainboard. LED on printer is still available and usable. See pictures for cabling and connection guide in the zip file provided in the download page. I used an FDD cable and crimped the connectors by myself. However, it is suggested (it requires less time) to use the 2 meters (1.5 meters is too short) optional cable sold for BLTouch

<a name="Marlin-Firmware-Source-Code-Links"></a>

#### Marlin Firmware Source Code Links

- https://github.com/digant73/Marlin/releases

<a name="BLTouch-Support-and-Probe-Offset-Setup"></a>

#### BLTouch Support and Probe Offset Setup

Both the **BLTouch Standard** and **BLTouch Waggster Mod** fw variants are configured for the BLTouch support linked in the download page requiring probe offset `{28, -33, 0}`. In case a different support is used by the user, it is simply needed to change and save to EEPROM the value for the **Probe Offset** setting listed on TFT menu **Menu->Settings->Machine->Parameter**.

The download page provides two BLTouch supports requiring the following probe offset:

- `{28, -33, 0}`: New support used since Marlin fw 2.0.9.2
- `{33, -33, 0}`: Old support used until Marlin fw 2.0.9.1

<a name="Firmware-Compatibility"></a>

## Firmware Compatibility

<a name="TFT-Firmware-Compatibility"></a>

### TFT Firmware Compatibility

The TFT fw is ready to be flashed on both Sidewinder X1 / X2 and Genius printers. So, no need to recompile the TFT fw is required. Only one change in configuration file is required for Genius (e.g. print volume).

**NOTE:** Latest Sidewinder X2 are equipped with a TFT based on GD32F305 chipset. The TFT fw provided here is **NOT** compatible with that chipset yet.

<a name="TFT-Firmware-for-Genius"></a>

#### TFT Firmware for Genius

To use the TFT fw on Genius:

1. Set the following parameter in TFT's configuration file `config.ini` with the build volume of the Genius:

   - `size_max:X220 Y220 Z250`

2. Load on TFT the updated configuration file `config.ini`

<a name="Marlin-Firmware-Dependencies"></a>

#### Marlin Firmware Dependencies

Minimum Marlin firmware version: **2.1.1**<br>
Distribution date: **2022-09-22**<br>
Firmware source: https://github.com/MarlinFirmware/Marlin/releases<br>

To use all the features and functionalities supported by the TFT,
the following options must be enabled in Marlin firmware.

**General options which MUST be always activated:**

`EEPROM_SETTINGS` (in Configuration.h)<br>
`BABYSTEPPING` (in Configuration_adv.h)<br>
`AUTO_REPORT_TEMPERATURES` (in Configuration_adv.h)<br>
`AUTO_REPORT_POSITION` (in Configuration_adv.h)<br>
`EXTENDED_CAPABILITIES_REPORT` (in Configuration_adv.h)<br>
`M115_GEOMETRY_REPORT` (in Configuration_adv.h)<br>
`M114_DETAIL` (in Configuration_adv.h)<br>
`REPORT_FAN_CHANGE` (in Configuration_adv.h)<br>

**Options to support printing from onboard media:**

`SDSUPPORT` (in Configuration.h)<br>
`LONG_FILENAME_HOST_SUPPORT` (in Configuration_adv.h)<br>
`AUTO_REPORT_SD_STATUS` (in Configuration_adv.h)<br>
`SDCARD_CONNECTION ONBOARD` (in Configuration_adv.h)<br>

**Options to support dialog with host:**

`EMERGENCY_PARSER` (in Configuration_adv.h)<br>
`SERIAL_FLOAT_PRECISION 4` (in Configuration_adv.h)<br>
`HOST_ACTION_COMMANDS` (in Configuration_adv.h)<br>
`HOST_PROMPT_SUPPORT` (in Configuration_adv.h)<br>
`HOST_STATUS_NOTIFICATIONS` (in Configuration_adv.h)<br>

**Options to support M73 with host:**

`Options to support dialog with host` (as pre requisite)<br>
`SET_PROGRESS_MANUALLY` (in Configuration_adv.h)<br>
`M73_REPORT` (in Configuration_adv.h)<br>

**Options to support ADVANCED_OK with host:**

`ADVANCED_OK` (in Configuration_adv.h)<br>

**Options to support M600 with host & (Un)Load menu:**

`Options to support dialog with host` (as pre requisite)<br>
`NOZZLE_PARK_FEATURE` (in Configuration.h)<br>
`ADVANCED_PAUSE_FEATURE` (in Configuration_adv.h)<br>
`PARK_HEAD_ON_PAUSE` (in Configuration_adv.h)<br>
`FILAMENT_LOAD_UNLOAD_GCODES` (in Configuration_adv.h)<br>

**Options to fully support Bed Leveling menu:**

`Z_MIN_PROBE_REPEATABILITY_TEST` (in Configuration.h)<br>
`G26_MESH_VALIDATION` (in Configuration.h)<br>
`Z_STEPPER_AUTO_ALIGN` (in Configuration_adv.h)<br>

<a name="Marlin-Firmware-Compatibility"></a>

### Marlin Firmware Compatibility

All the 4 Marlin fw variants reported on section [Marlin Firmware Variants](#Marlin-Firmware-Variants) are ready to be flashed on Sidewinder X1 printer. Small changes are required for Genius (e.g. print volume). While Sidewinder X2 has a totally different mainboard and it's not compatible at all with the Marlin fw provided here.

<a name="Marlin-Firmware-for-Genius"></a>

#### Marlin Firmware for Genius

The 4 Marlin fw variants can be easily adapted to Genius printer but it needs to recompile the fw (e.g. with MS vscode).

To use the Marlin fw on Genius:

1. Install **MS Visual Studio Code** compiler on your PC / laptop
2. Install the extension **PlatformIO IDE 2.3.2** or above on vscode
3. Open the fw source project reported on section [Marlin Firmware](#Marlin-Firmware) with vscode:

   1. Set the following settings in source file `Marlin-2.0.x\Marlin\Configuration.h` with the build volume of the Genius:

      - `X_BED_SIZE 220`
      - `Y_BED_SIZE 220`
      - `Z_MAX_POS 250`

   2. Recompile the fw (to compile, simply press the keys `CTRL-ALT-B` at the same time)

4. Flash on the printer the created fw file `Marlin-2.0.x\.pio\build\mega2560\firmware.hex`

<a name="Integration-with-OctoPrint"></a>

## Integration with OctoPrint

The serial bus with the mainboard **MKS GEN L v1.0** is shared between TFT and OctoPrint / ESP3D / Pronterface etc. This means that printing from OctoPrint causes Marlin to receive gcodes from OctoPrint and TFT at the same time (there are collisions). This will let Marlin reply with error messages, that will be displayed on both OctoPrint and TFT display, such as:

    Line Number is Not Last Line Number +1 Last Line 1686

In order to avoid the problem, when printing with OctoPrint etc. put the TFT in **Listening Mode** pressing on TFT button **Menu->Settings->Connection->ON**.

**NOTES:**

- This limitation is not due to bugs on the TFT firmware but it's an hardware limitation on MKS GEN L v1.0 mainboard
- Listening Mode state is stored on FLASH allowing to restore the mode at TFT startup. This allows to power on/off the printer remotely and to control the printer via USB without the need of any touch (from the user) on the display to engage the mode

<a name="Printing-from-Remote-Host"></a>

### Printing from Remote Host

After the TFT is set to Listening Mode (see section [Integration with OctoPrint](#Integration-with-OctoPrint)),
OctoPrint, ESP3D, Pronterface etc, connected to a TFT's or mainboard's serial port, can host a print (print handled by the host) and optionally can trigger some actions to the TFT sending specific G-codes. The following actions and the related triggering G-codes are currently supported by the TFT fw:

| **ACTION**                  | **G-CODE**                                                                                                                                                                                                  |
| :-------------------------- | :---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **start**                   | `M118 P0 A1 action:print_start`                                                                                                                                                                             |
| **end**                     | `M118 P0 A1 action:print_end`                                                                                                                                                                               |
| **cancel**                  | `M118 P0 A1 action:cancel`                                                                                                                                                                                  |
| **pause**                   | `M118 P0 A1 action:pause`                                                                                                                                                                                   |
| **resume**                  | `M118 P0 A1 action:resume`                                                                                                                                                                                  |
| **remaining time progress** | `M118 P0 A1 action:notification Time Left <XX>h<YY>m<ZZ>s`<br>or<br>`M117 Time Left <XX>h<YY>m<ZZ>s`<br><br>Examples:<br>`M118 P0 A1 action:notification Time Left 02h04m06s`<br>`M117 Time Left 02h04m06s` |
| **print layer progress**    | `M118 P0 A1 action:notification Layer Left <XXXX>/<YYYY>`<br>or<br>`M117 Layer Left <XXXX>/<YYYY>`<br><br>Examples:<br>`M118 P0 A1 action:notification Layer Left 51/940`<br>`M117 Layer Left 51/940`       |
| **file data progress**      | `M118 P0 A1 action:notification Data Left <XXXX>/<YYYY>`<br>or<br>`M117 Data Left <XXXX>/<YYYY>`<br><br>Examples:<br>`M118 P0 A1 action:notification Data Left 123/12345`<br>`M117 Data Left 123/12345`     |

When the trigger `print_start` is received, the TFT switches to **Printing** menu.
When the trigger `print_end` or `cancel` is received, the TFT Printing menu is finalized (statistics available etc.).
When on Printing menu, pressing on the **pause**, **resume** and **stop** buttons will trigger to the remote host the following notifications, respectively:

| **NOTIFICATION**            | **ACK MESSAGE**                       |
| :-------------------------- | :------------------------------------ |
| **pause**                   | `//action:notification remote pause`  |
| **resume**                  | `//action:notification remote resume` |
| **cancel**                  | `//action:notification remote cancel` |

The remote host must properly handle the received notifications. For example, if `//action:notification remote pause` is received then the remote host must effectively pause the print and send `M118 P0 A1 action:pause` in order to trigger the pause action to the TFT.

**NOTES:**
- A new plugin on OctoPrint implementing the above protocol should be the preferable way (available to everyone)

<a name="Firmware-Update"></a>

## Firmware Update

<a name="TFT-Firmware-Update"></a>

### TFT Firmware Update

<a name="TFT-Firmware-Installation"></a>

#### TFT Firmware Installation

In order to install the TFT firmware:

1. Download the firmware
2. Unzip the archive and copy the contents to the SD Card. The folder `TFT28` and file `MKSTFT28.bin` must be on the root folder of the SD card
3. Plug in the SD card into the printer
4. Turn on the printer and wait for the firmware to finish flashing
5. In case calibration procedure is started, touch the calibration points on the screen
6. Restart the printer
7. Proceed with the configuration as reported on section [TFT Firmware Configuration](#TFT-Firmware-Configuration)

**IMPORTANT NOTE:**
Always install all the content provided in the zip file. That means, copy in the SD card the `.bin` + `config.ini` + `TFT28` folder with its files.
In addition (optional) also the desired `language_xx.ini` file can be provided in the root folder of the SD card. All the language files are found in the `Language_Packs` folder.

<a name="TFT-Firmware-Configuration"></a>

#### TFT Firmware Configuration

To update the TFT firmware configuration:

1. Edit the settings in `config.ini`. See the comments on the file to properly set each setting
2. Copy the `config.ini` file to the root folder of the SD card. (The SD card capacity should be less than or equal to 8GB and formatted as FAT32)
3. Insert the SD card in the TFT's SD card slot and restart the TFT by pressing the reset button (if you have a Sidewinder X1 v4 or above printer revision) or switching off and on the printer
4. The TFT will load the configuration from `config.ini` file and store it on internal SPI flash. That means the configuration will be loaded from SPI flash on all the next printer reboots (no need to provide the configuration file on the SD card unless you make changes on `config.ini` file and want to load the new configuration)

<a name="TFT-Firmware-Reset---Recalibration"></a>

#### TFT Firmware Reset - Recalibration

Sometimes, after a TFT firmware installation, the firmware can need a reset / recalibration in order to properly boot up.

In order to reset / recalibrate the TFT:

1. Create an empty file named `reset.txt`
2. Copy the `reset.txt` file to the root folder of the SD card. (The SD card capacity should be less than or equal to 8GB and formatted as FAT32)
3. Insert the SD card in the TFT's SD card slot and restart the TFT by pressing the reset button (if you have a Sidewinder X1 v4 or above printer revision) or switching off and on the printer
4. The TFT will start the recalibration process. Simply follow and complete the process. After completion, the TFT firmware should be properly booted up

<a name="TFT-Firmware-Not-Attached"></a>

#### TFT Firmware Not Attached

If the text:

    No printer attached!

is displayed on top of the display it means you need to change the value for the **UART speed** setting. By default it is set to **250000**. Change it from TFT menu **Menu->Settings->Connection->S. Ports**, wait few seconds in order to check that with the selected UART speed the error message disappears. Once the message disappears it means that the TFT firmware is now connected to the printer and you can use it.

<a name="TFT-Firmware-Rollback"></a>

#### TFT Firmware Rollback

In case you have issues with this custom firmware or you don't like it, you can rollback to the firmware previously installed in your printer.

In order to rollback:

1. Download the stock Artillery TFT firmware (from https://artillery3d.com) or any other custom TFT firmware you had previously installed in your printer
2. Unzip the archive and copy the contents to the SD Card. The contents must be on the root folder of the SD card
3. Plug in the SD card into the printer
4. Turn on the printer and wait for the firmware to finish flashing
5. Restart the printer

<a name="Marlin-Firmware-Update"></a>

### Marlin Firmware Update

<a name="Marlin-Firmware-Installation"></a>

#### Marlin Firmware Installation

On Sidewinder X1 and Genius printers, the mainboard's USB port used to connect the printer to a PC (e.g. to OctoPrint) is wired to a serial bus. This bus is also shared by both TFT and mainboard. The sharing of the serial bus does not allow to easily flash Marlin firmware due to collisions in the bus.

Two possible solutions were normally adopted to allow Marlin firmware updates:

1. Physical disconnection of the TFT serial cable so the serial bus is no more shared with the TFT. This solution requires to remove the cover under the chassis and possibly to loose any warrenty
2. Use a script under Linux OS trying to lock the serial bus to the TFT

This TFT firmware provides a third, and easy to use, solution for flashing Marlin firmware.

In order to flash Marlin firmware, follow the steps below in the same order they are reported:

1. Switch on the printer from the main power button (on the back of the printer)
2. From the TFT, press on button **Menu->Settings->Connection->Disconnect**. A black background with a text asking to touch the screen to connect again the TFT is prompted. **DO NOT** press on the display, so the TFT will continue to be disconnected from the serial bus
3. From the PC, open the application you usually use for flashing Marlin firmware (e.g. PrusaSlicer)
4. Plug a USB cable from the PC to the mainboard's USB port and connect the application to the printer
5. Follow the instructions provided by your application to flash Marlin firmware
6. Once Marlin firmware is flashed, disconnect the application from the printer and restart the printer (switching off and on or pressing on the TFT's reset button if you have a Sidewinder X1 v4)

<a name="Marlin-Firmware-Configuration"></a>

#### Marlin Firmware Configuration

After a new Marlin firmware is installed (see section [Marlin Firmware Installation](#Marlin-Firmware-Installation)), EEPROM must always be reset and the following setups have to be performed again and saved to EEPROM after completion:

1. Reset EEPROM, from **Menu->Settings->Machine->EEPROM->Reset** button
2. Perform **PID** process, from **Menu->Settings->Machine->Tuning->PID** menu
3. Perform **Probe Offset** process (only for BLTouch Marlin firmware versions), from **Menu->Movement->Bed Level->P Offset** menu
4. Perform **Bed Leveling** process, from **Menu->Movement->Bed Level->UBL** (or MBL) menu
5. Save to EEPROM, from **Menu->Settings->Machine->EEPROM->Save** button

<a name="History-of-Changes"></a>

## History of Changes

<a name="TFT-Firmware-Changes"></a>

### TFT Firmware Changes

- 1.27.x Patch 10, January 14 2024

  **IMPROVEMENTS:**
  - Event driven sounds, no polling (made by user @rondln on TFT official repo)
  - Added TX Interrupt/DMA based serial writing
  - Improved RX serial reading: the TFT is now able to manage contiguous (not separated by IDLE on serial line) and very long ACK messages (e.g. M43 output) from mainboard without any loss
  - Added priorities to back end and front end tasks to speed up more critical tasks (e.g. printing)
  - Extended baudrates range for serial ports. Values range for param serial_port in config.ini has been extended providing other standard baudrates such as 230400 and 921600 (e.g. supported by ESP3D)
  - Added advanced_ok setting on config.ini file to allow Marlin ADVANCED_OK and static (TFT based) ADVANCED_OK support
  - Added Monitoring menu: Available in Notification menu (pressing on Info button)
  - Minor code cleanup/optimization

  **BUGFIXES:**
  - Fixed Random pauses or hesitation when printing
  - Improved partial message retrieval handling
  - Many other bugfixes

- 1.27.x Patch 9.5, May 16 2023

  **BUG FIXES:**
  - Minor bug fixes

- 1.27.x Patch 9.4, May 14 2023

  **BUG FIXES:**
  - Some bug fixes

- 1.27.x Patch 9.3, January 12 2023

- 1.27.x Patch 9.2, August 10 2022

- 1.27.x Patch 9.1, May 23 2022

  **BUG FIXES:**
  - Fixed missing display of probe values in LevelCorner menu when start button was used: In case the start button was used, only the value for the last point was properly displayed (for the first three points, values were not updated)

- 1.27.x Patch 9, May 09 2022

  **BUG FIXES:**
  - Fixed bug on wrong filament runout detection at print start
  - Fixed many other bugs

  **IMPROVEMENTS / NEW FEATURES:**
  - Improved GUI performance
  - Improved many other features
  - Some cleanup

- 1.27.x Patch 8, January 04 2022
  - Added Event LED feature: A new param "event_led" was added in "config.ini" (and also available on Feature menu) to enable Event LED feature. If enabled and when printing from TFT SD / TFT U Disk, during heating the TFT periodically sets the printer's (neopixel) LED color and TFT's knob LED color, if any, according to the current nozzle and bed temperatures.
  - Configurable suppression (hide) for common gcode file extension: new param "filename_extension" added in config.ini. If set to 0 (false), any file extension starting with ".g" or ".G" (e.g. ".g", ".gco", ".gcode" etc.) will be hidden in both List Mode / Icon Mode menu. That setting can also be changed from Screen->UI menu
  - Fixed incorrect sort order of files on USB/SD: The order of files shown on the display does not match the "Newest First" file order.
  - Fixed missing thumbnails while browsing icon list
  - Minor bug fixes and optimization

- 1.27.x Patch 7, November 25 2021
  - Fixed bugs on navigation menu in Print menu: ListMode was affected by a twice redrawn scrolling up/down. Title bar was also wrongly updated causing an avoidable flickering and lost of Temperature info (if enabled) on both icon/list mode
  - Fixed type for param "pl_recovery_z_raise" in config.ini. It was wrongly defined as integer type while it was then used as float type
  - Fixed TFT freeze due to permanent read/write error printing from SD slot: functions disk_read / disk_write in diskio.c performed a loop invoking SD_Init function. The loop was never terminated in case of a persistent error
  - Fixed MinX/MinY Leveling Distance: The origin of the bed is never less than 0. A negative minX/minY indicates the distance of the bed from endstops and must not be considered to determine the four leveling edges in Manual Leveling menu and Leveling Corner menu
  - Other fixes
  - Updated clock for MKS TFT: MKS TFT (based on STM32F10X_CL) supports 72MHz (as all the others TFT based on STM32F10X). Previous clock for MKS TFT was 48MHz
  - Update corner/manual levelling icons (by BTT)
  - Update ASCII font for TFT24/28 to be slightly taller and easy to read (by BTT)
  - Configurable Gcode file comment parsing feature: This previously hidden feature can now be enabled/disabled in config.ini (with param name "file_comment_parsing") and also in Feature menu. This gives visibility/control of the feature so it can be used according to the used slicer (e.g. Cura) and/or user preference.
    If enabled, the current implementation parses and processes print time and print layer information from the G-code file (nothing else).
    If disabled, the "layer_disp_type" setting provided in "UI Settings" section in config.ini becomes redundant.
  - Optimized loopPrintFromTFT function in Printing.c API: The parsing of each line in the gcode file is now split in order to speed up both the gcode parsing and the comment (if any) parsing
  - Added error handling and error notification in loopPrintFromTFT function in Printing.c API: The error handling function handleDiskError currently implemented forces a device re-initialization for a maximum number of retry attempts. If maximum number of retry is reached a print abort is forced. Previously, in case of error the file position (infoPrinting.cur) was never updated causing an infinite print loop (the print could never reach the end due to a permanent error reading from file)
  - Unified name for Controller Fan Active: Id for Active PWD in config.ini (CtL) was not matching the Id displayed in the menus (CtS) and its meaning (Active). The name was unified to CtA on both config.ini and menus
  - Implemented OctoPrint support
  - Some cleanup

- 1.27.x Patch 6, October 26 2021
  - Fixed (by BTT) a bug on Numpad menu causing wrong menu redraw on exit.

- 1.27.x Patch 5, September 23 2021
  - Added TFT Listening Mode: The TFT simply listen for ACK messages (e.g. spontaneous) while all the outgoing messages are purged.
    This mode is useful on main boards sharing the bus with TFT and USB (e.g. MKS GEN L) allowing OctoPrint/Pronterface to properly control the printer (via USB) avoiding command collisions (otherwise present with TFT in normal mode).
    The TFT will receive the ACK messages (spontaneous and/or related to gcodes from USB port) displaying on the screen all the status info.
    The mode can be activated/deactivated on "Connection" menu. Existing labels (ON/OFF) and icon have been used to avoid to add new ones
  - Fixed a freeze on Terminal menu caused by some texts

  **NOTE:** The mode state is stored on FLASH allowing to restore the mode at startup. This allows to power on/off the printer remotely and to control the printer via USB without the need of any touch (from the user) on the display to engage the mode

- 1.27.x Patch 4, September 9 2021
  - Configurable serial ports:
  - Added new param "serial_port" (it replaces "multi_serials") in config.ini allowing to set also the baudrate for each port. Each port can be configured with the proper baudrate (e.g. 125000 for Marlin, 500000 for ESP etc.)
  - Added "S ports" menu under "Connection" menu allowing to set each port at runtime. It allows to disable/change baudrate for each port when needed (e.g. when a device is plugged in the serial port)
  - Configurable feature "Emulated M109 / M190": New param "emulated_m109_m190" added in config.ini to enable/disable M109/M190 emulated with M104/M140. Set "emulated_m109_m190" to "0" to use M109/M190 and EVENT_LEDS
  - Added feature "Emulated M109 / M190" in Feature menu allowing to switch to M109/M190 <-> M104/M140 at runtime (no need to use config.ini)
  - Fixed bug on Level Corner menu
  - Optimized code to speedup processing performance
  - Fixed minor bugs

- 1.27.x Patch 3, July 23 2021
  - Fixed filament runout bug. An error message was previously displayed starting a print and then the filament runout was not working
  - Fixed minor bugs

- 1.27.x Patch 2, July 05 2021
  - Added touch buttons on Printing menu for heat, fan, time etc. menus
  - Fixed different bugs

- 1.27.x Patch 1, June 02 2021
  - Added M73 and M117 support for remaining print time (features provided by Prusa and Cura slicers). Both the elapsed and remaining time (if present in the gcode file) are displayed in the Printing menu
  - Added marked progress bar layout displaying also 10% progress markers
  - Fixed some freeze conditions in LoadUnload and Extrude menus

- 1.27.x, May 17 2021
  - A lot of work was done (bug fixes and new features) to release the first stable and complete TFT fw. Finally the 1.27.x version is available:
  - Official first stable version 1.27.x
  - Add file sorting option for TFT SD card and USB drive
  - Load/Unload/Extrude/Retract rework and bugfixes
  - Improved robustness of Printing menu during a dialog with Marlin
  - Fixed bug on Marlin not allowing M600 in case no LCD enabled and prompt support enabled
  - Fix PLR bug
  - Clean-up parameter settings and display only axis/stepper supported by the machine
  - Display of M117 messages on the notification screen. With the option to turn this view on or off in the CONFIG.INI file
  - Added custom LED menu
  - many other

- 1.0.26.1 Patch 9, February 04 2021
  - Improved Terminal menu. Added toggle button to temporary enable/disable ACK messages. In order to make the change permanent, change the related setting (terminal ACK) from Feature menu
  - Added other parameters from config.ini in Features menu. This allows to change them without the need to apply the changes in config.ini and load it in the TFT. A simply reset of the TFT is suggested (changes on some settings could not be applied at run time)
  - Fixed some bugs on MBL, Mesh Editor
  - Added Home menu, Not needed on stock Artillery SX1/Genius. It was requested on BTT main repo by users with other printers. I simply provided it
  - Many other fixes and improvements done by me and BTT

- 1.0.26.1 Patch 8.8, December 05 2020
  - Fixed bug "flow/speed reset to 10% during a print". Now even in case you still continue to get an error message on screen, the flow/speed is no more reset to 10%
  - Fixed bug "false filament runout detection". Now the bug, often present at the beginning of the print, should be fixed. This should also allow to reduce the value for "fil_noise_threshold" in config.ini to lower values (e.g. 100ms)
  - Added new filament (un)load menu. It needs M701, M702 enabled on Marlin fw
  - Minor fixes

- 1.0.26.1 Patch 8.7, November 14 2020
  - Improved Terminal menu
  - Minor improvement in Mesh Editor

- 1.0.26.1 Patch 8.6, October 31 2020
  - Improved Mesh Editor
  - Added languages pack. By default only english language is present in the fw. All the other desired languages can be loaded simply providing their .ini file in the root directory during the fw update. The language to use in the fw is then selectable form the usual Screen->Language menu
  - Fixed some bugs causing wrong error messages
  - Improved Terminal menu. Now it supports page navigation
  - minor fixes

- 1.0.26.1 Patch 8.5, October 04 2020
  - Added MBL (Mesh Bed Leveling) menu to perform MBL (it requires MBL enabled in Marlin fw)
  - Added Mesh Editor and Mesh Tuner menus providing a visual mesh grid (gradient colors are configurable in config.ini) and a fine tune tool for mesh editing. The Mesh Editor supports:
    1. MBL
    2. UBL
    3. ABL Bilinear
  - Added notifications history menu. Open it by clicking on the screen top area (title bar). That feature was made by BTT
  - Added precompiled Marlin fw MBL version

- 1.0.26.1 Patch 8.4, August 30 2020
  - fw preconfigured to support Marlin mode. A long press on the center of the display will display the Touch mode vs Marlin mode switching menu
  - Added real M600 support when printing from external onboard SD card (an SD card reader mounted on the main board)
  - Added a detailed PDF document reporting:
    1. how to enable Marlin mode on Sidewinder X1 v4 / Genius printers
    2. how to enable M600 support on Marlin fw

- 1.0.26.1 Patch 8.3, August 23 2020
  - fixed a bug causing a freeze when trying to load and print a file with long file name
  - M117 message is now reported also as notification
  - Added two new preheat materials
  - Improved notification popup. Notifications are now displayed on top of the screen. A list of notifications is also handled
  - Improved Extrude100 feature
  - Unified heat menu is also accessible from main screen, pressing on bed or nozzle icons. It allows to easily access the preheat menu
  - Terminal menu is also accessible from main screen, pressing on the Status bar.

- 1.0.26.1 Patch 8.2, August 11 2020
  - it could fix freezes present in patch 8.1.

- 1.0.26.1 Patch 8.1, August 07 2020 - CURRENTLY PUT ON STANDBY DUE TO BUGS ON BTT MAIN BRANCH CODE)
  - fixed a bug on BTT main branch causing many freezes

- 1.0.26.1 Patch 8, August 06 2020 - CURRENTLY PUT ON STANDBY DUE TO BUGS ON BTT MAIN BRANCH CODE
  - All the source code is now available in the latest official BTT main branch. Below the list of all my last additions/improvements/fixes
  - Improved existing menus such as:
    1. ProbeOffset: added new functions (save, XY axis unlock...) via a new submenu + cleanup
    2. ManualLeveling: Added new functions (XY axis unlock, bed edge distance menu...) via a new submenu + cleanup
    3. MachineSetting: Added new functions (save, restore, reset) via a new submenu
    4. ZFade: added save button (saving feature is now the same as in ProbeOffset and Babystep menus)
    5. UnifiedMenu: improved ABL ON/OFF update + cleanup
  - New menus:
    1. ConnectionSetting: Any connection settings such as baudrate, disconnect button, shutdown button were migrated AS IS in this new menu located under Settings menu
    2. Tuning: it contains features such as PID autotune menu and typical 100mm extrusion button (usefull for calculating proper steps-per-unit). The menu is located under Settings menu
    3. PID autotune: menu allowing to handle the entire PID process for bed + nozzles. A dialog box will popup the result of the process (success, fail, timeout)
    4. LevelingEdgeDistance: it allows to set the "level_edge" parameter. Thus to set the bed edge distance of the four leveling points
  - New features:
    1. added new UBL autoleveling menu (UBL must be enabled in Marlin fw)
    2. added new "notification" popup type. A notification popup is displayed for few seconds (by default set to 1.5 seconds, configurable in Configuration.h). No user interaction is needed
    3. added a configurable popup type and buzzer type for the "known" echo messages (registered in parseACK.c).
       Available popup types are:
       - none: no popup. The echo message is silently discarded
       - reminder: reminder popup. A reminder popup is displayed. A user interaction is needed
       - notification: notification popup. A notification popup is displayed for few seconds. No user interaction is needed
       Furthermore, the use of buzzer (on or off) is also selectable.
       Functions signature to read and set the parameters for any known echo message are available in parseACK.h.
       E.g. I used that in Z Fade menu to temporary disable some echo messages
    4. added a configurable popup type and buzzer type for the error ACK and echo ACK messages.
       Available settings, provided in config. ini and FeatureSetting menu, are:
       - OFF: no popup. The message is silently discarded
       - ON: A reminder popup is displayed. A user interaction is needed
       - SMART: A notification popup is displayed for few seconds. No user interaction is needed
       That feature is useful for example to temporary suppress any kind of error or echo ACK message
  - Fixes:
    1. general cleanup (converted tabs to spaces + correct indentation) on different files
    2. restored slovenian language in config.ini file (it was removed by mistake in the last BTT merge)
    3. changed some label names (e.g. ABL_start) whose values have a "general" meaning (e.g. "start", "down" etc.) in order the label names can be reused in more than one context and/or menus.
    4. fixed some wrong settings for MKS TFT + added correct SPI slave code to allow integration with SKR 1.3 main board

- 1.0.26.1 Patch 7, July 23 2020
  - Improved Z Offset menu. Now the nozzle is moved every time z offset is changed so, using a paper, it is possible to evaluate the proper z offset
  - Fixed a bug on Connection menu causing no store of baudrate when changed
  - Fixed a bug on runout sensor causing to display an error message after resuming the print
  - Changes in some languages translation

- 1.0.26.1 Patch 6, July 18 2020
  - Fixed a bug causing a freeze after a print or in general when changing fan, speed and flow
  - Fixed a bug causing no fan info update in the main menu
  - Added  slovenian language

- 1.0.26.1 Patch 5, July 09 2020
  - Fixed bug causing instability when changing fan, speed and flow

- 1.0.26.1 Patch 4.1, June 26 2020:
  - Fixed minor bug on permanent temperatures display menu. Text was partially truncated

- 1.0.26.1 Patch 4, June 24 2020:
  - Fixed minor bugs
  - Added TPU preheat button
  - improved UI (big fonts for values, dialog boxes etc.)

- 1.0.26.1 Patch 3, May 26 2020:
  - Fixed minor bugs

- 1.0.26.1 Patch 2, May 26 2020:
  - Fixed filament runout sensor bug (now enabled by default in the provided config.ini file)
  - Fixed rotate UI button on sreen menu (previously, the screen was not rotated of 180� by pressing on rotate button)
  - Minor fixes (some language translations, some Celsius degree symbols etc.)

- 1.0.26.1 Patch, May 22 2020:
  - Fixed all bugs on 1.0.26.1

- 1.0.26.1, May 14 2020:
  - Based on last BigTreeTech 0.26.1 version released on May 13 2020
  - Finally added a file based configuration (by BigTreeTech 0.26.1). See section FIRMWARE CONFIGURATION UPDATE below to know how to use it
  - Added a Tuning menu collecting the typical printer calibration tools such as:
    - PID autotune
    - 100mm extrusion
    - ABL and Manual leveling menu
    - Parameter menu to set standard printer settings
    - Terminal menu to send any gcode
  - Added a Connection menu collecting connection tools such as:
    - UART speed (baudrate)
    - disconnect button
    - shut down button
  - Fixed and improved Babystep and ProbeOffset menu
  - Improved Manual bed leveling menu adding 5th leveling point and a XY Offset menu to set the edge distance of the four leveling points

- 1.0.26, April 17 2020:
  - First fully stable version

<a name="Marlin-Firmware-Changes"></a>

### Marlin Firmware Changes

- 2.1.2.1, January 14 2024

  **IMPROVEMENTS:**
  - Enabled and configured ADVANCED_OK feature to work in tandem with the ADVANCED_OK support provided on new TFT fw patch 10

- 2.1.2, May 14 2023
  - Last update to Marlin 2.1.2 (May 14 2023)
  - Enabled input shaping

- 2.1.2, January 12 2023

- 2.1.1, August 10 2022

- 2.0.9.2 version, October 05 2021
  - Update to new official Marlin 2.0.9.2

- 2.0.9.1 version, July 05 2021
  - Fixed different bugs

- 2.0.8.2 version, May 31 2021
  - Fixed different bugs on 2.0.8.1

- 2.0.8.1 version, May 15 2021
  - Fixed some bugs (from me and BTT) on M600 support in case no Marlin LCD (as for stock ASWX1) is present. That bugs didn't allow M600 working on stock ASWX1. M600 was fully working only if Marlin mode was enabled (see my PDF doc)
  - Many others bug fixes
  - For MBL and standard Marlin fw versions, now homing is performed on X0 Y0 instead of the centre of the bed

- Marlin fw bugfix version, March 21 2021
  - It should fix many bugs present on Marlin fw 2.0.7.2 (e.g. temperature not reached)
  - For MBL and, standard version, fixed the bug applying the XY probe offset during home and probing (offsets are now set to 0, 0)
  - For MBL, Waggster and standard BLTouch version, probing margin and inset set to 10mm to allow to probe also the last row and column

- 2.0.7.2, February 04 2021

- 2.0.6.1, November 14 2020
  - Fixed bug causing popup of error messages during a print and a change in the flow/speed to 10%

- 2.0.6.1, September 20 2020
  - Fixed the Waggster mod version. Now it correctly works (probe is configured on Z max endstop instead of Z min endstop)
  - Enabled G26 (Mesh Validation Pattern tool)

- 2.0.6.1, August 30 2020
  - fw preconfigured to support Marlin mode. In order to enable Marlin mode it is required only to uncomment #define REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER on the Configuration.h file
  - fw preconfigured to support M600 when printing from external onboard SD card (an SD card reader mounted on the main board)

- 2.0.5.4, July 23 2020
  - First version
  - Based on official Marlin firmware last released on 2020 July 20
  - Source code available

<a name="List-of-Main-Features"></a>

## List of Main Features

<a name="TFT-Firmware-Main-Features"></a>

### TFT Firmware Main Features

- config.ini: a configuration file to set all the settings and features of the TFT firmware such as:
  - build volume (e.g. 300x300x400 for Sidewinder X1 or 220x220x250 for Genius printer)
  - number of tools, extruder and fans
  - max temperatures for all heaters
  - custom gcodes
  - default speeds
  - colours
  - etc.
- MBL (Mesh Bed Leveling) menu to perform MBL (it requires MBL enabled in Marlin fw)
- Mesh Editor and Mesh Tuner menus providing a visual mesh grid (gradient colors are configurable in config.ini) and a fine tune tool for mesh editing. The Mesh Editor supports:
  1. MBL
  2. UBL
  3. ABL Bilinear
- Notifications history menu. Open it by clicking on the screen top area (title bar).
- M600 support when printing from external onboard SD card (an SD card reader mounted on the main board)
- Tuning menu: a menu collecting all the typical printer calibration tools such as:
  - PID autotune: you can set the target temperatues for both the bed and the hotend and then start the autotune. Autotune is performed for all the heaters for which a temperature different than 0 was set. E.g. if you set the temperature only for bed, the autotune will be performed only for the bed
  - 100m extrusion: the classic 100mm of filament extrusion to calculate the correct steps-per-unit value
  - ABL e Manual leveling menu
  - parameter menu: the menu were you can set printer parameters (e.g. the correct steps-per-unit value you determined with the 100mm extrusion)
  - Terminal menu: to send any gcode to Marlin firmware
  - save button: it makes permanent on the EEPROM (it requires EEPROM is enabled on Marlin firmware) the setting provided on the Tuning menu. E.g. if you want to save PID values or babystep changes, don't forget to press this button otherwise you will loose those settings on next printer reboot
- Added a Connection menu collecting connection tools such as:
  - UART speed (baudrate): speed value to connect the TFT to Marlin firmware
  - disconnect button: used to temporary disconnect the TFT from Marlin firmware. It is usefull to allow flashing Marlin firmware without the need to open the printer chassis to disconnect the TFT cable from the main motherboard. E.g. you can use the Prusaslicer's firmware update tool to flash Marlin firmware
  - shut down button: used to shut down the printer (it requires the feature is enabled on Marlin firmware)
- Manual bed leveling menu:
  - added 5th leveling point: a center point is added
  - added XY Offset menu: it allows to set the edge distance of the four leveling points. An unlock button is also provided to unlock the X and Y axis (it allows to freely move the hotend along the bed)
- Auto bed leveling menu: it requires that feature is also enabled in Marlin firwmare (e.g. Waggster fw)
- Improved Z Offset menu. Now nozzle is moved every time z offset is changed so, using a paper, it is possible to evaluate the proper z offset
- BabyStep menu: available during printing
- Preheat menu: PLA, PETG and ABS buttons available. they can be applied to bed, nozzle or both. A button to cool down the selected heatear was also added
- Gcode menu: you can type any gcode command towards Marlin firmware. If an output is provided by the underliying Marlin firmware it will be shown on the display
- Custom gcode menu: load EEPROM (M501), reset to stock Marlin firmware (M502), Save on EEPROM (M500), disable steppers etc. are provided. It requires EEPROM is also enabled in Marlin firwmare (e.g. Waggster,  Robscar fw)
- Machine menu: it allows to see and modify settings such as steps-per-unit, max feed rate, max acceleration, Z probe etc.
- Feature menu: it allows to customize printer feature such as runot filament (on, off, smart), auto shut down after print (it requires it is enabled on Marlin firmware), file menu view (icon or list view mode) etc.
- more...

<a name="Marlin-Firmware-Main-Features"></a>

### Marlin Firmware Main Features

For all the Marlin fw variants, the following changes are provided:
- hotend and bed PID calibrated to 200�C and 60�C respectively. However PID values strongly depend on the environment and the current ambient temperature, so always perform PID calibration (from TFT menu) in order to have the proper values on your environment
- decreased values for DEFAULT_MAX_FEEDRATE compared to default values provided by Artillery
- increased values for DEFAULT_ACCELERATION compared to default values provided by Artillery
- disabled "Junction Deviation" (enabled "Classic Jerk")
- disabled "S-Curve Acceleration"
Both the above disabled two parameters provide better results on Sidewinder X1 and do not interfere with Linear Advance feature
- enabled BLTouch. Probe offsets configured to X33 Y33. The proper support (STL file) is provided in the zip file
- enabled "Probe Repeatability Test" to use M48 gcode
- enabled "ABL Bilinear"
- enabled "Restore Leveling After G28" to restore saved leveling data after every G28 gcode execution
- enabled "Z Safe Homing"
- enabled "EEPROM Settings" to allow persistent storage to preserve configurable settings across reboots
- enabled "Quick home"
- enabled "Adaptive Step Smoothing"
- enabled "Babystepping"
- enabled "Babystep ZProbe Offset" to combine M851 Z and Babystepping
- enabled "Linear Advance" with K factor set to 0.13 (LIN_ADVANCE_K)

<a name="Simplify3D-Profile-Features"></a>

### Simplify3D Profile Features

Profile for PLA filament. Change the following parameters value according to your needs:
- Extruder tab
  - Extrusion Width Manual: typically 0,40 or 0,50
- Layer tab
  - Primary Layer Height: typically 0,10, 0,15, 0,20 etc.
  - Top Solid Layers: depending on Primary Layer Height. E.g. with a 0,15 height, set to 10 to have a 1,5 mm solid layer
  Bottom Solid Layers: depending on Primary Layer Height. E.g. with a 0,15 height, set to 10 to have a 1,5 mm solid layer
  Outline/Perimeters Shells: depending on Extrusion Width. E.g. with a 0,50 width, set to 3 to have a 1,5 mm perimeters shells
  - First Layer Height: set to a value greater than 100% to have a first layer taller than Primary Layer Height and viceversa
  - First Layer Width: set to a value greater than 100% to have a first layer wider than Extrusion Width and viceversa
  - First Layer Speed: set to a value greater than 100% to have a speed bigger than Default Printing Speed and viceversa
- Infill tab
  - Interior Fill Percentage: set according to the needs of the object to print
- Temperature tab
  - Primary Extruder: set according to the needs of the object to print. Typical values for PLA filament are in range 180-210�C. Increase first layer temp to have a better stick on the bed
  - Heated Bed: set according to the needs of the object to print. Typical values for PLA filament are in range 50-80�C. Increase first layer temp to have a better stick on the bed
- Speeds tab
  - Default Printing Speed: typically 40, 60, 80, 100 etc.

The profile is configured for the Sidewinder X1 build volume. However, the profile works also on the Genius printer. On G-Code tab, simply set the "Build volume" parameters with the proper build volume
