# 컴파일러 및 플래그 설정(Github Action을 위한 경로)
CXX = g++
CURL-MINGW = C:/ProgramData/chocolatey/lib/curl/tools/curl-8.13.0_1-win64-mingw/include
CXXFLAGS = -std=c++17 -Iinclude -I"$(CURL-MINGW)/include" -static
LDFLAGS = -static -L"$(CURL-MINGW)/lib" -lcurl

# 소스 파일 및 타겟 설정
SRC = src/main.cpp src/downloader.cpp src/file_utils.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = build/main.exe

# 기본 빌드 타겟
all: $(TARGET)

# 실행 파일 생성
$(TARGET): $(OBJ)
	mkdir -p build
	$(CXX) -o $@ $(OBJ) $(LDFLAGS)

# 개별 소스 파일 컴파일
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 클린 타겟
clean:
	rm -rf $(OBJ) $(TARGET)