# PEI
Parameter Entry Interface (PEI) is a small GUI library for getting
parameters from the user.

# Usage
To create a dialog box where the user can enter parameters include
the following
```cpp
  #include <pei/dialogBox.hpp>
  #include <map>
  #include <string>
```

In the main function create a map and initialize it.
```cpp
map<string,double> params;

// Add some parameters
params["FirstParam"] = 1.0;
params["SecondParam"] = 2.0;
params["ThirdParam"] = 3.0;
```

Create a dialogbox and display the content.

```cpp
pei::DialogBox box( params );
box.show();
```

Full example file
```cpp
#include <pei/dialogBox.hpp>
#include <map>
#include <string>

using namespace std;

int main()
{
  map<string,double> params;

  // Add some parameters
  params["FirstParam"] = 1.0;
  params["SecondParam"] = 2.0;
  params["ThirdParam"] = 3.0;

  // Create the dialogbox
  pei::DialogBox box( params );
  box.show();
}
```

# Installation
After cloning the repository the library can be installed by
```bash
cmake .
make
sudo make install
```
This will put the header files in */usr/local/include/pei* and the shared
library file to */usr/local/lib*.
These paths can be changed by modifying the *INSTALL_INCLUDE_DIR* and the
*INSTALL_LIB_DIR* in CMakeLists.txt.

# Dependencies
In order to install this library [FLTK](http://www.fltk.org/index.php)
needs to installed.
In addition support for OpenGL is required.
