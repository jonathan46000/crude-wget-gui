# crude-wget-gui
[Crude wget gui]

-About the program

    Version: 0.17
    
    About:
        This Crude Wget Gui was written to make access to files on certain web platforms 
        easier and faster.  It is provided as is without warranty of any kind.  Use at
        your own risk.  This project was written to be very simple and effective at a
        small set of things and is not intended to replace command line wget.  There
        are more functional and full featured graphical interfaces for this application,
        the goal for this project is simplicity.  If a feature can be added and the
        simplicity maintained, please feel free to add it and send me a pull request or
        email me via the email listed on my website at http://jonathan46000.com.
    
    contributors: 
        Jonathan L. http://jonathan46000.com

[Build/Installation Instructions]

-Minimum tested build environment

    Qt 5.6.1 or greater,
    GCC 4.8.5 or greater, 
    64 bit Linux

-Required Packages

    GNU Wget 1.14 or greater,
    
-Build Instructions

    Load project and build with QtCreator
    
-Post build instructions

    Move README.txt, GNU GPL V3 license, and wgg_icon.png into folder with executable
    
    From executable folder run: 
        
        $make clean
        
[Using crude wget gui]

-Setting default download path

    The default download path will save your prefered download path and 
    reload this path everytime the program opens.  This setting can be 
    set by selecting the following from the menu bar:
    
        Settings->Default path
    
-Setting the current path

    Setting the current path only sets the download path for the current session.
    Setting the current path will override the default download path.  Setting
    the current download path can be achieved by selecting the following from
    the menu bar:
    
        File->Download Path
        
-Downloading items

    Copy the url of an item you would like to download "Download url" text box.
    Press the "Add item" button.  If the url appears in the "Items to download"
    window it has been successfully added to the download list.  Continue to add
    items until you are satisfied with the list.  If the site the items are to
    be downloaded from require a user name and password then all the items placed
    in the list must be from the same site.  If the site requires a user name and
    password enter them in the "Username" and "Password" text boxes.  Once you 
    are ready to download press the "Download" button.
    
-Help

    This help file can be accessed in your default text editor by selecting the
    following from the menu bar:
    
        Help->README
        
    Basic information about the current build can be accessed by selecting the
    following:
    
        Help->About
        
-Exiting the program

    You can exit the program either by clicking the x in the top right corner
    or by selecting File->Exit from the menu bar.
    

