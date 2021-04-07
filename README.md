# Mousemeter

Shows approximate distance mouse moved on the table, and number of clicks.

![Mousemeter](https://raw.github.com/miamibc/mousemeter/master/demo.gif)

One day, there will be two versions of this program for two platforms:

- linux/mousemeter - console app
- linux/mousemeterd - daemon for linux
- windows/mousemeter - console app
- windows/mousemeterd - windows service
 
## Installation

### Linux

Tested on Ubuntu 16 and 20.

    # Clone the repository
    git clone https://github.com/miamibc/mousemeter
    # Go to linux directory
    cd mousemeter/linux
    # Clean build files 
    make clean
    # Build new executables
    make
    # Run the app
    ./mousemeter 
    # or
    ./mousemeterd
    
### Windows

Who knows, it's not ready yet.

## PS

Thanks to [Max](https://github.com/GooDiK) for the idea. 
