#include <idc.idc>
#define create_qword(ea)    create_data(ea, FF_QWORD, 8, BADADDR)
//Experimental script to fix offset table. Use only on kernel with base 0xFFFFFFFF82200000. Probably not work on rebased kernels!
//Run after auto anlyze is done! 
//If used after PS4 Kernel Function Finder, wait until analyze will finish!
static main() {
  auto ea;


for ( ea = SegByName("LOAD"); ea != BADADDR;) {
    ea = FindBinary(ea, 1, "FF FF FF FF 08 00 00 00 00 00 00 00");
    if (ea == BADADDR)
      break;
     MakeUnkn(ea - 4, 1);
	 MakeUnkn(ea + 8, 1);
	 MakeUnkn(ea + 12, 1);
	ea = ea + 4;
	}
	
	for ( ea = SegByName("LOAD"); ea != BADADDR;) {
    ea = FindBinary(ea, 1, "FF FF FF FF 08 00 00 00 00 00 00 00");
    if (ea == BADADDR)
      break;
	MakeName(ea - 4, "offsets_table");
	create_qword(ea - 4);
	make_array(ea - 4, 0);
	  break;
	ea = ea + 4;
	
	}
	for ( ea = SegByName("LOAD"); ea != BADADDR;) {
    ea = FindBinary(ea, 1, "FF FF FF FF 08 00 00 00 00 00 00 00");
    if (ea == BADADDR)
      break;
	create_qword(ea - 4);
	make_array(ea - 4, 1);
	ea = ea + 4;
	}
	
	for ( ea = SegByName("LOAD"); ea != BADADDR;) {
    ea = FindBinary(ea, 1, "FF FF FF FF 08 00 00 00 00 00 00 00");
    if (ea == BADADDR)
      break;
	create_qword(ea + 4);
	make_array(ea + 4, 1);
	ea = ea + 4;
	}
	
	for ( ea = SegByName("LOAD"); ea != BADADDR;) {
    ea = FindBinary(ea, 1, "FF FF FF FF 08 00 00 00 00 00 00 00");
    if (ea == BADADDR)
      break;
	create_qword(ea + 12);
	make_array(ea + 12, 1);
	ea = ea + 4;
	}
	
}