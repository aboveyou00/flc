#pragma once

//Arithmetic
#include "AddInstr.h"
#include "AndInstr.h"
#include "DivInstr.h"
#include "MulInstr.h"
#include "NegInstr.h"
#include "NotInstr.h"
#include "OrInstr.h"
#include "RemInstr.h"
#include "ShlInstr.h"
#include "ShrInstr.h"
#include "SubInstr.h"
#include "XorInstr.h"

//Branch

//Compare
#include "CeqInstr.h"
#include "CgtInstr.h"
#include "CkfiniteInstr.h"
#include "CltInstr.h"

//Constant
#include "LdcI4Instr.h"
#include "LdcI8Instr.h"
#include "LdcR4Instr.h"
#include "LdcR8Instr.h"
#include "LdnullInstr.h"
#include "LdstrInstr.h"

//Convert
#include "BoxInstr.h"
#include "ConvI1Instr.h"
#include "ConvI2Instr.h"
#include "ConvI4Instr.h"
#include "ConvI8Instr.h"
#include "ConvIInstr.h"
#include "ConvR4Instr.h"
#include "ConvR8Instr.h"

//Misc
#include "BreakInstr.h"
#include "NopInstr.h"

//Stack
#include "DupInstr.h"
#include "PopInstr.h"



//Unimplemented:



//FE 00        arglist
//FE 06 <T>    ldftn <method>
//FE 07 <T>    ldvirtftn <method>
//FE 0F        localloc
//FE 11        endfilter
//FE 15 <T>    initobj <type>
//FE 17        cpblk
//FE 18        initblk
//FE 1A        rethrow
//FE 1A <T>    sizeof <type>
//FE 1D        refanytype
//DC           endfault;   endfinally
//DD <int32>   leave <target>
//DE <int8>    leave.s <target>
//C2 <T>       refanyval <type>
//C6 <T>       mkrefany <class>
//D0 <T>       ldtoken <token>
//70 <T>       cpobj <type>
//71 <T>       ldobj <type>
//81 <T>       stobj <type>



//27 <T>   jmp <method>
//28 <T>   call <method>
//29 <T>   calli <callsitedescr>
//2A       ret
//6F <T>   callvirt <method>



//45 <uint32> <int32 ...>   switch <t1> <t2> <t3...> <tN>



//76   conv.r.un



//FE 09 <uint16>   ldarg <num>
//FE 0A <uint16>   ldarga <num>
//0E <uint8>       ldarg.s <num>
//0F <uint8>       ldarga.s <num>
//02               ldarg.0
//03               ldarg.1
//04               ldarg.2
//05               ldarg.3

//FE 0B <uint16>   starg <num>
//10 <uint8>       starg.s <num>



//FE 0C <uint16>   ldloc <idx>
//FE 0D <uint16>   ldloca <idx>
//11 <uint8>       ldloc.s <idx>
//12 <uint8>       ldloca.s <idx>
//06               ldloc.0
//07               ldloc.1
//08               ldloc.2
//09               ldloc.3

//FE 0E <uint16>   stloc <idx>
//13 <uint8>       stloc.s <idx>
//0A               stloc.0
//0B               stloc.1
//0C               stloc.2
//0D               stloc.3



//73 <T>   newobj <ctor>
//74 <T>   castclass <type>
//75 <T>   isinst <type>
//79 <T>   unbox <valuetype>
//A5 <T>   unbox.any <type>
//7A       throw



//7B <T>   ldfld <field>
//7C <T>   ldflda <field>
//7E <T>   ldsfld <field>
//7F <T>   ldsflda <field>

//7D <T>   stfld <field>
//80 <T>   stsfld <field>



//46   ldind.i1
//48   ldind.i2
//4A   ldind.i4
//4C   ldind.i8
//47   ldind.u1
//49   ldind.u2
//4B   ldind.u4
//4E   ldind.r4
//4C   ldind.u8
//4F   ldind.r8
//4D   ldind.i
//50   ldind.ref

//52   stind.i1
//53   stind.i2
//54   stind.i4
//55   stind.i8
//56   stind.r4
//57   stind.r8
//DF   stind.i
//51   stind.ref



//8D       newarr <type>
//8E       ldlen

//A3 <T>   ldelem <type>
//8F <T>   ldelema <type>
//90       ldelem.i1
//92       ldelem.i2
//94       ldelem.i4
//96       ldelem.i8;   ldelem.u8
//91       ldelem.u1
//93       ldelem.u2
//95       ldelem.u4
//98       ldelem.r4
//99       ldelem.r8
//97       ldelem.i
//9A       ldelem.ref

//A4 <T>   stelem <type>
//9C       stelem.i1
//9D       stelem.i2
//9E       stelem.i4
//9F       stelem.i8
//A0       stelem.r4
//A1       stelem.r8
//9B       stelem.i
//A2       stelem.ref
