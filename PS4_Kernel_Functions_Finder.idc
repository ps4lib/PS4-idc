#include <idc.idc>
//Experimental. Can be not reliable, nothing can replace manual analyze. 

static main() {
  auto ea;

  for ( ea = SegByName("LOAD"); ea != BADADDR;) {
    ea = FindBinary(ea, 1, "55 48 89");
    if (ea == BADADDR)
      break;
     MakeUnkn(ea, 2000);
	 MakeCode(ea);
	 MakeFunction(ea, BADADDR);
    ea = ea + 4;
  }
  
  for ( ea = 0; ea != BADADDR;) {
    ea = FindBinary(ea, 1, "0F 01 F8 65 48 89 24 25 A8 02 00 00 65 48 8B 24");
    if (ea == BADADDR)
      break;
     //MakeUnkn(ea, 1000);
	 //MakeCode(ea);
	   MakeFunction(ea, BADADDR);
	   MakeName(ea, "Xfast_syscall");
    ea = ea + 4;
  }
  
  for ( ea = SegByName("LOAD"); ea != BADADDR;) {
    ea = FindBinary(ea, 1, "48 81 EC A8 00 00 00");
    if (ea == BADADDR)
      break;
     //MakeUnkn(ea, 1000);
	 MakeCode(ea);
	 MakeFunction(ea, BADADDR);
    ea = ea + 4;
  }
  
  for ( ea = SegByName("LOAD"); ea != BADADDR;) {
    ea = FindBinary(ea, 1, "B8 2D 00 00 00 C3");
    if (ea == BADADDR)
      break;
     //MakeUnkn(ea, 1000);
	 //MakeCode(ea);
	 MakeFunction(ea, BADADDR);
    ea = ea + 4;
  }
  
  for ( ea = SegByName("LOAD"); ea != BADADDR;) {
    ea = FindBinary(ea, 1, "31 C0 C3");
    if (ea == BADADDR)
      break;
     //MakeUnkn(ea, 1000);
	 //MakeCode(ea);
	 MakeFunction(ea, BADADDR);
    ea = ea + 4;
  }
  
}
