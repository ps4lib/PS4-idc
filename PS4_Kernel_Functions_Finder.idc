#include <idc.idc>

//Experimental script to find more kernel functions. Use after initial auto analyze is done. 

static main() {
  auto ea;

  for ( ea = SegByName("LOAD"); ea != BADADDR;) {
    ea = FindBinary(ea, 1, "55 48 89");
    if (ea == BADADDR)
      break;
     MakeUnkn(ea, 0);
	 MakeCode(ea);
	 MakeFunction(ea, BADADDR);
    ea = ea + 4;
  }
  
  for ( ea = SegByName("LOAD"); ea != BADADDR;) {
    ea = FindBinary(ea, 1, "0F 01 F8 65 48 89 24 25 A8 02 00 00 65 48 8B 24");
    if (ea == BADADDR)
      break;
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
	 MakeFunction(ea, BADADDR);
    ea = ea + 4;
  }
  
  for ( ea = SegByName("LOAD"); ea != BADADDR;) {
    ea = FindBinary(ea, 1, "31 C0 C3");
    if (ea == BADADDR)
      break;
	 MakeFunction(ea, BADADDR);
    ea = ea + 4;
  }
  
  for ( ea = SegByName("LOAD"); ea != BADADDR;) {
    ea = FindBinary(ea, 1, "C5 FA 5A C0 C5 F2 5A C9 C5 EA 5A D2 C5 FB 59 C1");
    if (ea == BADADDR)
      break;
	 MakeCode(ea);
	 MakeFunction(ea, BADADDR);
    ea = ea + 4;
  }
  
  for ( ea = SegByName("LOAD"); ea != BADADDR;) {
    ea = FindBinary(ea, 1, "C5 F9 7E C0 31 C9");
    if (ea == BADADDR)
      break;
	 MakeFunction(ea, BADADDR);
    ea = ea + 4;
  }
  
	for ( ea = SegByName("LOAD"); ea != BADADDR;) {
    ea = FindBinary(ea, 1, "48 89 E0 55 53");
    if (ea == BADADDR)
      break;
	 MakeFunction(ea, BADADDR);
    ea = ea + 4;
	}
	
}
