##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=wymemcached
ConfigurationName      :=Debug
WorkspacePath          := "C:\wuyang\workspace\CodeLite\hello"
ProjectPath            := "C:\wuyang\workspace\CodeLite\hello\wymemcached"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=wuy12
Date                   :=7/28/2013
CodeLitePath           :="C:\wuyang\tools\CodeLite"
LinkerName             :=gcc
SharedObjectLinkerName :=gcc -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="wymemcached.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=windres
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := gcc
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall -std=c++11 $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall -std=c99 $(Preprocessors)


##
## User defined environment variables
##
CodeLiteDir:=C:\wuyang\tools\CodeLite
WXWIN:=C:\wxWidgets-2.9.4
PATH:=$(WXWIN)\lib\gcc_dll;$(PATH)
WXCFG:=gcc_dll\mswu
UNIT_TEST_PP_SRC_DIR:=C:\UnitTest++-1.3
Objects0=$(IntermediateDirectory)/main$(ObjectSuffix) $(IntermediateDirectory)/hash$(ObjectSuffix) $(IntermediateDirectory)/slab$(ObjectSuffix) $(IntermediateDirectory)/item$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main$(ObjectSuffix): main.c $(IntermediateDirectory)/main$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/wuyang/workspace/CodeLite/hello/wymemcached/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main$(ObjectSuffix) -MF$(IntermediateDirectory)/main$(DependSuffix) -MM "main.c"

$(IntermediateDirectory)/main$(PreprocessSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main$(PreprocessSuffix) "main.c"

$(IntermediateDirectory)/hash$(ObjectSuffix): hash.c $(IntermediateDirectory)/hash$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/wuyang/workspace/CodeLite/hello/wymemcached/hash.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/hash$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/hash$(DependSuffix): hash.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/hash$(ObjectSuffix) -MF$(IntermediateDirectory)/hash$(DependSuffix) -MM "hash.c"

$(IntermediateDirectory)/hash$(PreprocessSuffix): hash.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/hash$(PreprocessSuffix) "hash.c"

$(IntermediateDirectory)/slab$(ObjectSuffix): slab.c $(IntermediateDirectory)/slab$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/wuyang/workspace/CodeLite/hello/wymemcached/slab.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/slab$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/slab$(DependSuffix): slab.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/slab$(ObjectSuffix) -MF$(IntermediateDirectory)/slab$(DependSuffix) -MM "slab.c"

$(IntermediateDirectory)/slab$(PreprocessSuffix): slab.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/slab$(PreprocessSuffix) "slab.c"

$(IntermediateDirectory)/item$(ObjectSuffix): item.c $(IntermediateDirectory)/item$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/wuyang/workspace/CodeLite/hello/wymemcached/item.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/item$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/item$(DependSuffix): item.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/item$(ObjectSuffix) -MF$(IntermediateDirectory)/item$(DependSuffix) -MM "item.c"

$(IntermediateDirectory)/item$(PreprocessSuffix): item.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/item$(PreprocessSuffix) "item.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/main$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/main$(DependSuffix)
	$(RM) $(IntermediateDirectory)/main$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/hash$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/hash$(DependSuffix)
	$(RM) $(IntermediateDirectory)/hash$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/slab$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/slab$(DependSuffix)
	$(RM) $(IntermediateDirectory)/slab$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/item$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/item$(DependSuffix)
	$(RM) $(IntermediateDirectory)/item$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) "../.build-debug/wymemcached"


