BUILD_ARCH ?= $(shell uname -m)
BUILD_TYPE ?= Release
SOURCE_DIR = $(patsubst %/,%,${PWD})
BINARY_DIR = .build/$(BUILD_ARCH)/$(BUILD_TYPE)
CMAKE ?= cmake

%: cmake
	cd ${BINARY_DIR}; ${MAKE} ${MAKE_FLAGS} $@

cmake:
	mkdir -p ${BINARY_DIR}; cd ${BINARY_DIR}; ${CMAKE} -DCMAKE_BUILD_TYPE=${BUILD_TYPE} ${CMAKE_FLAGS} ${SOURCE_DIR}

install: cmake
	cd ${BINARY_DIR}; ${MAKE} ${MAKE_FLAGS} install

clean: cmake
	cd ${BINARY_DIR}; ${MAKE} ${MAKE_FLAGS} clean
	
test:
	cd ${BINARY_DIR}; ./r201x-tests-tests

.PHONY: cmake install clean test