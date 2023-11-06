# libV5SDK
This is an SDK that provides voicebank management and singing rendering based on VOCALOID5.
## Supported platforms:
- Windows x64
## Compile
### Windows(Visual Studio 2022)
Run Developer PowerShell for VS 2022 and cd to your repo dir.
```
mkdir build
cd build
cmake -G "Visual Studio 17 2022" ../
msbuild /p:Configuration=Debug libV5SDK.sln
```
Replace "Debug" with "Release" to build a release version.
