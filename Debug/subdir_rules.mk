################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/LeStoreDownload/CCS/app/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O2 -I"D:/compitation/NUEDC/empty/empty" -I"D:/compitation/NUEDC/empty/empty/Debug" -I"D:/LeStoreDownload/CCS/mspm0sdk/mspm0_sdk_2_06_00_05/source/third_party/CMSIS/Core/Include" -I"D:/LeStoreDownload/CCS/mspm0sdk/mspm0_sdk_2_06_00_05/source" -gdwarf-3 -Wall -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-1978854367: ../empty.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"D:/LeStoreDownload/CCS/app/ccs/utils/sysconfig_1.25.0/sysconfig_cli.bat" --script "D:/compitation/NUEDC/empty/empty/empty.syscfg" -o "." -s "D:/LeStoreDownload/CCS/mspm0sdk/mspm0_sdk_2_06_00_05/.metadata/product.json" --compiler ticlang
	@echo 'Finished building: "$<"'
	@echo ' '

device_linker.cmd: build-1978854367 ../empty.syscfg
device.opt: build-1978854367
device.cmd.genlibs: build-1978854367
ti_msp_dl_config.c: build-1978854367
ti_msp_dl_config.h: build-1978854367
Event.dot: build-1978854367

%.o: ./%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/LeStoreDownload/CCS/app/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O2 -I"D:/compitation/NUEDC/empty/empty" -I"D:/compitation/NUEDC/empty/empty/Debug" -I"D:/LeStoreDownload/CCS/mspm0sdk/mspm0_sdk_2_06_00_05/source/third_party/CMSIS/Core/Include" -I"D:/LeStoreDownload/CCS/mspm0sdk/mspm0_sdk_2_06_00_05/source" -gdwarf-3 -Wall -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

startup_mspm0g350x_ticlang.o: D:/LeStoreDownload/CCS/mspm0sdk/mspm0_sdk_2_06_00_05/source/ti/devices/msp/m0p/startup_system_files/ticlang/startup_mspm0g350x_ticlang.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/LeStoreDownload/CCS/app/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O2 -I"D:/compitation/NUEDC/empty/empty" -I"D:/compitation/NUEDC/empty/empty/Debug" -I"D:/LeStoreDownload/CCS/mspm0sdk/mspm0_sdk_2_06_00_05/source/third_party/CMSIS/Core/Include" -I"D:/LeStoreDownload/CCS/mspm0sdk/mspm0_sdk_2_06_00_05/source" -gdwarf-3 -Wall -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


