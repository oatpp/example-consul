# Consul Integration Example [![Build Status](https://dev.azure.com/lganzzzo/lganzzzo/_apis/build/status/oatpp.example-consul?branchName=master)](https://dev.azure.com/lganzzzo/lganzzzo/_build?definitionId=15&branchName=master)

Example project how-to use [oatpp-consul](https://github.com/oatpp/oatpp-consul) module. 

#### More about oat++:
- Website: [https://oatpp.io](https://oatpp.io)
- Docs: [https://oatpp.io/docs/start](https://oatpp.io/docs/start)
- Oat++ Repo: [https://github.com/oatpp/oatpp](https://github.com/oatpp/oatpp)

## Overview
This project is using `oatpp` and `oatpp-consul` modules.  

Currently this is trivial example.- Read/Write from/to Consul KV via endpoints declared in Controller.
More complex example later.  

In this example Consul is expected to run at port 8500.

### Project layout

```

- CMakeLists.txt               // project loader script. load and build dependencies 
- main/                        // main project directory
    |
    |- CMakeLists.txt          // projects CMakeLists.txt
    |- src/                    // source folder
    |- test/                   // test folder
    
```
```
- src/
    |
    |- controller/              // Folder containing controller where all endpoints are declared
    |- dto/                     // DTOs are declared here
    |- AppComponent.hpp         // Service config
    |- Logger.hpp               // Application Logger
    |- App.cpp                  // main() is here
    
```

---

### Build and Run

#### Using CMake

```
$ mkdir build && cd build
$ cmake ..
$ make run        ## Download, build, and install all dependencies. Run project

```

#### In Docker

```
$ docker build -t example-consul .
$ docker run -p 8000:8000 -t example-consul
```
