/*
 * Save_Load_Struct.c
 *
 *  Created on: 22 sep. 2021
 *      Author: Daniel Mårtensson
 */

#include "Hardware.h"

bool Save_Struct(uint8_t data[], uint32_t data_length, char file_name[]){
#if PROCESSOR_CHOICE == STM32
	/* Save it to SD card */
	if(STM32_PLC_SD_Mont_Card() != FR_OK)
		return false;
	STM32_PLC_SD_Create_File_With_Write(file_name);
	STM32_PLC_SD_Write_Data(data, data_length);
	STM32_PLC_SD_Close_File();
	STM32_PLC_SD_Unmount_Card();
#elif PROCESSOR_CHOICE == ARDUINO
	/* Implement your memory handler function for the Arduino platform */
#elif PROCESSOR_CHOICE == PIC
	/* Implement your memory handler function for the PIC platform */
#elif PROCESSOR_CHOICE == AVR
	/* Implement your memory handler function for the AVR platform */
#endif
	return true;
}

bool Load_Struct(uint8_t data[], uint32_t data_length, char file_name[]){
#if PROCESSOR_CHOICE == STM32
	/* Load it from SD card */
	if(STM32_PLC_SD_Mont_Card() != FR_OK)
		return false;
	STM32_PLC_SD_Open_File_With_Read(file_name);
	STM32_PLC_SD_Read_Data(data, data_length);
	STM32_PLC_SD_Close_File();
	STM32_PLC_SD_Unmount_Card();
#elif PROCESSOR_CHOICE == ARDUINO
	/* Implement your memory handler function for the Arduino platform */
#elif PROCESSOR_CHOICE == PIC
	/* Implement your memory handler function for the PIC platform */
#elif PROCESSOR_CHOICE == AVR
	/* Implement your memory handler function for the AVR platform */
#endif
	return true;
}
