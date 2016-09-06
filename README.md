# Build Instructions:

下載 pre-built i686-elf-gcc GCC tool chain (http://wiki.osdev.org/GCC_Cross-Compiler#Prebuilt_Toolchains)

解壓縮後把 ghost-i686-elf-tools\bin 添加到系統環境變數 PATH 裡

下載 MinGW (https://sourceforge.net/projects/mingw/files/latest/download)

安裝後把 MinGW\bin 添加到系統環境變數 PATH 裡

下載 msys2 (https://msys2.github.io)

安裝後把 msys64\usr\bin 添加到系統環境變數 PATH 裡

打開 cmd 執行 pacman -S make

git clone https://github.com/kugwa/freertos_x86_gcc_pc.git

(以下提及的目錄都是以 freertos_x86_gcc_pc 起始的相對路徑，絕對路徑請自行補齊)

打開 VC

File / New / Project From Existing Code

Project file location: freertos_x86_gcc_pc\Demo\Blinky

Project name: Blinky

File types to add to the project: \*.c;\*.S;\*.h;\*.lds;Makefile

Use external build system

Build command line: make

Clean command line: make clean

之後 Build / Build solution 就會在 freertos_x86_gcc_pc\Demo\Blinky\build 裡生出 Blinky.elf

Build / Clean solution 則是會把所有編出來的檔案砍掉