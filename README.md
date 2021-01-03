# Eye Tracking with OpenCV C++
Status: ongoing
Development: on macOS

An OpenCV project on traking eye gazing via webcam
1. Detect faces
2. Detect eyes
3. Detect pupils
4. Track pupils' movement

## Install OpenCV on macOS
https://www.learnopencv.com/install-opencv-4-on-macos/

## Compile the program
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
### Database
(BioID database)[https://www.bioid.com/facedb/] for eyec entre 

### Normalize vector
![alt text](img/unit_vector.png)

### Calculate Derivative 
![alt text](img/derivative_finite_difference.png)

Use [finite difference](https://www.math.ubc.ca/~pwalls/math-python/differentiation/differentiation/) methods, a numerical technique, to calculate differential equations. It finds approximation but easier to execute

## References 
- [Timm, Fabian, and Erhardt Barth. "Accurate eye centre localisation by means of gradients." Visapp 11 (2011): 125-130.](https://www.researchgate.net/publication/221415814_Accurate_Eye_Centre_Localisation_by_Means_of_Gradients)

