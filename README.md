# Consul Integration Example [![Build Status](https://dev.azure.com/lganzzzo/lganzzzo/_apis/build/status/oatpp.example-consul?branchName=master)](https://dev.azure.com/lganzzzo/lganzzzo/_build?definitionId=15&branchName=master)

Example project how-to use [oatpp-consul](https://github.com/oatpp/oatpp-consul) module. 

See more:

- [Oat++ Website](https://oatpp.io/)
- [Oat++ Github Repository](https://github.com/oatpp/oatpp)
- [Get Started](https://oatpp.io/docs/start)

## Overview
This project is using [oatpp](https://github.com/oatpp/oatpp) and [oatpp-consul](https://github.com/oatpp/oatpp-consul) modules.  

Currently this is trivial example.- Read/Write from/to Consul KV via endpoints declared in Controller.
More complex example later.  

In this example Consul is expected to run at port 8500.

### Project layout

```
|- CMakeLists.txt                        // projects CMakeLists.txt
|- src/
|    |
|    |- controller/                      // Folder containing controller where all endpoints are declared
|    |- dto/                             // DTOs are declared here
|    |- AppComponent.hpp                 // Service config
|    |- App.cpp                          // main() is here
|
|- test/                                 // test folder
|- utility/install-oatpp-modules.sh      // utility script to install required oatpp-modules.
```

---

### Build and Run

#### Using CMake

**Requires** 

- `oatpp` and `oatpp-consul` modules installed. You may run `utility/install-oatpp-modules.sh` 
script to install required oatpp modules.

```
$ mkdir build && cd build
$ cmake ..
$ make 
$ ./example-consul-exe          # - run application.
```

#### In Docker

```
$ docker build -t example-consul .
$ docker run -p 8000:8000 -t example-consul
```
