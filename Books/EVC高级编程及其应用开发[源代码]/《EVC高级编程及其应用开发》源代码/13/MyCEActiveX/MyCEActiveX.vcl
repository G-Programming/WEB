<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: MyCEActiveX - Win32 (WCE x86) Debug--------------------
</h3>
<h3>Command Lines</h3>
Creating command line "midl.exe /nologo /D "_DEBUG" /tlb "X86Dbg/MyCEActiveX.tlb" /mktyplib203 /o "NUL" /win32 "F:\工作项目\EVC编程入门及项目开发\例子程序\9\MyCEActiveX\MyCEActiveX.odl""
Creating command line "rc.exe /l 0x409 /fo"X86Dbg/MyCEActiveX.res" /i "X86Dbg" /d UNDER_CE=300 /d _WIN32_WCE=300 /d "UNICODE" /d "_UNICODE" /d "DEBUG" /d "WIN32_PLATFORM_PSPC=310" /d "_X86_" /d "x86" /d "_i386_" /d "_AFXDLL" /r "F:\工作项目\EVC编程入门及项目开发\例子程序\9\MyCEActiveX\MyCEActiveX.rc"" 
Creating temporary file "C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP26C.tmp" with contents
[
/nologo /W3 /GX- /Zi /Od /D "DEBUG" /D "_i386_" /D UNDER_CE=300 /D _WIN32_WCE=300 /D "WIN32_PLATFORM_PSPC=310" /D "UNICODE" /D "_UNICODE" /D "_X86_" /D "x86" /D "_WIN32_WCE_CEPC" /D "_AFXDLL" /Fp"X86Dbg/MyCEActiveX.pch" /Yu"stdafx.h" /Fo"X86Dbg/" /Fd"X86Dbg/" /Gs8192 /GF  /c 
"F:\工作项目\EVC编程入门及项目开发\例子程序\9\MyCEActiveX\MyCEActiveXCtl.cpp"
]
Creating command line "cl.exe @C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP26C.tmp" 
Creating temporary file "C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP26D.tmp" with contents
[
/nologo /base:"0x00100000" /stack:0x10000,0x1000 /entry:"_DllMainCRTStartup" /dll /incremental:yes /pdb:"X86Dbg/MyCEActiveX.pdb" /debug /def:".\MyCEActiveX.def" /out:"X86Dbg/MyCEActiveX.ocx" /implib:"X86Dbg/MyCEActiveX.lib" /subsystem:windowsce,3.00 /MACHINE:IX86 
".\X86Dbg\StdAfx.obj"
".\X86Dbg\MyCEActiveX.obj"
".\X86Dbg\MyCEActiveX.res"
".\X86Dbg\MyCEActiveXCtl.obj"
".\X86Dbg\MyCEActiveXPpg.obj"
]
Creating command line "link.exe @C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP26D.tmp"
<h3>Output Window</h3>
Creating Type Library...
MyCEActiveX.odl
oaidl.idl
objidl.idl
unknwn.idl
wtypes.idl
Compiling resources...
Compiling...
MyCEActiveXCtl.cpp
Linking...




<h3>Results</h3>
MyCEActiveX.ocx - 0 error(s), 0 warning(s)
</pre>
</body>
</html>
