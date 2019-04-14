# PS4-idc

* PS4_Kernel_Functions_Finder.idc - Self explainatory. Run after initial autoanalyze is done. 
* fix_offset_table.idc - Script to run after PS4_Kernel_Functions_Finder. Require image base set to 0xFFFFFFFF82200000, otherwise it will do nothing useful.

* PS4_Function_Finder.idc - Like PS4_Kernel_Functions_Finder.idc but can be used on any PS4 ELF. 
