################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/GIE/subdir.mk
-include MCAL/EXTI/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/LM35/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/KPD/subdir.mk
-include HAL/DC_Motor/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
MP5_2TempSensor_Interrupts.lss \

FLASH_IMAGE += \
MP5_2TempSensor_Interrupts.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: MP5_2TempSensor_Interrupts.elf secondary-outputs

# Tool invocations
MP5_2TempSensor_Interrupts.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,MP5_2TempSensor_Interrupts.map -mmcu=atmega32 -o "MP5_2TempSensor_Interrupts.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

MP5_2TempSensor_Interrupts.lss: MP5_2TempSensor_Interrupts.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S MP5_2TempSensor_Interrupts.elf  >"MP5_2TempSensor_Interrupts.lss"
	@echo 'Finished building: $@'
	@echo ' '

MP5_2TempSensor_Interrupts.hex: MP5_2TempSensor_Interrupts.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex MP5_2TempSensor_Interrupts.elf  "MP5_2TempSensor_Interrupts.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: MP5_2TempSensor_Interrupts.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 MP5_2TempSensor_Interrupts.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) MP5_2TempSensor_Interrupts.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
