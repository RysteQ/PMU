SHELL:=/bin/bash

OUTPUT=pmu

debug:
	gcc main.c "./Platforms/Raspberry Pi 5/RP5PMU.c" "./Platforms/x86/x86PMU.c" ./Utils/buffer.c ./Utils/arguments.c -o $(OUTPUT)

optimised:
	time gcc main.c "./Platforms/Raspberry Pi 5/RP5PMU.c" "./Platforms/x86/x86PMU.c" ./Utils/buffer.c ./Utils/arguments.c -O3 -o $(OUTPUT)

clean:
	rm $(OUTPUT)