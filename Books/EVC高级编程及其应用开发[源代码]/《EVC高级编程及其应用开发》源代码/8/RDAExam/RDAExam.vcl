<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: RDAExam - Win32 (WCE x86) Debug--------------------
</h3>
<h3>Command Lines</h3>
Creating command line "rc.exe /l 0x804 /fo"X86Dbg/RDAExam.res" /d UNDER_CE=400 /d _WIN32_WCE=400 /d "UNICODE" /d "_UNICODE" /d "DEBUG" /d "WCE_PLATFORM_STANDARDSDK" /d "_X86_" /d "x86" /d "_i386_" /d "_AFXDLL" /r "K:\系统开发\wince\《EVC高级编程及其应用开发》源代码-2676\8\RDAExam\RDAExam.rc"" 
Creating temporary file "C:\DOCUME~1\ds\LOCALS~1\Temp\RSP98.tmp" with contents
[
/nologo /W3 /Zi /Od /D "DEBUG" /D "_i386_" /D UNDER_CE=400 /D _WIN32_WCE=400 /D "WCE_PLATFORM_STANDARDSDK" /D "UNICODE" /D "_UNICODE" /D "_X86_" /D "x86" /D "_WIN32_WCE_CEPC" /D "_AFXDLL" /FR"X86Dbg/" /Fp"X86Dbg/RDAExam.pch" /Yu"stdafx.h" /Fo"X86Dbg/" /Fd"X86Dbg/" /Gs8192 /GF /c 
"K:\系统开发\wince\《EVC高级编程及其应用开发》源代码-2676\8\RDAExam\DlgPull.cpp"
"K:\系统开发\wince\《EVC高级编程及其应用开发》源代码-2676\8\RDAExam\DlgPush.cpp"
"K:\系统开发\wince\《EVC高级编程及其应用开发》源代码-2676\8\RDAExam\DlgSubmit.cpp"
"K:\系统开发\wince\《EVC高级编程及其应用开发》源代码-2676\8\RDAExam\RDAExam.cpp"
"K:\系统开发\wince\《EVC高级编程及其应用开发》源代码-2676\8\RDAExam\RDAExamDlg.cpp"
]
Creating command line "cl.exe @C:\DOCUME~1\ds\LOCALS~1\Temp\RSP98.tmp" 
Creating temporary file "C:\DOCUME~1\ds\LOCALS~1\Temp\RSP99.tmp" with contents
[
/nologo /W3 /Zi /Od /D "DEBUG" /D "_i386_" /D UNDER_CE=400 /D _WIN32_WCE=400 /D "WCE_PLATFORM_STANDARDSDK" /D "UNICODE" /D "_UNICODE" /D "_X86_" /D "x86" /D "_WIN32_WCE_CEPC" /D "_AFXDLL" /FR"X86Dbg/" /Fp"X86Dbg/RDAExam.pch" /Yc"stdafx.h" /Fo"X86Dbg/" /Fd"X86Dbg/" /Gs8192 /GF /c 
"K:\系统开发\wince\《EVC高级编程及其应用开发》源代码-2676\8\RDAExam\StdAfx.cpp"
]
Creating command line "cl.exe @C:\DOCUME~1\ds\LOCALS~1\Temp\RSP99.tmp" 
Creating temporary file "C:\DOCUME~1\ds\LOCALS~1\Temp\RSP9A.tmp" with contents
[
ca_mergex20.lib /nologo /base:"0x00010000" /stack:0x10000,0x1000 /entry:"wWinMainCRTStartup" /incremental:yes /pdb:"X86Dbg/RDAExam.pdb" /debug /out:"X86Dbg/RDAExam.exe" /subsystem:windowsce,4.00 /MACHINE:IX86 
".\X86Dbg\DlgPull.obj"
".\X86Dbg\DlgPush.obj"
".\X86Dbg\DlgSubmit.obj"
".\X86Dbg\RDAExam.obj"
".\X86Dbg\RDAExamDlg.obj"
".\X86Dbg\StdAfx.obj"
".\X86Dbg\RDAExam.res"
]
Creating command line "link.exe @C:\DOCUME~1\ds\LOCALS~1\Temp\RSP9A.tmp"
<h3>Output Window</h3>
Compiling resources...
Compiling...
StdAfx.cpp
Compiling...
DlgPull.cpp
DlgPush.cpp
DlgSubmit.cpp
RDAExam.cpp
K:\系统开发\wince\《EVC高级编程及其应用开发》源代码-2676\8\RDAExam\RDAExamDlg.h(11) : fatal error C1083: Cannot open include file: 'ca_mergex20.h': No such file or directory
RDAExamDlg.cpp
K:\系统开发\wince\《EVC高级编程及其应用开发》源代码-2676\8\RDAExam\RDAExamDlg.h(11) : fatal error C1083: Cannot open include file: 'ca_mergex20.h': No such file or directory
Generating Code...
Error executing cl.exe.
Creating command line "bscmake.exe /nologo /o"X86Dbg/RDAExam.bsc"  ".\X86Dbg\StdAfx.sbr" ".\X86Dbg\DlgPull.sbr" ".\X86Dbg\DlgPush.sbr" ".\X86Dbg\DlgSubmit.sbr" ".\X86Dbg\RDAExam.sbr" ".\X86Dbg\RDAExamDlg.sbr""
Creating browse info file...
BSCMAKE: error BK1506 : cannot open file '.\X86Dbg\RDAExam.sbr': No such file or directory
Error executing bscmake.exe.
<h3>Output Window</h3>



<h3>Results</h3>
RDAExam.exe - 3 error(s), 0 warning(s)
</pre>
</body>
</html>
