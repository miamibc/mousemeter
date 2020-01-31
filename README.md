# Mousemeter

Application to get distance mouse moved on table and number of clicks.

There will be two versions of this program for two platforms:

- linux/mousemeter - console app
- linux/mousemeterd - daemon for linux
- windows/mousemeter - console app
- windows/mousemeterd - windows service
 
## Installation

### Linux

Tested on Ubuntu16.

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

Thanks to **Max** for the idea. 