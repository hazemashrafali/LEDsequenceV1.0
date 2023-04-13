################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/TIMER_0/subdir.mk
-include MCAL/TIMER2_PWM/subdir.mk
-include MCAL/GPIO/subdir.mk
-include MCAL/External_INT/subdir.mk
-include HAL/LED/subdir.mk
-include HAL/DC_motor/subdir.mk
-include HAL/BUTTON/subdir.mk
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

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := Moving_car
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Moving_car.lss \

FLASH_IMAGE += \
Moving_car.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: main-build

# Main-build Target
main-build: Moving_car.elf secondary-outputs

# Tool invocations
Moving_car.elf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Moving_car.map -mmcu=atmega16 -o "Moving_car.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Moving_car.lss: Moving_car.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Moving_car.elf  >"Moving_car.lss"
	@echo 'Finished building: $@'
	@echo ' '

Moving_car.hex: Moving_car.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Moving_car.elf  "Moving_car.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Moving_car.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 Moving_car.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Moving_car.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents main-build

-include ../makefile.targets
