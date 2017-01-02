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

Create a dialogbox , initialize it and display the content.

```cpp
pei::DialogBox box( params );
box.init();
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
  box.init();
  box.show();
}
```
