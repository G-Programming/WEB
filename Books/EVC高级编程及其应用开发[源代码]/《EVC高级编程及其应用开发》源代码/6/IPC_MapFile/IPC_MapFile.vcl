<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: IPC_MapFile - Win32 (WCE x86) Debug--------------------
</h3>
<h3>Command Lines</h3>
Creating temporary file "C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP2CD.tmp" with contents
[
/nologo /W3 /Zi /Od /D "DEBUG" /D "_i386_" /D UNDER_CE=300 /D _WIN32_WCE=300 /D "WIN32_PLATFORM_PSPC=310" /D "UNICODE" /D "_UNICODE" /D "_X86_" /D "x86" /D "_WIN32_WCE_CEPC" /D "_AFXDLL" /FR"X86Dbg/" /Fp"X86Dbg/IPC_MapFile.pch" /Yu"stdafx.h" /Fo"X86Dbg/" /Fd"X86Dbg/" /Gs8192 /GF /c 
"F:\工作项目\EVC编程入门及项目开发\例子程序\5\IPC_MapFile\IPC_MapFile.cpp"
"F:\工作项目\EVC编程入门及项目开发\例子程序\5\IPC_MapFile\IPC_MapFileDlg.cpp"
"F:\工作项目\EVC编程入门及项目开发\例子程序\5\IPC_MapFile\MemFileMap.cpp"
]
Creating command line "cl.exe @C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP2CD.tmp" 
Creating temporary file "C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP2CE.tmp" with contents
[
/nologo /W3 /Zi /Od /D "DEBUG" /D "_i386_" /D UNDER_CE=300 /D _WIN32_WCE=300 /D "WIN32_PLATFORM_PSPC=310" /D "UNICODE" /D "_UNICODE" /D "_X86_" /D "x86" /D "_WIN32_WCE_CEPC" /D "_AFXDLL" /FR"X86Dbg/" /Fp"X86Dbg/IPC_MapFile.pch" /Yc"stdafx.h" /Fo"X86Dbg/" /Fd"X86Dbg/" /Gs8192 /GF /c 
"F:\工作项目\EVC编程入门及项目开发\例子程序\5\IPC_MapFile\StdAfx.cpp"
]
Creating command line "cl.exe @C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP2CE.tmp" 
Creating temporary file "C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP2CF.tmp" with contents
[
/nologo /base:"0x00010000" /stack:0x10000,0x1000 /entry:"wWinMainCRTStartup" /incremental:yes /pdb:"X86Dbg/IPC_MapFile.pdb" /debug /out:"X86Dbg/IPC_MapFile.exe" /subsystem:windowsce,3.00 /MACHINE:IX86 
".\X86Dbg\IPC_MapFile.obj"
".\X86Dbg\IPC_MapFileDlg.obj"
".\X86Dbg\MemFileMap.obj"
".\X86Dbg\StdAfx.obj"
".\X86Dbg\IPC_MapFile.res"
]
Creating command line "link.exe @C:\DOCUME~1\wangbing\LOCALS~1\Temp\RSP2CF.tmp"
<h3>Output Window</h3>
Compiling...
StdAfx.cpp
Compiling...
IPC_MapFile.cpp
F:\工作项目\EVC编程入门及项目开发\例子程序\5\IPC_MapFile\MemFileMap.h(51) : error C2226: syntax error : unexpected type 'HANDLE'
F:\工作项目\EVC编程入门及项目开发\例子程序\5\IPC_MapFile\MemFileMap.h(53) : error C2238: unexpected token(s) preceding ';'
IPC_MapFileDlg.cpp
F:\工作项目\EVC编程入门及项目开发\例子程序\5\IPC_MapFile\MemFileMap.h(51) : error C2226: syntax error : unexpected type 'HANDLE'
F:\工作项目\EVC编程入门及项目开发\例子程序\5\IPC_MapFile\MemFileMap.h(53) : error C2238: unexpected token(s) preceding ';'
F:\工作项目\EVC编程入门及项目开发\例子程序\5\IPC_MapFile\IPC_MapFileDlg.cpp(104) : error C2039: 'OpenFileMap' : is not a member of 'CMemFileMap'
        F:\工作项目\EVC编程入门及项目开发\例子程序\5\IPC_MapFile\MemFileMap.h(17) : see declaration of 'CMemFileMap'
F:\工作项目\EVC编程入门及项目开发\例子程序\5\IPC_MapFile\IPC_MapFileDlg.cpp(168) : warning C4800: 'int' : forcing value to bool 'true' or 'false' (performance warning)
MemFileMap.cpp
F:\工作项目\EVC编程入门及项目开发\例子程序\5\IPC_MapFile\MemFileMap.h(51) : error C2226: syntax error : unexpected type 'HANDLE'
F:\工作项目\EVC编程入门及项目开发\例子程序\5\IPC_MapFile\MemFileMap.h(53) : error C2238: unexpected token(s) preceding ';'
F:\工作项目\EVC编程入门及项目开发\例子程序\5\IPC_MapFile\MemFileMap.cpp(57) : error C2039: 'OpenFileMap' : is not a member of 'CMemFileMap'
        F:\工作项目\EVC编程入门及项目开发\例子程序\5\IPC_MapFile\MemFileMap.h(17) : see declaration of 'CMemFileMap'
F:\工作项目\EVC编程入门及项目开发\例子程序\5\IPC_MapFile\MemFileMap.cpp(61) : error C2065: 'm_pParentWnd' : undeclared identifier
F:\工作项目\EVC编程入门及项目开发\例子程序\5\IPC_MapFile\MemFileMap.cpp(61) : error C2440: '=' : cannot convert from 'class CWnd *' to 'int'
        This conversion requires a reinterpret_cast, a C-style cast or function-style cast
F:\工作项目\EVC编程入门及项目开发\例子程序\5\IPC_MapFile\MemFileMap.cpp(63) : error C2065: 'm_hMapFile' : undeclared identifier
F:\工作项目\EVC编程入门及项目开发\例子程序\5\IPC_MapFile\MemFileMap.cpp(64) : error C2065: 'm_MaxSize' : undeclared identifier
F:\工作项目\EVC编程入门及项目开发\例子程序\5\IPC_MapFile\MemFileMap.cpp(64) : error C2065: 'm_MapName' : undeclared identifier
F:\工作项目\EVC编程入门及项目开发\例子程序\5\IPC_MapFile\MemFileMap.cpp(64) : error C2228: left of '.GetBuffer' must have class/struct/union type
F:\工作项目\EVC编程入门及项目开发\例子程序\5\IPC_MapFile\MemFileMap.cpp(64) : error C2228: left of '.GetLength' must have class/struct/union type
F:\工作项目\EVC编程入门及项目开发\例子程序\5\IPC_MapFile\MemFileMap.cpp(66) : error C2446: '==' : no conversion from 'void *' to 'int'
        This conversion requires a reinterpret_cast, a C-style cast or function-style cast
F:\工作项目\EVC编程入门及项目开发\例子程序\5\IPC_MapFile\MemFileMap.cpp(66) : error C2040: '==' : 'int' differs in levels of indirection from 'void *'
F:\工作项目\EVC编程入门及项目开发\例子程序\5\IPC_MapFile\MemFileMap.cpp(77) : error C2065: 'm_pMapPointer' : undeclared identifier
F:\工作项目\EVC编程入门及项目开发\例子程序\5\IPC_MapFile\MemFileMap.cpp(85) : error C2065: 'm_hSynEvent' : undeclared identifier
F:\工作项目\EVC编程入门及项目开发\例子程序\5\IPC_MapFile\MemFileMap.cpp(85) : error C2440: '=' : cannot convert from 'void *' to 'int'
        This conversion requires a reinterpret_cast, a C-style cast or function-style cast
F:\工作项目\EVC编程入门及项目开发\例子程序\5\IPC_MapFile\MemFileMap.cpp(95) : error C2065: 'm_SynMessageID' : undeclared identifier
Generating Code...
Error executing cl.exe.
Creating command line "bscmake.exe /nologo /o"X86Dbg/IPC_MapFile.bsc"  ".\X86Dbg\StdAfx.sbr" ".\X86Dbg\IPC_MapFile.sbr" ".\X86Dbg\IPC_MapFileDlg.sbr" ".\X86Dbg\MemFileMap.sbr""
Creating browse info file...
<h3>Output Window</h3>



<h3>Results</h3>
IPC_MapFile.exe - 21 error(s), 1 warning(s)
</pre>
</body>
</html>
