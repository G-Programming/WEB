<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: RASDemo - Win32 (WCE x86) Debug--------------------
</h3>
<h3>Command Lines</h3>
Creating temporary file "C:\DOCUME~1\ADMINI~1\LOCALS~1\Temp\RSP1D.tmp" with contents
[
/nologo /W3 /Zi /Od /D "DEBUG" /D "_i386_" /D UNDER_CE=300 /D _WIN32_WCE=300 /D "WIN32_PLATFORM_PSPC=310" /D "UNICODE" /D "_UNICODE" /D "_X86_" /D "x86" /D "_WIN32_WCE_CEPC" /D "_AFXDLL" /FR"X86Dbg/" /Fp"X86Dbg/RASDemo.pch" /Yu"stdafx.h" /Fo"X86Dbg/" /Fd"X86Dbg/" /Gs8192 /GF /c 
"D:\工作项目\EVC编程入门及项目开发\例子程序\RASDemo\CERAS.cpp"
"D:\工作项目\EVC编程入门及项目开发\例子程序\RASDemo\RASDemo.cpp"
"D:\工作项目\EVC编程入门及项目开发\例子程序\RASDemo\RASDemoDlg.cpp"
]
Creating command line "cl.exe @C:\DOCUME~1\ADMINI~1\LOCALS~1\Temp\RSP1D.tmp" 
Creating temporary file "C:\DOCUME~1\ADMINI~1\LOCALS~1\Temp\RSP1E.tmp" with contents
[
/nologo /base:"0x00010000" /stack:0x10000,0x1000 /entry:"wWinMainCRTStartup" /incremental:yes /pdb:"X86Dbg/RASDemo.pdb" /debug /out:"X86Dbg/RASDemo.exe" /subsystem:windowsce,3.00 /MACHINE:IX86 
".\X86Dbg\CERAS.obj"
".\X86Dbg\RASDemo.obj"
".\X86Dbg\RASDemoDlg.obj"
".\X86Dbg\StdAfx.obj"
".\X86Dbg\RASDemo.res"
]
Creating command line "link.exe @C:\DOCUME~1\ADMINI~1\LOCALS~1\Temp\RSP1E.tmp"
<h3>Output Window</h3>
Compiling...
CERAS.cpp
RASDemo.cpp
RASDemoDlg.cpp
Generating Code...
Linking...
Creating command line "bscmake.exe /nologo /o"X86Dbg/RASDemo.bsc"  ".\X86Dbg\StdAfx.sbr" ".\X86Dbg\CERAS.sbr" ".\X86Dbg\RASDemo.sbr" ".\X86Dbg\RASDemoDlg.sbr""
Creating browse info file...
<h3>Output Window</h3>



<h3>Results</h3>
RASDemo.exe - 0 error(s), 0 warning(s)
</pre>
</body>
</html>
