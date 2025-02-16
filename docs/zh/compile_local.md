# 如何在本地编译并安装 Paddle2ONNX

Paddle2ONNX 的编译安装至少需要确保环境满足以下需求：

- cmake >= 3.18.0
- protobuf == 3.16.0

## 在 Linux/Mac 下编译并安装

### 安装 Protobuf

```bash
git clone https://github.com/protocolbuffers/protobuf.git
cd protobuf
git checkout v3.16.0
mkdir build_source && cd build_source
cmake ../cmake -DCMAKE_INSTALL_PREFIX=${PWD}/installed_protobuf_lib -Dprotobuf_BUILD_SHARED_LIBS=OFF -DCMAKE_POSITION_INDEPENDENT_CODE=ON -Dprotobuf_BUILD_TESTS=OFF -DCMAKE_BUILD_TYPE=Release
make -j8
make install

# 将编译目录加入环境变量
export PATH=${PWD}/installed_protobuf_lib/bin:${PATH}
```

### 安装Paddle2ONNX

```bash
git clone https://github.com/PaddlePaddle/Paddle2ONNX.git
cd Paddle2ONNX
git submodule init
git submodule update

pip install setuptools wheel auditwheel auditwheel-symbols build
python -m build
pip install dist/*.whl
```

## Windows编译安装

注意Windows编译安装先验条件是系统中已安装好Visual Studio 2019

### 打开VS命令行工具

系统菜单中，找到**x64 Native Tools Command Prompt for VS 2019**打开

### 安装Protobuf

注意下面cmake命令中`-DCMAKE_INSTALL_PREFIX`指定为你实际设定的路径

```bash
git clone https://github.com/protocolbuffers/protobuf.git
cd protobuf
git checkout v3.16.0
cd cmake
cmake -G "Visual Studio 16 2019" -A x64 -DCMAKE_INSTALL_PREFIX=D:\Paddle\installed_protobuf_lib -Dprotobuf_MSVC_STATIC_RUNTIME=OFF -Dprotobuf_BUILD_SHARED_LIBS=OFF -Dprotobuf_BUILD_TESTS=OFF -Dprotobuf_BUILD_EXAMPLES=OFF .
msbuild protobuf.sln /m /p:Configuration=Release /p:Platform=x64
msbuild INSTALL.vcxproj /p:Configuration=Release /p:Platform=x64

# 将protobuf加入环境变量
set PATH=D:\Paddle\installed_protobuf_lib\bin;%PATH%
```

### 安装Paddle2ONNX

```bash
git clone https://github.com/PaddlePaddle/Paddle2ONNX.git
cd Paddle2ONNX
git submodule init
git submodule update

pip install setuptools wheel auditwheel auditwheel-symbols build
python -m build
pip install dist/*.whl
```
