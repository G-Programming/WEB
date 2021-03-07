<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: ConnectionCom - Win32 (WCE x86) Debug--------------------
</h3>
<h3>Command Lines</h3>
Creating temporary file "C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP1AC.tmp" with contents
[
/nologo /W3 /Zi /Od /D "DEBUG" /D "_i386_" /D UNDER_CE=300 /D _WIN32_WCE=300 /D "_USRDLL" /D "WIN32_PLATFORM_PSPC=310" /D "UNICODE" /D "_UNICODE" /D "_X86_" /D "x86" /D "_WIN32_WCE_CEPC" /FR"X86Dbg/" /Fp"X86Dbg/ConnectionCom.pch" /Yu"stdafx.h" /Fo"X86Dbg/" /Fd"X86Dbg/" /Gs8192 /GF /c 
"F:\工作项目\EVC编程入门及项目开发\例子程序\9\ConnectionCom\Add.cpp"
]
Creating command line "cl.exe @C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP1AC.tmp" 
Creating temporary file "C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP1AD.tmp" with contents
[
/nologo /base:"0x00100000" /stack:0x10000,0x1000 /entry:"_DllMainCRTStartup" /dll /incremental:yes /pdb:"X86Dbg/ConnectionCom.pdb" /debug /def:".\ConnectionCom.def" /out:"X86Dbg/ConnectionCom.dll" /implib:"X86Dbg/ConnectionCom.lib" /subsystem:windowsce,3.00 /MACHINE:IX86 
".\X86Dbg\Add.obj"
".\X86Dbg\ConnectionCom.obj"
".\X86Dbg\StdAfx.obj"
".\X86Dbg\ConnectionCom.res"
]
Creating command line "link.exe @C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP1AD.tmp"
<h3>Output Window</h3>
Compiling...
Add.cpp
F:\工作项目\EVC编程入门及项目开发\例子程序\9\ConnectionCom\Add.cpp(12) : error C2065: 'AFX_MANAGE_STATE' : undeclared identifier
F:\工作项目\EVC编程入门及项目开发\例子程序\9\ConnectionCom\Add.cpp(12) : error C2065: 'AfxGetStaticModuleState' : undeclared identifier
F:\工作项目\EVC编程入门及项目开发\例子程序\9\ConnectionCom\Add.cpp(14) : error C2146: syntax error : missing ';' before identifier 'Sleep'
Error executing cl.exe.
Creating command line "bscmake.exe /nologo /o"X86Dbg/ConnectionCom.bsc"  ".\X86Dbg\StdAfx.sbr" ".\X86Dbg\Add.sbr" ".\X86Dbg\ConnectionCom.sbr""
Creating browse info file...
<h3>Output Window</h3>



<h3>Results</h3>
ConnectionCom.dll - 3 error(s), 0 warning(s)
</pre>
</body>
</html>
