#pragma once

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



//3B <int32>   beq <target>
//2E <int8>    beq.s <target>
//3C <int32>   bge <target>
//2F <int8>    bge.s <target>
//41 <int32>   bge.un <target>
//34 <int8>    bge.un.s <target>
//3D <int32>   bgt <target>
//30 <int8>    bgt.s <target>
//42 <int32>   bgt.un <target>
//35 <int8>    bgt.un.s <target>
//3E <int32>   ble <target>
//31 <int8>    ble.s <target>
//43 <int32>   ble.un <target>
//36 <int8>    ble.un.s <target>
//3F <int32>   blt <target>
//32 <int8>    blt.s <target>
//44 <int32>   blt.un <target>
//37 <int8>    blt.un.s <target>
//40 <int32>   bne <target>
//33 <int8>    bne.s <target>
//38 <int32>   br <target>
//2B <int8>    br.s <target>
//39 <int32>   brfalse <target>;     brnull <target>;     brzero <target>
//2C <int8>    brfalse.s <target>;   brnull.s <target>;   brzero.s <target>
//3A <int32>   brtrue <target>;     brinst <target>;
//2D <int8>    brtrue.s <target>;   brinst.s <target>;

//45 <uint32> <int32 ...>   switch <t1> <t2> <t3...> <tN>



//72 <T>   ldstr <string>



//67   conv.i1
//B3   conv.ovf.i1
//82   conv.ovf.i1.un
//68   conv.i2
//B5   conv.ovf.i2
//83   conv.ovf.i2.un
//69   conv.i4
//B7   conv.ovf.i4
//84   conv.ovf.i4.un
//6A   conv.i8
//B9   conv.ovf.i8
//85   conv.ovf.i8.un
//6B   conv.r4
//6C   conv.r8
//D2   conv.u1
//B4   conv.ovf.u1
//86   conv.ovf.u1.un
//D1   conv.u2
//B6   conv.ovf.u2
//87   conv.ovf.u2.un
//6D   conv.u4
//B8   conv.ovf.u4
//88   conv.ovf.u4.un
//6E   conv.u8
//BA   conv.ovf.u8
//89   conv.ovf.u8.un
//D3   conv.i
//D4   conv.ovf.i
//8A   conv.ovf.i.un
//E0   conv.u
//D5   conv.ovf.u
//8B   conv.ovf.u.un
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



//21 <int64>     ldc.i8 <num>
//22 <float32>   ldc.r4 <num>
//23 <float64>   ldc.r8 <num>



//73 <T>   newobj <ctor>
//74 <T>   castclass <type>
//75 <T>   isinst <type>
//8C       box
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
