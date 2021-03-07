<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: TCPServer - Win32 (WCE x86) Debug--------------------
</h3>
<h3>Command Lines</h3>
Creating temporary file "C:\DOCUME~1\wb\LOCALS~1\Temp\RSP85.tmp" with contents
[
/nologo /W3 /Zi /Od /D "DEBUG" /D "_i386_" /D UNDER_CE=300 /D _WIN32_WCE=300 /D "WIN32_PLATFORM_PSPC=310" /D "UNICODE" /D "_UNICODE" /D "_X86_" /D "x86" /D "_WIN32_WCE_CEPC" /D "_AFXDLL" /FR"X86Dbg/" /Fp"X86Dbg/TCPServer.pch" /Yu"stdafx.h" /Fo"X86Dbg/" /Fd"X86Dbg/" /Gs8192 /GF /c 
"E:\工作项目\EVC编程入门及项目开发\例子程序\8\TCPServer\TCPCustom_CE.cpp"
"E:\工作项目\EVC编程入门及项目开发\例子程序\8\TCPServer\TCPServer_CE.cpp"
]
Creating command line "cl.exe @C:\DOCUME~1\wb\LOCALS~1\Temp\RSP85.tmp" 
Creating temporary file "C:\DOCUME~1\wb\LOCALS~1\Temp\RSP86.tmp" with contents
[
winsock.lib ole32.lib /nologo /base:"0x00010000" /stack:0x10000,0x1000 /entry:"wWinMainCRTStartup" /incremental:yes /pdb:"X86Dbg/TCPServer.pdb" /debug /out:"X86Dbg/TCPServer.exe" /subsystem:windowsce,3.00 /MACHINE:IX86 
".\X86Dbg\StdAfx.obj"
".\X86Dbg\TCPCustom_CE.obj"
".\X86Dbg\TCPServer.obj"
".\X86Dbg\TCPServer_CE.obj"
".\X86Dbg\TCPServerDlg.obj"
".\X86Dbg\TCPServer.res"
]
Creating command line "link.exe @C:\DOCUME~1\wb\LOCALS~1\Temp\RSP86.tmp"
<h3>Output Window</h3>
Compiling...
TCPCustom_CE.cpp
TCPServer_CE.cpp
Generating Code...
Linking...
Creating command line "bscmake.exe /nologo /o"X86Dbg/TCPServer.bsc"  ".\X86Dbg\StdAfx.sbr" ".\X86Dbg\TCPCustom_CE.sbr" ".\X86Dbg\TCPServer.sbr" ".\X86Dbg\TCPServer_CE.sbr" ".\X86Dbg\TCPServerDlg.sbr""
Creating browse info file...
<h3>Output Window</h3>




<h3>Results</h3>
TCPServer.exe - 0 error(s), 0 warning(s)
</pre>
</body>
</html>
