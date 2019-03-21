#include <idc.idc>

static main() {
  auto ea;

  for ( ea = 0; ea != BADADDR;) {
    ea = FindBinary(ea, 1, "55 48 89");
    if (ea == BADADDR)
      break;

    MakeFunction(ea, BADADDR);
    ea = ea + 4;
  }
}
