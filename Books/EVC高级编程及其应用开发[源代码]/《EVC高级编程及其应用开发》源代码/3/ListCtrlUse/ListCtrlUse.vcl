<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: ListCtrlUse - Win32 (WCE ARMV4) Debug--------------------
</h3>
<h3>Command Lines</h3>
Creating command line "rc.exe /l 0x804 /fo"ARMV4Dbg/ListCtrlUse.res" /d UNDER_CE=410 /d _WIN32_WCE=410 /d "DEBUG" /d "UNICODE" /d "_UNICODE" /d "WCE_PLATFORM_SA_IA" /d "ARM" /d "_ARM_" /d "ARMV4" /d "_AFXDLL" /r "K:\系统开发1\wince\《EVC高级编程及其应用开发》源代码-2676\3\ListCtrlUse\ListCtrlUse.rc"" 
Creating temporary file "C:\DOCUME~1\ds\LOCALS~1\Temp\RSP9B.tmp" with contents
[
/nologo /W3 /Zi /Od /D "DEBUG" /D "ARM" /D "_ARM_" /D "ARMV4" /D UNDER_CE=410 /D _WIN32_WCE=410 /D "WCE_PLATFORM_SA_IA" /D "UNICODE" /D "_UNICODE" /D "_AFXDLL" /FR"ARMV4Dbg/" /Fp"ARMV4Dbg/ListCtrlUse.pch" /Yu"stdafx.h" /Fo"ARMV4Dbg/" /Fd"ARMV4Dbg/" /Gs8192 /GF /c 
"K:\系统开发1\wince\《EVC高级编程及其应用开发》源代码-2676\3\ListCtrlUse\ListCtrlAttr.cpp"
"K:\系统开发1\wince\《EVC高级编程及其应用开发》源代码-2676\3\ListCtrlUse\ListCtrlUse.cpp"
"K:\系统开发1\wince\《EVC高级编程及其应用开发》源代码-2676\3\ListCtrlUse\ListCtrlUseDlg.cpp"
]
Creating command line "clarm.exe @C:\DOCUME~1\ds\LOCALS~1\Temp\RSP9B.tmp" 
Creating temporary file "C:\DOCUME~1\ds\LOCALS~1\Temp\RSP9C.tmp" with contents
[
/nologo /W3 /Zi /Od /D "DEBUG" /D "ARM" /D "_ARM_" /D "ARMV4" /D UNDER_CE=410 /D _WIN32_WCE=410 /D "WCE_PLATFORM_SA_IA" /D "UNICODE" /D "_UNICODE" /D "_AFXDLL" /FR"ARMV4Dbg/" /Fp"ARMV4Dbg/ListCtrlUse.pch" /Yc"stdafx.h" /Fo"ARMV4Dbg/" /Fd"ARMV4Dbg/" /Gs8192 /GF /c 
"K:\系统开发1\wince\《EVC高级编程及其应用开发》源代码-2676\3\ListCtrlUse\StdAfx.cpp"
]
Creating command line "clarm.exe @C:\DOCUME~1\ds\LOCALS~1\Temp\RSP9C.tmp" 
Creating temporary file "C:\DOCUME~1\ds\LOCALS~1\Temp\RSP9D.tmp" with contents
[
/nologo /base:"0x00010000" /stack:0x10000,0x1000 /entry:"wWinMainCRTStartup" /incremental:yes /pdb:"ARMV4Dbg/ListCtrlUse.pdb" /debug /nodefaultlib:"libc.lib /nodefaultlib:libcd.lib /nodefaultlib:libcmt.lib /nodefaultlib:libcmtd.lib /nodefaultlib:msvcrt.lib /nodefaultlib:msvcrtd.lib" /out:"ARMV4Dbg/ListCtrlUse.exe" /subsystem:windowsce,4.10 /MACHINE:IX86 
".\ARMV4Dbg\ListCtrlAttr.obj"
".\ARMV4Dbg\ListCtrlUse.obj"
".\ARMV4Dbg\ListCtrlUse.res"
".\ARMV4Dbg\ListCtrlUseDlg.obj"
".\ARMV4Dbg\StdAfx.obj"
]
Creating command line "link.exe @C:\DOCUME~1\ds\LOCALS~1\Temp\RSP9D.tmp"
<h3>Output Window</h3>
Compiling resources...
Compiling...
Command line warning D4002 : ignoring unknown option '/Gs8192'
StdAfx.cpp
Compiling...
Command line warning D4002 : ignoring unknown option '/Gs8192'
ListCtrlAttr.cpp
ListCtrlUse.cpp
ListCtrlUseDlg.cpp
Generating Code...
Linking...
.\ARMV4Dbg\ListCtrlAttr.obj : fatal error LNK1112: module machine type 'ARM' conflicts with target machine type 'X86'
Error executing link.exe.
Creating command line "bscmake.exe /nologo /o"ARMV4Dbg/ListCtrlUse.bsc"  ".\ARMV4Dbg\StdAfx.sbr" ".\ARMV4Dbg\ListCtrlAttr.sbr" ".\ARMV4Dbg\ListCtrlUse.sbr" ".\ARMV4Dbg\ListCtrlUseDlg.sbr""
Creating browse info file...
<h3>Output Window</h3>



<h3>Results</h3>
ListCtrlUse.exe - 1 error(s), 2 warning(s)
</pre>
</body>
</html>
