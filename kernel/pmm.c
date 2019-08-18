
#include <multiboot.h>
#include <common.h>
#include <kernel/debug.h>
#include <kernel/pmm.h>
#include <kernel/kernel.h>

void show_memory_map(void)
{
    uint32_t mmap_addr = glb_mboot_ptr->mmap_addr;
    uint32_t mmap_length = glb_mboot_ptr->mmap_length;

    printk_log_info("Memory map:");

    mmap_entry_t *mmap = (mmap_entry_t *)mmap_addr;
    for (mmap = (mmap_entry_t *)mmap_addr; (uint32_t)mmap < mmap_addr + mmap_length; mmap++) {
        printk_log_info("base_addr = 0x%X%08X, length = 0x%X%08X, type = 0x%X",
            (uint32_t)mmap->base_addr_high, (uint32_t)mmap->base_addr_low,
            (uint32_t)mmap->length_high, (uint32_t)mmap->length_low,
            (uint32_t)mmap->type);
    }
}
