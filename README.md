# KaleidoscopicSeal (封印万華鏡)

A game developed with OpenSiv3D

## Build on macOS

1. Move current directory to root directory of the project.
1. To change directory structure, move `examples/empty/*` to `./`.
1. To configure dependencies, change `./empty.xcodeproj` as follows:

    1. add `./lib/` to project navigator as group, 
    1. add [Build Settings/Search Paths/Header Search Paths] `"./include"` and `"./include/ThirdParty"`,
    1. add [Build Settings/Search Paths/Library Search Paths] `"./lib/macOS"`.

1. To rename project name, change [Identity and Types] of `./empty.xcodeproj`.

