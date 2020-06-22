# Eye Tracking with OpenCV C++

## Run the program
In the CMakeLists, you would need to change the path of OpenCv
```cmake 
# in CMakeLists.txt

# OpenCV library
set(OpenCV_LIBS "/usr/local/lib/opencv4")  # change this path
```

```bash
mkdir build
cd build
cmake ../
make

./../bin/eyeTracking # executable file
```

## Speed up the program
Initially, there were 12 frame per seconds. Let's try to speed up the program using threading.

This is the [link]() that implement multithreading in OpenCV C++  

## Explaining The Algorithms 

### Normalize vector
![alt text](img/unit_vector.png)

### Calculate Derivative 
![alt text](img/derivative_finite_difference.png)

Use [finite difference](https://www.math.ubc.ca/~pwalls/math-python/differentiation/differentiation/) methods, a numerical technique, to calculate differential equations. It finds approximation but easier to execute


 

