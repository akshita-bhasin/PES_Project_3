############################

############################
#Command for removing files
RM := rm -rf

ifeq ($(MODULE),KL25Z)
############################
# Include files
INCLUDES := \
	-I"CMSIS" \
	-I"source" \
	-I"board" \
	-I"drivers" \
	-I"utilities" \
	-I"startup"
	
# Compiler
CC := arm-none-eabi-gcc
	
# Linker
LL := arm-none-eabi-gcc

# Binary/exectable to build
EXE := \
  ./debug/PESProject3.axf

# List of object files
OBJS := \
	./debug/startup_mkl25z4.o \
	./debug/system_MKL25Z4.o \
	./debug/board.o \
	./debug/clock_config.o \
	./debug/peripherals.o \
	./debug/pin_mux.o \
	./debug/fsl_clock.o \
	./debug/fsl_common.o \
	./debug/fsl_flash.o \
	./debug/fsl_gpio.o \
	./debug/fsl_lpsci.o \
	./debug/fsl_smc.o \
	./debug/fsl_uart.o \
	./debug/fsl_debug_console.o \
	./debug/main.o \
	./debug/led_blink.o \
	./debug/logger.o \
	./debug/memorytest.o \
	./debug/pattern_gen.o
	
# List of dependency files
C_DEPS = \
	./debug/startup_mkl25z4.d \
	./debug/system_MKL25Z4.d \
	./debug/board.d \
	./debug/clock_config.d \
	./debug/peripherals.d \
	./debug/pin_mux.d \
	./debug/fsl_clock.d \
	./debug/fsl_common.d \
	./debug/fsl_flash.d \
	./debug/fsl_gpio.d \
	./debug/fsl_lpsci.d \
	./debug/fsl_smc.d \
	./debug/fsl_uart.d \
	./debug/fsl_debug_console.d \
	./debug/main.d \
	./debug/led_blink.d \
	./debug/logger.d \
	./debug/memorytest.d \
	./debug/pattern_gen.d
	
# Compiler options
CC_OPTIONS := \
	-c \
	-std=gnu99 \
	-O0 \
	-g3 \
	-ffunction-sections \
	-fmessage-length=0\
	-fno-common \
	-fdata-sections \
	-fno-builtin \
	-mcpu=cortex-m0plus \
	-mthumb

# Linker Options
LL_OPTIONS := -nostdlib -Xlinker -Map="debug/PESProject3.map" \
			-Xlinker --gc-sections -Xlinker -print-memory-usage \
			-mcpu=cortex-m0plus -mthumb -T linkerfile.ld -o $(EXE)

endif

ifeq ($(MODULE),PC)
############################
# Include files
INCLUDES := \
	-I"C:\MinGW\include"
# included MinGW to run gcc on Windows

# Compiler
CC := gcc
	
# Linker
LL := gcc

# Binary/exectable to build
EXE := \
	./debug/PESProject3.exe
#generating exe file and collecting and object files at linking
#and making an exe file

# List of object files
OBJS := \
	./debug/main.o \
	./debug/logger.o \
	./debug/memorytest.o \
	./debug/pattern_gen.o
	
# List of dependency files
C_DEPS = \
	./debug/main.d \
	./debug/logger.d \
	./debug/memorytest.d \
	./debug/pattern_gen.d
	
# Compiler options
CC_OPTIONS := \
	-Wall -Werror -c -std=c99

# Linker Options
LL_OPTIONS := -g -o $(EXE)

endif

############################
# Include generated dependency files (only if not clean target)
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

############################
# Main (all) target
all: $(EXE)
	@echo "*** finished building ***"

############################
# Clean target
clean:
	-$(RM) $(OBJS) $(EXE)
	-$(RM) ./debug/*.map
	-@echo "*******Cleaned!*******"
	
 ############################
#Rules to include all build targets
ifeq ($(MODULE),KL25Z)
############################
# Build Options
B_OPTIONS := \
	-D__REDLIB__ -DCPU_MKL25Z128VLK4 -DCPU_MKL25Z128VLK4_cm0plus -DSDK_OS_BAREMETAL \
	-DFSL_RTOS_BM -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 \
	-DSCANF_FLOAT_ENABLE=0 -DPRINTF_ADVANCED_ENABLE=0 -DSCANF_ADVANCED_ENABLE=0 \
	-D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DFRDM_KL25Z -DFREEDOM -DKL25Z -specs=redlib.specs \
	
./debug/%.o: ./source/%.c
	@echo 'Building file: $<'
	$(CC) $(CC_OPTIONS) $(B_OPTIONS) $(INCLUDES) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
	
else ifeq ($(MODULE),PC)
	
./debug/%.o: ./source/%.c
	@echo 'Building file: $<'
	$(CC) $(CC_OPTIONS) -DPC_DEBUG $(INCLUDES) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

endif

############################

$(EXE): $(OBJS) linkerfile.ld
	@echo 'Building target: $@'
	@echo 'Invoking: Linker'
	$(LL) $(LL_OPTIONS) $(OBJS)
	@echo 'Finished building target: $@'
	@echo ' '
 
############################
# Rule to build the files in the board folder
./debug/%.o: ./board/%.c
	@echo 'Building file: $<'
	$(CC) $(CC_OPTIONS) $(B_OPTIONS) $(INCLUDES) -MMD -MP -MF"./$(@:%.o=%.d)" -MT"./$(@:%.o=%.o)" -MT"./$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
 
############################
# Rule to build the files in the CMSIS folder
./debug/%.o: ./CMSIS/%.c
	@echo 'Building file: $<'
	$(CC) $(CC_OPTIONS) $(B_OPTIONS) $(INCLUDES) -MMD -MP -MF"./$(@:%.o=%.d)" -MT"./$(@:%.o=%.o)" -MT"./$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

############################
# Rule to build the files in the drivers folder	
./debug/%.o: ./drivers/%.c	
	@echo 'Building file: $<'
	$(CC) $(CC_OPTIONS) $(B_OPTIONS) $(INCLUDES) -MMD -MP -MF"./$(@:%.o=%.d)" -MT"./$(@:%.o=%.o)" -MT"./$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

############################
# Rule to build the files in the utilities folder
./debug/%.o: ./utilities/%.c
	@echo 'Building file: $<'
	$(CC) $(CC_OPTIONS) $(B_OPTIONS) $(INCLUDES) -MMD -MP -MF"./$(@:%.o=%.d)" -MT"./$(@:%.o=%.o)" -MT"./$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
	
############################
# Rule to build the files in the startup folder - Madhukar Chu
./debug/%.o: ./startup/%.c
	@echo 'Building file: $<'
	$(CC) $(CC_OPTIONS) $(B_OPTIONS) $(INCLUDES) -MMD -MP -MF"./$(@:%.o=%.d)" -MT"./$(@:%.o=%.o)" -MT"./$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '