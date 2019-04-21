//Use only on fixed full dumps that have segment 2, and 3 edited correctly in dump header!
//Change "82 FF FF FF FF" to correspond your base address start.
//For example for 0xFFFFFFFFCFXXXXXX base it will be "CF FF FF FF FF"
//Then 83 to D0,, 84 to D1, etc. That fix all pointers that we got after fixing kernel.
//Only cons is that you can't rebase kernel, before, or after.

#include <idc.idc>
#define create_qword(ea)    create_data(ea, FF_QWORD, 8, BADADDR)

static main() {
  auto ea;
  
  for ( ea = 0; ea != BADADDR;) {
    ea = FindBinary(ea, 1, "82 FF FF FF FF");
    if (ea == BADADDR)
      break;
       create_qword(ea - 3);
       op_offset(ea -3, 1, 9, -1, 0, 0);
    ea = ea + 4;
  }
  
  for ( ea = 0; ea != BADADDR;) {
    ea = FindBinary(ea, 1, "83 FF FF FF FF");
    if (ea == BADADDR)
      break;
       create_qword(ea - 3);
       op_offset(ea -3, 1, 9, -1, 0, 0);
    ea = ea + 4;
  }
  
  for ( ea = 0; ea != BADADDR;) {
    ea = FindBinary(ea, 1, "84 FF FF FF FF");
    if (ea == BADADDR)
      break;
       create_qword(ea - 3);
       op_offset(ea -3, 1, 9, -1, 0, 0);
    ea = ea + 4;
  }
  
  for ( ea = 0; ea != BADADDR;) {
    ea = FindBinary(ea, 1, "85 FF FF FF FF");
    if (ea == BADADDR)
      break;
       create_qword(ea - 3);
       op_offset(ea -3, 1, 9, -1, 0, 0);
    ea = ea + 4;
  }
  
}
