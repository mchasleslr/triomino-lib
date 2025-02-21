# lib-triomino



C library for creating a simplified version of the Triomino game.

## Installation

```bash
# https
$ git clone https://github.com/mchasleslr/triomino-lib.git

# ssh
$ git clone git@github.com:mchasleslr/triomino-lib.git
```

## Usage

### Build

```bash
$ mkdir build
$ cd build
$ cmake .. \
  -DBUILD_TESTS=<ON | OFF>
  -DCMAKE_INSTALL_PREFIX=<path/to/install>
  -DCMAKE_BUILD_TYPE=<Debug | Release | RelWithDebInfo | MinSizeRel>
$ make
```

### Run tests

```bash
$ make test
```

### Install library

```bash
$ make install
```

### Create archives

```bash
$ make package
$ make package_source
```

## License

[BSD-3-Clause](LICENSE)

## Authors

+ [Maxime Chasles](https://github.com/mchasleslr)

+ [Christophe Demko](https://github.com/chdemko)





