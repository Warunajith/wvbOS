 #include "drivers/frame_buffer.h"
    #include "drivers/serial_port.h"
    #include "drivers/io.h"
    #include "segmentation/segments.h"
    #include "interrupts/interrupts.h"
    #include "interrupts/keyboard.h"
    #include "interrupts/pic.h"
    #include "multiboot.h"
    #include "paging.h"

    void kmain(unsigned int ebx,u32int kernel_physical_start, u32int kernel_physical_end)
    {

	init_paging(kernel_physical_start,kernel_physical_end);
       /*char arr[] = "Welcome to WVBOS";
       fb_move_cursor(6*80);
       fb_write(arr, 20);
       serial_write(arr, 20);
       segments_install_gdt();
       interrupts_install_idt();*/
     
   multiboot_info_t *mbinfo = (multiboot_info_t *) ebx;
  	multiboot_module_t* modules = (multiboot_module_t*) mbinfo->mods_addr; 
  	unsigned int address_of_module = modules->mod_start;
  	
  	if((mbinfo->mods_count) == 1){
  		char message[] = "ONE module loaded successfully!";
  		serial_write(message,sizeof(message));
  		
  		typedef void (*call_module_t)(void);
        	/* ... */
        	call_module_t start_program = (call_module_t) address_of_module;
        	start_program();
        	/* we'll never get here, unless the module code returns */

  	}else{
  		char message[] = "Error: More than ONE module loaded";
  		serial_write(message,sizeof(message));
  	}

    }
