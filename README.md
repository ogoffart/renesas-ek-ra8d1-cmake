Experiment of Slint on a Renesas EK-RA8D1 board

All generated files where compied from the Thermostat_App_EK_RA8D1 example.

```sh
JLinkExe -Device R7FA8D1BH -if SWD -speed 4000 -autoconnect 1
```

```sh
mkdir build
cd build
cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=1
make && gdb-multiarch ra8d1_blinky.elf -ex "target remote localhost:2331" -ex "load" -ex "monitor reset" -ex "continue"
```
