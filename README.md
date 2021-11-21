# R-Type

The purpose of this project is to create a video game which is inspired by the video game r-type released in 1987, using a client/server architecture.

## Setup

#### Conan / Cmake

1. Install conan binary using python3 pip command.
`pip3 install --user conan`

2. Update your Conan profile in `$HOME/.conan/profiles.`.
    Edit the following variables:
    - compiler: You must set your compiler (*Exemple: gcc*)
    - compiler.version: This **MUST** match your compiler version. `<compiler> --version`
    - compiler.libcxx: You **MUST** set this variable to use c++11 (libstdc++11for gcc)

4. Install CMake
5. Build the project. `make -j`



#### Dynamic library
After compiled, you **MUST** get dynamics libraries to play.

1. Create a directory at the root of the repositorie which is named : `./lib`
`mkdir lib`
2. Move the dynamic library compiled located at `build/lib/` in to `./lib`
`move build/lib/libFirstMonsterEntity.so ./lib`
`move build/lib/libSecondMonsterEntity.so ./lib`
`move build/lib/libThirdMonsterEntity.so ./lib`

#### r-type_server / r-type_client

1. Run r-type_server and set the port to open
`./r-type_server 8080`
2. Run r-type_client and set the address and the port of server
`./r-type_client`

> If you have a problem when you run babel_client.
> Try to remove portaudio in conan.
> `conan remove portaudio`

## Credits
- Alan Sigal
- Quentin Fonkenell
- Thomas Tricaud
- Tom Rives