SHELL:=/bin/bash

OUTPUT=pmu

debug:
	gcc main.c "./Platforms/Raspberry Pi 5/RP5PMU.c" "./Platforms/x86/x86PMU.c" ./Utils/buffer.c ./Utils/arguments.c -Wno-unused-result -Og -o $(OUTPUT)

optimised:
	time gcc main.c "./Platforms/Raspberry Pi 5/RP5PMU.c" "./Platforms/x86/x86PMU.c" ./Utils/buffer.c ./Utils/arguments.c -Ofast -o $(OUTPUT)

clean:
	rm $(OUTPUT)