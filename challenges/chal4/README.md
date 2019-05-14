# Multithreaded Raining Balls Island Simulator
Simulation of falling balls falling from the sky from the moment they touch the island until the momment they stop moving in a valley or they sink into the ocean.

## Authors
- **A00959979** Humberto Atondo Martin del Campo 
- **A01227157** Kevin Oswaldo Cabrera Navarro 
- **A01630171** Gilberto Rogel García 

## Compile 
You can either go by using the make file
````
make
````

or compiling by hand
````
go run ballsRainingSimulator.go
````

## Requirements

To run you need to have Golang installed

|          Operating System         |             Architectures             |                               Notes                               |
|:---------------------------------:|:-------------------------------------:|:-----------------------------------------------------------------:|
|       FreeBSD 10.3 or later       |               amd64, 386              |                 Debian GNU/kFreeBSD not supported                 |
|  Linux 2.6.23 or later with glibc | amd64, 386, arm, arm64,s390x, ppc64le | CentOS/RHEL 5.x not supported.Install from source for other libc. |
|        macOS 10.10 or later       |                 amd64                 |    use the clang or gcc† that comes with Xcode‡ for cgo support   |
| Windows 7, Server 2008R2 or later |               amd64, 386              |            use MinGW gcc†. No need for cygwin or msys.            |

For any other doubt visit the Goland official page in [here](https://golang.org/doc/install)

You can also find available Operating systems to run Go in [here](https://github.com/golang/go/wiki/MinimumRequirements)
