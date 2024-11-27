################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/Timer/subdir.mk
-include MCAL/External\ Interrupt/subdir.mk
-include MCAL/DIO/subdir.mk
-include ECUAL/LED/subdir.mk
-include ECUAL/Button/subdir.mk
-include APP/subdir.mk
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
On-demandTrafficLightControl.lss \

FLASH_IMAGE += \
On-demandTrafficLightControl.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: On-demandTrafficLightControl.elf secondary-outputs

# Tool invocations
On-demandTrafficLightControl.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,On-demandTrafficLightControl.map -mmcu=atmega32 -o "On-demandTrafficLightControl.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

On-demandTrafficLightControl.lss: On-demandTrafficLightControl.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S On-demandTrafficLightControl.elf  >"On-demandTrafficLightControl.lss"
	@echo 'Finished building: $@'
	@echo ' '

On-demandTrafficLightControl.hex: On-demandTrafficLightControl.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex On-demandTrafficLightControl.elf  "On-demandTrafficLightControl.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: On-demandTrafficLightControl.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 On-demandTrafficLightControl.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) On-demandTrafficLightControl.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
