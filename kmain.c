/* The C function */
   #include "drivers/frame_buffer.h"
   #include "drivers/serial_port.h"

    void kmain()
    {
    
            char ptr2[] = "Welcome to WVBOS";
            serial_write(SERIAL_COM1_BASE, ptr2, 26);
            fb_write(ptr2, 19);
    
    
    }
