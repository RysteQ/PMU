# PMU

PMU is a power measurement utility to help measure the power consumption of x86 based processors or the SBCs or Raspberry pi 4 and 5. The project is a merge of my other two repositories that do such things separately, these repositories being [XPMU](https://github.com/Athena-HPC-research/XPMU) and [RPMU](https://github.com/Athena-HPC-research/RPMU). This is just an all in one package with a better interface and plans for future updates.

## Usage

PMU has two modes, Terminal mode and Daemon more, it also has two platforms, x86 and the rpi platform.

Terminal mode is used for debugging purposes, to access the mode you type the following.

```bash
> ./pmu -t [-x86 or -rpi]
```

If you want to run the process for prolonged usage you need to run daemon mode, to do this you type the following.

```bash
> ./pmu -d [-x86 or -rpi] <filename> <minutes>
```

The \<filename\> is the name of the file the data will be saved as accompanied with a number afterwards, this is meant to minimise memory usage by saving a file each minute the PMU is being run.

The \<minutes\> is the amount of time in minutes the process should run for, this is to prevent the process from running forever.

The file output will contain the time the measurement was taken at and and depending on the mode the voltage and amps of the raspberry pi 4 / 5 CPU (this will be changed in the future to be only watts) or just the watts the CPU is consuming.

---

Version: 1