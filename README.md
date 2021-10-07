# All-In-One DFU-Programmer

This is a Tool designed for Code::Blocks to help you Upload your hex file to a MCU

### Prerequisites

- [Code::Blocks](https://www.codeblocks.org/downloads/binaries) 
- [DFU-Programmer](https://sourceforge.net/projects/dfu-programmer/files/)
- [WinAVR](https://sourceforge.net/projects/winavr/) (not required, used to generate .hex file)

## Installing

1. Download the AIO-DFU from the Releases tab or click [here](https://github.com/ThomasW2005/AIO-DFU/releases/latest)

2. Save it somewhere (e.g "C:\Program Files (x86)\dfu-programmer-win-0.7.2\aio-dfu.exe")

3. Open Code::Blocks

4. Configure a new Tool:
    1. Menu Bar → Tools → Configure tools... → Add

        1. Name: [A name for the tool, doesn't matter]

        2. Executable: the location of aio-dfu.exe (e.g "C:\Program Files (x86)\dfu-programmer-win-0.7.2\aio-dfu.exe")
        
        3. Parameters: You should add 2 Parameters, seperated by space
            1. 1st: Location of the dfu-programmer.exe sorrounded by "" (e.g "C:\Program Files (x86)\dfu-programmer-win-0.7.2\dfu-programmer.exe")
            
            2. \${TARGET_OUTPUT_DIR}${PROJECT_NAME} (exactly this)
        4. should look something like this: "C:\Program Files (x86)\dfu-programmer-win-0.7.2\dfu-programmer.exe" \${TARGET_OUTPUT_DIR}${PROJECT_NAME}
        
        5. Working directory: [leave blank]
        
        6. For Launching options you can choose the second option if you don't want to see the Console popping up everytime you program
        
        7. Click OK
    
    2. Click Close

5. Optionally, you can add a keyboard shortcut:
    1. Menu Bar → Settings → Editor... → Keyboard shortcuts (scroll down on the left side)

    2. Under Commands open Tools and click on you Tool's name

    3. Add a shortcut on the right side

    4. Click OK

6. Thats it ✌️

You can test it by either Selecting the Tool under Tools or pressing the keyboard shortcut (don't forget to click on the button on your MCU-board)

## Compiling

Feel free to explore and modify the source code

1. Clone this repo: ```$ git clone  https://github.com/ThomasW2005/AIO-DFU.git```

2. Compile with GCC: ```$ g++ aio-dfu.cpp -o aio-dfu.exe -O3 -Wall```

## Common Issues

Under Construction
