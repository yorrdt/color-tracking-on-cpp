# testq

## To compile in Code::Blocks your should add flags and includes:

### Build options... -> Linker Settings -> Link libraries:

* "/usr/local/lib/libopencv_calib3d.so",
* "/usr/local/lib/libopencv_core.so",
* "/usr/local/lib/libopencv_dnn.so",
* "/usr/local/lib/libopencv_features2d.so",
* "/usr/local/lib/libopencv_flann.so",
* "/usr/local/lib/libopencv_gapi.so",
* "/usr/local/lib/libopencv_highgui.so",
* "/usr/local/lib/libopencv_imgcodecs.so",
* "/usr/local/lib/libopencv_imgproc.so",
* "/usr/local/lib/libopencv_ml.so",
* "/usr/local/lib/libopencv_objdetect.so",
* "/usr/local/lib/libopencv_photo.so",
* "/usr/local/lib/libopencv_stitching.so",
* "/usr/local/lib/libopencv_video.so",
* "/usr/local/lib/libopencv_videoio.so"

### Build options... -> Linker Settings -> Other linker options:

* "-lglfw",
* "-lglut",
* "-lGL",
* "-lGLU",
* "-lGLEW",
* "-lpthread"

### Build options... -> Search directories -> Compiler:

* "/usr/include/GL",
* "/usr/include/GLFW",
* "/usr/local/include/opencv4"

![Illustration](https://github.com/yorrdt/opengl-cube-and-controller/blob/master/scr.jpg)


