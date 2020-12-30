#include <3ds.h>
#include <iostream>

#include "gui.hpp"
#include "download.hpp"

int main ()
{
    //main
    Gui::init();
    gfxInitDefault();
    romfsInit();
    cfguInit();
    downloadToFile("https://github.com/NPID7/nightlys/raw/master/builds/3ds-download-test/3ds-download-test.3dsx", "sdmc:/3ds-download-test.3dsx");
    

    while (aptMainLoop())
    {
        hidScanInput();
        u32 hDown = hidKeysDown();
        
        if (hDown & KEY_START)
        {
            break;
        }
    }
    Gui::exit();
    gfxExit();
    romfsExit();
    cfguExit();

}
