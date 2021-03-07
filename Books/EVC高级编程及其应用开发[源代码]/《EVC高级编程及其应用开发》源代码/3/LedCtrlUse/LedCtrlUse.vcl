<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: LedCtrlUse - Win32 (WCE ARMV4) Debug--------------------
</h3>
<h3>Command Lines</h3>
Creating command line "rc.exe /l 0x804 /fo"ARMV4Dbg/LedCtrlUse.res" /d UNDER_CE=410 /d _WIN32_WCE=410 /d "DEBUG" /d "UNICODE" /d "_UNICODE" /d "WCE_PLATFORM_SA_IA" /d "ARM" /d "_ARM_" /d "ARMV4" /d "_AFXDLL" /r "K:\系统开发1\wince\《EVC高级编程及其应用开发》源代码-2676\3\LedCtrlUse\LedCtrlUse.rc"" 
Creating temporary file "C:\DOCUME~1\ds\LOCALS~1\Temp\RSP3D.tmp" with contents
[
/nologo /W3 /Zi /Od /D "DEBUG" /D "ARM" /D "_ARM_" /D "ARMV4" /D UNDER_CE=410 /D _WIN32_WCE=410 /D "WCE_PLATFORM_SA_IA" /D "UNICODE" /D "_UNICODE" /D "_AFXDLL" /Fp"ARMV4Dbg/LedCtrlUse.pch" /Yu"stdafx.h" /Fo"ARMV4Dbg/" /Fd"ARMV4Dbg/" /Gs8192 /GF /c 
"K:\系统开发1\wince\《EVC高级编程及其应用开发》源代码-2676\3\LedCtrlUse\LedCtrl.cpp"
"K:\系统开发1\wince\《EVC高级编程及其应用开发》源代码-2676\3\LedCtrlUse\LedCtrlUse.cpp"
"K:\系统开发1\wince\《EVC高级编程及其应用开发》源代码-2676\3\LedCtrlUse\LedCtrlUseDlg.cpp"
]
Creating command line "clarm.exe @C:\DOCUME~1\ds\LOCALS~1\Temp\RSP3D.tmp" 
Creating temporary file "C:\DOCUME~1\ds\LOCALS~1\Temp\RSP3E.tmp" with contents
[
/nologo /W3 /Zi /Od /D "DEBUG" /D "ARM" /D "_ARM_" /D "ARMV4" /D UNDER_CE=410 /D _WIN32_WCE=410 /D "WCE_PLATFORM_SA_IA" /D "UNICODE" /D "_UNICODE" /D "_AFXDLL" /Fp"ARMV4Dbg/LedCtrlUse.pch" /Yc"stdafx.h" /Fo"ARMV4Dbg/" /Fd"ARMV4Dbg/" /Gs8192 /GF /c 
"K:\系统开发1\wince\《EVC高级编程及其应用开发》源代码-2676\3\LedCtrlUse\StdAfx.cpp"
]
Creating command line "clarm.exe @C:\DOCUME~1\ds\LOCALS~1\Temp\RSP3E.tmp" 
Creating temporary file "C:\DOCUME~1\ds\LOCALS~1\Temp\RSP3F.tmp" with contents
[
/nologo /base:"0x00010000" /stack:0x10000,0x1000 /entry:"wWinMainCRTStartup" /incremental:yes /pdb:"ARMV4Dbg/LedCtrlUse.pdb" /debug /nodefaultlib:"libc.lib /nodefaultlib:libcd.lib /nodefaultlib:libcmt.lib /nodefaultlib:libcmtd.lib /nodefaultlib:msvcrt.lib /nodefaultlib:msvcrtd.lib" /out:"ARMV4Dbg/LedCtrlUse.exe" /subsystem:windowsce,4.10 /MACHINE:IX86 
".\ARMV4Dbg\LedCtrl.obj"
".\ARMV4Dbg\LedCtrlUse.obj"
".\ARMV4Dbg\LedCtrlUseDlg.obj"
".\ARMV4Dbg\StdAfx.obj"
".\ARMV4Dbg\LedCtrlUse.res"
]
Creating command line "link.exe @C:\DOCUME~1\ds\LOCALS~1\Temp\RSP3F.tmp"
<h3>Output Window</h3>
Compiling resources...
Compiling...
Command line warning D4002 : ignoring unknown option '/Gs8192'
StdAfx.cpp
Compiling...
Command line warning D4002 : ignoring unknown option '/Gs8192'
LedCtrl.cpp
LedCtrlUse.cpp
LedCtrlUseDlg.cpp
Generating Code...
Linking...
.\ARMV4Dbg\LedCtrl.obj : fatal error LNK1112: module machine type 'ARM' conflicts with target machine type 'X86'
Error executing link.exe.



<h3>Results</h3>
LedCtrlUse.exe - 1 error(s), 2 warning(s)
</pre>
</body>
</html>
