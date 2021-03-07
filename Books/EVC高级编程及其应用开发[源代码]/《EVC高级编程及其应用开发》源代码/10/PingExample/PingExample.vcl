<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: PingExample - Win32 (WCE x86) Debug--------------------
</h3>
<h3>Command Lines</h3>
Creating temporary file "C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP9B.tmp" with contents
[
/nologo /W3 /Zi /Od /D "DEBUG" /D "_i386_" /D UNDER_CE=300 /D _WIN32_WCE=300 /D "WIN32_PLATFORM_PSPC=310" /D "UNICODE" /D "_UNICODE" /D "_X86_" /D "x86" /D "_WIN32_WCE_CEPC" /D "_AFXDLL" /FR"X86Dbg/" /Fp"X86Dbg/PingExample.pch" /Yu"stdafx.h" /Fo"X86Dbg/" /Fd"X86Dbg/" /Gs8192 /GF /c 
"F:\工作项目\EVC编程入门及项目开发\例子程序\7\PingExample\PingExample.cpp"
"F:\工作项目\EVC编程入门及项目开发\例子程序\7\PingExample\PingExampleDlg.cpp"
]
Creating command line "cl.exe @C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP9B.tmp" 
Creating temporary file "C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP9C.tmp" with contents
[
Winsock.lib icmplib.lib /nologo /base:"0x00010000" /stack:0x10000,0x1000 /entry:"wWinMainCRTStartup" /incremental:yes /pdb:"X86Dbg/PingExample.pdb" /debug /out:"X86Dbg/PingExample.exe" /subsystem:windowsce,3.00 /MACHINE:IX86 
".\X86Dbg\PingExample.obj"
".\X86Dbg\PingExampleDlg.obj"
".\X86Dbg\StdAfx.obj"
".\X86Dbg\PingExample.res"
]
Creating command line "link.exe @C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP9C.tmp"
<h3>Output Window</h3>
Compiling...
PingExample.cpp
PingExampleDlg.cpp
Generating Code...
Linking...
Creating command line "bscmake.exe /nologo /o"X86Dbg/PingExample.bsc"  ".\X86Dbg\StdAfx.sbr" ".\X86Dbg\PingExample.sbr" ".\X86Dbg\PingExampleDlg.sbr""
Creating browse info file...
<h3>Output Window</h3>




<h3>Results</h3>
PingExample.exe - 0 error(s), 0 warning(s)
</pre>
</body>
</html>
